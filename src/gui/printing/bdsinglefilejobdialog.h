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

#include <bdspooler.h>
#include <qstring.h>

class QComboBox;
class QCheckBox;
class QRadioButton;

class GeneralTab : public QWidget
{
    LSCS_OBJECT( GeneralTab )

public:
    explicit GeneralTab( QWidget *parent = nullptr );

    void setDestination( QString destination );

    QString destination();
    QString paper();
    QString pages();
    int     copies();
    bool    collate();
    QString orientation();
    QString color();

    BdSpoolerType spoolerType();

private:
    QRadioButton *m_textSpoolerRB;
    QRadioButton *m_rawSpoolerRB;
    QRadioButton *m_pdfSpoolerRB;
    QRadioButton *m_postscriptSpoolerRB;

    QComboBox *m_destinationCB;
    QComboBox *m_paperCB;
    QComboBox *m_pagesCB;  // @todo need to have a manual page range entry
    QComboBox *m_copiesSB;
    QCheckBox *m_collateCKB;
    QComboBox *m_orientationCB;
    QComboBox *m_colorCB;
};

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


};

class Q_GUI_EXPORT BdSingleFileJobDialog : public QDialog
{
    LSCS_OBJECT( BdSingleFileJobDialog )

public:
    explicit BdSingleFileJobDialog( QWidget *parent = nullptr );
    ~BdSingleFileJobDialog();

private:
    void submitJob();
    void quit();
    void tabChanged( int index );
    void newDeviceSelected( int index );

};
#endif   // LSCS_NO_PRINTER
#endif   // BDSINGLEFILEJOBDIALOG_H