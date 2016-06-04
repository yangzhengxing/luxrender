/********************************************************************************
** Form generated from reading UI file 'gamma.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMMA_H
#define UI_GAMMA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GammaWidget
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QLabel *gamma_label;
    QSlider *slider_gamma;
    QDoubleSpinBox *spinBox_gamma;
    QCheckBox *checkBox_CRF;
    QLabel *crf_label;
    QSpacerItem *verticalSpacer;
    QComboBox *combo_CRF_List;

    void setupUi(QWidget *GammaWidget)
    {
        if (GammaWidget->objectName().isEmpty())
            GammaWidget->setObjectName(QString::fromUtf8("GammaWidget"));
        GammaWidget->resize(400, 268);
        verticalLayout = new QVBoxLayout(GammaWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 12, -1, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(6);
        gamma_label = new QLabel(GammaWidget);
        gamma_label->setObjectName(QString::fromUtf8("gamma_label"));

        gridLayout_2->addWidget(gamma_label, 0, 0, 1, 1);

        slider_gamma = new QSlider(GammaWidget);
        slider_gamma->setObjectName(QString::fromUtf8("slider_gamma"));
        slider_gamma->setMaximum(512);
        slider_gamma->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(slider_gamma, 1, 0, 1, 1);

        spinBox_gamma = new QDoubleSpinBox(GammaWidget);
        spinBox_gamma->setObjectName(QString::fromUtf8("spinBox_gamma"));
        spinBox_gamma->setKeyboardTracking(false);
        spinBox_gamma->setMaximum(5);
        spinBox_gamma->setSingleStep(0.1);

        gridLayout_2->addWidget(spinBox_gamma, 1, 1, 1, 1);

        checkBox_CRF = new QCheckBox(GammaWidget);
        checkBox_CRF->setObjectName(QString::fromUtf8("checkBox_CRF"));
        checkBox_CRF->setChecked(true);

        gridLayout_2->addWidget(checkBox_CRF, 5, 1, 1, 1);

        crf_label = new QLabel(GammaWidget);
        crf_label->setObjectName(QString::fromUtf8("crf_label"));

        gridLayout_2->addWidget(crf_label, 5, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 8, 0, 1, 1);

        combo_CRF_List = new QComboBox(GammaWidget);
        combo_CRF_List->setObjectName(QString::fromUtf8("combo_CRF_List"));

        gridLayout_2->addWidget(combo_CRF_List, 6, 0, 1, 2);


        verticalLayout->addLayout(gridLayout_2);


        retranslateUi(GammaWidget);

        QMetaObject::connectSlotsByName(GammaWidget);
    } // setupUi

    void retranslateUi(QWidget *GammaWidget)
    {
        GammaWidget->setWindowTitle(QApplication::translate("GammaWidget", "Form", 0, QApplication::UnicodeUTF8));
        gamma_label->setText(QApplication::translate("GammaWidget", "Gamma", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        slider_gamma->setToolTip(QApplication::translate("GammaWidget", "Adjust Gamma Correction", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinBox_gamma->setToolTip(QApplication::translate("GammaWidget", "Adjust Gamma Correction Value", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        checkBox_CRF->setToolTip(QApplication::translate("GammaWidget", "Toggle CRF on/off", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        checkBox_CRF->setText(QApplication::translate("GammaWidget", "Active", 0, QApplication::UnicodeUTF8));
        crf_label->setText(QApplication::translate("GammaWidget", "Film Response", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GammaWidget: public Ui_GammaWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMMA_H
