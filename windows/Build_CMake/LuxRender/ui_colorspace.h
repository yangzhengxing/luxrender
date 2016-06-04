/********************************************************************************
** Form generated from reading UI file 'colorspace.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORSPACE_H
#define UI_COLORSPACE_H

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
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ColorSpaceWidget
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_colorSpacePreset;
    QComboBox *comboBox_colorSpacePreset;
    QTabWidget *tabs_colorSpaceTabs;
    QWidget *tab_whitepoint;
    QGridLayout *gridLayout_15;
    QGridLayout *gridLayout_28;
    QLabel *label_whitePointPreset;
    QComboBox *comboBox_whitePointPreset;
    QLabel *label_whitePointX;
    QSlider *slider_whitePointX;
    QDoubleSpinBox *spinBox_whitePointX;
    QLabel *label_whtePointY;
    QSlider *slider_whitePointY;
    QDoubleSpinBox *spinBox_whitePointY;
    QSpacerItem *verticalSpacer_2;
    QCheckBox *checkbox_precisionEdit;
    QWidget *tab_rgb;
    QGridLayout *gridLayout_14;
    QGridLayout *gridLayout_2;
    QLabel *label_rgbXY;
    QSlider *slider_redX;
    QDoubleSpinBox *spinBox_redX;
    QSlider *slider_redY;
    QDoubleSpinBox *spinBox_redY;
    QSlider *slider_greenX;
    QDoubleSpinBox *spinBox_greenX;
    QSlider *slider_greenY;
    QDoubleSpinBox *spinBox_greenY;
    QSlider *slider_blueX;
    QDoubleSpinBox *spinBox_blueX;
    QSlider *slider_blueY;
    QDoubleSpinBox *spinBox_blueY;
    QSpacerItem *verticalSpacer;
    QWidget *tab_temperature;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QLabel *label_whitePointTemp;
    QSlider *slider_temperature;
    QDoubleSpinBox *spinBox_temperature;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_whitePointTempNotice;

    void setupUi(QWidget *ColorSpaceWidget)
    {
        if (ColorSpaceWidget->objectName().isEmpty())
            ColorSpaceWidget->setObjectName(QString::fromUtf8("ColorSpaceWidget"));
        ColorSpaceWidget->resize(558, 272);
        verticalLayout = new QVBoxLayout(ColorSpaceWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_colorSpacePreset = new QLabel(ColorSpaceWidget);
        label_colorSpacePreset->setObjectName(QString::fromUtf8("label_colorSpacePreset"));
        label_colorSpacePreset->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(label_colorSpacePreset, 0, 0, 1, 1);

        comboBox_colorSpacePreset = new QComboBox(ColorSpaceWidget);
        comboBox_colorSpacePreset->setObjectName(QString::fromUtf8("comboBox_colorSpacePreset"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox_colorSpacePreset->sizePolicy().hasHeightForWidth());
        comboBox_colorSpacePreset->setSizePolicy(sizePolicy);

        gridLayout->addWidget(comboBox_colorSpacePreset, 0, 1, 1, 2);

        tabs_colorSpaceTabs = new QTabWidget(ColorSpaceWidget);
        tabs_colorSpaceTabs->setObjectName(QString::fromUtf8("tabs_colorSpaceTabs"));
        tab_whitepoint = new QWidget();
        tab_whitepoint->setObjectName(QString::fromUtf8("tab_whitepoint"));
        gridLayout_15 = new QGridLayout(tab_whitepoint);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        gridLayout_15->setContentsMargins(12, -1, 12, 12);
        gridLayout_28 = new QGridLayout();
        gridLayout_28->setObjectName(QString::fromUtf8("gridLayout_28"));
        label_whitePointPreset = new QLabel(tab_whitepoint);
        label_whitePointPreset->setObjectName(QString::fromUtf8("label_whitePointPreset"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_whitePointPreset->sizePolicy().hasHeightForWidth());
        label_whitePointPreset->setSizePolicy(sizePolicy1);

        gridLayout_28->addWidget(label_whitePointPreset, 0, 0, 1, 1);

        comboBox_whitePointPreset = new QComboBox(tab_whitepoint);
        comboBox_whitePointPreset->setObjectName(QString::fromUtf8("comboBox_whitePointPreset"));

        gridLayout_28->addWidget(comboBox_whitePointPreset, 0, 1, 1, 3);

        label_whitePointX = new QLabel(tab_whitepoint);
        label_whitePointX->setObjectName(QString::fromUtf8("label_whitePointX"));

        gridLayout_28->addWidget(label_whitePointX, 1, 0, 1, 2);

        slider_whitePointX = new QSlider(tab_whitepoint);
        slider_whitePointX->setObjectName(QString::fromUtf8("slider_whitePointX"));
        slider_whitePointX->setMaximum(512);
        slider_whitePointX->setOrientation(Qt::Horizontal);

        gridLayout_28->addWidget(slider_whitePointX, 1, 2, 1, 1);

        spinBox_whitePointX = new QDoubleSpinBox(tab_whitepoint);
        spinBox_whitePointX->setObjectName(QString::fromUtf8("spinBox_whitePointX"));
        spinBox_whitePointX->setKeyboardTracking(false);
        spinBox_whitePointX->setDecimals(3);
        spinBox_whitePointX->setMaximum(1);
        spinBox_whitePointX->setSingleStep(0.01);

        gridLayout_28->addWidget(spinBox_whitePointX, 1, 3, 1, 1);

        label_whtePointY = new QLabel(tab_whitepoint);
        label_whtePointY->setObjectName(QString::fromUtf8("label_whtePointY"));

        gridLayout_28->addWidget(label_whtePointY, 2, 0, 1, 2);

        slider_whitePointY = new QSlider(tab_whitepoint);
        slider_whitePointY->setObjectName(QString::fromUtf8("slider_whitePointY"));
        slider_whitePointY->setMaximum(512);
        slider_whitePointY->setOrientation(Qt::Horizontal);

        gridLayout_28->addWidget(slider_whitePointY, 2, 2, 1, 1);

        spinBox_whitePointY = new QDoubleSpinBox(tab_whitepoint);
        spinBox_whitePointY->setObjectName(QString::fromUtf8("spinBox_whitePointY"));
        spinBox_whitePointY->setKeyboardTracking(false);
        spinBox_whitePointY->setDecimals(3);
        spinBox_whitePointY->setMaximum(1);
        spinBox_whitePointY->setSingleStep(0.01);

        gridLayout_28->addWidget(spinBox_whitePointY, 2, 3, 1, 1);


        gridLayout_15->addLayout(gridLayout_28, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_15->addItem(verticalSpacer_2, 3, 0, 1, 1);

        checkbox_precisionEdit = new QCheckBox(tab_whitepoint);
        checkbox_precisionEdit->setObjectName(QString::fromUtf8("checkbox_precisionEdit"));
        checkbox_precisionEdit->setEnabled(true);
        checkbox_precisionEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_15->addWidget(checkbox_precisionEdit, 2, 0, 1, 1);

        tabs_colorSpaceTabs->addTab(tab_whitepoint, QString());
        tab_rgb = new QWidget();
        tab_rgb->setObjectName(QString::fromUtf8("tab_rgb"));
        gridLayout_14 = new QGridLayout(tab_rgb);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        gridLayout_14->setContentsMargins(12, -1, 12, 12);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_rgbXY = new QLabel(tab_rgb);
        label_rgbXY->setObjectName(QString::fromUtf8("label_rgbXY"));

        gridLayout_2->addWidget(label_rgbXY, 0, 0, 1, 2);

        slider_redX = new QSlider(tab_rgb);
        slider_redX->setObjectName(QString::fromUtf8("slider_redX"));
        slider_redX->setMaximum(512);
        slider_redX->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(slider_redX, 1, 0, 1, 1);

        spinBox_redX = new QDoubleSpinBox(tab_rgb);
        spinBox_redX->setObjectName(QString::fromUtf8("spinBox_redX"));
        spinBox_redX->setKeyboardTracking(false);
        spinBox_redX->setDecimals(3);
        spinBox_redX->setMaximum(1);
        spinBox_redX->setSingleStep(0.01);

        gridLayout_2->addWidget(spinBox_redX, 1, 1, 1, 1);

        slider_redY = new QSlider(tab_rgb);
        slider_redY->setObjectName(QString::fromUtf8("slider_redY"));
        slider_redY->setMaximum(512);
        slider_redY->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(slider_redY, 1, 2, 1, 1);

        spinBox_redY = new QDoubleSpinBox(tab_rgb);
        spinBox_redY->setObjectName(QString::fromUtf8("spinBox_redY"));
        spinBox_redY->setKeyboardTracking(false);
        spinBox_redY->setDecimals(3);
        spinBox_redY->setMaximum(1);
        spinBox_redY->setSingleStep(0.01);

        gridLayout_2->addWidget(spinBox_redY, 1, 3, 1, 1);

        slider_greenX = new QSlider(tab_rgb);
        slider_greenX->setObjectName(QString::fromUtf8("slider_greenX"));
        slider_greenX->setMaximum(512);
        slider_greenX->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(slider_greenX, 2, 0, 1, 1);

        spinBox_greenX = new QDoubleSpinBox(tab_rgb);
        spinBox_greenX->setObjectName(QString::fromUtf8("spinBox_greenX"));
        spinBox_greenX->setKeyboardTracking(false);
        spinBox_greenX->setDecimals(3);
        spinBox_greenX->setMaximum(1);
        spinBox_greenX->setSingleStep(0.01);

        gridLayout_2->addWidget(spinBox_greenX, 2, 1, 1, 1);

        slider_greenY = new QSlider(tab_rgb);
        slider_greenY->setObjectName(QString::fromUtf8("slider_greenY"));
        slider_greenY->setMaximum(512);
        slider_greenY->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(slider_greenY, 2, 2, 1, 1);

        spinBox_greenY = new QDoubleSpinBox(tab_rgb);
        spinBox_greenY->setObjectName(QString::fromUtf8("spinBox_greenY"));
        spinBox_greenY->setKeyboardTracking(false);
        spinBox_greenY->setDecimals(3);
        spinBox_greenY->setMaximum(1);
        spinBox_greenY->setSingleStep(0.01);

        gridLayout_2->addWidget(spinBox_greenY, 2, 3, 1, 1);

        slider_blueX = new QSlider(tab_rgb);
        slider_blueX->setObjectName(QString::fromUtf8("slider_blueX"));
        slider_blueX->setMaximum(512);
        slider_blueX->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(slider_blueX, 3, 0, 1, 1);

        spinBox_blueX = new QDoubleSpinBox(tab_rgb);
        spinBox_blueX->setObjectName(QString::fromUtf8("spinBox_blueX"));
        spinBox_blueX->setKeyboardTracking(false);
        spinBox_blueX->setDecimals(3);
        spinBox_blueX->setMaximum(1);
        spinBox_blueX->setSingleStep(0.01);

        gridLayout_2->addWidget(spinBox_blueX, 3, 1, 1, 1);

        slider_blueY = new QSlider(tab_rgb);
        slider_blueY->setObjectName(QString::fromUtf8("slider_blueY"));
        slider_blueY->setMaximum(512);
        slider_blueY->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(slider_blueY, 3, 2, 1, 1);

        spinBox_blueY = new QDoubleSpinBox(tab_rgb);
        spinBox_blueY->setObjectName(QString::fromUtf8("spinBox_blueY"));
        spinBox_blueY->setKeyboardTracking(false);
        spinBox_blueY->setDecimals(3);
        spinBox_blueY->setMinimum(0);
        spinBox_blueY->setMaximum(1);
        spinBox_blueY->setSingleStep(0.01);
        spinBox_blueY->setValue(0);

        gridLayout_2->addWidget(spinBox_blueY, 3, 3, 1, 1);


        gridLayout_14->addLayout(gridLayout_2, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_14->addItem(verticalSpacer, 1, 0, 1, 1);

        tabs_colorSpaceTabs->addTab(tab_rgb, QString());
        tab_temperature = new QWidget();
        tab_temperature->setObjectName(QString::fromUtf8("tab_temperature"));
        gridLayout_4 = new QGridLayout(tab_temperature);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_whitePointTemp = new QLabel(tab_temperature);
        label_whitePointTemp->setObjectName(QString::fromUtf8("label_whitePointTemp"));

        gridLayout_3->addWidget(label_whitePointTemp, 1, 0, 1, 1);

        slider_temperature = new QSlider(tab_temperature);
        slider_temperature->setObjectName(QString::fromUtf8("slider_temperature"));
        slider_temperature->setMinimum(1900);
        slider_temperature->setMaximum(25000);
        slider_temperature->setSingleStep(100);
        slider_temperature->setPageStep(1000);
        slider_temperature->setSliderPosition(6504);
        slider_temperature->setOrientation(Qt::Horizontal);
        slider_temperature->setTickPosition(QSlider::TicksBelow);
        slider_temperature->setTickInterval(1000);

        gridLayout_3->addWidget(slider_temperature, 1, 1, 1, 1);

        spinBox_temperature = new QDoubleSpinBox(tab_temperature);
        spinBox_temperature->setObjectName(QString::fromUtf8("spinBox_temperature"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(spinBox_temperature->sizePolicy().hasHeightForWidth());
        spinBox_temperature->setSizePolicy(sizePolicy2);
        spinBox_temperature->setMinimumSize(QSize(0, 0));
        spinBox_temperature->setWrapping(false);
        spinBox_temperature->setFrame(true);
        spinBox_temperature->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBox_temperature->setSuffix(QString::fromUtf8(" K"));
        spinBox_temperature->setDecimals(0);
        spinBox_temperature->setMinimum(1900);
        spinBox_temperature->setMaximum(25000);
        spinBox_temperature->setSingleStep(100);
        spinBox_temperature->setValue(6504);

        gridLayout_3->addWidget(spinBox_temperature, 1, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 147, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_3, 2, 0, 1, 1);

        label_whitePointTempNotice = new QLabel(tab_temperature);
        label_whitePointTempNotice->setObjectName(QString::fromUtf8("label_whitePointTempNotice"));
        label_whitePointTempNotice->setWordWrap(true);

        gridLayout_4->addWidget(label_whitePointTempNotice, 1, 0, 1, 1);

        tabs_colorSpaceTabs->addTab(tab_temperature, QString());

        gridLayout->addWidget(tabs_colorSpaceTabs, 1, 0, 1, 3);


        verticalLayout->addLayout(gridLayout);

#ifndef QT_NO_SHORTCUT
        label_whitePointPreset->setBuddy(comboBox_whitePointPreset);
        label_whitePointX->setBuddy(slider_whitePointX);
        label_whtePointY->setBuddy(slider_whitePointY);
#endif // QT_NO_SHORTCUT

        retranslateUi(ColorSpaceWidget);

        tabs_colorSpaceTabs->setCurrentIndex(0);
        comboBox_whitePointPreset->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ColorSpaceWidget);
    } // setupUi

    void retranslateUi(QWidget *ColorSpaceWidget)
    {
        ColorSpaceWidget->setWindowTitle(QApplication::translate("ColorSpaceWidget", "Form", 0, QApplication::UnicodeUTF8));
        label_colorSpacePreset->setText(QApplication::translate("ColorSpaceWidget", "Preset", 0, QApplication::UnicodeUTF8));
        comboBox_colorSpacePreset->clear();
        comboBox_colorSpacePreset->insertItems(0, QStringList()
         << QApplication::translate("ColorSpaceWidget", "User-defined", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ColorSpaceWidget", "SMPTE (D65)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ColorSpaceWidget", "sRGB - HDTV (ITU-R BT.709-5)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ColorSpaceWidget", "ROMM RGB", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ColorSpaceWidget", "Adobe RGB 98", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ColorSpaceWidget", "Apple RGB", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ColorSpaceWidget", "NTSC (FCC 1953)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ColorSpaceWidget", "NTSC (1979) (SMPTE C/-RP 145)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ColorSpaceWidget", "PAL/SECAM (EBU 3213)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ColorSpaceWidget", "CIE (1931) E", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        comboBox_colorSpacePreset->setToolTip(QApplication::translate("ColorSpaceWidget", "Select ColorSpace Preset", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_whitePointPreset->setText(QApplication::translate("ColorSpaceWidget", "Preset", 0, QApplication::UnicodeUTF8));
        comboBox_whitePointPreset->clear();
        comboBox_whitePointPreset->insertItems(0, QStringList()
         << QApplication::translate("ColorSpaceWidget", "User-defined", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ColorSpaceWidget", "A - incandescent", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ColorSpaceWidget", "B - sunlight", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ColorSpaceWidget", "C - daylight", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ColorSpaceWidget", "D50 - daylight, 5003K", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ColorSpaceWidget", "D55 - daylight, 5503K", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ColorSpaceWidget", "D65 - daylight, 6504K", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ColorSpaceWidget", "D75 - daylight, 7504K", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ColorSpaceWidget", "E - equal energy", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ColorSpaceWidget", "F2 - standard fluorescent", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ColorSpaceWidget", "F7 - broadband fluorescent", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ColorSpaceWidget", "F11 - narrow threeband fluorescent", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ColorSpaceWidget", "9300K", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ColorSpaceWidget", "D65 (SMPTE)", 0, QApplication::UnicodeUTF8)
        );
        label_whitePointX->setText(QApplication::translate("ColorSpaceWidget", "White X", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        slider_whitePointX->setToolTip(QApplication::translate("ColorSpaceWidget", "Adjust Whitepoint X", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinBox_whitePointX->setToolTip(QApplication::translate("ColorSpaceWidget", "White X", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_whtePointY->setText(QApplication::translate("ColorSpaceWidget", "White Y", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        slider_whitePointY->setToolTip(QApplication::translate("ColorSpaceWidget", "Adjust Whitepoint Y", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinBox_whitePointY->setToolTip(QApplication::translate("ColorSpaceWidget", "White Y", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        checkbox_precisionEdit->setToolTip(QApplication::translate("ColorSpaceWidget", "Toggle Adjustment 2th/4th decimal", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        checkbox_precisionEdit->setText(QApplication::translate("ColorSpaceWidget", "High Precision Editing", 0, QApplication::UnicodeUTF8));
        tabs_colorSpaceTabs->setTabText(tabs_colorSpaceTabs->indexOf(tab_whitepoint), QApplication::translate("ColorSpaceWidget", "Whitepoint", 0, QApplication::UnicodeUTF8));
        label_rgbXY->setText(QApplication::translate("ColorSpaceWidget", "Red/Green/Blue XY", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        slider_redX->setToolTip(QApplication::translate("ColorSpaceWidget", "Red X", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinBox_redX->setToolTip(QApplication::translate("ColorSpaceWidget", "Red X", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        slider_redY->setToolTip(QApplication::translate("ColorSpaceWidget", "Red Y", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinBox_redY->setToolTip(QApplication::translate("ColorSpaceWidget", "Red Y", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        slider_greenX->setToolTip(QApplication::translate("ColorSpaceWidget", "Green X", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinBox_greenX->setToolTip(QApplication::translate("ColorSpaceWidget", "Green X", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        slider_greenY->setToolTip(QApplication::translate("ColorSpaceWidget", "Green Y", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinBox_greenY->setToolTip(QApplication::translate("ColorSpaceWidget", "Green Y", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        slider_blueX->setToolTip(QApplication::translate("ColorSpaceWidget", "Blue X", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinBox_blueX->setToolTip(QApplication::translate("ColorSpaceWidget", "Blue X", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        slider_blueY->setToolTip(QApplication::translate("ColorSpaceWidget", "Blue Y", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinBox_blueY->setToolTip(QApplication::translate("ColorSpaceWidget", "Blue Y", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        tabs_colorSpaceTabs->setTabText(tabs_colorSpaceTabs->indexOf(tab_rgb), QApplication::translate("ColorSpaceWidget", "RGB", 0, QApplication::UnicodeUTF8));
        label_whitePointTemp->setText(QApplication::translate("ColorSpaceWidget", "Temperature", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        slider_temperature->setToolTip(QApplication::translate("ColorSpaceWidget", "Correlated color temperature", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinBox_temperature->setToolTip(QApplication::translate("ColorSpaceWidget", "Correlated color temperature", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_whitePointTempNotice->setText(QApplication::translate("ColorSpaceWidget", "Note: Conversion between xy coordinates and correlated color temperature is approximate, and may be poor for data outside of the range spanned by the CIE A to D75 illuminants.", 0, QApplication::UnicodeUTF8));
        tabs_colorSpaceTabs->setTabText(tabs_colorSpaceTabs->indexOf(tab_temperature), QApplication::translate("ColorSpaceWidget", "Temperature", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ColorSpaceWidget: public Ui_ColorSpaceWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORSPACE_H
