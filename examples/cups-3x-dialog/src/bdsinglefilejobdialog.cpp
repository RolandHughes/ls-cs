/*;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Copyright (c) 2024-2025 Roland Hughes d.b.a Logikal Solutions
;;
;; This file is part of Ls-Cs.
;;
;; Ls-Cs is free software. You can redistribute it and/or
;; modify it under the terms the Basis Doctrina License found in
;; Basis_Doctrina_License.txt
;;
;; Ls-Cs is distributed in the hope that it will be useful,
;; but WITHOUT ANY WARRANTY; without even the implied warranty of
;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;*/
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

#include <cups/cups.h>      // @todo need non-windows conditional around this

#include <bdsinglefilejobdialog.h>

const char *URI_TAG = "printer-uri";        // @todo need non-windows conditional around this
const char *REQUESTED_ATTRIBUTES = "requested-attributes";  // @todo need non-windows conditional around this.
const char *REQUEST_DEFAULT_ORIENTATION = "orientation-requested-default";  // @todo need non-windows conditional around this
const char *URI_SUPPORTED_TAG = "printer-uri-supported";  // @todo need non-windows conditional around this
const char *REQUEST_COLOR_SUPPORTED = "color-supported";  // @todo need non-windows conditional around this
const char *REQUEST_COLOR_MODE = "print-color-mode-supported"; // @todo need non-windows conditional around this
const char *REQUEST_COLOR_MODE_DEFAULT = "print-color-mode-default"; // @todo need non-windows conditional around this
const char *REQUEST_PRINT_QUALITY_DEFAULT = "print-quality-default"; // @todo need non-windows conditional around this

/*! \brief Constructor
 */
BdSingleFileJobDialog::BdSingleFileJobDialog( QWidget *parent ) :
    QDialog( parent )
{
    setModal( true );
    setWindowTitle( tr( "BdSingleFileJobDialog" ) );

    m_tabWidget = new QTabWidget();
    m_tabWidget->setTabsClosable( false );
    m_tabWidget->tabBar()->setMovable( false );
    m_tabWidget->tabBar()->setShape( QTabBar::TriangularNorth );

    m_generalTab    = new GeneralTab();
    m_pageSetupTab  = new PageSetupTab();
    m_spoolerTab    = new SpoolerTab();
    m_tabWidget->addTab( m_spoolerTab, tr( "Spooler" ) );
    m_tabWidget->addTab( m_generalTab, tr( "General" ) );
    m_tabWidget->addTab( m_pageSetupTab, tr( "Page Setup" ) );

    QDialogButtonBox *btnBox = new QDialogButtonBox( QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this );

    // make connections here

    connect( m_spoolerTab, &SpoolerTab::spoolerTypeChanged,  this, &BdSingleFileJobDialog::spoolerSelected );

    connect( m_generalTab, &GeneralTab::destinationChanged,  this, &BdSingleFileJobDialog::destinationSelected );
    connect( m_generalTab, &GeneralTab::copiesChanged,       this, &BdSingleFileJobDialog::copiesChanged );
    connect( m_generalTab, &GeneralTab::paperSourceChanged,  this, &BdSingleFileJobDialog::paperSourceChanged );
    connect( m_generalTab, &GeneralTab::paperChanged,        this, &BdSingleFileJobDialog::paperChanged );
    connect( m_generalTab, &GeneralTab::printQualityChanged, this, &BdSingleFileJobDialog::printQualityChanged );

    connect( m_pageSetupTab, &PageSetupTab::duplexChanged,      this, &BdSingleFileJobDialog::duplexChanged );
    connect( m_pageSetupTab, &PageSetupTab::scalingChanged,     this, &BdSingleFileJobDialog::scalingChanged );
    connect( m_pageSetupTab, &PageSetupTab::numberUpChanged,    this, &BdSingleFileJobDialog::numberUpChanged );
    connect( m_pageSetupTab, &PageSetupTab::orientationChanged, this, &BdSingleFileJobDialog::orientationChanged );

    connect( btnBox, &QDialogButtonBox::rejected,   this, &QDialog::reject );
    connect( btnBox, &QDialogButtonBox::accepted,   this, &BdSingleFileJobDialog::submitJob );


    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget( m_tabWidget );
    mainLayout->addWidget( btnBox );

    setLayout( mainLayout );

    m_spoolerTab->pushSpoolerButton( BdSpoolerType::Text );

    m_generalTab->makeDefaultCurrentDestination();

}

