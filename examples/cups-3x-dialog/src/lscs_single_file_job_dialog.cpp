/*! \file lscs_single_file_job_dialog.cpp
 *
 *  \brief Source file for lscs_single_file_job_dialog class.
 *
 *  \details Handles all job values including CUPS security (when needed)
 *        With CUPS 3.x and even later 2.x it is no longer acceptable to
 *        open a "device" and lock it while you spew to it a page at a time.
 *        Now we generate a temporary file via a spooler and send the entire
 *        single file job to the output device.
 *
 *  \author Roland Hughes
 *  \copyright Copyright © 2025-2026 Roland Hughes d.b.a. Logikal Solutions All rights reserved.
 *  \license This project is released under LGPL 2.1
 *
 *;;;;
 *
 * This file is part of Ls-Cs, also known as LsCs
 *
 * Ls-Cs is free software. You can redistribute it and/or
 * modify it under the terms the Basis Doctrina License found in
 * Basis_Doctrina_License.txt
 *
 * Ls-Cs is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 */

#include <qcombobox.h>
#include <qspinbox.h>
#include <qradiobutton.h>
#include <qgroupbox.h>
#include <qcheckbox.h>
#include <qtabwidget.h>
#include <qvboxlayout.h>
#include <qhboxlayout.h>
#include <qtoolbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qstringparser.h>
#include <qdialogbuttonbox.h>
#include <qapplication.h>
#include <qtimer.h>

#include <cups/cups.h>      /*! \todo need non-windows conditional around this */

#include <lscs_single_file_job_dialog.h>

const char *URI_TAG = "printer-uri";        /*! \todo need non-windows conditional around this */
const char *REQUESTED_ATTRIBUTES = "requested-attributes";  /*! \todo need non-windows conditional around this.*/
const char *REQUEST_DEFAULT_ORIENTATION = "orientation-requested-default";  /*! \todo need non-windows conditional around this */
const char *URI_SUPPORTED_TAG = "printer-uri-supported";  // @todo need non-windows conditional around this
const char *REQUEST_COLOR_SUPPORTED = "color-supported";  // @todo need non-windows conditional around this
const char *REQUEST_COLOR_MODE = "print-color-mode-supported"; // @todo need non-windows conditional around this
const char *REQUEST_COLOR_MODE_DEFAULT = "print-color-mode-default"; // @todo need non-windows conditional around this
const char *REQUEST_PRINT_QUALITY_DEFAULT = "print-quality-default"; // @todo need non-windows conditional around this

/*! \brief Constructor
 *
 *  \param parent - pointer to parent widget or NULL
 */
lscs_single_file_job_dialog::lscs_single_file_job_dialog( QWidget *parent ) :
    QDialog( parent )
{
    setModal( true );
    setWindowTitle( tr( "lscs_single_file_job_dialog" ) );


    m_tabWidget = new QTabWidget();
    m_tabWidget->setTabsClosable( false );
    m_tabWidget->tabBar()->setMovable( false );
    m_tabWidget->tabBar()->setShape( QTabBar::TriangularNorth );

    m_generalTab    = new general_tab();
    m_pageSetupTab  = new page_setup_tab();
    m_spoolerTab    = new spooler_tab();
    m_tabWidget->addTab( m_spoolerTab, tr( "Spooler" ) );
    m_tabWidget->addTab( m_generalTab, tr( "General" ) );
    m_tabWidget->addTab( m_pageSetupTab, tr( "Page Setup" ) );

    QDialogButtonBox *btnBox = new QDialogButtonBox( QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this );

    // make connections here

    connect( m_spoolerTab, &spooler_tab::spooler_type_changed,     this, &lscs_single_file_job_dialog::spooler_selected );

    connect( m_generalTab, &general_tab::destination_changed,      this, &lscs_single_file_job_dialog::destination_selected );
    connect( m_generalTab, &general_tab::copies_changed,           this, &lscs_single_file_job_dialog::copies_changed );
    connect( m_generalTab, &general_tab::paper_source_changed,     this, &lscs_single_file_job_dialog::paper_source_changed );
    connect( m_generalTab, &general_tab::paper_changed,            this, &lscs_single_file_job_dialog::paper_changed );
    connect( m_generalTab, &general_tab::print_quality_changed,    this, &lscs_single_file_job_dialog::print_quality_changed );

    connect( m_pageSetupTab, &page_setup_tab::duplex_changed,      this, &lscs_single_file_job_dialog::duplex_changed );
    connect( m_pageSetupTab, &page_setup_tab::scaling_changed,     this, &lscs_single_file_job_dialog::scaling_changed );
    connect( m_pageSetupTab, &page_setup_tab::number_up_changed,   this, &lscs_single_file_job_dialog::number_up_changed );
    connect( m_pageSetupTab, &page_setup_tab::orientation_changed, this, &lscs_single_file_job_dialog::orientation_changed );

    connect( btnBox, &QDialogButtonBox::rejected,   this, &QDialog::reject );
    connect( btnBox, &QDialogButtonBox::accepted,   this, &lscs_single_file_job_dialog::submit_job );


    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget( m_tabWidget );
    mainLayout->addWidget( btnBox );

    setLayout( mainLayout );

    QTimer::singleShot( 800, this, SLOT( choose_defaults() ) );


}

/*! \brief  Submit single file job to spooler and/or destination
 *
 *  \details Chosen spooler type will be created and passed information
 *           about what to include in the temporary file it creates
 *           that will then be submitted as a job to the spooler destination.
 */
void lscs_single_file_job_dialog::submit_job()
{
    qDebug() << "called submit_job() \n";

    // Update the job capabilities
    //
    m_job.useCollateValue           = m_generalTab->is_collate_visible();
    m_job.usePrintQualityValue      = m_generalTab->is_print_quality_visible();
    m_job.usePaperSourceValue       = m_generalTab->is_paper_source_visible();
    m_job.useColorValue             = m_generalTab->is_color_mode_visible();
    m_job.useCopiesValue            = m_generalTab->is_copies_visible();
    m_job.useNumberUpValue          = m_pageSetupTab->is_number_up_visible();
    m_job.useDuplexValue            = m_pageSetupTab->is_duplex_visible();
    m_job.useOrientationValue       = m_pageSetupTab->is_orientation_visible();
    m_job.useScalingValue           = m_pageSetupTab->is_scaling_visible();


    qDebug() << "m_job: " << m_job.to_string() << "\n";

#if defined(CUPS_VERSION)
    //int job_id = 0;
    size_t num_options = 0;
    cups_option_t *options = nullptr;

    if ( m_job.useCopiesValue )
    {
        num_options = cupsAddIntegerOption( CUPS_COPIES, m_job.copies, num_options, &options );
    }

#else
    /*! \todo  need to submit job for other operating systems */
#endif
    accept();
}

/*! \brief Abandon creation of a spooler job
 */
void lscs_single_file_job_dialog::quit()
{
    reject();
}

