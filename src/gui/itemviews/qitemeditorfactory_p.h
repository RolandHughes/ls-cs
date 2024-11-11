/***********************************************************************
*
* Copyright (c) 2012-2024 Barbara Geller
* Copyright (c) 2012-2024 Ansel Sermersheim
*
* Copyright (c) 2015 The Qt Company Ltd.
* Copyright (c) 2012-2016 Digia Plc and/or its subsidiary(-ies).
* Copyright (c) 2008-2012 Nokia Corporation and/or its subsidiary(-ies).
*
* This file is part of CopperSpice.
*
* CopperSpice is free software. You can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public License
* version 2.1 as published by the Free Software Foundation.
*
* CopperSpice is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*
* https://www.gnu.org/licenses/
*
***********************************************************************/

#ifndef QITEMEDITORFACTORY_P_H
#define QITEMEDITORFACTORY_P_H

#include <qlineedit.h>

#ifndef LSCS_NO_ITEMVIEWS

#ifndef LSCS_NO_LINEEDIT



class QExpandingLineEdit : public QLineEdit
{
    GUI_LSCS_OBJECT( QExpandingLineEdit )

public:
    QExpandingLineEdit( QWidget *parent );

    void setWidgetOwnsGeometry( bool value )
    {
        widgetOwnsGeometry = value;
    }

    GUI_LSCS_SLOT_1( Public, void resizeToContents() )
    GUI_LSCS_SLOT_2( resizeToContents )

protected:
    void changeEvent( QEvent *event ) override;

private:
    void updateMinimumWidth();

    int originalWidth;
    bool widgetOwnsGeometry;
};


#endif // LSCS_NO_LINEEDIT

#endif //LSCS_NO_ITEMVIEWS

#endif //QITEMEDITORFACTORY_P_H