/*! \brief  Submit single file job to spooler then destination
 *
 *  \details Chosen spooler type will be created and passed information
 *           about what to include in the temporary file it creates
 *           that will then be submitted as a job to the spooler destination.
 */
void BdSingleFileJobDialog::submitJob()
{
    qDebug() << "called submitJob() \n";

    // Update the job capabilities
    //
    m_job.useCollateValue           = m_generalTab->isCollateVisible();
    m_job.usePrintQualityValue      = m_generalTab->isPrintQualityVisible();
    m_job.usePaperSourceValue       = m_generalTab->isPaperSourceVisible();
    m_job.useColorValue             = m_generalTab->isColorModeVisible();
    m_job.useCopiesValue            = m_generalTab->isCopiesVisible();
    m_job.useNumberUpValue          = m_pageSetupTab->isNumberUpVisible();
    m_job.useDuplexValue            = m_pageSetupTab->isDuplexVisible();
    m_job.useOrientationValue       = m_pageSetupTab->isOrientationVisible();
    m_job.useScalingValue           = m_pageSetupTab->isScalingVisible();


    qDebug() << "m_job: " << m_job.toString() << "\n";
    accept();
}

/*! \brief Abandon creation of a spooler job
 */
void BdSingleFileJobDialog::quit()
{
    reject();
}

/*! \brief slot to record change to number of copies
 *
 *  \param copies - non-zero integer indicating number of copies to generate
 */
void BdSingleFileJobDialog::copiesChanged( int copies )
{
    m_job.copies = copies;
}

/*! \brief
 */
void BdSingleFileJobDialog::spoolerSelected( BdSpoolerType spoolerType )
{
    m_job.spoolerType = spoolerType;
}

BdSpoolerType BdSingleFileJobDialog::spoolerType()
{
    return m_job.spoolerType;
}

void BdSingleFileJobDialog::destinationSelected( QString destinationName, bool isFile )
{
    m_job.destinationName   = destinationName;
    m_job.destinationIsFile = isFile;
    m_job.validJob          = true;

    m_pageSetupTab->destinationChanged( destinationName );
}

void BdSingleFileJobDialog::paperSourceChanged( const QString &source )
{
    m_job.paperSource = source;
}

void BdSingleFileJobDialog::paperChanged( const QString &paper )
{
    m_job.paper = paper;
}

void BdSingleFileJobDialog::orientationChanged( const QString &orientation )
{
    m_job.orientation = orientation;
}

void BdSingleFileJobDialog::duplexChanged( const QString &duplex )
{
    m_job.duplex = duplex;
}

void BdSingleFileJobDialog::scalingChanged( const QString &scaling )
{
    m_job.scaling = scaling;
}

void BdSingleFileJobDialog::numberUpChanged( const QString &numberUp )
{
    m_job.numberUp = numberUp;
}

void BdSingleFileJobDialog::printQualityChanged( const QString &printQuality )
{
    m_job.printQuality = printQuality;
}

//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
//      General Tab
//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
/*! \brief Explicit Constructor
 *
 *  \details Constructs the General tab widget for single file job dialog
 */
GeneralTab::GeneralTab( QWidget *parent ) :
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
    // \todo  show/hide source depending on how many printer supports
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
    populateDestinationCB();

    //  Make connections
    //
    connect( m_destinationCB,   &QComboBox::currentTextChanged, this, &GeneralTab::destTextChanged );
    connect( m_fileChooserBtn,  &QToolButton::triggered,        this, &GeneralTab::chooseDestinationFile );
    connect( m_paperSourceCB,   &QComboBox::currentTextChanged, this, &GeneralTab::sourceChanged );
    connect( m_paperCB,         &QComboBox::currentTextChanged, this, &GeneralTab::paperChanged );
    connect( m_printQualityCB,  &QComboBox::currentTextChanged, this, &GeneralTab::printQualityChanged );

    connect( m_copiesSB,       static_cast<void ( QSpinBox::* )( int )>( &QSpinBox::valueChanged ),
             this, &GeneralTab::copiesValueChanged );

}

bool GeneralTab::isCollateVisible()
{
    return m_collateWidget->isVisible();
}

bool GeneralTab::isPrintQualityVisible()
{
    return m_printQWidget->isVisible();
}

bool GeneralTab::isPaperSourceVisible()
{
    return m_sourceWidget->isVisible();
}