/*! \brief slot to set default printer values in dialog
 *
 *  \details called from timer because signals and slots are not
 *           firing during construction. That gives us a chicken and egg
 *           problem. Need method of populating default destination
 *           information once comboboxes have been created.
 */
void lscs_single_file_job_dialog::choose_defaults()
{
    // when communicating across network to populate dialog
    // things can take time.
    qApp->setOverrideCursor( QCursor( Qt::WaitCursor ) );

    m_spoolerTab->push_spooler_button( LsCsSpoolerType::Text );

    m_generalTab->make_default_current_destination();

    qApp->restoreOverrideCursor();

}

/*! \brief slot to record change to number of copies
 *
 *  \param copies - non-zero integer indicating number of copies to generate
 */
void lscs_single_file_job_dialog::copies_changed( int copies )
{
    m_job.copies = copies;
}

/*! \brief slot to record change to spooler type
 *
 *  \param spoolerType - value from LsCsSpoolerType enum class
 */
void lscs_single_file_job_dialog::spooler_selected( LsCsSpoolerType spoolerType )
{
    m_job.spoolerType = spoolerType;
}

/*! \brief method that returns spooler type from internal job variable.
 */
LsCsSpoolerType lscs_single_file_job_dialog::spooler_type()
{
    return m_job.spoolerType;
}

/*! \brief records destination name and if it is a file in the internal job variable
 *
 *  \param destinationName - string containing device name or full path to file
 *  \param isFile - bool indicating if destinationName is full path to file
 */
void lscs_single_file_job_dialog::destination_selected( QString destinationName, bool isFile )
{
    qDebug() << "destination_selected called";
    m_job.destinationName   = destinationName;
    m_job.destinationIsFile = isFile;
    m_job.validJob          = true;

    m_pageSetupTab->destination_changed( destinationName );
}

/*! \brief slot to record new paper source in internal job variable
 *
 *  \param source - string containing name of paper source
 */
void lscs_single_file_job_dialog::paper_source_changed( const QString &source )
{
    m_job.paperSource = source;
}

/*! \brief slot to record new type/size of paper in internal job variable
 *
 *  \param paper - string containing type/size of paper as recognized by device
 */
void lscs_single_file_job_dialog::paper_changed( const QString &paper )
{
    m_job.paper = paper;
}

/*! \brief slot to record page orientation in internal job variable
 *
 *  \param orientation - string containing name of orientation as recognized by device
 */
void lscs_single_file_job_dialog::orientation_changed( const QString &orientation )
{
    m_job.orientation = orientation;
}

/*! \brief slot to record change of duplex value in internal job variable
 *
 * \param duplex - string containing duplex value recognized by device
 */
void lscs_single_file_job_dialog::duplex_changed( const QString &duplex )
{
    m_job.duplex = duplex;
}

/*! \brief slot to record change of scaling value in internal job variable
 *
 *  \param scaling - string containing scaling value as recognized by device
 */
void lscs_single_file_job_dialog::scaling_changed( const QString &scaling )
{
    m_job.scaling = scaling;
}

/*! \brief slot to record change in number of pages up value in internal job variable
 *
 *  \param numberUp - string containing number of pages up on a single sheet as recognized
 *                    by the device to be recorded in internal job variable.
 */
void lscs_single_file_job_dialog::number_up_changed( const QString &numberUp )
{
    m_job.numberUp = numberUp;
}

/*! \brief slot to record change of print quality in internal job variable.
 *
 *  \param printQuality - string containing print quality value as recognized by device
 *                        in internal job variable.
 */
void lscs_single_file_job_dialog::print_quality_changed( const QString &printQuality )
{
    m_job.printQuality = printQuality;
}

//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
//      General Tab
//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
/*! \brief Explicit general_tab Constructor
 *
 *  \details Constructs the General tab widget for single file job dialog
 *
 *  \param parent - pointer to parent widget or nullptr
 */
