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

    void setDestination( QString destination );


    LSCS_SIGNAL_1( Public, void spoolerTypeChanged( BdSpoolerType spoolerType ) )
    LSCS_SIGNAL_2( spoolerTypeChanged, spoolerType )

    LSCS_SIGNAL_1( Public, void destinationChanged( QString destinationName, bool isFile ) )
    LSCS_SIGNAL_2( destinationChanged, destinationName, isFile )

    LSCS_SIGNAL_1( Public, void copiesChanged( int copies ) )
    LSCS_SIGNAL_2( copiesChanged, copies )

    LSCS_SIGNAL_1( Public, void paperSourceChanged( const QString &source ) )
    LSCS_SIGNAL_2( paperSourceChanged, source )

    LSCS_SIGNAL_1( Public, void paperChanged( const QString &paper ) )
    LSCS_SIGNAL_2( paperChanged, paper )

    LSCS_SIGNAL_1( Public, void orientationChanged( const QString &orientation ) )
    LSCS_SIGNAL_2( orientationChanged, orientation )

    void pushSpoolerButton( BdSpoolerType spoolerType );


private:
    QGroupBox    *m_spoolerGroupBox;
    QRadioButton *m_textSpoolerRB;
    QRadioButton *m_rawSpoolerRB;
    QRadioButton *m_pdfSpoolerRB;
    QRadioButton *m_postscriptSpoolerRB;

    QComboBox   *m_destinationCB;
    QToolButton *m_fileChooserBtn;
    QLineEdit   *m_fileNameLE;
    QComboBox   *m_paperSourceCB;
    QComboBox   *m_paperCB;
    QLineEdit   *m_pagesLE;
    QSpinBox    *m_copiesSB;
    QCheckBox   *m_collateCKB;
    QComboBox   *m_orientationCB;
    QComboBox   *m_colorCB;
    QWidget     *m_destFileWidget;
    QWidget     *m_copiesWidget;
    QWidget     *m_collateWidget;
    QWidget     *m_orientationWidget;
    QWidget     *m_colorWidget;

    void chooseDestinationFile();
    void destTextChanged( const QString &text );
    void paperSourceChanged( const QString &text );

    void populateDestinationCB();
    void populatePaperSourceCB();
    void populatePaperCB();
    void populateOrientationCB();
    void populateColorCB();


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
    QString mediaName();
    QString mediaSource();

private:
    QComboBox *m_duplexCB;
    QSpinBox  *m_numberUpSB;    // pages per side
    QComboBox *m_mediaCB;
    QComboBox *m_mediaSourceCB;

    void populateDuplexCB();
    void populateMediaCB();
    void populateMediaSourceCB();

};


/*! \brief tab containing advanced printing options such as resolution, output bin, finishings, etc.
 *
 *  \param parent - QWidget pointer to parent widget - defaults to nullptr
 */
class OptionsTab : public QWidget
{
    LSCS_OBJECT( OptionsTab )

public:
    explicit OptionsTab( QWidget *parent = nullptr );


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
    ~BdSingleFileJobDialog();

    BdSpoolerType spoolerType();

private:
    void copiesChanged( int copies );
    void submitJob();
    void quit();
    void deviceSelected( int index );
    void destinationSelected( QString destinationName, bool isFile );
    void spoolerSelected( BdSpoolerType spoolerType );


    QTabWidget *m_tabWidget;
    BdSingleFileJob m_job;
};
#endif   // LSCS_NO_PRINTER
#endif   // BDSINGLEFILEJOBDIALOG_H