bool GeneralTab::isColorModeVisible()
{
    return m_colorWidget->isVisible();
}

bool GeneralTab::isCopiesVisible()
{
    qDebug() << "m_copiesWidget-isVisible():  " << m_copiesWidget->isVisible();
    return m_copiesWidget->isVisible();
}


void GeneralTab::copiesValueChanged( int newValue )
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

QString GeneralTab::getDestinationName()
{
    return m_destinationCB->currentText();
}

void GeneralTab::populateDestinationCB()
{
    m_destinationCB->clear();

    cups_dest_t *dests = nullptr;
    size_t destCnt = cupsGetDests( &dests );  //cupsGetDests2( CUPS_HTTP_DEFAULT, &dests );

    QStringList items;

    for ( size_t jjj = 0; jjj < destCnt; jjj++ )
    {
        cups_dest_t *workDest = &dests[jjj];

        if ( workDest != nullptr )
        {
            items << QString::fromUtf8( workDest->name );
        }
    }

    cupsFreeDests( destCnt, dests );
    items.sort();


    m_destinationCB->addItems( items );

    if ( items.count() > 0 )
    {
        m_destinationCB->insertSeparator( items.count() + 1 );
    }

    m_destinationCB->addItem( tr( "File" ) );


}

void GeneralTab::makeDefaultCurrentDestination()
{

    QString defaultDestination = QString::fromUtf8( cupsGetDefault() );
    int defaultIndex = m_destinationCB->findText( defaultDestination );

    if ( defaultIndex > -1 )
    {
        m_destinationCB->setCurrentIndex( defaultIndex );
    }
    else
    {
        m_destinationCB->setCurrentIndex( 0 );
    }

}

void GeneralTab::populatePaperSourceCB()
{
    m_paperSourceCB->clear();

    cups_dest_t *dests = nullptr;

    size_t destCnt = cupsGetDests2( CUPS_HTTP_DEFAULT, &dests );

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
}

bool GeneralTab::destCanCollate( QString destination )
{
    cups_dest_t *dests = nullptr;

    bool retVal = false;

    size_t destCnt = cupsGetDests2( CUPS_HTTP_DEFAULT, &dests );

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

    return retVal;
}

void GeneralTab::populatePaperCB()
{
    // @todo  translate the cups paper names to human names
    m_paperCB->clear();

    cups_dest_t *dests = nullptr;

    size_t destCnt = cupsGetDests2( CUPS_HTTP_DEFAULT, &dests );

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
#if (CUPS_VERSION_MAJOR >= 3)
    cups_media_t defaultMedia;

    if ( cupsGetDestMediaDefault( CUPS_HTTP_DEFAULT, currentDest, info, CUPS_MEDIA_FLAGS_BORDERLESS, &defaultMedia ) )
    {
        currentItem = m_paperCB->findText( QString::fromUtf8( defaultMedia.media ) );
    }

#else
    cups_size_t defaultMedia;

    if ( cupsGetDestMediaDefault( CUPS_HTTP_DEFAULT, currentDest, info, CUPS_MEDIA_FLAGS_BORDERLESS, &defaultMedia ) )
    {
        currentItem = m_paperCB->findText( QString::fromUtf8( defaultMedia.media ) );
    }

#endif

    m_paperCB->setCurrentIndex( currentItem );


    cupsFreeDestInfo( info );
    cupsFreeDests( destCnt, dests );

}

void GeneralTab::populateColorCB()
{
    m_colorCB->clear();

    cups_dest_t *dests = nullptr;
    size_t destCnt = cupsGetDests2( CUPS_HTTP_DEFAULT, &dests );

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

}

void GeneralTab::populateCopies()
{

    m_copiesSB->clear();
    m_copiesSB->setRange( 1, 10 ); // set rather safe bogus limit until we get actual values

    cups_dest_t *dests = nullptr;
    size_t destCnt = cupsGetDests2( CUPS_HTTP_DEFAULT, &dests );

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

}

void GeneralTab::populatePrintQualityCB()
{
    m_printQualityCB->clear();

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
}

void GeneralTab::chooseDestinationFile()
{
    qDebug() << "called chooseDestinationFile\n";
}