general_tab::general_tab( QWidget *parent ) :
    QWidget( parent )
{
    QVBoxLayout *mainLayout    = new QVBoxLayout();

    //  scratch variables used when manipulating layouts
    //
    int left = 0;
    int top = 0;
    int right = 0;
    int bottom = 0;


    // Destination
    //
    QLabel *destLbl         = new QLabel( tr( "Destination" ) );
    m_destinationCB         = new QComboBox();
    QHBoxLayout *destLayout = new QHBoxLayout();
    destLayout->addWidget( destLbl );
    destLayout->addWidget( m_destinationCB );

    mainLayout->addLayout( destLayout );

    // magic file destination location
    //
    QHBoxLayout *destFileLayout = new QHBoxLayout();
    m_destFileWidget            = new QWidget();
    m_fileChooserBtn            = new QToolButton();
    m_fileNameLE                = new QLineEdit();

    m_fileChooserBtn->setText( "..." );     // @todo  need an icon instead of this
    m_fileChooserBtn->setToolTip( tr( "Choose output file path and name" ) );

    destFileLayout->addWidget( m_fileChooserBtn );
    destFileLayout->addWidget( m_fileNameLE );
    m_destFileWidget->setLayout( destFileLayout );
    m_destFileWidget->setVisible( false );          // we only show this when destination is a file.

    mainLayout->addWidget( m_destFileWidget );


    // paper source
    /*! \todo  show/hide source depending on how many printer supports*/
    //
    QHBoxLayout *sourceLayout   = new QHBoxLayout();
    QLabel *sourceLabel         = new QLabel( tr( "Paper Source" ) );
    m_paperSourceCB             = new QComboBox();

    sourceLayout->addWidget( sourceLabel );
    sourceLayout->addWidget( m_paperSourceCB );
    sourceLayout->getContentsMargins( &left, &top, &right, &bottom );
    left = 0;
    right = 0;
    sourceLayout->setContentsMargins( left, top, right, bottom );

    m_sourceWidget = new QWidget();
    m_sourceWidget->setLayout( sourceLayout );

    mainLayout->addWidget( m_sourceWidget );

    // paper
    //
    QHBoxLayout *paperLayout    = new QHBoxLayout();
    QLabel *paperLabel          = new QLabel( tr( "Paper" ) );
    m_paperCB                   = new QComboBox();

    paperLayout->addWidget( paperLabel );
    paperLayout->addWidget( m_paperCB );
    paperLayout->getContentsMargins( &left, &top, &right, &bottom );
    left = 0;
    right = 0;
    paperLayout->setContentsMargins( left, top, right, bottom );

    m_paperLayoutWidget = new QWidget();
    m_paperLayoutWidget->setLayout( paperLayout );

    mainLayout->addWidget( m_paperLayoutWidget );

    // print quality
    //
    QHBoxLayout *printQLayout   = new QHBoxLayout();
    QLabel *printQLabel         = new QLabel( tr( "Print Quality" ) );
    m_printQualityCB            = new QComboBox();

    printQLayout->addWidget( printQLabel );
    printQLayout->addWidget( m_printQualityCB );
    printQLayout->getContentsMargins( &left, &top, &right, &bottom );
    left = 0;
    right = 0;
    printQLayout->setContentsMargins( left, top, right, bottom );

    m_printQWidget = new QWidget();
    m_printQWidget->setLayout( printQLayout );

    mainLayout->addWidget( m_printQWidget );

    // pages
    //
    QHBoxLayout *pagesLayout    = new QHBoxLayout();
    QLabel *pagesLabel          = new QLabel( tr( "Pages" ) );
    m_pagesLE                   = new QLineEdit();

    m_pagesLE->setToolTip( tr( "Leave blank for all" ) );

    pagesLayout->addWidget( pagesLabel );
    pagesLayout->addStretch();
    pagesLayout->addWidget( m_pagesLE );

    pagesLayout->getContentsMargins( &left, &top, &right, &bottom );
    left = 0;
    right = 0;
    pagesLayout->setContentsMargins( left, top, right, bottom );

    m_pagesWidget = new QWidget();
    m_pagesWidget->setLayout( pagesLayout );

    mainLayout->addWidget( m_pagesWidget );

    // copies
    //
    QHBoxLayout *copiesLayout = new QHBoxLayout();
    QLabel *copiesLbl         = new QLabel( tr( "Copies" ) );
    m_copiesSB                = new QSpinBox();

    copiesLayout->getContentsMargins( &left, &top, &right, &bottom );
    left = 0;
    right = 0;
    copiesLayout->setContentsMargins( left, top, right, bottom );

    copiesLayout->addWidget( copiesLbl );
    copiesLayout->addStretch();
    copiesLayout->addWidget( m_copiesSB );


    m_copiesWidget = new QWidget();
    m_copiesWidget->setLayout( copiesLayout );

    mainLayout->addWidget( m_copiesWidget );

    // collate copies
    // \todo  show/hide collate widget if file or printer does not support
    //
    QHBoxLayout *collateLayout  = new QHBoxLayout();
    QLabel *collateLabel        = new QLabel( tr( "Collate Copies" ) );
    m_collateCKB                = new QCheckBox();

    collateLayout->getContentsMargins( &left, &top, &right, &bottom );
    left = 0;
    right = 0;
    collateLayout->setContentsMargins( left, top, right, bottom );

    collateLayout->addWidget( collateLabel );
    collateLayout->addStretch();
    collateLayout->addWidget( m_collateCKB );

    m_collateWidget = new QWidget();
    m_collateWidget->setLayout( collateLayout );

    mainLayout->addWidget( m_collateWidget );

    // color
    //
    QHBoxLayout *colorLayout    = new QHBoxLayout();
    QLabel *colorLbl            = new QLabel( tr( "Color Mode" ) );
    m_colorCB                   = new QComboBox();

    colorLayout->getContentsMargins( &left, &top, &right, &bottom );
    left = 0;
    right = 0;
    colorLayout->setContentsMargins( left, top, right, bottom );

    colorLayout->addWidget( colorLbl );
    colorLayout->addStretch();
    colorLayout->addWidget( m_colorCB );

    m_colorWidget = new QWidget();
    m_colorWidget->setLayout( colorLayout );

    mainLayout->addWidget( m_colorWidget );

    this->setLayout( mainLayout );

    // avoid chicken and egg problem.
    // populate destinations combobox before connections made.
    //
    populate_destination_CB();

    //  Make connections
    //
    connect( m_destinationCB,   &QComboBox::currentTextChanged, this, &general_tab::dest_text_changed );
    connect( m_fileChooserBtn,  &QToolButton::triggered,        this, &general_tab::choose_destination_file );
    connect( m_paperSourceCB,   &QComboBox::currentTextChanged, this, &general_tab::source_changed );
    connect( m_paperCB,         &QComboBox::currentTextChanged, this, &general_tab::paper_changed );
    connect( m_printQualityCB,  &QComboBox::currentTextChanged, this, &general_tab::print_quality_changed );

    connect( m_copiesSB,       static_cast<void ( QSpinBox::* )( int )>( &QSpinBox::valueChanged ),
             this, &general_tab::copies_value_changed );

}

/*! \brief returns visibility state of collate widget
 *
 *  \returns bool - TRUE == is visible
 */
bool general_tab::is_collate_visible()
{
    return m_collateWidget->isVisible();
}

/*! \brief returns visibility state of print quality widget
 *
 *  \returns bool - TRUE == is visible
 */
bool general_tab::is_print_quality_visible()
{
    return m_printQWidget->isVisible();
}

/*! \brief returns visibility state of paper source widget
 *
 *  \returns bool - TRUE == visibl
 */
bool general_tab::is_paper_source_visible()
{
    return m_sourceWidget->isVisible();
}

/*! \brief returns visibility state of color mode widget
 *
 *  \returns bool - TRUE == is visible
 */
bool general_tab::is_color_mode_visible()
{
    return m_colorWidget->isVisible();
}

/*! \brief returns visibility state of number of copies widget
 *
 *  \returns bool - TRUE == is visible
 */
bool general_tab::is_copies_visible()
{
    qDebug() << "m_copiesWidget-isVisible():  " << m_copiesWidget->isVisible();
    return m_copiesWidget->isVisible();
}

/*! \brief slot to record change in number of copies value
 *
 *  \param newValue - integer number of copies. Must be at least 1.
 */
void general_tab::copies_value_changed( int newValue )
{
    if ( m_canCollate )
    {
        m_collateWidget->setVisible( true );

        if ( newValue < 2 )
        {
            m_collateWidget->setDisabled( true );
        }
        else
        {
            m_collateWidget->setDisabled( false );
        }
    }
    else
    {
        m_collateCKB->setCheckState( Qt::Unchecked );
        m_collateWidget->setVisible( false );
        m_collateWidget->setDisabled( true );
    }
}

/*! \brief returns destination name.
 *
 * \returns string - This may be device name or full path to file.
 */
QString general_tab::get_destination_name()
{
    return m_destinationCB->currentText();
}

/*! \brief method to populate destination combobox
 *
 *  \details On Linux systems this will be a list of devices recognized by CUPS. On other platforms
 *           the list will come from the OS specific API.
 */
void general_tab::populate_destination_CB()
{
    m_destinationCB->clear();

    qDebug() << "called populate_destination_CB()";

#if defined(CUPS_VERSION)

    cups_dest_t *dests = nullptr;
    size_t destCnt = cupsGetDests( &dests );  //cupsGetDests2( CUPS_HTTP_DEFAULT, &dests );

    QStringList items;

    for ( size_t jjj = 0; jjj < destCnt; jjj++ )
    {
        cups_dest_t *workDest = &dests[jjj];

        if ( workDest != nullptr )
        {
            QString printerName = QString::fromUtf8( workDest->name );
            items << printerName;

            if ( workDest->is_default )
            {
                qDebug() << "default printer: " << printerName;
                m_user_default_printer = printerName;
            }
        }
    }

    items.sort();


    m_destinationCB->addItems( items );

    if ( items.count() > 0 )
    {
        m_destinationCB->insertSeparator( items.count() + 1 );
    }

    m_destinationCB->addItem( tr( "File" ) );


    cupsFreeDests( destCnt, dests );
#else
    /*! \todo need to get destinations for other OSes */
#endif


}

/*! \brief method to change destination to the default output device or file
 *
 */
void general_tab::make_default_current_destination()
{
    qDebug() << "called make_default_current_destination()";

    int current_index = m_destinationCB->currentIndex();

    // set combobox to default destination
    //
    if ( m_user_default_printer.length() > 0 )
    {
        qDebug() << "setting default destination: " << m_user_default_printer;
        m_destinationCB->setCurrentIndex( m_destinationCB->findText( m_user_default_printer ) );
    }
    else
    {
        qDebug() << "No default printer established, choosing first one";
        m_destinationCB->setCurrentIndex( 0 );
        m_user_default_printer = m_destinationCB->itemText( 0 );
    }

    /* work around for bug inherited from CopperSpice. If you set the current index to a value
     * like zero, for a newly constructed combo box, signals will not be emitted because there
     * was no change in value.
     */
    if ( m_destinationCB->currentIndex() == current_index )
    {
        dest_text_changed( m_destinationCB->currentText() );
    }

}

/*! \brief method to populate paper source combobox based on current device destination
 *
 *  \details On Linux this will be paper source information provided by CUPS. On other
 *           platforms it will be obtained from the OS specific API.
 */
void general_tab::populate_paper_source_CB()
{
    m_paperSourceCB->clear();

#if defined(CUPS_VERSION)

    cups_dest_t *dests = nullptr;

#if CUPS_VERSION_MAJOR == 3
    size_t destCnt = cupsGetDests( CUPS_HTTP_DEFAULT, &dests );
#else
    int destCnt = cupsGetDests2( CUPS_HTTP_DEFAULT, &dests );
#endif

    // if populate paper called instantly behind populateDestinationCB it is possible
    // the GUI has not had time to set display text, but the object will know what the
    // current index was set to.
    //
    QString currentDestStr = m_destinationCB->itemText( m_destinationCB->currentIndex() );
    cups_dest_t *currentDest = cupsGetDest( currentDestStr.toUtf8().constData(), NULL, destCnt, dests );

    // if we didn't find then bail
    //
    if ( currentDest == nullptr )
    {
        return;
    }

    cups_dinfo_t *info = cupsCopyDestInfo( CUPS_HTTP_DEFAULT, currentDest );
    char value[4096];

    ipp_attribute_t *attr = nullptr;

    QString defaultSource;
    QStringList items;


    if ( ( attr = cupsFindDestDefault( CUPS_HTTP_DEFAULT, currentDest, info, CUPS_MEDIA_SOURCE ) ) != NULL )
    {
        ippAttributeString( attr, value, sizeof( value ) );
        defaultSource = QString::fromUtf8( value );
    }

    if ( ( attr = cupsFindDestSupported( CUPS_HTTP_DEFAULT, currentDest, info, CUPS_MEDIA_SOURCE ) ) != NULL )
    {
        ippAttributeString( attr, value, sizeof( value ) );
        items = QString::fromUtf8( value ).split( "," );
    }


    m_paperSourceCB->addItems( items );

    int defaultItem = m_paperSourceCB->findText( defaultSource );

    if ( defaultItem > -1 )
    {
        m_paperSourceCB->setCurrentIndex( defaultItem );
    }

    if ( m_paperSourceCB->count() < 2 )
    {
        m_sourceWidget->setVisible( false );
    }
    else
    {
        m_sourceWidget->setVisible( true );
    }

    cupsFreeDestInfo( info );
    cupsFreeDests( destCnt, dests );
#else
    /*! \todo need to get paper sources for other platforms */
#endif
}

/*! \brief ask if the destination can collate output
 *
 *  \details On Linux the collate information will be requested via CPUS. OS specific APIs will
 *           be called on other platforms.
 *
 *  \param string - name of destination device.
 */
bool general_tab::dest_can_collate( QString destination )
{
    bool retVal = false;

#if defined(CUPS_VERSION)
    cups_dest_t *dests = nullptr;


#if CUPS_VERSION_MAJOR == 3
    size_t destCnt = cupsGetDests( CUPS_HTTP_DEFAULT, &dests );
#else
    int destCnt = cupsGetDests2( CUPS_HTTP_DEFAULT, &dests );
#endif

    cups_dest_t *currentDest = cupsGetDest( destination.toUtf8().constData(), NULL, destCnt, dests );

    // if we didn't find then bail
    //
    if ( currentDest == nullptr )
    {
        return retVal;
    }

    cups_dinfo_t *info = cupsCopyDestInfo( CUPS_HTTP_DEFAULT, currentDest );
    char value[4096];

    ipp_attribute_t *attr = nullptr;


    if ( ( attr = cupsFindDestSupported( CUPS_HTTP_DEFAULT, currentDest, info, "multiple-document-handling" ) ) != NULL )
    {
        ippAttributeString( attr, value, sizeof( value ) );
        QString rslt = QString::fromUtf8( value );

        if ( rslt.contains( "-collated" ) )
        {
            retVal = true;
        }
    }
    else
    {
        qDebug() << "cupsFindDestSupported call failed";
    }


    cupsFreeDestInfo( info );
    cupsFreeDests( destCnt, dests );
#else
    /*!  \todo need to see if device can allocate on other platforms */
#endif

    return retVal;
}

/*! \brief method to populate the paper combobox based on current destination device
 *
 *  \details On Linux the list of paper names will be obtained from CUPS. OS specific APIs
 *           will be used on other platforms.
 */
