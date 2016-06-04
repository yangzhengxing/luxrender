/********************************************************************************
** Form generated from reading UI file 'advancedinfo.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADVANCEDINFO_H
#define UI_ADVANCEDINFO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdvancedInfoWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QTextEdit *textAdvancedInfo;

    void setupUi(QWidget *AdvancedInfoWidget)
    {
        if (AdvancedInfoWidget->objectName().isEmpty())
            AdvancedInfoWidget->setObjectName(QString::fromUtf8("AdvancedInfoWidget"));
        AdvancedInfoWidget->resize(402, 304);
        verticalLayout = new QVBoxLayout(AdvancedInfoWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayoutWidget = new QWidget(AdvancedInfoWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 381, 281));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        textAdvancedInfo = new QTextEdit(gridLayoutWidget);
        textAdvancedInfo->setObjectName(QString::fromUtf8("textAdvancedInfo"));
        textAdvancedInfo->setReadOnly(true);

        gridLayout->addWidget(textAdvancedInfo, 0, 0, 1, 1);


        verticalLayout->addWidget(gridLayoutWidget);


        retranslateUi(AdvancedInfoWidget);

        QMetaObject::connectSlotsByName(AdvancedInfoWidget);
    } // setupUi

    void retranslateUi(QWidget *AdvancedInfoWidget)
    {
        AdvancedInfoWidget->setWindowTitle(QApplication::translate("AdvancedInfoWidget", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AdvancedInfoWidget: public Ui_AdvancedInfoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADVANCEDINFO_H