void GeneralTab::destTextChanged( const QString &text )
{
    if ( text.compare( tr( "File" ), Qt::CaseInsensitive ) == 0 )
    {
        m_canCollate = false;
        m_destFileWidget->setVisible( true );
        // TODO::
        // @todo  need file path display after file dialog
    }
    else
    {
        m_canCollate = destCanCollate( text );

        populatePaperSourceCB();
        populatePaperCB();
        populateColorCB();
        populateCopies();
        qDebug() << "calling populatePrintQualityCB() " << endl;
        populatePrintQualityCB();
        m_destFileWidget->setVisible( false );
        destinationChanged( text, false );
    }
}



void GeneralTab::sourceChanged( const QString & )
{

    populatePaperCB();
}

//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
//      Page Setup Tab
//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

PageSetupTab::PageSetupTab( QWidget *parent ) :
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

    connect( m_duplexCB,      &QComboBox::currentTextChanged, this, &PageSetupTab::duplexChanged );
    connect( m_numberUpCB,    &QComboBox::currentTextChanged, this, &PageSetupTab::numberUpChanged );
    connect( m_scalingCB,     &QComboBox::currentTextChanged, this, &PageSetupTab::scalingChanged );
    connect( m_orientationCB, &QComboBox::currentTextChanged, this, &PageSetupTab::orientationChanged );
}


QString PageSetupTab::duplexMode()
{
    return m_duplexCB->currentText();
}


bool PageSetupTab::isDuplexVisible()
{
    return m_duplexWidget->isVisible();
}

bool PageSetupTab::isNumberUpVisible()
{
    return m_numberUpWidget->isVisible();
}

bool PageSetupTab::isOrientationVisible()
{
    return m_orientationWidget->isVisible();
}

bool PageSetupTab::isScalingVisible()
{
    return m_scalingWidget->isVisible();
}


int PageSetupTab::numberOfPagesPerSide()
{
    int retVal = 1;
    QString txt = m_numberUpCB->currentText();

    if ( txt.length() > 0 )
    {
        retVal = txt.toInteger<int>();
    }

    return retVal;
}

QString PageSetupTab::scaling()
{
    return m_scalingCB->currentText();
}

void PageSetupTab::destinationChanged( const QString destination )
{
    m_destination = destination;

    populateNumberUpCB();
    populateDuplexCB();
    populateScalingCB();
    populateOrientationCB();
}

void PageSetupTab::populateNumberUpCB()
{
    m_numberUpCB->clear();

    cups_dest_t *dests = nullptr;
    size_t destCnt = cupsGetDests2( CUPS_HTTP_DEFAULT, &dests );

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
}

void PageSetupTab::populateDuplexCB()
{
    m_duplexCB->clear();

    cups_dest_t *dests = nullptr;
    size_t destCnt = cupsGetDests2( CUPS_HTTP_DEFAULT, &dests );

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

}


void PageSetupTab::populateScalingCB()
{
    m_scalingCB->clear();

    cups_dest_t *dests = nullptr;
    size_t destCnt = cupsGetDests2( CUPS_HTTP_DEFAULT, &dests );

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
}

void PageSetupTab::populateOrientationCB()
{
    m_orientationCB->clear();

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
}



//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
//      Spooler Tab
//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

SpoolerTab::SpoolerTab( QWidget *parent ) :
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
        spoolerTypeChanged( BdSpoolerType::Text );
    } );

    connect( m_rawSpoolerRB, &QRadioButton::clicked, this,
             [this]()
    {
        spoolerTypeChanged( BdSpoolerType::Raw );
    } );

    connect( m_pdfSpoolerRB, &QRadioButton::clicked, this,
             [this]()
    {
        spoolerTypeChanged( BdSpoolerType::Pdf );
    } );

    connect( m_postscriptSpoolerRB, &QRadioButton::clicked, this,
             [this]()
    {
        spoolerTypeChanged( BdSpoolerType::Postscript );
    } );

}

SpoolerTab::~SpoolerTab()
{
    if ( m_spoolerGroupBox != nullptr )
    {
        delete m_spoolerGroupBox;
        m_spoolerGroupBox = nullptr;
    }

}

void SpoolerTab::pushSpoolerButton( BdSpoolerType spoolerType )
{
    switch ( spoolerType )
    {
        case BdSpoolerType::None:
        case BdSpoolerType::Raw:
            m_rawSpoolerRB->setChecked( true );
            break;

        case BdSpoolerType::Text:
            m_textSpoolerRB->setChecked( true );
            break;

        case BdSpoolerType::Pdf:
            m_pdfSpoolerRB->setChecked( true );
            break;

        case BdSpoolerType::Postscript:
            m_postscriptSpoolerRB->setChecked( true );
            break;
    }

}