void general_tab::populate_paper_CB()
{
    qDebug() << "called populate_paper_CB()" ;
    // @todo  translate the cups paper names to human names
    m_paperCB->clear();

#if defined(CUPS_VERSION)
    cups_dest_t *dests = nullptr;

#if CUPS_VERSION_MAJOR == 3
    size_t destCnt = cupsGetDests( CUPS_HTTP_DEFAULT, &dests );
#else
    int destCnt = cupsGetDests2( CUPS_HTTP_DEFAULT, &dests );
#endif

    // if populate paper called instantly behind populateDestinationCB it is possible
    // the GUI has not had time to set display text, but the object will know what the
    // current index was set to.
    //
    QString currentDestStr = m_destinationCB->itemText( m_destinationCB->currentIndex() );
    qDebug() << "**************** currentDestStr: " << currentDestStr;
    cups_dest_t *currentDest = cupsGetDest( currentDestStr.toUtf8().constData(), NULL, destCnt, dests );

    // if we didn't find then bail
    //
    if ( currentDest == nullptr )
    {
        return;
    }

    cups_dinfo_t *info = cupsCopyDestInfo( CUPS_HTTP_DEFAULT, currentDest );
    int mediaCount = cupsGetDestMediaCount( CUPS_HTTP_DEFAULT, currentDest, info, CUPS_MEDIA_FLAGS_DEFAULT );

    QStringList items;

    for ( int jjj=0; jjj < mediaCount; jjj++ )
    {
        cups_size_t media;

        if ( cupsGetDestMediaByIndex( CUPS_HTTP_DEFAULT, currentDest, info, jjj, CUPS_MEDIA_FLAGS_DEFAULT, &media ) )
        {
            items << QString::fromUtf8( media.media );
        }
    }

    m_paperCB->addItems( items );

    // now set the default value
    //
    int currentItem = -1;
#if defined(CUPS_VERSION_MAJOR) && CUPS_VERSION_MAJOR >= 3
    cups_media_t defaultMedia;

    qDebug() << "calling cupsGetDestMediaDefault in 3.x API";

    if ( cupsGetDestMediaDefault( CUPS_HTTP_DEFAULT, currentDest, info, CUPS_MEDIA_FLAGS_BORDERLESS, &defaultMedia ) )
    {
        qDebug() << "defaultMedia.media:  " << QString::fromUtf8( defaultMedia.media );
        currentItem = m_paperCB->findText( QString::fromUtf8( defaultMedia.media ) );
        qDebug() << "new currentItem value: " << currentItem;
    }

#else
    cups_size_t defaultMedia;

    qDebug() << "calling cupsGetDestMediaDefault 2.x API";

    int rslt = cupsGetDestMediaDefault( CUPS_HTTP_DEFAULT, currentDest, info, CUPS_MEDIA_FLAGS_BORDERLESS, &defaultMedia );

    qDebug() << "got result of " << rslt;

    if ( rslt )
    {
        qDebug() << "defaultMedia.media:  " << QString::fromUtf8( defaultMedia.media );
        currentItem = m_paperCB->findText( QString::fromUtf8( defaultMedia.media ) );
        qDebug() << "new currentItem value: " << currentItem;
    }

#endif

    m_paperCB->setCurrentIndex( currentItem );


    cupsFreeDestInfo( info );
    cupsFreeDests( destCnt, dests );

#else
    /*! \todo need to find paper for other platforms */
#endif

}

/*! \brief method to populate color combobox based on current destination device.
 *
 *  \details On Linux color values will be obtained from CUPS. OS specific APIs will
 *           be used for other operating systems.
 */
void general_tab::populate_color_CB()
{
    m_colorCB->clear();

#if defined(CUPS_VERSION)
    cups_dest_t *dests = nullptr;


#if CUPS_VERSION_MAJOR == 3
    size_t destCnt = cupsGetDests( CUPS_HTTP_DEFAULT, &dests );
#else
    int destCnt = cupsGetDests2( CUPS_HTTP_DEFAULT, &dests );
#endif

    // if populate color called instantly behind populateDestinationCB it is possible
    // the GUI has not had time to set display text, but the object will know what the
    // current index was set to.
    //
    QString currentDestStr = m_destinationCB->itemText( m_destinationCB->currentIndex() );
    cups_dest_t *currentDest = cupsGetDest( currentDestStr.toUtf8().constData(), NULL, destCnt, dests );

    // if we didn't find then bail
    //
    if ( currentDest == nullptr )
    {
        cupsFreeDests( destCnt, dests );

        return;
    }

    cups_dinfo_t *info = cupsCopyDestInfo( CUPS_HTTP_DEFAULT, currentDest );

    char value[4096];

    ipp_attribute_t *attr = nullptr;

    QString defaultColorMode;
    QStringList items;


    if ( ( attr = cupsFindDestDefault( CUPS_HTTP_DEFAULT, currentDest, info, CUPS_PRINT_COLOR_MODE ) ) != NULL )
    {
        ippAttributeString( attr, value, sizeof( value ) );
        defaultColorMode = QString::fromUtf8( value );
    }

    if ( ( attr = cupsFindDestSupported( CUPS_HTTP_DEFAULT, currentDest, info, CUPS_PRINT_COLOR_MODE ) ) != NULL )
    {
        ippAttributeString( attr, value, sizeof( value ) );
        items = QString::fromUtf8( value ).split( "," );
    }


    m_colorCB->addItems( items );

    int defaultItem = m_colorCB->findText( defaultColorMode );

    if ( defaultItem > -1 )
    {
        m_colorCB->setCurrentIndex( defaultItem );
    }

    cupsFreeDestInfo( info );
    cupsFreeDests( destCnt, dests );
#else
    /*! \todo need to get color capabilities from other OSs */
#endif

}

/*! \brief method to set min and max spinbox values for copies
 *
 *  \details On Linux CUPS will be queried for maximum number of copies supported by current device.
 *           OS specific API calls will be made for other operating systems.
 */
void general_tab::populate_copies()
{

    m_copiesSB->clear();
    m_copiesSB->setRange( 1, 10 ); // set rather safe bogus limit until we get actual values

#if defined(CUPS_VERSION)

    cups_dest_t *dests = nullptr;

#if CUPS_VERSION_MAJOR == 3
    size_t destCnt = cupsGetDests( CUPS_HTTP_DEFAULT, &dests );
#else
    int destCnt = cupsGetDests2( CUPS_HTTP_DEFAULT, &dests );
#endif

    // if populate color called instantly behind populateDestinationCB it is possible
    // the GUI has not had time to set display text, but the object will know what the
    // current index was set to.
    //
    QString currentDestStr = m_destinationCB->itemText( m_destinationCB->currentIndex() );
    cups_dest_t *currentDest = cupsGetDest( currentDestStr.toUtf8().constData(), NULL, destCnt, dests );

    // if we didn't find then bail
    //
    if ( currentDest == nullptr )
    {
        cupsFreeDests( destCnt, dests );

        return;
    }

    cups_dinfo_t *info = cupsCopyDestInfo( CUPS_HTTP_DEFAULT, currentDest );

    char value[4096];

    ipp_attribute_t *attr = nullptr;

    QString copiesRange;
    QStringList items;

    if ( ( attr = cupsFindDestSupported( CUPS_HTTP_DEFAULT, currentDest, info, CUPS_COPIES ) ) != NULL )
    {
        ippAttributeString( attr, value, sizeof( value ) );
        items = QString::fromUtf8( value ).split( "-" );
    }


    if ( items.count() < 1 )
    {
        m_copiesSB->setValue( 1 );
    }
    else
    {
        int min = items[0].toInteger<int>();
        int max = min + 10; // just in case we got a bogus response string

        if ( items.count() > 1 )
        {
            max = items[1].toInteger<int>();
        }

        m_copiesSB->setRange( min, max );
        m_copiesSB->setValue( min );
    }

    cupsFreeDestInfo( info );
    cupsFreeDests( destCnt, dests );

#else
    /*! \todo need to get maximum number of copies for other operating systems. */
#endif

}

/*! \brief  Called when user chooses new printer destination to populate print quality options
 *
 *  \details When printer changes the available list of print qualities
 *           will change. This method takes into accoun the UI
 *           may not have had time to update and display
 *           the current printer.
 */
