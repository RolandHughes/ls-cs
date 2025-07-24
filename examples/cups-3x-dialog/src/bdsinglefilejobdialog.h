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
#ifndef BDSINGLEFILEJOBDIALOG_H
#define BDSINGLEFILEJOBDIALOG_H

#ifndef LSCS_NO_PRINTER
#include <qdialog.h>
#include <qstring.h>

#include <bdspooler.h>
#include <bdsinglefilejob.h>

class QComboBox;
class QCheckBox;
class QRadioButton;
class QSpinBox;
class QTabWidget;
class QGroupBox;
class QLineEdit;
class QToolButton;

/*! \brief Tab containing general printing configuration
 *
  * \param parent - QWidget pointer to parent widget - defaults to nullptr
 */
class GeneralTab : public QWidget
{
    LSCS_OBJECT( GeneralTab )

public:
    explicit GeneralTab( QWidget *parent = nullptr );

    void pushSpoolerButton( BdSpoolerType spoolerType );
    void makeDefaultCurrentDestination();

    QString getDestinationName();


    bool destCanCollate( QString destination );

    bool isCollateVisible();
    bool isPrintQualityVisible();
    bool isPaperSourceVisible();
    bool isColorModeVisible();
    bool isOrientationVisible();
    bool isScalingVisible();
    bool isCopiesVisible();

    LSCS_SIGNAL_1( Public, void destinationChanged( QString destinationName, bool isFile ) )
    LSCS_SIGNAL_2( destinationChanged, destinationName, isFile )

    LSCS_SIGNAL_1( Public, void copiesChanged( int copies ) )
    LSCS_SIGNAL_2( copiesChanged, copies )

    LSCS_SIGNAL_1( Public, void paperSourceChanged( const QString &source ) )
    LSCS_SIGNAL_2( paperSourceChanged, source )

    LSCS_SIGNAL_1( Public, void paperChanged( const QString &paper ) )
    LSCS_SIGNAL_2( paperChanged, paper )

    LSCS_SIGNAL_1( Public, void printQualityChanged( const QString &paper ) )
    LSCS_SIGNAL_2( printQualityChanged, paper )




private:

    QComboBox   *m_destinationCB;
    QToolButton *m_fileChooserBtn;
    QLineEdit   *m_fileNameLE;
    QComboBox   *m_paperSourceCB;
    QComboBox   *m_paperCB;
    QComboBox   *m_printQualityCB;
    QLineEdit   *m_pagesLE;
    QSpinBox    *m_copiesSB;
    QCheckBox   *m_collateCKB;
    QComboBox   *m_colorCB;
    QWidget     *m_destFileWidget;
    QWidget     *m_copiesWidget;
    QWidget     *m_collateWidget;
    QWidget     *m_colorWidget;
    QWidget     *m_sourceWidget;
    QWidget     *m_paperLayoutWidget;
    QWidget     *m_printQWidget;
    QWidget     *m_pagesWidget;

    bool        m_canCollate;

    void chooseDestinationFile();
    void destTextChanged( const QString &text );
    void sourceChanged( const QString &text );
    void copiesValueChanged( int newValue );

    void populateDestinationCB();
    void populatePaperSourceCB();
    void populatePaperCB();
    void populateColorCB();
    void populatePrintQualityCB();
    void populateCopies();


};

/*! \brief Tab containing advanced page setup information for print jobs
 *
 *  \param parent - QWidget pointer to parent widget - defaults to nullptr
 */
class PageSetupTab : public QWidget
{
    LSCS_OBJECT( PageSetupTab )

public:
    explicit PageSetupTab( QWidget *parent = nullptr );

    QString duplexMode();
    int     numberOfPagesPerSide();
    QString scaling();

    bool isDuplexVisible();
    bool isNumberUpVisible();
    bool isScalingVisible();
    bool isOrientationVisible();


    void destinationChanged( const QString destination );

    LSCS_SIGNAL_1( Public, void numberUpChanged( const QString &source ) )
    LSCS_SIGNAL_2( numberUpChanged, source )

    LSCS_SIGNAL_1( Public, void scalingChanged( const QString &source ) )
    LSCS_SIGNAL_2( scalingChanged, source )

    LSCS_SIGNAL_1( Public, void duplexChanged( const QString &source ) )
    LSCS_SIGNAL_2( duplexChanged, source )

    LSCS_SIGNAL_1( Public, void orientationChanged( const QString &orientation ) )
    LSCS_SIGNAL_2( orientationChanged, orientation )


private:
    QString     m_destination;

    QComboBox   *m_duplexCB;
    QComboBox   *m_numberUpCB;    // pages per side
    QComboBox   *m_scalingCB;
    QComboBox   *m_orientationCB;

    QWidget     *m_duplexWidget;
    QWidget     *m_numberUpWidget;
    QWidget     *m_scalingWidget;
    QWidget     *m_orientationWidget;

    void populateNumberUpCB();
    void populateDuplexCB();
    void populateScalingCB();
    void populateOrientationCB();

};


/*! \brief tab containing spooler data type and type specific options
 *
 *  We must now create a temporary file and need to know what type of data
 *  to put into that file. Normally this will be launched from some kind of
 *  text edit widget, but could be a word processor or image editor.
 *
 *  \todo need to add some method of identifying input type so we can perform
 *        some form of conversion. Say from MS Word or ODT format to PostScript.
 *
 *  \param parent - QWidget pointer to parent widget - defaults to nullptr
 */
class SpoolerTab : public QWidget
{
    LSCS_OBJECT( SpoolerTab )

public:
    explicit SpoolerTab( QWidget *parent = nullptr );
    ~SpoolerTab();

    void pushSpoolerButton( BdSpoolerType spoolerType );


    LSCS_SIGNAL_1( Public, void spoolerTypeChanged( BdSpoolerType spoolerType ) )
    LSCS_SIGNAL_2( spoolerTypeChanged, spoolerType )

private:
    QGroupBox    *m_spoolerGroupBox;
    QRadioButton *m_textSpoolerRB;
    QRadioButton *m_rawSpoolerRB;
    QRadioButton *m_pdfSpoolerRB;
    QRadioButton *m_postscriptSpoolerRB;

};

/*! \brief Dialog for submitting a single file print job to the host print system
 *
 *  \param parent  QWidget pointer to parent - defaults to nullptr
 */
class Q_GUI_EXPORT BdSingleFileJobDialog : public QDialog
{
    LSCS_OBJECT( BdSingleFileJobDialog )

public:
    explicit BdSingleFileJobDialog( QWidget *parent = nullptr );

    BdSpoolerType spoolerType();

private:
    void copiesChanged( int copies );
    void submitJob();
    void quit();
    void destinationSelected( QString destinationName, bool isFile );
    void spoolerSelected( BdSpoolerType spoolerType );
    void paperSourceChanged( const QString &source );
    void paperChanged( const QString &source );
    void orientationChanged( const QString &orientation );
    void printQualityChanged( const QString &printQuality );

    void duplexChanged( const QString &duplex );
    void scalingChanged( const QString &scaling );
    void numberUpChanged( const QString &numberUp );


    QTabWidget *m_tabWidget;

    GeneralTab      *m_generalTab;
    PageSetupTab    *m_pageSetupTab;
    SpoolerTab      *m_spoolerTab;
    BdSingleFileJob m_job;
};
#endif   // LSCS_NO_PRINTER
#endif   // BDSINGLEFILEJOBDIALOG_H
