/********************************************************************************
** Form generated from reading UI file 'lenseffects.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LENSEFFECTS_H
#define UI_LENSEFFECTS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LensEffectsWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabs_lensEffects;
    QWidget *tab_gaussianBloom;
    QGridLayout *gridLayout_16;
    QGridLayout *gridLayout_20;
    QPushButton *button_gaussianDeleteLayer;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *button_gaussianComputeLayer;
    QDoubleSpinBox *spinBox_gaussianRadius;
    QSlider *slider_gaussianRadius;
    QLabel *label_gaussianRadius;
    QDoubleSpinBox *spinBox_gaussianAmount;
    QSlider *slider_gaussianAmount;
    QLabel *label_gaussianAmount;
    QSpacerItem *verticalSpacer_3;
    QWidget *tab_vignetting;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *checkBox_vignettingEnabled;
    QLabel *label_vignettingAmount;
    QGridLayout *gridLayout_21;
    QLabel *label_vignettingMin;
    QLabel *label_vignettingMed;
    QLabel *label_vignettingMax;
    QSlider *slider_vignettingAmount;
    QDoubleSpinBox *spinBox_vignettingAmount;
    QSpacerItem *verticalSpacer_5;
    QWidget *tab_chromaticAbberationTab;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *checkBox_caEnabled;
    QLabel *label_caAmount;
    QGridLayout *gridLayout_22;
    QLabel *label_caAmountMin;
    QLabel *label_caAmountMed;
    QLabel *checkBox_caAmountMax;
    QSlider *slider_caAmount;
    QDoubleSpinBox *spinBox_caAmount;
    QSpacerItem *verticalSpacer_6;
    QWidget *tab_glare;
    QVBoxLayout *verticalLayout_6;
    QGridLayout *gridLayout_23;
    QSpacerItem *horizontalSpacer;
    QPushButton *button_glareComputeLayer;
    QCheckBox *checkBox_glareMap;
    QSpacerItem *hSpacer3;
    QPushButton *button_glareDeleteLayer;
    QLabel *label_lashesMap;
    QLabel *label_pupilMap;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_pupilMap;
    QPushButton *button_browsePupilMap;
    QSpacerItem *horizontalSpacer_2;
    QDoubleSpinBox *spinBox_glareRadius;
    QLabel *label_glareAmount;
    QSlider *slider_glareAmount;
    QDoubleSpinBox *spinBox_glareAmount;
    QLabel *label_glareThreshold;
    QSlider *slider_glareThreshold;
    QDoubleSpinBox *spinBox_glareThreshold;
    QLabel *label_glareBlades;
    QLabel *glareRadiusLabel;
    QSpacerItem *hSpacer2;
    QSpinBox *spinBox_glareBlades;
    QSlider *slider_glareRadius;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_lashesMap;
    QPushButton *button_browseLashesMap;
    QSpacerItem *verticalSpacer_7;

    void setupUi(QWidget *LensEffectsWidget)
    {
        if (LensEffectsWidget->objectName().isEmpty())
            LensEffectsWidget->setObjectName(QString::fromUtf8("LensEffectsWidget"));
        LensEffectsWidget->resize(497, 356);
        verticalLayout = new QVBoxLayout(LensEffectsWidget);
        verticalLayout->setContentsMargins(12, 12, 12, 12);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabs_lensEffects = new QTabWidget(LensEffectsWidget);
        tabs_lensEffects->setObjectName(QString::fromUtf8("tabs_lensEffects"));
        tabs_lensEffects->setEnabled(true);
        tab_gaussianBloom = new QWidget();
        tab_gaussianBloom->setObjectName(QString::fromUtf8("tab_gaussianBloom"));
        gridLayout_16 = new QGridLayout(tab_gaussianBloom);
        gridLayout_16->setContentsMargins(4, 4, 4, 4);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        gridLayout_20 = new QGridLayout();
        gridLayout_20->setObjectName(QString::fromUtf8("gridLayout_20"));
        button_gaussianDeleteLayer = new QPushButton(tab_gaussianBloom);
        button_gaussianDeleteLayer->setObjectName(QString::fromUtf8("button_gaussianDeleteLayer"));
        button_gaussianDeleteLayer->setEnabled(false);

        gridLayout_20->addWidget(button_gaussianDeleteLayer, 2, 3, 1, 2);

        horizontalSpacer_5 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_20->addItem(horizontalSpacer_5, 2, 2, 1, 1);

        button_gaussianComputeLayer = new QPushButton(tab_gaussianBloom);
        button_gaussianComputeLayer->setObjectName(QString::fromUtf8("button_gaussianComputeLayer"));

        gridLayout_20->addWidget(button_gaussianComputeLayer, 2, 0, 1, 2);

        spinBox_gaussianRadius = new QDoubleSpinBox(tab_gaussianBloom);
        spinBox_gaussianRadius->setObjectName(QString::fromUtf8("spinBox_gaussianRadius"));
        spinBox_gaussianRadius->setKeyboardTracking(false);
        spinBox_gaussianRadius->setDecimals(4);
        spinBox_gaussianRadius->setMaximum(1);
        spinBox_gaussianRadius->setSingleStep(0.01);

        gridLayout_20->addWidget(spinBox_gaussianRadius, 1, 4, 1, 1);

        slider_gaussianRadius = new QSlider(tab_gaussianBloom);
        slider_gaussianRadius->setObjectName(QString::fromUtf8("slider_gaussianRadius"));
        slider_gaussianRadius->setMaximum(512);
        slider_gaussianRadius->setOrientation(Qt::Horizontal);

        gridLayout_20->addWidget(slider_gaussianRadius, 1, 1, 1, 3);

        label_gaussianRadius = new QLabel(tab_gaussianBloom);
        label_gaussianRadius->setObjectName(QString::fromUtf8("label_gaussianRadius"));

        gridLayout_20->addWidget(label_gaussianRadius, 1, 0, 1, 1);

        spinBox_gaussianAmount = new QDoubleSpinBox(tab_gaussianBloom);
        spinBox_gaussianAmount->setObjectName(QString::fromUtf8("spinBox_gaussianAmount"));
        spinBox_gaussianAmount->setEnabled(false);
        spinBox_gaussianAmount->setKeyboardTracking(false);
        spinBox_gaussianAmount->setMaximum(1);
        spinBox_gaussianAmount->setSingleStep(0.01);

        gridLayout_20->addWidget(spinBox_gaussianAmount, 0, 4, 1, 1);

        slider_gaussianAmount = new QSlider(tab_gaussianBloom);
        slider_gaussianAmount->setObjectName(QString::fromUtf8("slider_gaussianAmount"));
        slider_gaussianAmount->setEnabled(false);
        slider_gaussianAmount->setMaximum(512);
        slider_gaussianAmount->setOrientation(Qt::Horizontal);

        gridLayout_20->addWidget(slider_gaussianAmount, 0, 1, 1, 3);

        label_gaussianAmount = new QLabel(tab_gaussianBloom);
        label_gaussianAmount->setObjectName(QString::fromUtf8("label_gaussianAmount"));

        gridLayout_20->addWidget(label_gaussianAmount, 0, 0, 1, 1);


        gridLayout_16->addLayout(gridLayout_20, 0, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_16->addItem(verticalSpacer_3, 1, 0, 1, 1);

        tabs_lensEffects->addTab(tab_gaussianBloom, QString());
        tab_vignetting = new QWidget();
        tab_vignetting->setObjectName(QString::fromUtf8("tab_vignetting"));
        verticalLayout_4 = new QVBoxLayout(tab_vignetting);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        checkBox_vignettingEnabled = new QCheckBox(tab_vignetting);
        checkBox_vignettingEnabled->setObjectName(QString::fromUtf8("checkBox_vignettingEnabled"));

        verticalLayout_4->addWidget(checkBox_vignettingEnabled);

        label_vignettingAmount = new QLabel(tab_vignetting);
        label_vignettingAmount->setObjectName(QString::fromUtf8("label_vignettingAmount"));

        verticalLayout_4->addWidget(label_vignettingAmount);

        gridLayout_21 = new QGridLayout();
        gridLayout_21->setObjectName(QString::fromUtf8("gridLayout_21"));
        label_vignettingMin = new QLabel(tab_vignetting);
        label_vignettingMin->setObjectName(QString::fromUtf8("label_vignettingMin"));

        gridLayout_21->addWidget(label_vignettingMin, 0, 0, 1, 1);

        label_vignettingMed = new QLabel(tab_vignetting);
        label_vignettingMed->setObjectName(QString::fromUtf8("label_vignettingMed"));
        label_vignettingMed->setAlignment(Qt::AlignCenter);

        gridLayout_21->addWidget(label_vignettingMed, 0, 1, 1, 1);

        label_vignettingMax = new QLabel(tab_vignetting);
        label_vignettingMax->setObjectName(QString::fromUtf8("label_vignettingMax"));
        label_vignettingMax->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_21->addWidget(label_vignettingMax, 0, 2, 1, 1);

        slider_vignettingAmount = new QSlider(tab_vignetting);
        slider_vignettingAmount->setObjectName(QString::fromUtf8("slider_vignettingAmount"));
        slider_vignettingAmount->setEnabled(true);
        slider_vignettingAmount->setMaximum(512);
        slider_vignettingAmount->setOrientation(Qt::Horizontal);
        slider_vignettingAmount->setTickPosition(QSlider::TicksAbove);
        slider_vignettingAmount->setTickInterval(10);

        gridLayout_21->addWidget(slider_vignettingAmount, 1, 0, 1, 3);

        spinBox_vignettingAmount = new QDoubleSpinBox(tab_vignetting);
        spinBox_vignettingAmount->setObjectName(QString::fromUtf8("spinBox_vignettingAmount"));
        spinBox_vignettingAmount->setEnabled(true);
        spinBox_vignettingAmount->setKeyboardTracking(false);
        spinBox_vignettingAmount->setDecimals(3);
        spinBox_vignettingAmount->setMinimum(-1);
        spinBox_vignettingAmount->setMaximum(1);
        spinBox_vignettingAmount->setSingleStep(0.1);

        gridLayout_21->addWidget(spinBox_vignettingAmount, 1, 3, 1, 1);


        verticalLayout_4->addLayout(gridLayout_21);

        verticalSpacer_5 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_5);

        tabs_lensEffects->addTab(tab_vignetting, QString());
        tab_chromaticAbberationTab = new QWidget();
        tab_chromaticAbberationTab->setObjectName(QString::fromUtf8("tab_chromaticAbberationTab"));
        verticalLayout_5 = new QVBoxLayout(tab_chromaticAbberationTab);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        checkBox_caEnabled = new QCheckBox(tab_chromaticAbberationTab);
        checkBox_caEnabled->setObjectName(QString::fromUtf8("checkBox_caEnabled"));

        verticalLayout_5->addWidget(checkBox_caEnabled);

        label_caAmount = new QLabel(tab_chromaticAbberationTab);
        label_caAmount->setObjectName(QString::fromUtf8("label_caAmount"));

        verticalLayout_5->addWidget(label_caAmount);

        gridLayout_22 = new QGridLayout();
        gridLayout_22->setObjectName(QString::fromUtf8("gridLayout_22"));
        label_caAmountMin = new QLabel(tab_chromaticAbberationTab);
        label_caAmountMin->setObjectName(QString::fromUtf8("label_caAmountMin"));

        gridLayout_22->addWidget(label_caAmountMin, 0, 0, 1, 1);

        label_caAmountMed = new QLabel(tab_chromaticAbberationTab);
        label_caAmountMed->setObjectName(QString::fromUtf8("label_caAmountMed"));
        label_caAmountMed->setAlignment(Qt::AlignCenter);

        gridLayout_22->addWidget(label_caAmountMed, 0, 1, 1, 1);

        checkBox_caAmountMax = new QLabel(tab_chromaticAbberationTab);
        checkBox_caAmountMax->setObjectName(QString::fromUtf8("checkBox_caAmountMax"));
        checkBox_caAmountMax->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_22->addWidget(checkBox_caAmountMax, 0, 2, 1, 1);

        slider_caAmount = new QSlider(tab_chromaticAbberationTab);
        slider_caAmount->setObjectName(QString::fromUtf8("slider_caAmount"));
        slider_caAmount->setMaximum(512);
        slider_caAmount->setOrientation(Qt::Horizontal);
        slider_caAmount->setTickPosition(QSlider::NoTicks);
        slider_caAmount->setTickInterval(0);

        gridLayout_22->addWidget(slider_caAmount, 1, 0, 1, 3);

        spinBox_caAmount = new QDoubleSpinBox(tab_chromaticAbberationTab);
        spinBox_caAmount->setObjectName(QString::fromUtf8("spinBox_caAmount"));
        spinBox_caAmount->setKeyboardTracking(false);
        spinBox_caAmount->setDecimals(3);
        spinBox_caAmount->setMinimum(0);
        spinBox_caAmount->setMaximum(0.5);
        spinBox_caAmount->setSingleStep(0.001);

        gridLayout_22->addWidget(spinBox_caAmount, 1, 3, 1, 1);


        verticalLayout_5->addLayout(gridLayout_22);

        verticalSpacer_6 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_6);

        tabs_lensEffects->addTab(tab_chromaticAbberationTab, QString());
        tab_glare = new QWidget();
        tab_glare->setObjectName(QString::fromUtf8("tab_glare"));
        verticalLayout_6 = new QVBoxLayout(tab_glare);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        gridLayout_23 = new QGridLayout();
        gridLayout_23->setObjectName(QString::fromUtf8("gridLayout_23"));
        horizontalSpacer = new QSpacerItem(13, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_23->addItem(horizontalSpacer, 5, 1, 1, 6);

        button_glareComputeLayer = new QPushButton(tab_glare);
        button_glareComputeLayer->setObjectName(QString::fromUtf8("button_glareComputeLayer"));

        gridLayout_23->addWidget(button_glareComputeLayer, 11, 0, 1, 2);

        checkBox_glareMap = new QCheckBox(tab_glare);
        checkBox_glareMap->setObjectName(QString::fromUtf8("checkBox_glareMap"));

        gridLayout_23->addWidget(checkBox_glareMap, 6, 0, 1, 1);

        hSpacer3 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_23->addItem(hSpacer3, 11, 2, 1, 2);

        button_glareDeleteLayer = new QPushButton(tab_glare);
        button_glareDeleteLayer->setObjectName(QString::fromUtf8("button_glareDeleteLayer"));
        button_glareDeleteLayer->setEnabled(false);

        gridLayout_23->addWidget(button_glareDeleteLayer, 11, 4, 1, 3);

        label_lashesMap = new QLabel(tab_glare);
        label_lashesMap->setObjectName(QString::fromUtf8("label_lashesMap"));

        gridLayout_23->addWidget(label_lashesMap, 8, 0, 1, 1);

        label_pupilMap = new QLabel(tab_glare);
        label_pupilMap->setObjectName(QString::fromUtf8("label_pupilMap"));

        gridLayout_23->addWidget(label_pupilMap, 7, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit_pupilMap = new QLineEdit(tab_glare);
        lineEdit_pupilMap->setObjectName(QString::fromUtf8("lineEdit_pupilMap"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_pupilMap->sizePolicy().hasHeightForWidth());
        lineEdit_pupilMap->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lineEdit_pupilMap);

        button_browsePupilMap = new QPushButton(tab_glare);
        button_browsePupilMap->setObjectName(QString::fromUtf8("button_browsePupilMap"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(button_browsePupilMap->sizePolicy().hasHeightForWidth());
        button_browsePupilMap->setSizePolicy(sizePolicy1);
        button_browsePupilMap->setMinimumSize(QSize(16, 16));
        button_browsePupilMap->setMaximumSize(QSize(24, 16777215));

        horizontalLayout->addWidget(button_browsePupilMap);


        gridLayout_23->addLayout(horizontalLayout, 7, 1, 1, 6);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_23->addItem(horizontalSpacer_2, 6, 1, 1, 6);

        spinBox_glareRadius = new QDoubleSpinBox(tab_glare);
        spinBox_glareRadius->setObjectName(QString::fromUtf8("spinBox_glareRadius"));
        spinBox_glareRadius->setKeyboardTracking(false);
        spinBox_glareRadius->setDecimals(3);
        spinBox_glareRadius->setMaximum(0.2);
        spinBox_glareRadius->setSingleStep(0.01);

        gridLayout_23->addWidget(spinBox_glareRadius, 4, 6, 1, 1);

        label_glareAmount = new QLabel(tab_glare);
        label_glareAmount->setObjectName(QString::fromUtf8("label_glareAmount"));

        gridLayout_23->addWidget(label_glareAmount, 1, 0, 1, 1);

        slider_glareAmount = new QSlider(tab_glare);
        slider_glareAmount->setObjectName(QString::fromUtf8("slider_glareAmount"));
        slider_glareAmount->setEnabled(false);
        slider_glareAmount->setMaximum(512);
        slider_glareAmount->setOrientation(Qt::Horizontal);

        gridLayout_23->addWidget(slider_glareAmount, 1, 1, 1, 5);

        spinBox_glareAmount = new QDoubleSpinBox(tab_glare);
        spinBox_glareAmount->setObjectName(QString::fromUtf8("spinBox_glareAmount"));
        spinBox_glareAmount->setEnabled(false);
        spinBox_glareAmount->setKeyboardTracking(false);
        spinBox_glareAmount->setDecimals(3);
        spinBox_glareAmount->setMaximum(0.3);
        spinBox_glareAmount->setSingleStep(0.01);

        gridLayout_23->addWidget(spinBox_glareAmount, 1, 6, 1, 1);

        label_glareThreshold = new QLabel(tab_glare);
        label_glareThreshold->setObjectName(QString::fromUtf8("label_glareThreshold"));

        gridLayout_23->addWidget(label_glareThreshold, 2, 0, 1, 1);

        slider_glareThreshold = new QSlider(tab_glare);
        slider_glareThreshold->setObjectName(QString::fromUtf8("slider_glareThreshold"));
        slider_glareThreshold->setMaximum(512);
        slider_glareThreshold->setOrientation(Qt::Horizontal);

        gridLayout_23->addWidget(slider_glareThreshold, 2, 1, 1, 5);

        spinBox_glareThreshold = new QDoubleSpinBox(tab_glare);
        spinBox_glareThreshold->setObjectName(QString::fromUtf8("spinBox_glareThreshold"));
        spinBox_glareThreshold->setKeyboardTracking(false);
        spinBox_glareThreshold->setDecimals(3);
        spinBox_glareThreshold->setMaximum(1);
        spinBox_glareThreshold->setSingleStep(0.01);

        gridLayout_23->addWidget(spinBox_glareThreshold, 2, 6, 1, 1);

        label_glareBlades = new QLabel(tab_glare);
        label_glareBlades->setObjectName(QString::fromUtf8("label_glareBlades"));

        gridLayout_23->addWidget(label_glareBlades, 3, 0, 1, 1);

        glareRadiusLabel = new QLabel(tab_glare);
        glareRadiusLabel->setObjectName(QString::fromUtf8("glareRadiusLabel"));

        gridLayout_23->addWidget(glareRadiusLabel, 3, 1, 1, 2);

        hSpacer2 = new QSpacerItem(116, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_23->addItem(hSpacer2, 3, 3, 1, 4);

        spinBox_glareBlades = new QSpinBox(tab_glare);
        spinBox_glareBlades->setObjectName(QString::fromUtf8("spinBox_glareBlades"));
        spinBox_glareBlades->setMaximum(100);

        gridLayout_23->addWidget(spinBox_glareBlades, 4, 0, 1, 1);

        slider_glareRadius = new QSlider(tab_glare);
        slider_glareRadius->setObjectName(QString::fromUtf8("slider_glareRadius"));
        slider_glareRadius->setMaximum(512);
        slider_glareRadius->setOrientation(Qt::Horizontal);

        gridLayout_23->addWidget(slider_glareRadius, 4, 1, 1, 5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEdit_lashesMap = new QLineEdit(tab_glare);
        lineEdit_lashesMap->setObjectName(QString::fromUtf8("lineEdit_lashesMap"));

        horizontalLayout_2->addWidget(lineEdit_lashesMap);

        button_browseLashesMap = new QPushButton(tab_glare);
        button_browseLashesMap->setObjectName(QString::fromUtf8("button_browseLashesMap"));
        sizePolicy1.setHeightForWidth(button_browseLashesMap->sizePolicy().hasHeightForWidth());
        button_browseLashesMap->setSizePolicy(sizePolicy1);
        button_browseLashesMap->setMinimumSize(QSize(16, 16));
        button_browseLashesMap->setMaximumSize(QSize(24, 16777215));

        horizontalLayout_2->addWidget(button_browseLashesMap);


        gridLayout_23->addLayout(horizontalLayout_2, 8, 1, 1, 6);


        verticalLayout_6->addLayout(gridLayout_23);

        tabs_lensEffects->addTab(tab_glare, QString());

        verticalLayout->addWidget(tabs_lensEffects);

        verticalSpacer_7 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_7);

#ifndef QT_NO_SHORTCUT
        label_gaussianRadius->setBuddy(slider_gaussianRadius);
        label_gaussianAmount->setBuddy(slider_gaussianAmount);
        label_vignettingAmount->setBuddy(slider_vignettingAmount);
        label_caAmount->setBuddy(slider_caAmount);
        label_glareAmount->setBuddy(slider_glareAmount);
        label_glareBlades->setBuddy(spinBox_glareBlades);
        glareRadiusLabel->setBuddy(slider_glareRadius);
#endif // QT_NO_SHORTCUT

        retranslateUi(LensEffectsWidget);

        tabs_lensEffects->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(LensEffectsWidget);
    } // setupUi

    void retranslateUi(QWidget *LensEffectsWidget)
    {
        LensEffectsWidget->setWindowTitle(QApplication::translate("LensEffectsWidget", "Form", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        button_gaussianDeleteLayer->setToolTip(QApplication::translate("LensEffectsWidget", "Delete/Disable Bloom image layer", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        button_gaussianDeleteLayer->setText(QApplication::translate("LensEffectsWidget", "Delete layer", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        button_gaussianComputeLayer->setToolTip(QApplication::translate("LensEffectsWidget", "Compute/Update Bloom image layer", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        button_gaussianComputeLayer->setText(QApplication::translate("LensEffectsWidget", "Compute layer", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        spinBox_gaussianRadius->setToolTip(QApplication::translate("LensEffectsWidget", "Adjust Image length Bloom Radius Value", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        slider_gaussianRadius->setToolTip(QApplication::translate("LensEffectsWidget", "Adjust Image length Bloom Radius", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_gaussianRadius->setText(QApplication::translate("LensEffectsWidget", "Radius", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        spinBox_gaussianAmount->setToolTip(QApplication::translate("LensEffectsWidget", "Adjust Bloom amount Value", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        slider_gaussianAmount->setToolTip(QApplication::translate("LensEffectsWidget", "Adjust Bloom amount", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_gaussianAmount->setText(QApplication::translate("LensEffectsWidget", "Amount", 0, QApplication::UnicodeUTF8));
        tabs_lensEffects->setTabText(tabs_lensEffects->indexOf(tab_gaussianBloom), QApplication::translate("LensEffectsWidget", "Bloom", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox_vignettingEnabled->setToolTip(QApplication::translate("LensEffectsWidget", "Enable Vignetting", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        checkBox_vignettingEnabled->setText(QApplication::translate("LensEffectsWidget", "Enabled", 0, QApplication::UnicodeUTF8));
        label_vignettingAmount->setText(QApplication::translate("LensEffectsWidget", "Amount:", 0, QApplication::UnicodeUTF8));
        label_vignettingMin->setText(QApplication::translate("LensEffectsWidget", "-1.0", 0, QApplication::UnicodeUTF8));
        label_vignettingMed->setText(QApplication::translate("LensEffectsWidget", "0.0", 0, QApplication::UnicodeUTF8));
        label_vignettingMax->setText(QApplication::translate("LensEffectsWidget", "+1.0", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        slider_vignettingAmount->setToolTip(QApplication::translate("LensEffectsWidget", "Adjust Vignetting Amount", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinBox_vignettingAmount->setToolTip(QApplication::translate("LensEffectsWidget", "Adjust Vignetting Amount Value", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        tabs_lensEffects->setTabText(tabs_lensEffects->indexOf(tab_vignetting), QApplication::translate("LensEffectsWidget", "Vignetting", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox_caEnabled->setToolTip(QApplication::translate("LensEffectsWidget", "Enable Chromatic Abberation", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        checkBox_caEnabled->setText(QApplication::translate("LensEffectsWidget", "Enabled", 0, QApplication::UnicodeUTF8));
        label_caAmount->setText(QApplication::translate("LensEffectsWidget", "Amount:", 0, QApplication::UnicodeUTF8));
        label_caAmountMin->setText(QApplication::translate("LensEffectsWidget", "0.0", 0, QApplication::UnicodeUTF8));
        label_caAmountMed->setText(QString());
        checkBox_caAmountMax->setText(QApplication::translate("LensEffectsWidget", "0.1", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        slider_caAmount->setToolTip(QApplication::translate("LensEffectsWidget", "Adjust Chromatic Abberation Amount", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinBox_caAmount->setToolTip(QApplication::translate("LensEffectsWidget", "Adjust Chromatic Abberation Amount Value", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        tabs_lensEffects->setTabText(tabs_lensEffects->indexOf(tab_chromaticAbberationTab), QApplication::translate("LensEffectsWidget", "C. Aberration", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        button_glareComputeLayer->setToolTip(QApplication::translate("LensEffectsWidget", "Compute/Update Glare image layer", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        button_glareComputeLayer->setText(QApplication::translate("LensEffectsWidget", "Compute layer", 0, QApplication::UnicodeUTF8));
        checkBox_glareMap->setText(QApplication::translate("LensEffectsWidget", "Use maps", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        button_glareDeleteLayer->setToolTip(QApplication::translate("LensEffectsWidget", "Delete/Disable Glare image layer", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        button_glareDeleteLayer->setText(QApplication::translate("LensEffectsWidget", "Delete layer", 0, QApplication::UnicodeUTF8));
        label_lashesMap->setText(QApplication::translate("LensEffectsWidget", "Eye lashes map:", 0, QApplication::UnicodeUTF8));
        label_pupilMap->setText(QApplication::translate("LensEffectsWidget", "Pupil map:", 0, QApplication::UnicodeUTF8));
        button_browsePupilMap->setText(QApplication::translate("LensEffectsWidget", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        spinBox_glareRadius->setToolTip(QApplication::translate("LensEffectsWidget", "Adjust Image length Glare Value", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_glareAmount->setText(QApplication::translate("LensEffectsWidget", "Amount:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        slider_glareAmount->setToolTip(QApplication::translate("LensEffectsWidget", "Adjust Glare amount", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinBox_glareAmount->setToolTip(QApplication::translate("LensEffectsWidget", "Adjust Glare amount Value", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_glareThreshold->setText(QApplication::translate("LensEffectsWidget", "Threshold:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        slider_glareThreshold->setToolTip(QApplication::translate("LensEffectsWidget", "Just pixels with a brightness above this threshold will be used for the glare effect", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinBox_glareThreshold->setToolTip(QApplication::translate("LensEffectsWidget", "Just pixels with a brightness above this threshold will be used for the glare effect", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_glareBlades->setText(QApplication::translate("LensEffectsWidget", "Blades:", 0, QApplication::UnicodeUTF8));
        glareRadiusLabel->setText(QApplication::translate("LensEffectsWidget", "Radius:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        spinBox_glareBlades->setToolTip(QApplication::translate("LensEffectsWidget", "Adjust number of Glare blades used", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        slider_glareRadius->setToolTip(QApplication::translate("LensEffectsWidget", "Adjust Image length Glare Radius", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        button_browseLashesMap->setText(QApplication::translate("LensEffectsWidget", "...", 0, QApplication::UnicodeUTF8));
        tabs_lensEffects->setTabText(tabs_lensEffects->indexOf(tab_glare), QApplication::translate("LensEffectsWidget", "Glare", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LensEffectsWidget: public Ui_LensEffectsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LENSEFFECTS_H
