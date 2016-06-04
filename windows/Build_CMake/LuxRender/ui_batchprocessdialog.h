/********************************************************************************
** Form generated from reading UI file 'batchprocessdialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BATCHPROCESSDIALOG_H
#define UI_BATCHPROCESSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QRadioButton>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BatchProcessDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QRadioButton *currentLGModeRadioButton;
    QRadioButton *allLightGroupsModeRadioButton;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *inputDirectoryLineEdit;
    QToolButton *browseForInputDirectoryButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *outputDirectoryLineEdit;
    QToolButton *browseForOutputDirectoryButton;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *tonemapCheckBox;
    QComboBox *imageFormatComboBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *BatchProcessDialog)
    {
        if (BatchProcessDialog->objectName().isEmpty())
            BatchProcessDialog->setObjectName(QString::fromUtf8("BatchProcessDialog"));
        BatchProcessDialog->resize(501, 255);
        verticalLayout_3 = new QVBoxLayout(BatchProcessDialog);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox = new QGroupBox(BatchProcessDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(label_3);

        currentLGModeRadioButton = new QRadioButton(groupBox);
        currentLGModeRadioButton->setObjectName(QString::fromUtf8("currentLGModeRadioButton"));
        currentLGModeRadioButton->setChecked(true);

        horizontalLayout_3->addWidget(currentLGModeRadioButton);

        allLightGroupsModeRadioButton = new QRadioButton(groupBox);
        allLightGroupsModeRadioButton->setObjectName(QString::fromUtf8("allLightGroupsModeRadioButton"));

        horizontalLayout_3->addWidget(allLightGroupsModeRadioButton);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        inputDirectoryLineEdit = new QLineEdit(groupBox);
        inputDirectoryLineEdit->setObjectName(QString::fromUtf8("inputDirectoryLineEdit"));

        horizontalLayout->addWidget(inputDirectoryLineEdit);

        browseForInputDirectoryButton = new QToolButton(groupBox);
        browseForInputDirectoryButton->setObjectName(QString::fromUtf8("browseForInputDirectoryButton"));

        horizontalLayout->addWidget(browseForInputDirectoryButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        outputDirectoryLineEdit = new QLineEdit(groupBox);
        outputDirectoryLineEdit->setObjectName(QString::fromUtf8("outputDirectoryLineEdit"));

        horizontalLayout_2->addWidget(outputDirectoryLineEdit);

        browseForOutputDirectoryButton = new QToolButton(groupBox);
        browseForOutputDirectoryButton->setObjectName(QString::fromUtf8("browseForOutputDirectoryButton"));

        horizontalLayout_2->addWidget(browseForOutputDirectoryButton);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(BatchProcessDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        tonemapCheckBox = new QCheckBox(groupBox_2);
        tonemapCheckBox->setObjectName(QString::fromUtf8("tonemapCheckBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tonemapCheckBox->sizePolicy().hasHeightForWidth());
        tonemapCheckBox->setSizePolicy(sizePolicy1);
        tonemapCheckBox->setChecked(true);

        horizontalLayout_4->addWidget(tonemapCheckBox);

        imageFormatComboBox = new QComboBox(groupBox_2);
        imageFormatComboBox->setObjectName(QString::fromUtf8("imageFormatComboBox"));

        horizontalLayout_4->addWidget(imageFormatComboBox);


        verticalLayout_3->addWidget(groupBox_2);

        buttonBox = new QDialogButtonBox(BatchProcessDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(buttonBox);


        retranslateUi(BatchProcessDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), BatchProcessDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), BatchProcessDialog, SLOT(reject()));
        QObject::connect(tonemapCheckBox, SIGNAL(toggled(bool)), imageFormatComboBox, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(BatchProcessDialog);
    } // setupUi

    void retranslateUi(QDialog *BatchProcessDialog)
    {
        BatchProcessDialog->setWindowTitle(QApplication::translate("BatchProcessDialog", "Batch Processing Options", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("BatchProcessDialog", "Input/Output Options", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BatchProcessDialog", "Mode:", 0, QApplication::UnicodeUTF8));
        currentLGModeRadioButton->setText(QApplication::translate("BatchProcessDialog", "Current Settings Only", 0, QApplication::UnicodeUTF8));
        allLightGroupsModeRadioButton->setText(QApplication::translate("BatchProcessDialog", "Individual Light Groups", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BatchProcessDialog", "Input Directory:", 0, QApplication::UnicodeUTF8));
        browseForInputDirectoryButton->setText(QApplication::translate("BatchProcessDialog", "...", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BatchProcessDialog", "Output Directory:", 0, QApplication::UnicodeUTF8));
        browseForOutputDirectoryButton->setText(QApplication::translate("BatchProcessDialog", "...", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("BatchProcessDialog", "Format Options", 0, QApplication::UnicodeUTF8));
        tonemapCheckBox->setText(QApplication::translate("BatchProcessDialog", "Apply Tonemapping:", 0, QApplication::UnicodeUTF8));
        imageFormatComboBox->clear();
        imageFormatComboBox->insertItems(0, QStringList()
         << QApplication::translate("BatchProcessDialog", "PNG", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("BatchProcessDialog", "JPEG", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("BatchProcessDialog", "BMP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("BatchProcessDialog", "TIFF", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class BatchProcessDialog: public Ui_BatchProcessDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BATCHPROCESSDIALOG_H
