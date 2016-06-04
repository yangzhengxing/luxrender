/********************************************************************************
** Form generated from reading UI file 'tonemap.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TONEMAP_H
#define UI_TONEMAP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ToneMapWidget
{
public:
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout_31;
    QLabel *label_kernel;
    QComboBox *comboBox_kernel;
    QFrame *frame_toneMapReinhard;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_25;
    QLabel *label_prescale;
    QSlider *slider_prescale;
    QDoubleSpinBox *spinBox_prescale;
    QLabel *label_postscale;
    QSlider *slider_postscale;
    QDoubleSpinBox *spinBox_postscale;
    QLabel *label_burn;
    QSlider *slider_burn;
    QDoubleSpinBox *spinBox_burn;
    QFrame *frame_toneMapLinear;
    QVBoxLayout *verticalLayout_16;
    QGridLayout *gridLayout_17;
    QLabel *label_sensitivity;
    QSlider *slider_sensitivity;
    QDoubleSpinBox *spinBox_sensitivity;
    QLabel *label_exposure;
    QSlider *slider_exposure;
    QDoubleSpinBox *spinBox_exposure;
    QLabel *label_fstop;
    QSlider *slider_fstop;
    QDoubleSpinBox *spinBox_fstop;
    QLabel *label_gamma_linear;
    QSlider *slider_gamma_linear;
    QDoubleSpinBox *spinBox_gamma_linear;
    QComboBox *comboBox_SensitivityPreset;
    QComboBox *comboBox_ExposurePreset;
    QComboBox *comboBox_FStopPreset;
    QLabel *label_preset;
    QPushButton *button_linearEstimate;
    QFrame *frame_toneMapContrast;
    QVBoxLayout *verticalLayout_17;
    QGridLayout *gridLayout_24;
    QLabel *label_ywa;
    QSlider *slider_ywa;
    QDoubleSpinBox *spinBox_ywa;
    QFrame *frame_toneMapFalse;
    QVBoxLayout *verticalLayout_18;
    QGridLayout *gridLayout_26;
    QLabel *label_false_max;
    QLabel *label_false_valuemax;
    QLabel *label_false_valuemaxSat;
    QLineEdit *lineEdit_false_valuemaxsat;
    QLabel *label_false_min;
    QLabel *label_false_valuemin;
    QLabel *label_false_valueminsat;
    QLineEdit *lineEdit_false_valueminsat;
    QLabel *label_false_colorscale;
    QComboBox *comboBox_false_colorscale;
    QLabel *label_false_Method;
    QComboBox *comboBox_false_Method;
    QLabel *label_false_numbervalue;
    QLineEdit *lineEdit_false_legendeTest;
    QLabel *label_false_averageluminance;
    QLabel *label_false_valueaverageluminance;
    QLabel *label_false_averageluminousemittance;
    QLabel *label_false_valueaverageluminousemittance;
    QLabel *Qlabel_image_false_legende;
    QLabel *label_clampMethod;
    QComboBox *comboBox_clampMethod;

    void setupUi(QWidget *ToneMapWidget)
    {
        if (ToneMapWidget->objectName().isEmpty())
            ToneMapWidget->setObjectName(QString::fromUtf8("ToneMapWidget"));
        ToneMapWidget->resize(498, 544);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ToneMapWidget->sizePolicy().hasHeightForWidth());
        ToneMapWidget->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(ToneMapWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gridLayout_31 = new QGridLayout();
        gridLayout_31->setObjectName(QString::fromUtf8("gridLayout_31"));
        gridLayout_31->setSizeConstraint(QLayout::SetNoConstraint);
        label_kernel = new QLabel(ToneMapWidget);
        label_kernel->setObjectName(QString::fromUtf8("label_kernel"));
        label_kernel->setMaximumSize(QSize(50, 16777215));

        gridLayout_31->addWidget(label_kernel, 0, 0, 1, 1);

        comboBox_kernel = new QComboBox(ToneMapWidget);
        comboBox_kernel->setObjectName(QString::fromUtf8("comboBox_kernel"));

        gridLayout_31->addWidget(comboBox_kernel, 0, 1, 1, 1);

        frame_toneMapReinhard = new QFrame(ToneMapWidget);
        frame_toneMapReinhard->setObjectName(QString::fromUtf8("frame_toneMapReinhard"));
        frame_toneMapReinhard->setFrameShape(QFrame::StyledPanel);
        frame_toneMapReinhard->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_toneMapReinhard);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_25 = new QGridLayout();
        gridLayout_25->setObjectName(QString::fromUtf8("gridLayout_25"));
        label_prescale = new QLabel(frame_toneMapReinhard);
        label_prescale->setObjectName(QString::fromUtf8("label_prescale"));

        gridLayout_25->addWidget(label_prescale, 0, 0, 1, 1);

        slider_prescale = new QSlider(frame_toneMapReinhard);
        slider_prescale->setObjectName(QString::fromUtf8("slider_prescale"));
        slider_prescale->setMaximum(512);
        slider_prescale->setOrientation(Qt::Horizontal);

        gridLayout_25->addWidget(slider_prescale, 0, 1, 1, 1);

        spinBox_prescale = new QDoubleSpinBox(frame_toneMapReinhard);
        spinBox_prescale->setObjectName(QString::fromUtf8("spinBox_prescale"));
        spinBox_prescale->setKeyboardTracking(false);
        spinBox_prescale->setDecimals(3);
        spinBox_prescale->setMaximum(8);
        spinBox_prescale->setSingleStep(0.1);

        gridLayout_25->addWidget(spinBox_prescale, 0, 2, 1, 1);

        label_postscale = new QLabel(frame_toneMapReinhard);
        label_postscale->setObjectName(QString::fromUtf8("label_postscale"));

        gridLayout_25->addWidget(label_postscale, 1, 0, 1, 1);

        slider_postscale = new QSlider(frame_toneMapReinhard);
        slider_postscale->setObjectName(QString::fromUtf8("slider_postscale"));
        slider_postscale->setMaximum(512);
        slider_postscale->setOrientation(Qt::Horizontal);

        gridLayout_25->addWidget(slider_postscale, 1, 1, 1, 1);

        spinBox_postscale = new QDoubleSpinBox(frame_toneMapReinhard);
        spinBox_postscale->setObjectName(QString::fromUtf8("spinBox_postscale"));
        spinBox_postscale->setKeyboardTracking(false);
        spinBox_postscale->setDecimals(3);
        spinBox_postscale->setMaximum(8);
        spinBox_postscale->setSingleStep(0.1);

        gridLayout_25->addWidget(spinBox_postscale, 1, 2, 1, 1);

        label_burn = new QLabel(frame_toneMapReinhard);
        label_burn->setObjectName(QString::fromUtf8("label_burn"));

        gridLayout_25->addWidget(label_burn, 2, 0, 1, 1);

        slider_burn = new QSlider(frame_toneMapReinhard);
        slider_burn->setObjectName(QString::fromUtf8("slider_burn"));
        slider_burn->setMaximum(512);
        slider_burn->setOrientation(Qt::Horizontal);

        gridLayout_25->addWidget(slider_burn, 2, 1, 1, 1);

        spinBox_burn = new QDoubleSpinBox(frame_toneMapReinhard);
        spinBox_burn->setObjectName(QString::fromUtf8("spinBox_burn"));
        spinBox_burn->setKeyboardTracking(false);
        spinBox_burn->setDecimals(3);
        spinBox_burn->setMaximum(12);
        spinBox_burn->setSingleStep(0.1);

        gridLayout_25->addWidget(spinBox_burn, 2, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_25);


        gridLayout_31->addWidget(frame_toneMapReinhard, 1, 0, 1, 2);

        frame_toneMapLinear = new QFrame(ToneMapWidget);
        frame_toneMapLinear->setObjectName(QString::fromUtf8("frame_toneMapLinear"));
        frame_toneMapLinear->setFrameShape(QFrame::StyledPanel);
        frame_toneMapLinear->setFrameShadow(QFrame::Raised);
        verticalLayout_16 = new QVBoxLayout(frame_toneMapLinear);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        gridLayout_17 = new QGridLayout();
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        label_sensitivity = new QLabel(frame_toneMapLinear);
        label_sensitivity->setObjectName(QString::fromUtf8("label_sensitivity"));

        gridLayout_17->addWidget(label_sensitivity, 0, 0, 1, 1);

        slider_sensitivity = new QSlider(frame_toneMapLinear);
        slider_sensitivity->setObjectName(QString::fromUtf8("slider_sensitivity"));
        slider_sensitivity->setMaximum(512);
        slider_sensitivity->setOrientation(Qt::Horizontal);

        gridLayout_17->addWidget(slider_sensitivity, 0, 1, 1, 1);

        spinBox_sensitivity = new QDoubleSpinBox(frame_toneMapLinear);
        spinBox_sensitivity->setObjectName(QString::fromUtf8("spinBox_sensitivity"));
        spinBox_sensitivity->setKeyboardTracking(false);
        spinBox_sensitivity->setDecimals(1);
        spinBox_sensitivity->setMaximum(6400);
        spinBox_sensitivity->setSingleStep(10);

        gridLayout_17->addWidget(spinBox_sensitivity, 0, 3, 1, 1);

        label_exposure = new QLabel(frame_toneMapLinear);
        label_exposure->setObjectName(QString::fromUtf8("label_exposure"));

        gridLayout_17->addWidget(label_exposure, 1, 0, 1, 1);

        slider_exposure = new QSlider(frame_toneMapLinear);
        slider_exposure->setObjectName(QString::fromUtf8("slider_exposure"));
        slider_exposure->setMaximum(512);
        slider_exposure->setOrientation(Qt::Horizontal);

        gridLayout_17->addWidget(slider_exposure, 1, 1, 1, 1);

        spinBox_exposure = new QDoubleSpinBox(frame_toneMapLinear);
        spinBox_exposure->setObjectName(QString::fromUtf8("spinBox_exposure"));
        spinBox_exposure->setKeyboardTracking(false);
        spinBox_exposure->setDecimals(3);
        spinBox_exposure->setMinimum(0);
        spinBox_exposure->setMaximum(100);
        spinBox_exposure->setSingleStep(0.01);

        gridLayout_17->addWidget(spinBox_exposure, 1, 3, 1, 1);

        label_fstop = new QLabel(frame_toneMapLinear);
        label_fstop->setObjectName(QString::fromUtf8("label_fstop"));

        gridLayout_17->addWidget(label_fstop, 2, 0, 1, 1);

        slider_fstop = new QSlider(frame_toneMapLinear);
        slider_fstop->setObjectName(QString::fromUtf8("slider_fstop"));
        slider_fstop->setMaximum(512);
        slider_fstop->setOrientation(Qt::Horizontal);

        gridLayout_17->addWidget(slider_fstop, 2, 1, 1, 1);

        spinBox_fstop = new QDoubleSpinBox(frame_toneMapLinear);
        spinBox_fstop->setObjectName(QString::fromUtf8("spinBox_fstop"));
        spinBox_fstop->setKeyboardTracking(false);
        spinBox_fstop->setMaximum(128);
        spinBox_fstop->setSingleStep(1);

        gridLayout_17->addWidget(spinBox_fstop, 2, 3, 1, 1);

        label_gamma_linear = new QLabel(frame_toneMapLinear);
        label_gamma_linear->setObjectName(QString::fromUtf8("label_gamma_linear"));

        gridLayout_17->addWidget(label_gamma_linear, 3, 0, 1, 1);

        slider_gamma_linear = new QSlider(frame_toneMapLinear);
        slider_gamma_linear->setObjectName(QString::fromUtf8("slider_gamma_linear"));
        slider_gamma_linear->setMaximum(512);
        slider_gamma_linear->setOrientation(Qt::Horizontal);

        gridLayout_17->addWidget(slider_gamma_linear, 3, 1, 1, 1);

        spinBox_gamma_linear = new QDoubleSpinBox(frame_toneMapLinear);
        spinBox_gamma_linear->setObjectName(QString::fromUtf8("spinBox_gamma_linear"));
        spinBox_gamma_linear->setKeyboardTracking(false);
        spinBox_gamma_linear->setMaximum(5);
        spinBox_gamma_linear->setSingleStep(0.2);

        gridLayout_17->addWidget(spinBox_gamma_linear, 3, 3, 1, 1);

        comboBox_SensitivityPreset = new QComboBox(frame_toneMapLinear);
        comboBox_SensitivityPreset->setObjectName(QString::fromUtf8("comboBox_SensitivityPreset"));
        comboBox_SensitivityPreset->setMinimumSize(QSize(0, 0));
        comboBox_SensitivityPreset->setMaximumSize(QSize(80, 16777215));
        QFont font;
        font.setPointSize(11);
        comboBox_SensitivityPreset->setFont(font);
        comboBox_SensitivityPreset->setMaxVisibleItems(26);

        gridLayout_17->addWidget(comboBox_SensitivityPreset, 0, 2, 1, 1);

        comboBox_ExposurePreset = new QComboBox(frame_toneMapLinear);
        comboBox_ExposurePreset->setObjectName(QString::fromUtf8("comboBox_ExposurePreset"));
        comboBox_ExposurePreset->setMaximumSize(QSize(80, 16777215));
        comboBox_ExposurePreset->setFont(font);
        comboBox_ExposurePreset->setMaxVisibleItems(17);

        gridLayout_17->addWidget(comboBox_ExposurePreset, 1, 2, 1, 1);

        comboBox_FStopPreset = new QComboBox(frame_toneMapLinear);
        comboBox_FStopPreset->setObjectName(QString::fromUtf8("comboBox_FStopPreset"));
        comboBox_FStopPreset->setMaximumSize(QSize(80, 16777215));
        comboBox_FStopPreset->setFont(font);
        comboBox_FStopPreset->setMaxVisibleItems(17);

        gridLayout_17->addWidget(comboBox_FStopPreset, 2, 2, 1, 1);

        label_preset = new QLabel(frame_toneMapLinear);
        label_preset->setObjectName(QString::fromUtf8("label_preset"));
        label_preset->setAlignment(Qt::AlignCenter);

        gridLayout_17->addWidget(label_preset, 3, 2, 1, 1);

        button_linearEstimate = new QPushButton(frame_toneMapLinear);
        button_linearEstimate->setObjectName(QString::fromUtf8("button_linearEstimate"));

        gridLayout_17->addWidget(button_linearEstimate, 4, 2, 1, 2);


        verticalLayout_16->addLayout(gridLayout_17);


        gridLayout_31->addWidget(frame_toneMapLinear, 2, 0, 1, 2);

        frame_toneMapContrast = new QFrame(ToneMapWidget);
        frame_toneMapContrast->setObjectName(QString::fromUtf8("frame_toneMapContrast"));
        frame_toneMapContrast->setFrameShape(QFrame::StyledPanel);
        frame_toneMapContrast->setFrameShadow(QFrame::Raised);
        verticalLayout_17 = new QVBoxLayout(frame_toneMapContrast);
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        gridLayout_24 = new QGridLayout();
        gridLayout_24->setObjectName(QString::fromUtf8("gridLayout_24"));
        label_ywa = new QLabel(frame_toneMapContrast);
        label_ywa->setObjectName(QString::fromUtf8("label_ywa"));

        gridLayout_24->addWidget(label_ywa, 0, 0, 1, 2);

        slider_ywa = new QSlider(frame_toneMapContrast);
        slider_ywa->setObjectName(QString::fromUtf8("slider_ywa"));
        slider_ywa->setMaximum(512);
        slider_ywa->setOrientation(Qt::Horizontal);

        gridLayout_24->addWidget(slider_ywa, 1, 0, 1, 1);

        spinBox_ywa = new QDoubleSpinBox(frame_toneMapContrast);
        spinBox_ywa->setObjectName(QString::fromUtf8("spinBox_ywa"));
        spinBox_ywa->setKeyboardTracking(false);
        spinBox_ywa->setDecimals(4);
        spinBox_ywa->setMinimum(0);
        spinBox_ywa->setMaximum(10000);

        gridLayout_24->addWidget(spinBox_ywa, 1, 1, 1, 1);


        verticalLayout_17->addLayout(gridLayout_24);


        gridLayout_31->addWidget(frame_toneMapContrast, 3, 0, 1, 2);

        frame_toneMapFalse = new QFrame(ToneMapWidget);
        frame_toneMapFalse->setObjectName(QString::fromUtf8("frame_toneMapFalse"));
        frame_toneMapFalse->setFrameShape(QFrame::StyledPanel);
        frame_toneMapFalse->setFrameShadow(QFrame::Raised);
        verticalLayout_18 = new QVBoxLayout(frame_toneMapFalse);
        verticalLayout_18->setObjectName(QString::fromUtf8("verticalLayout_18"));
        gridLayout_26 = new QGridLayout();
        gridLayout_26->setObjectName(QString::fromUtf8("gridLayout_26"));
        gridLayout_26->setHorizontalSpacing(5);
        gridLayout_26->setVerticalSpacing(2);
        label_false_max = new QLabel(frame_toneMapFalse);
        label_false_max->setObjectName(QString::fromUtf8("label_false_max"));

        gridLayout_26->addWidget(label_false_max, 0, 0, 1, 3);

        label_false_valuemax = new QLabel(frame_toneMapFalse);
        label_false_valuemax->setObjectName(QString::fromUtf8("label_false_valuemax"));

        gridLayout_26->addWidget(label_false_valuemax, 0, 2, 1, 4);

        label_false_valuemaxSat = new QLabel(frame_toneMapFalse);
        label_false_valuemaxSat->setObjectName(QString::fromUtf8("label_false_valuemaxSat"));

        gridLayout_26->addWidget(label_false_valuemaxSat, 1, 0, 1, 3);

        lineEdit_false_valuemaxsat = new QLineEdit(frame_toneMapFalse);
        lineEdit_false_valuemaxsat->setObjectName(QString::fromUtf8("lineEdit_false_valuemaxsat"));

        gridLayout_26->addWidget(lineEdit_false_valuemaxsat, 1, 2, 1, 2);

        label_false_min = new QLabel(frame_toneMapFalse);
        label_false_min->setObjectName(QString::fromUtf8("label_false_min"));

        gridLayout_26->addWidget(label_false_min, 2, 0, 1, 2);

        label_false_valuemin = new QLabel(frame_toneMapFalse);
        label_false_valuemin->setObjectName(QString::fromUtf8("label_false_valuemin"));

        gridLayout_26->addWidget(label_false_valuemin, 2, 2, 1, 2);

        label_false_valueminsat = new QLabel(frame_toneMapFalse);
        label_false_valueminsat->setObjectName(QString::fromUtf8("label_false_valueminsat"));

        gridLayout_26->addWidget(label_false_valueminsat, 3, 0, 1, 2);

        lineEdit_false_valueminsat = new QLineEdit(frame_toneMapFalse);
        lineEdit_false_valueminsat->setObjectName(QString::fromUtf8("lineEdit_false_valueminsat"));

        gridLayout_26->addWidget(lineEdit_false_valueminsat, 3, 2, 1, 2);

        label_false_colorscale = new QLabel(frame_toneMapFalse);
        label_false_colorscale->setObjectName(QString::fromUtf8("label_false_colorscale"));

        gridLayout_26->addWidget(label_false_colorscale, 5, 0, 1, 2);

        comboBox_false_colorscale = new QComboBox(frame_toneMapFalse);
        comboBox_false_colorscale->setObjectName(QString::fromUtf8("comboBox_false_colorscale"));

        gridLayout_26->addWidget(comboBox_false_colorscale, 5, 2, 1, 2);

        label_false_Method = new QLabel(frame_toneMapFalse);
        label_false_Method->setObjectName(QString::fromUtf8("label_false_Method"));

        gridLayout_26->addWidget(label_false_Method, 6, 0, 1, 2);

        comboBox_false_Method = new QComboBox(frame_toneMapFalse);
        comboBox_false_Method->setObjectName(QString::fromUtf8("comboBox_false_Method"));

        gridLayout_26->addWidget(comboBox_false_Method, 6, 2, 1, 2);

        label_false_numbervalue = new QLabel(frame_toneMapFalse);
        label_false_numbervalue->setObjectName(QString::fromUtf8("label_false_numbervalue"));

        gridLayout_26->addWidget(label_false_numbervalue, 7, 0, 1, 2);

        lineEdit_false_legendeTest = new QLineEdit(frame_toneMapFalse);
        lineEdit_false_legendeTest->setObjectName(QString::fromUtf8("lineEdit_false_legendeTest"));

        gridLayout_26->addWidget(lineEdit_false_legendeTest, 7, 2, 1, 2);

        label_false_averageluminance = new QLabel(frame_toneMapFalse);
        label_false_averageluminance->setObjectName(QString::fromUtf8("label_false_averageluminance"));

        gridLayout_26->addWidget(label_false_averageluminance, 9, 0, 1, 2);

        label_false_valueaverageluminance = new QLabel(frame_toneMapFalse);
        label_false_valueaverageluminance->setObjectName(QString::fromUtf8("label_false_valueaverageluminance"));

        gridLayout_26->addWidget(label_false_valueaverageluminance, 9, 2, 1, 2);

        label_false_averageluminousemittance = new QLabel(frame_toneMapFalse);
        label_false_averageluminousemittance->setObjectName(QString::fromUtf8("label_false_averageluminousemittance"));

        gridLayout_26->addWidget(label_false_averageluminousemittance, 10, 0, 1, 2);

        label_false_valueaverageluminousemittance = new QLabel(frame_toneMapFalse);
        label_false_valueaverageluminousemittance->setObjectName(QString::fromUtf8("label_false_valueaverageluminousemittance"));

        gridLayout_26->addWidget(label_false_valueaverageluminousemittance, 10, 2, 1, 2);

        Qlabel_image_false_legende = new QLabel(frame_toneMapFalse);
        Qlabel_image_false_legende->setObjectName(QString::fromUtf8("Qlabel_image_false_legende"));

        gridLayout_26->addWidget(Qlabel_image_false_legende, 0, 4, 11, 2);


        verticalLayout_18->addLayout(gridLayout_26);


        gridLayout_31->addWidget(frame_toneMapFalse, 4, 0, 1, 2);

        label_clampMethod = new QLabel(ToneMapWidget);
        label_clampMethod->setObjectName(QString::fromUtf8("label_clampMethod"));

        gridLayout_31->addWidget(label_clampMethod, 5, 0, 1, 1);

        comboBox_clampMethod = new QComboBox(ToneMapWidget);
        comboBox_clampMethod->setObjectName(QString::fromUtf8("comboBox_clampMethod"));

        gridLayout_31->addWidget(comboBox_clampMethod, 5, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout_31);

#ifndef QT_NO_SHORTCUT
        label_kernel->setBuddy(comboBox_kernel);
        label_prescale->setBuddy(slider_prescale);
        label_postscale->setBuddy(slider_postscale);
        label_burn->setBuddy(slider_burn);
        label_sensitivity->setBuddy(slider_prescale);
        label_exposure->setBuddy(slider_postscale);
        label_fstop->setBuddy(slider_burn);
        label_gamma_linear->setBuddy(slider_burn);
        label_ywa->setBuddy(slider_prescale);
        label_false_colorscale->setBuddy(comboBox_false_colorscale);
        label_false_Method->setBuddy(comboBox_false_Method);
        label_clampMethod->setBuddy(comboBox_clampMethod);
#endif // QT_NO_SHORTCUT

        retranslateUi(ToneMapWidget);

        comboBox_SensitivityPreset->setCurrentIndex(0);
        comboBox_ExposurePreset->setCurrentIndex(0);
        comboBox_FStopPreset->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ToneMapWidget);
    } // setupUi

    void retranslateUi(QWidget *ToneMapWidget)
    {
        ToneMapWidget->setWindowTitle(QApplication::translate("ToneMapWidget", "Form", 0, QApplication::UnicodeUTF8));
        label_kernel->setText(QApplication::translate("ToneMapWidget", "Kernel:", 0, QApplication::UnicodeUTF8));
        comboBox_kernel->clear();
        comboBox_kernel->insertItems(0, QStringList()
         << QApplication::translate("ToneMapWidget", "Reinhard / non-Linear", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "Linear", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "Contrast", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "MaxWhite", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "Auto Linear", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "False Colors", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        comboBox_kernel->setToolTip(QApplication::translate("ToneMapWidget", "Select Tonemapping Kernel", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_prescale->setText(QApplication::translate("ToneMapWidget", "Prescale", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        slider_prescale->setToolTip(QApplication::translate("ToneMapWidget", "Adjust Reinhard Prescale", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinBox_prescale->setToolTip(QApplication::translate("ToneMapWidget", "Adjust Reinhard Prescale Value", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_postscale->setText(QApplication::translate("ToneMapWidget", "Postscale", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        slider_postscale->setToolTip(QApplication::translate("ToneMapWidget", "Adjust Reinhard Postscale", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinBox_postscale->setToolTip(QApplication::translate("ToneMapWidget", "Adjust Reinhard Postscale Value", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_burn->setText(QApplication::translate("ToneMapWidget", "Burn", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        slider_burn->setToolTip(QApplication::translate("ToneMapWidget", "Adjust Reinhard Burn", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinBox_burn->setToolTip(QApplication::translate("ToneMapWidget", "Adjust Reinhard Burn Value", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_sensitivity->setText(QApplication::translate("ToneMapWidget", "Film ISO", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        slider_sensitivity->setToolTip(QApplication::translate("ToneMapWidget", "Adjust Sensitivity", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinBox_sensitivity->setToolTip(QApplication::translate("ToneMapWidget", "Adjust Sensitivity Value", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_exposure->setText(QApplication::translate("ToneMapWidget", "Shutter", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        slider_exposure->setToolTip(QApplication::translate("ToneMapWidget", "Adjust Exposure", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinBox_exposure->setToolTip(QApplication::translate("ToneMapWidget", "Adjust Exposure Value", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_fstop->setText(QApplication::translate("ToneMapWidget", "f-stop", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        slider_fstop->setToolTip(QApplication::translate("ToneMapWidget", "Adjust FStop", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinBox_fstop->setToolTip(QApplication::translate("ToneMapWidget", "Adjust FStopValue", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_gamma_linear->setText(QApplication::translate("ToneMapWidget", "Gamma", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        slider_gamma_linear->setToolTip(QApplication::translate("ToneMapWidget", "Adjust Gamma", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinBox_gamma_linear->setToolTip(QApplication::translate("ToneMapWidget", "Adjust Gamma Value", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        comboBox_SensitivityPreset->clear();
        comboBox_SensitivityPreset->insertItems(0, QStringList()
         << QApplication::translate("ToneMapWidget", "User", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "6400", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "5000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "4000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "3200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "2500", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "2000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "1600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "1250", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "1000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "800", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "640", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "500", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "400", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "320", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "250", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "160", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "125", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "100", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "80", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "64", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "50", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "40", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "32", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "25", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "20", 0, QApplication::UnicodeUTF8)
        );
        comboBox_ExposurePreset->clear();
        comboBox_ExposurePreset->insertItems(0, QStringList()
         << QApplication::translate("ToneMapWidget", "User", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "30", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "20", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "1/2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "1/4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "1/8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "1/15", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "1/30", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "1/60", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "1/125", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "1/250", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "1/500", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "1/1000", 0, QApplication::UnicodeUTF8)
        );
        comboBox_FStopPreset->clear();
        comboBox_FStopPreset->insertItems(0, QStringList()
         << QApplication::translate("ToneMapWidget", "User", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "128", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "90", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "64", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "45", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "32", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "22", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "16", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "11", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "5.6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "2.8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "1.4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "0.7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "0.5", 0, QApplication::UnicodeUTF8)
        );
        label_preset->setText(QApplication::translate("ToneMapWidget", "Presets:", 0, QApplication::UnicodeUTF8));
        button_linearEstimate->setText(QApplication::translate("ToneMapWidget", "Estimate settings", 0, QApplication::UnicodeUTF8));
        label_ywa->setText(QApplication::translate("ToneMapWidget", "Ywa (Display/World Adaptation Luminance)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        slider_ywa->setToolTip(QApplication::translate("ToneMapWidget", "Adjust Ywa", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinBox_ywa->setToolTip(QApplication::translate("ToneMapWidget", "Adjust Ywa Value", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_false_max->setText(QApplication::translate("ToneMapWidget", "Maximum: ", 0, QApplication::UnicodeUTF8));
        label_false_valuemax->setText(QApplication::translate("ToneMapWidget", "...", 0, QApplication::UnicodeUTF8));
        label_false_valuemaxSat->setText(QApplication::translate("ToneMapWidget", "Max Value: ", 0, QApplication::UnicodeUTF8));
        lineEdit_false_valuemaxsat->setText(QApplication::translate("ToneMapWidget", "0", 0, QApplication::UnicodeUTF8));
        label_false_min->setText(QApplication::translate("ToneMapWidget", "Minimum: ", 0, QApplication::UnicodeUTF8));
        label_false_valuemin->setText(QApplication::translate("ToneMapWidget", "...", 0, QApplication::UnicodeUTF8));
        label_false_valueminsat->setText(QApplication::translate("ToneMapWidget", "Min Value: ", 0, QApplication::UnicodeUTF8));
        lineEdit_false_valueminsat->setText(QApplication::translate("ToneMapWidget", "0", 0, QApplication::UnicodeUTF8));
        label_false_colorscale->setText(QApplication::translate("ToneMapWidget", "color scale: ", 0, QApplication::UnicodeUTF8));
        comboBox_false_colorscale->clear();
        comboBox_false_colorscale->insertItems(0, QStringList()
         << QApplication::translate("ToneMapWidget", "Standard", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "LMK", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "RED", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "WHITE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "YELLOW", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "SPEOS", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        comboBox_false_colorscale->setToolTip(QApplication::translate("ToneMapWidget", "Select coloring scale", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_false_Method->setText(QApplication::translate("ToneMapWidget", "scale method: ", 0, QApplication::UnicodeUTF8));
        comboBox_false_Method->clear();
        comboBox_false_Method->insertItems(0, QStringList()
         << QApplication::translate("ToneMapWidget", "linear", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "log", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "log3", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        comboBox_false_Method->setToolTip(QApplication::translate("ToneMapWidget", "Select scaling method", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_false_numbervalue->setText(QApplication::translate("ToneMapWidget", "Number of Values: ", 0, QApplication::UnicodeUTF8));
        lineEdit_false_legendeTest->setText(QApplication::translate("ToneMapWidget", "0", 0, QApplication::UnicodeUTF8));
        label_false_averageluminance->setText(QApplication::translate("ToneMapWidget", "Average luminance (cd/m\302\262): ", 0, QApplication::UnicodeUTF8));
        label_false_valueaverageluminance->setText(QApplication::translate("ToneMapWidget", "...", 0, QApplication::UnicodeUTF8));
        label_false_averageluminousemittance->setText(QApplication::translate("ToneMapWidget", "Luminous emittance (lux): ", 0, QApplication::UnicodeUTF8));
        label_false_valueaverageluminousemittance->setText(QApplication::translate("ToneMapWidget", "...", 0, QApplication::UnicodeUTF8));
        Qlabel_image_false_legende->setText(QApplication::translate("ToneMapWidget", "TEST", 0, QApplication::UnicodeUTF8));
        label_clampMethod->setText(QApplication::translate("ToneMapWidget", "Clamp method:", 0, QApplication::UnicodeUTF8));
        comboBox_clampMethod->clear();
        comboBox_clampMethod->insertItems(0, QStringList()
         << QApplication::translate("ToneMapWidget", "Preserve luminosity", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "Preserve hue", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "Clip channels individually", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ToneMapWidget", "Darken color", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        comboBox_clampMethod->setToolTip(QApplication::translate("ToneMapWidget", "Select color clamping method", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class ToneMapWidget: public Ui_ToneMapWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TONEMAP_H