void general_tab::populate_print_quality_CB()
{
    m_printQualityCB->clear();

#if defined(CUPS_VERSION)
    cups_dest_t *dests = nullptr;

    size_t destCnt = cupsGetDests( &dests );

    qDebug() << "populatePrintQualityCB destCnt: " << destCnt;

    // if populate paper called instantly behind populateDestinationCB it is possible
    // the GUI has not had time to set display text, but the object will know what the
    // current index was set to.
    //
    QString currentDestStr = m_destinationCB->itemText( m_destinationCB->currentIndex() );
    cups_dest_t *currentDest = cupsGetDest( currentDestStr.toUtf8().constData(), NULL, destCnt, dests );

    // if we didn't find then bail
    //
    if ( currentDest == nullptr )
    {
        qDebug() << "currentDest: " << currentDestStr << "  not found";
        return;
    }

    cups_dinfo_t *info = cupsCopyDestInfo( CUPS_HTTP_DEFAULT, currentDest );
    QTextStream out( stdout );


    char value[4096];

    ipp_attribute_t *attr = nullptr;

    QString defaultQuality;
    QStringList items;

    if ( ( attr = cupsFindDestDefault( CUPS_HTTP_DEFAULT, currentDest, info, CUPS_PRINT_QUALITY ) ) != NULL )
    {
        ippAttributeString( attr, value, sizeof( value ) );
        defaultQuality = QString::fromUtf8( value );
        qDebug() << "default print quality: " << defaultQuality;
    }
    else
    {
        qDebug() << "default print quality error: " << QString::fromUtf8( cupsLastErrorString() );
    }

    if ( ( attr = cupsFindDestSupported( CUPS_HTTP_DEFAULT, currentDest, info, CUPS_PRINT_QUALITY ) ) != NULL )
    {
        ippAttributeString( attr, value, sizeof( value ) );
        items = QString::fromUtf8( value ).split( "," );
        qDebug() << "print quality supported: " << items;
    }
    else
    {
        qDebug() << "default print quality error: " << QString::fromUtf8( cupsLastErrorString() );
    }

    if ( items.count() > 0 )
    {
        m_printQualityCB->addItems( items );
    }

    if ( defaultQuality.length() > 0 )
    {
        int defaultItem = m_printQualityCB->findText( defaultQuality );

        if ( defaultItem > -1 )
        {
            m_printQualityCB->setCurrentIndex( defaultItem );
        }
    }

    cupsFreeDestInfo( info );
    cupsFreeDests( destCnt, dests );
#else
    /*! \todo need to get print quality for other OSs */
#endif
}


/*! \brief  Called when destination text changed to a file
 *
 *  \details Need to show file dialog so user can choose destination
 *           file and location.
 *
 *  \todo need actual file dialog
 */
void general_tab::choose_destination_file()
{
    qDebug() << "called chooseDestinationFile\n";
}

/*! \brief  Called when destination text changed to populate rest of tab
 *
 *  \details When text of destination changes, dialog needs new
 *           printer specific paper, color, etc. values. If destination
 *           is now a file, we need to prompt for file name and path.
 *
 *  \todo Need to handle printer security via CUPS. Username/password type stuff.
 */
void general_tab::dest_text_changed( const QString &text )
{

    qDebug() << "called dest_text_changed() with text of: " << text;

    if ( text.compare( tr( "File" ), Qt::CaseInsensitive ) == 0 )
    {
        m_canCollate = false;
        m_destFileWidget->setVisible( true );
        /*! \todo  need file path display after file dialog
         */
        destination_changed( text, true );
    }
    else
    {
        m_canCollate = dest_can_collate( text );

        populate_paper_source_CB();
        populate_paper_CB();
        populate_color_CB();
        populate_copies();
        qDebug() << "calling populatePrintQualityCB() " << endl;
        populate_print_quality_CB();
        m_destFileWidget->setVisible( false );
        destination_changed( text, false );
    }
}


/*! \brief slot called when paper source changes to populate paper combo box
 *
 *  \param unused string reference
 */
void general_tab::source_changed( const QString & )
{

    populate_paper_CB();
}

//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
//      Page Setup Tab
//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

/*! \brief Constructor
 *
 *  \param parent - pointer to parent widget or NULL
 */
page_setup_tab::page_setup_tab( QWidget *parent ) :
    QWidget( parent )
{
    m_duplexWidget      = new QWidget();
    QLabel *duplexLbl   = new QLabel( tr( "Duplex" ) );
    m_duplexCB          = new QComboBox();

    QHBoxLayout *duplexLayout   = new QHBoxLayout();
    duplexLayout->addWidget( duplexLbl );
    duplexLayout->addWidget( m_duplexCB );
    m_duplexWidget->setLayout( duplexLayout );

    m_numberUpWidget    = new QWidget();
    QLabel *numberUpLbl = new QLabel( tr( "Pages Per Side" ) );
    m_numberUpCB        = new QComboBox();

    QHBoxLayout *numberUpLayout = new QHBoxLayout();
    numberUpLayout->addWidget( numberUpLbl );
    numberUpLayout->addWidget( m_numberUpCB );
    m_numberUpWidget->setLayout( numberUpLayout );

    m_scalingWidget     = new QWidget();
    QLabel *scalingLbl   = new QLabel( tr( "Scaling" ) );
    m_scalingCB         = new QComboBox();

    QHBoxLayout *scalingLayout  = new QHBoxLayout();
    scalingLayout->addWidget( scalingLbl );
    scalingLayout->addWidget( m_scalingCB );
    m_scalingWidget->setLayout( scalingLayout );

    // Orientation
    //
    QHBoxLayout *orientationLayout = new QHBoxLayout();
    QLabel *oLbl                   = new QLabel( tr( "Orientation" ) );
    m_orientationCB                = new QComboBox();

    orientationLayout->addWidget( oLbl );
    orientationLayout->addStretch();
    orientationLayout->addWidget( m_orientationCB );

    m_orientationWidget = new QWidget();
    m_orientationWidget->setLayout( orientationLayout );


    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget( m_duplexWidget );
    mainLayout->addWidget( m_numberUpWidget );
    mainLayout->addWidget( m_scalingWidget );
    mainLayout->addWidget( m_orientationWidget );

    setLayout( mainLayout );

    connect( m_duplexCB,      &QComboBox::currentTextChanged, this, &page_setup_tab::duplex_changed );
    connect( m_numberUpCB,    &QComboBox::currentTextChanged, this, &page_setup_tab::number_up_changed );
    connect( m_scalingCB,     &QComboBox::currentTextChanged, this, &page_setup_tab::scaling_changed );
    connect( m_orientationCB, &QComboBox::currentTextChanged, this, &page_setup_tab::orientation_changed );
}

/*! \brief returns string containing current text of duplex combobox
 *
 *  \returns string - text of a duplex value recognized by the destination device
 */
QString page_setup_tab::duplex_mode()
{
    return m_duplexCB->currentText();
}


