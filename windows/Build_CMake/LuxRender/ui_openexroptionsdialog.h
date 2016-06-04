/********************************************************************************
** Form generated from reading UI file 'openexroptionsdialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENEXROPTIONSDIALOG_H
#define UI_OPENEXROPTIONSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QRadioButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_OpenEXROptionsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QRadioButton *halfFloatRadioButton;
    QRadioButton *singleFloatRadioButton;
    QFrame *line;
    QCheckBox *depthChannelCheckBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QComboBox *compressionTypeComboBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *OpenEXROptionsDialog)
    {
        if (OpenEXROptionsDialog->objectName().isEmpty())
            OpenEXROptionsDialog->setObjectName(QString::fromUtf8("OpenEXROptionsDialog"));
        OpenEXROptionsDialog->resize(470, 150);
        OpenEXROptionsDialog->setMinimumSize(QSize(470, 150));
        OpenEXROptionsDialog->setMaximumSize(QSize(470, 150));
        verticalLayout = new QVBoxLayout(OpenEXROptionsDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(OpenEXROptionsDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        halfFloatRadioButton = new QRadioButton(OpenEXROptionsDialog);
        halfFloatRadioButton->setObjectName(QString::fromUtf8("halfFloatRadioButton"));
        halfFloatRadioButton->setChecked(true);
        halfFloatRadioButton->setAutoExclusive(true);

        horizontalLayout_3->addWidget(halfFloatRadioButton);

        singleFloatRadioButton = new QRadioButton(OpenEXROptionsDialog);
        singleFloatRadioButton->setObjectName(QString::fromUtf8("singleFloatRadioButton"));

        horizontalLayout_3->addWidget(singleFloatRadioButton);

        line = new QFrame(OpenEXROptionsDialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line);

        depthChannelCheckBox = new QCheckBox(OpenEXROptionsDialog);
        depthChannelCheckBox->setObjectName(QString::fromUtf8("depthChannelCheckBox"));

        horizontalLayout_3->addWidget(depthChannelCheckBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(OpenEXROptionsDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label_3);

        compressionTypeComboBox = new QComboBox(OpenEXROptionsDialog);
        compressionTypeComboBox->setObjectName(QString::fromUtf8("compressionTypeComboBox"));

        horizontalLayout->addWidget(compressionTypeComboBox);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(OpenEXROptionsDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setMinimumSize(QSize(0, 0));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(halfFloatRadioButton);
        label_3->setBuddy(compressionTypeComboBox);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(buttonBox, halfFloatRadioButton);
        QWidget::setTabOrder(halfFloatRadioButton, singleFloatRadioButton);
        QWidget::setTabOrder(singleFloatRadioButton, depthChannelCheckBox);
        QWidget::setTabOrder(depthChannelCheckBox, compressionTypeComboBox);

        retranslateUi(OpenEXROptionsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), OpenEXROptionsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), OpenEXROptionsDialog, SLOT(reject()));

        compressionTypeComboBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(OpenEXROptionsDialog);
    } // setupUi

    void retranslateUi(QDialog *OpenEXROptionsDialog)
    {
        OpenEXROptionsDialog->setWindowTitle(QApplication::translate("OpenEXROptionsDialog", "OpenEXR Options", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("OpenEXROptionsDialog", "Floating Point Precision:", 0, QApplication::UnicodeUTF8));
        halfFloatRadioButton->setText(QApplication::translate("OpenEXROptionsDialog", "16 bit", 0, QApplication::UnicodeUTF8));
        singleFloatRadioButton->setText(QApplication::translate("OpenEXROptionsDialog", "32 bit", 0, QApplication::UnicodeUTF8));
        depthChannelCheckBox->setText(QApplication::translate("OpenEXROptionsDialog", "Include Z Buffer", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("OpenEXROptionsDialog", "Compression Type:", 0, QApplication::UnicodeUTF8));
        compressionTypeComboBox->clear();
        compressionTypeComboBox->insertItems(0, QStringList()
         << QApplication::translate("OpenEXROptionsDialog", "Run length encoding", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OpenEXROptionsDialog", "PIZ Wavelet (recommended)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OpenEXROptionsDialog", "ZIP style (per scanline)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OpenEXROptionsDialog", "Pixar 24bit ZIP (lossy for 32bit floats)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OpenEXROptionsDialog", "Uncompressed", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class OpenEXROptionsDialog: public Ui_OpenEXROptionsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENEXROPTIONSDIALOG_H
