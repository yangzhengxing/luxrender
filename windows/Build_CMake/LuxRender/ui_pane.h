/********************************************************************************
** Form generated from reading UI file 'pane.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANE_H
#define UI_PANE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PaneWidget
{
public:
    QVBoxLayout *paneLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *labelPaneName;
    QLabel *labelPaneIcon;

    void setupUi(QWidget *PaneWidget)
    {
        if (PaneWidget->objectName().isEmpty())
            PaneWidget->setObjectName(QString::fromUtf8("PaneWidget"));
        PaneWidget->resize(379, 284);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PaneWidget->sizePolicy().hasHeightForWidth());
        PaneWidget->setSizePolicy(sizePolicy);
        paneLayout = new QVBoxLayout(PaneWidget);
        paneLayout->setContentsMargins(0, 0, 0, 0);
        paneLayout->setObjectName(QString::fromUtf8("paneLayout"));
        frame = new QFrame(PaneWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(0, 30));
        frame->setMaximumSize(QSize(16777215, 30));
        frame->setAutoFillBackground(false);
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setContentsMargins(4, 4, 4, 4);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        labelPaneName = new QLabel(frame);
        labelPaneName->setObjectName(QString::fromUtf8("labelPaneName"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        labelPaneName->setFont(font);
        labelPaneName->setTextFormat(Qt::PlainText);

        gridLayout->addWidget(labelPaneName, 0, 1, 1, 1);

        labelPaneIcon = new QLabel(frame);
        labelPaneIcon->setObjectName(QString::fromUtf8("labelPaneIcon"));

        gridLayout->addWidget(labelPaneIcon, 0, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        paneLayout->addWidget(frame);


        retranslateUi(PaneWidget);

        QMetaObject::connectSlotsByName(PaneWidget);
    } // setupUi

    void retranslateUi(QWidget *PaneWidget)
    {
        PaneWidget->setWindowTitle(QApplication::translate("PaneWidget", "Form", 0, QApplication::UnicodeUTF8));
        labelPaneName->setText(QApplication::translate("PaneWidget", "Panelabel", 0, QApplication::UnicodeUTF8));
        labelPaneIcon->setText(QApplication::translate("PaneWidget", "[]", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PaneWidget: public Ui_PaneWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANE_H
