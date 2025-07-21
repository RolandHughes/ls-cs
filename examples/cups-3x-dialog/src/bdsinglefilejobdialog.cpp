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
const char *REQUESTED_DEFAULT_ORIENTATION = "orientation-requested-default";  // @todo need non-windows conditional around this
const char *URI_SUPPORTED_TAG = "printer-uri-supported";  // @todo need non-windows conditional around this
const char *REQUESTED_COLOR_SUPPORTED = "color-supported";  // @todo need non-windows conditional around this
const char *REQUESTED_COLOR_MODE = "print-color-mode-supported"; // @todo need non-windows conditional around this
const char *REQUESTED_COLOR_MODE_DEFAULT = "print-color-mode-default"; // @todo need non-windows conditional around this

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

    connect( btnBox, &QDialogButtonBox::rejected,   this, &QDialog::rejected );
    connect( btnBox, &QDialogButtonBox::accepted,   this, &BdSingleFileJobDialog::submitJob );

    m_spoolerTab->pushSpoolerButton( BdSpoolerType::Text );

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget( m_tabWidget );
    mainLayout->addWidget( btnBox );

    setLayout( mainLayout );


    // chicken and egg problem during inital load
    //
    m_pageSetupTab->destinationChanged( m_generalTab->getDestinationName() );
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
    //
    QHBoxLayout *sourceLayout   = new QHBoxLayout();
    QLabel *sourceLabel         = new QLabel( tr( "Paper Source" ) );
    m_paperSourceCB             = new QComboBox();

    sourceLayout->addWidget( sourceLabel );
    sourceLayout->addWidget( m_paperSourceCB );

    mainLayout->addLayout( sourceLayout );

    // paper
    //
    QHBoxLayout *paperLayout    = new QHBoxLayout();
    QLabel *paperLabel          = new QLabel( tr( "Paper" ) );
    m_paperCB                   = new QComboBox();

    paperLayout->addWidget( paperLabel );
    paperLayout->addWidget( m_paperCB );

    mainLayout->addLayout( paperLayout );

    // pages
    //
    QHBoxLayout *pagesLayout    = new QHBoxLayout();
    QLabel *pagesLabel          = new QLabel( tr( "Pages" ) );
    m_pagesLE                   = new QLineEdit();

    m_pagesLE->setToolTip( tr( "Leave blank for all" ) );

    pagesLayout->addWidget( pagesLabel );
    pagesLayout->addStretch();
    pagesLayout->addWidget( m_pagesLE );

    mainLayout->addLayout( pagesLayout );

    // copies
    //
    QHBoxLayout *copiesLayout = new QHBoxLayout();
    QLabel *copiesLbl         = new QLabel( tr( "Copies" ) );
    m_copiesSB                = new QSpinBox();


    m_copiesSB->setRange( 1, 999 );

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

    //  Make connections
    //

    connect( m_destinationCB, &QComboBox::currentTextChanged, this, &GeneralTab::destTextChanged );
    connect( m_fileChooserBtn, &QToolButton::triggered, this, &GeneralTab::chooseDestinationFile );
    connect( m_copiesSB, SIGNAL( valueChanged( int ) ), this, SLOT( copiesChanged( int ) ) );
    connect( m_paperSourceCB, &QComboBox::currentTextChanged, this, &GeneralTab::sourceChanged );
    connect( m_paperCB, &QComboBox::currentTextChanged, this, &GeneralTab::paperChanged );


    // populate after connecting so inital values get loaded into the job class
    //
    populateDestinationCB();
    populatePaperSourceCB();
    populatePaperCB();
    populateColorCB();

    m_copiesSB->setValue( 1 );

    show();

}