/*! \brief returns visibility state of duplex widget
 *
 * \returns bool - TRUE == is visible
 */
bool page_setup_tab::is_duplex_visible()
{
    return m_duplexWidget->isVisible();
}

/*! \brief returns visibility state of number up widget
 *
 *  \returns bool - TRUE == number up is visible
 */
bool page_setup_tab::is_number_up_visible()
{
    return m_numberUpWidget->isVisible();
}

/*! \brief returns visibility state of page orientation widget
 *
 *  \returns bool - TRUE == widget is visible
 */
bool page_setup_tab::is_orientation_visible()
{
    return m_orientationWidget->isVisible();
}

/*! \brief returns visibility status of scaling widget
 *
 *  \returns bool - TRUE == widget is visible
 */
bool page_setup_tab::is_scaling_visible()
{
    return m_scalingWidget->isVisible();
}

/*! \brief returns number of pages per side
 *
 *  \returns integer - number of pages per side (number up)
 */
int page_setup_tab::number_of_pages_per_side()
{
    int retVal = 1;
    QString txt = m_numberUpCB->currentText();

    if ( txt.length() > 0 )
    {
        retVal = txt.toInteger<int>();
    }

    return retVal;
}

/*! \brief returns device supported current scaling value from combo box
 *
 * \returns string - the device supported scaling value currently in combo box
 */
QString page_setup_tab::scaling()
{
    return m_scalingCB->currentText();
}

/*! \brief slot to store new destination value and kick off population of other device combo boxes
 *
 *  \param destination - string containing recognized destination
 */
void page_setup_tab::destination_changed( const QString destination )
{
    qDebug() << "page_setup_tab::destination_changed() called";
    m_destination = destination;

    qApp->setOverrideCursor( QCursor( Qt::WaitCursor ) );

    populate_number_up_CB();
    populate_duplex_CB();
    populate_scaling_CB();
    populate_orientation_CB();

    qApp->restoreOverrideCursor();
}

/*! \brief method to populate the number up combo box
 *
 *  \details On Linux this range of values will be retrieved from CUPS.
 *           OS specific APIs used for other platforms.
 */
void page_setup_tab::populate_number_up_CB()
{
    m_numberUpCB->clear();

#if defined(CUPS_VERSION)

    cups_dest_t *dests = nullptr;

#if CUPS_VERSION_MAJOR == 3
    size_t destCnt = cupsGetDests( CUPS_HTTP_DEFAULT, &dests );
#else
    int destCnt = cupsGetDests2( CUPS_HTTP_DEFAULT, &dests );
#endif

    cups_dest_t *currentDest = cupsGetDest( m_destination.toUtf8().constData(), NULL, destCnt, dests );

    // if we didn't find then bail
    //
    if ( currentDest == nullptr )
    {
        return;
    }

    cups_dinfo_t *info = cupsCopyDestInfo( CUPS_HTTP_DEFAULT, currentDest );

    if ( cupsCheckDestSupported( CUPS_HTTP_DEFAULT, currentDest, info, CUPS_NUMBER_UP, NULL ) )
    {
        ipp_attribute_t *numberUp = cupsFindDestSupported( CUPS_HTTP_DEFAULT, currentDest, info, CUPS_NUMBER_UP );
        size_t count = ippGetCount( numberUp );

        for ( size_t iii=0; iii < count; iii++ )
        {
            m_numberUpCB->addItem( QString::number( ippGetInteger( numberUp, iii ) ) );
        }
    }
    else
    {
        m_numberUpCB->addItem( "" );
    }

    cupsFreeDestInfo( info );
    cupsFreeDests( destCnt, dests );
#else
    /*! \todo number up for other OSes */
#endif
}

/*! \brief method to populate the duplex combo box for current device
 *
 *  \details populates duplex combo box based on currently selected destination device. On
 *           Linux the values will be obtained from CUPS. OS specific APIs will be used on
 *           other operating systems.
 */
void page_setup_tab::populate_duplex_CB()
{
    m_duplexCB->clear();

#if defined(CUPS_VERSION)
    cups_dest_t *dests = nullptr;


#if CUPS_VERSION_MAJOR == 3
    size_t destCnt = cupsGetDests( CUPS_HTTP_DEFAULT, &dests );
#else
    int destCnt = cupsGetDests2( CUPS_HTTP_DEFAULT, &dests );
#endif

    cups_dest_t *currentDest = cupsGetDest( m_destination.toUtf8().constData(), NULL, destCnt, dests );

    // if we didn't find then bail
    //
    if ( currentDest == nullptr )
    {
        return;
    }

    cups_dinfo_t *info = cupsCopyDestInfo( CUPS_HTTP_DEFAULT, currentDest );

    if ( cupsCheckDestSupported( CUPS_HTTP_DEFAULT, currentDest, info, CUPS_SIDES, NULL ) )
    {
        ipp_attribute_t *sides = cupsFindDestSupported( CUPS_HTTP_DEFAULT, currentDest, info, CUPS_SIDES );
        size_t count = ippGetCount( sides );

        for ( size_t iii=0; iii < count; iii++ )
        {
            m_duplexCB->addItem( QString::fromUtf8( ippGetString( sides, iii, NULL ) ) );
        }

        ipp_attribute_t *attr = nullptr;
        char value[4096];

        if ( ( attr = cupsFindDestDefault( CUPS_HTTP_DEFAULT, currentDest, info, CUPS_SIDES ) ) != NULL )
        {
            ippAttributeString( attr, value, sizeof( value ) );
            QString defaultDuplex = QString::fromUtf8( value );
            int defaultIndex = m_duplexCB->findText( defaultDuplex );

            if ( defaultIndex > -1 )
            {
                m_duplexCB->setCurrentIndex( defaultIndex );
            }

        }

    }
    else
    {
        m_duplexCB->addItem( "" );
    }

    cupsFreeDestInfo( info );
    cupsFreeDests( destCnt, dests );
#else
    /*! \todo get duplex information for other operating systems */
#endif
}

/*! \brief populate scaling combo box with values supported by current destination device
 *
 *  \details On Linux scaling values will be obtained from CUPS. OS specific API calls will
 *           be used on other OSes.
 */
