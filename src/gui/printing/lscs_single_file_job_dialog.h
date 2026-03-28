/*;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Copyright (c) 2024-2026 Roland Hughes d.b.a Logikal Solutions
;;
;; This file is part of Ls-Cs, also known as LsCs
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
#ifndef LSCSSINGLEFILEJOBDIALOG_H
#define LSCSSINGLEFILEJOBDIALOG_H

#ifndef LSCS_NO_PRINTER
#include <qdialog.h>
#include <qstring.h>

#include <lscs_spooler.h>
#include <lscs_single_file_job.h>

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
class general_tab : public QWidget
{
    LSCS_OBJECT( general_tab )

public:
    explicit general_tab( QWidget *parent = nullptr );

    void push_spooler_button( LsCsSpoolerType spoolerType );
    void make_default_current_destination();

    QString get_destination_name();


    bool dest_can_collate( QString destination );

    bool is_collate_visible();
    bool is_print_quality_visible();
    bool is_paper_source_visible();
    bool is_color_mode_visible();
    bool is_orientation_visible();
    bool is_scaling_visible();
    bool is_copies_visible();

    LSCS_SIGNAL_1( Public, void destination_changed( QString destinationName, bool isFile ) )
    LSCS_SIGNAL_2( destination_changed, destinationName, isFile )

    LSCS_SIGNAL_1( Public, void copies_changed( int copies ) )
    LSCS_SIGNAL_2( copies_changed, copies )

    LSCS_SIGNAL_1( Public, void paper_source_changed( const QString &source ) )
    LSCS_SIGNAL_2( paper_source_changed, source )

    LSCS_SIGNAL_1( Public, void paper_changed( const QString &paper ) )
    LSCS_SIGNAL_2( paper_changed, paper )

    LSCS_SIGNAL_1( Public, void print_quality_changed( const QString &paper ) )
    LSCS_SIGNAL_2( print_quality_changed, paper )




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

    void choose_destination_File();
    void dest_text_changed( const QString &text );
    void source_changed( const QString &text );
    void copies_value_changed( int newValue );

    void populate_destination_CB();
    void populate_paper_source_CB();
    void populate_paper_CB();
    void populate_color_CB();
    void populate_print_quality_CB();
    void populate_copies();


};

/*! \brief Tab containing advanced page setup information for print jobs
 *
 *  \param parent - QWidget pointer to parent widget - defaults to nullptr
 */
class page_setup_tab : public QWidget
{
    LSCS_OBJECT( page_setup_tab )

public:
    explicit page_setup_tab( QWidget *parent = nullptr );

    QString duplex_mode();
    int     number_of_pages_per_side();
    QString scaling();

    bool is_duplex_visible();
    bool is_number_up_visible();
    bool is_scaling_visible();
    bool is_orientation_visible();


    void destinationChanged( const QString destination );

    LSCS_SIGNAL_1( Public, void number_up_changed( const QString &source ) )
    LSCS_SIGNAL_2( number_up_changed, source )

    LSCS_SIGNAL_1( Public, void scaling_changed( const QString &source ) )
    LSCS_SIGNAL_2( scaling_changed, source )

    LSCS_SIGNAL_1( Public, void duplex_changed( const QString &source ) )
    LSCS_SIGNAL_2( duplex_changed, source )

    LSCS_SIGNAL_1( Public, void orientation_changed( const QString &orientation ) )
    LSCS_SIGNAL_2( orientation_changed, orientation )


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

    void populate_number_up_CB();
    void populate_duplex_CB();
    void populate_scaling_CB();
    void populate_orientation_CB();

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
class spooler_tab : public QWidget
{
    LSCS_OBJECT( spooler_tab )

public:
    explicit spooler_tab( QWidget *parent = nullptr );
    ~spooler_tab();

    void push_spooler_button( LsCsSpoolerType spoolerType );


    LSCS_SIGNAL_1( Public, void spooler_type_changed( LsCsSpoolerType spoolerType ) )
    LSCS_SIGNAL_2( spooler_type_changed, spoolerType )

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

    LsCsSpoolerType spoolerType();

private:
    void copiesChanged( int copies );
    void submit_job();
    void quit();
    void destinationSelected( QString destinationName, bool isFile );
    void spoolerSelected( LsCsSpoolerType spoolerType );
    void paperSourceChanged( const QString &source );
    void paperChanged( const QString &source );
    void orientation_changed( const QString &orientation );
    void printQualityChanged( const QString &printQuality );

    void duplexChanged( const QString &duplex );
    void scaling_changed( const QString &scaling );
    void number_up_changed( const QString &numberUp );


    QTabWidget *m_tabWidget;

    GeneralTab      *m_generalTab;
    PageSetupTab    *m_pageSetupTab;
    SpoolerTab      *m_spoolerTab;
    BdSingleFileJob m_job;
};
#endif   // LSCS_NO_PRINTER
#endif   // BDSINGLEFILEJOBDIALOG_H