GeneralTab::~GeneralTab()
{
    if ( m_destFileWidget != nullptr )
    {
        delete m_destFileWidget;
        m_destFileWidget = nullptr;
    }

    if ( m_copiesWidget != nullptr )
    {
        delete m_copiesWidget;
        m_copiesWidget = nullptr;
    }

    if ( m_collateWidget != nullptr )
    {
        delete m_collateWidget;
        m_collateWidget = nullptr;
    }


    if ( m_colorWidget != nullptr )
    {
        delete m_colorWidget;
        m_colorWidget = nullptr;
    }


    if ( m_destinationCB != nullptr )
    {
        delete m_destinationCB;
        m_destinationCB = nullptr;
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
    size_t destCnt = cupsGetDests2( CUPS_HTTP_DEFAULT, &dests );

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


    QString defaultDestination = QString::fromUtf8( cupsGetDefault() );
    int defaultIndex = m_destinationCB->findText( defaultDestination );

    if ( defaultIndex > -1 )
    {
        m_destinationCB->setCurrentIndex( defaultIndex );
    }
    else
    {
        m_destinationCB->setCurrentIndex( m_destinationCB->count() );
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

    int defaultItem = m_colorCB->findText( defaultSource );

    if ( defaultItem > -1 )
    {
        m_paperSourceCB->setCurrentIndex( defaultItem );
    }

    cupsFreeDestInfo( info );
    cupsFreeDests( destCnt, dests );
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

void GeneralTab::chooseDestinationFile()
{
    qDebug() << "called chooseDestinationFile\n";
}

void GeneralTab::destTextChanged( const QString &text )
{
    // TODO::
    // @todo  need to show/hide collate, color, orientation based on
    //        device.

    if ( text.compare( tr( "File" ), Qt::CaseInsensitive ) == 0 )
    {
        m_destFileWidget->setVisible( true );
        // TODO::
        // @todo  need file path display after file dialog
    }
    else
    {
        populatePaperSourceCB();
        populatePaperCB();
        populateColorCB();
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

#if 0
    //  scratch variables used when manipulating layouts
    //
    int left = 0;
    int top = 0;
    int right = 0;
    int bottom = 0;

    orientationLayout->getContentsMargins( &left, &top, &right, &bottom );
    left = 0;
    right = 0;
    orientationLayout->setContentsMargins( left, top, right, bottom );
#endif
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

    destinationChanged( "" );

    connect( m_duplexCB,      &QComboBox::currentTextChanged, this, &PageSetupTab::duplexChanged );
    connect( m_numberUpCB,    &QComboBox::currentTextChanged, this, &PageSetupTab::numberUpChanged );
    connect( m_scalingCB,     &QComboBox::currentTextChanged, this, &PageSetupTab::scalingChanged );
    connect( m_orientationCB, &QComboBox::currentTextChanged, this, &PageSetupTab::orientationChanged );
}

PageSetupTab::~PageSetupTab()
{
    if ( m_duplexWidget != nullptr )
    {
        delete m_duplexWidget;
        m_duplexWidget = nullptr;
    }

    if ( m_numberUpWidget != nullptr )
    {
        delete m_numberUpWidget;
        m_numberUpWidget = nullptr;
    }

    if ( m_scalingWidget != nullptr )
    {
        delete m_scalingWidget;
        m_scalingWidget = nullptr;
    }

    if ( m_orientationWidget != nullptr )
    {
        delete m_orientationWidget;
        m_orientationWidget = nullptr;
    }
}

QString PageSetupTab::duplexMode()
{
    return m_duplexCB->currentText();
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
    }
    else
    {
        m_numberUpCB->addItem( "" );
    }

    cupsFreeDestInfo( info );

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
    }
    else
    {
        m_scalingCB->addItem( "none" );
    }

    cupsFreeDestInfo( info );
}

void PageSetupTab::populateOrientationCB()
{
    m_orientationCB->clear();

    cups_dest_t *dests = nullptr;
    size_t destCnt = cupsGetDests2( CUPS_HTTP_DEFAULT, &dests );

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

    QString uri = QString::fromUtf8( cupsGetOption( URI_SUPPORTED_TAG, currentDest->num_options, currentDest->options ) );

    static const char *const requested_attributes[] =
    {
        CUPS_ORIENTATION_SUPPORTED,
        REQUESTED_DEFAULT_ORIENTATION
    };

    char resource[40000];
    char value[4096];
    http_t *http = cupsConnectDest( currentDest, CUPS_DEST_FLAGS_NONE, 30000, NULL, resource, sizeof( resource ), NULL, NULL );

    ipp_t *request = ippNewRequest( IPP_OP_GET_PRINTER_ATTRIBUTES );
    ippAddString( request, IPP_TAG_OPERATION, IPP_TAG_URI, URI_TAG, NULL, uri.toUtf8().constData() );
    ippAddStrings( request, IPP_TAG_OPERATION, IPP_TAG_KEYWORD, REQUESTED_ATTRIBUTES,
                   ( int ) ( sizeof( requested_attributes ) / sizeof( requested_attributes[0] ) ), NULL, requested_attributes );
    ipp_t *response = cupsDoRequest( http, request, resource );

    if ( cupsLastError() >= IPP_STATUS_ERROR_BAD_REQUEST )
    {
        httpClose( http );
        cupsFreeDestInfo( info );
        return;
    }

    ipp_attribute_t *attr = nullptr;

    if ( ( attr = ippFindAttribute( response, CUPS_ORIENTATION_SUPPORTED, IPP_TAG_ZERO ) ) != NULL )
    {
        ippAttributeString( attr, value, sizeof( value ) );
        QString str = QString::fromUtf8( value );
        QStringList lst = str.split( "," );

        for ( QString orientStr : lst )
        {
            m_orientationCB->addItem( orientStr );
        }
    }

    if ( ( attr = ippFindAttribute( response, REQUESTED_DEFAULT_ORIENTATION, IPP_TAG_ZERO ) ) != NULL )
    {
        ippAttributeString( attr, value, sizeof( value ) );
        QString defaultOrientation = QString::fromUtf8( value );

        int defaultIdx = m_orientationCB->findText( defaultOrientation );

        if ( defaultIdx > -1 )
        {
            m_orientationCB->setCurrentIndex( defaultIdx );
        }
    }

    httpClose( http );
    cupsFreeDestInfo( info );
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