void page_setup_tab::populate_scaling_CB()
{
    m_scalingCB->clear();

#if defined(CUPS_VERSION)
    cups_dest_t *dests = nullptr;

#if CUPS_VERSION_MAJOR == 3
    size_t destCnt = cupsGetDests( CUPS_HTTP_DEFAULT, &dests );
#else
    int destCnt = cupsGetDests2( CUPS_HTTP_DEFAULT, &dests );
#endif

    cups_dest_t *currentDest = cupsGetDest( m_destination.toUtf8().constData(), NULL, destCnt, dests );

    // if we didn't find then bail
    //
    if ( currentDest == nullptr )
    {
        return;
    }

    cups_dinfo_t *info = cupsCopyDestInfo( CUPS_HTTP_DEFAULT, currentDest );

    const char *SCALING = "print-scaling";

    if ( cupsCheckDestSupported( CUPS_HTTP_DEFAULT, currentDest, info, SCALING, NULL ) )
    {
        ipp_attribute_t *scaling = cupsFindDestSupported( CUPS_HTTP_DEFAULT, currentDest, info, SCALING );
        size_t count = ippGetCount( scaling );

        for ( size_t iii=0; iii < count; iii++ )
        {
            m_scalingCB->addItem( QString::fromUtf8( ippGetString( scaling, iii, NULL ) ) );
        }

        ipp_attribute_t *attr = nullptr;

        if ( ( attr = cupsFindDestDefault( CUPS_HTTP_DEFAULT, currentDest, info, SCALING ) ) != NULL )
        {
            char value[4096];
            ippAttributeString( attr, value, sizeof( value ) );
            QString defaultScaling = QString::fromUtf8( value );

            int defaultIndex = m_scalingCB->findText( defaultScaling );

            if ( defaultIndex > -1 )
            {
                m_scalingCB->setCurrentIndex( defaultIndex );
            }
        }

    }
    else
    {
        m_scalingCB->addItem( "none" );
    }

    cupsFreeDestInfo( info );
    cupsFreeDests( destCnt, dests );
#else
    /*! \todo obtain scaling values for other operating systems */
#endif
}

/*! \brief fill orientation combo box with values current device supports.
 *
 *  \details On Linux orientation values for current device will be obtained from CUPS.
 *           OS specific APIs will be used on other operating systems.
 */
void page_setup_tab::populate_orientation_CB()
{
    m_orientationCB->clear();

#if defined(CUPS_VERSION)
    cups_dest_t *dests = nullptr;
    size_t destCnt = cupsGetDests( &dests );

    // if populate orientation called instantly behind populateDestinationCB it is possible
    // the GUI has not had time to set display text, but the object will know what the
    // current index was set to.
    //
    cups_dest_t *currentDest = cupsGetDest( m_destination.toUtf8().constData(), NULL, destCnt, dests );

    // if we didn't find then bail
    //
    if ( currentDest == nullptr )
    {
        return;
    }

    cups_dinfo_t *info = cupsCopyDestInfo( CUPS_HTTP_DEFAULT, currentDest );
    char value[4096];

    ipp_attribute_t *attr = nullptr;

    QString defaultOrientation;
    QStringList items;

    if ( ( attr = cupsFindDestDefault( CUPS_HTTP_DEFAULT, currentDest, info, CUPS_ORIENTATION ) ) != NULL )
    {
        ippAttributeString( attr, value, sizeof( value ) );
        defaultOrientation = QString::fromUtf8( value );
    }

    if ( ( attr = cupsFindDestSupported( CUPS_HTTP_DEFAULT, currentDest, info, CUPS_ORIENTATION ) ) != NULL )
    {
        ippAttributeString( attr, value, sizeof( value ) );
        items = QString::fromUtf8( value ).split( "," );
    }

    if ( items.count() > 0 )
    {
        m_orientationCB->addItems( items );
    }

    if ( defaultOrientation.length() > 0 )
    {
        int defaultItem = m_orientationCB->findText( defaultOrientation );

        if ( defaultItem > -1 )
        {
            m_orientationCB->setCurrentIndex( defaultItem );
        }
    }

    if ( m_orientationCB->count() < 2 )
    {
        m_orientationWidget->setVisible( false );
    }
    else
    {
        m_orientationWidget->setVisible( true );
    }

    cupsFreeDestInfo( info );
    cupsFreeDests( destCnt, dests );
#else
    /*! \todo obtain orientation values for other OSes. */
#endif
}



//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
//      Spooler Tab
//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

/*! \brief Constructor
 *
 *  \param parent - pointer to parent widget or NULL
 */
spooler_tab::spooler_tab( QWidget *parent ) :
    QWidget( parent )
{
    // spooler radio button box
    //
    m_textSpoolerRB         = new QRadioButton( tr( "Text" ) );
    m_rawSpoolerRB          = new QRadioButton( tr( "Raw" ) );
    m_pdfSpoolerRB          = new QRadioButton( tr( "PDF" ) );
    m_postscriptSpoolerRB   = new QRadioButton( tr( "Postscript" ) );

    m_textSpoolerRB->setToolTip( tr( "Plain text using default font of destination" ) );
    m_rawSpoolerRB->setToolTip( tr( "Raw byte for byte dump to output destination" ) );
    m_pdfSpoolerRB->setToolTip( tr( "Create temporary PDF for destination" ) );
    m_postscriptSpoolerRB->setToolTip( tr( "Create temporary Postscript for destination" ) );


    QVBoxLayout *gbLayout = new QVBoxLayout();

    gbLayout->addWidget( m_textSpoolerRB );
    gbLayout->addWidget( m_rawSpoolerRB );
    gbLayout->addWidget( m_pdfSpoolerRB );
    gbLayout->addWidget( m_postscriptSpoolerRB );

    m_spoolerGroupBox = new QGroupBox( tr( "Spooler Type" ) );
    m_spoolerGroupBox->setLayout( gbLayout );

    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainLayout->addWidget( m_spoolerGroupBox );

    setLayout( mainLayout );

    connect( m_textSpoolerRB, &QRadioButton::clicked, this,
             [this]()
    {
        spooler_type_changed( LsCsSpoolerType::Text );
    } );

    connect( m_rawSpoolerRB, &QRadioButton::clicked, this,
             [this]()
    {
        spooler_type_changed( LsCsSpoolerType::Raw );
    } );

    connect( m_pdfSpoolerRB, &QRadioButton::clicked, this,
             [this]()
    {
        spooler_type_changed( LsCsSpoolerType::Pdf );
    } );

    connect( m_postscriptSpoolerRB, &QRadioButton::clicked, this,
             [this]()
    {
        spooler_type_changed( LsCsSpoolerType::Postscript );
    } );

}

/*! \brief Destructor
 */
spooler_tab::~spooler_tab()
{
    if ( m_spoolerGroupBox != nullptr )
    {
        delete m_spoolerGroupBox;
        m_spoolerGroupBox = nullptr;
    }

}

/*! \brief method which allows program to click a spooler type button
 *
 *  \details We have a chickend and egg issue at startup. This method allows
 *           spooler type to be chosen by the application, esepcially if the
 *           destination device only supports certain types.
 */
void spooler_tab::push_spooler_button( LsCsSpoolerType spoolerType )
{
    switch ( spoolerType )
    {
        case LsCsSpoolerType::None:
        case LsCsSpoolerType::Raw:
            m_rawSpoolerRB->setChecked( true );
            break;

        case LsCsSpoolerType::Text:
            m_textSpoolerRB->setChecked( true );
            break;

        case LsCsSpoolerType::Pdf:
            m_pdfSpoolerRB->setChecked( true );
            break;

        case LsCsSpoolerType::Postscript:
            m_postscriptSpoolerRB->setChecked( true );
            break;
    }

}
