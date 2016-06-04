/********************************************************************************
** Form generated from reading UI file 'noisereduction.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOISEREDUCTION_H
#define UI_NOISEREDUCTION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NoiseReductionWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabs_noiseReduction;
    QWidget *tab_GREYC;
    QVBoxLayout *verticalLayout_9;
    QTabWidget *tabs_GREYC;
    QWidget *tab_regularization;
    QVBoxLayout *verticalLayout_10;
    QGridLayout *gridLayout_4;
    QCheckBox *checkBox_regularizationEnabled;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *checkBox_fastApproximation;
    QLabel *label_iterations;
    QSlider *slider_iterations;
    QDoubleSpinBox *spinBox_iterations;
    QLabel *label_amplitude;
    QSlider *slider_amplitude;
    QDoubleSpinBox *spinBox_amplitude;
    QLabel *label_precission;
    QSlider *slider_precision;
    QDoubleSpinBox *spinBox_precision;
    QSpacerItem *verticalSpacer_9;
    QWidget *tab_adv;
    QVBoxLayout *verticalLayout_13;
    QGridLayout *gridLayout_7;
    QGroupBox *groupBox_integration;
    QVBoxLayout *verticalLayout_12;
    QGridLayout *gridLayout_6;
    QLabel *label_angular;
    QSlider *slider_spatial;
    QDoubleSpinBox *spinBox_spatial;
    QLabel *label_spatial;
    QSlider *slider_angular;
    QDoubleSpinBox *spinBox_angular;
    QLabel *label_interplType;
    QComboBox *comboBox_interpolType;
    QSpacerItem *verticalSpacer_11;
    QWidget *tab_filter;
    QVBoxLayout *verticalLayout_11;
    QGridLayout *gridLayout_5;
    QLabel *label_alpha;
    QSlider *slider_alpha;
    QDoubleSpinBox *spinBox_alpha;
    QLabel *label_sigma;
    QDoubleSpinBox *spinBox_sigma;
    QLabel *label_sharpness;
    QSlider *slider_sharpness;
    QDoubleSpinBox *spinBox_sharpness;
    QLabel *label_aniso;
    QSlider *slider_aniso;
    QDoubleSpinBox *spinBox_aniso;
    QSlider *slider_sigma;
    QSpacerItem *verticalSpacer_10;
    QWidget *tab_chiu;
    QVBoxLayout *verticalLayout_14;
    QGridLayout *gridLayout_8;
    QCheckBox *checkBox_chiuEnabled;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *checkBox_includeCenter;
    QLabel *label_chiuRadius;
    QSlider *slider_chiuRadius;
    QDoubleSpinBox *spinBox_chiuRadius;
    QSpacerItem *verticalSpacer_13;

    void setupUi(QWidget *NoiseReductionWidget)
    {
        if (NoiseReductionWidget->objectName().isEmpty())
            NoiseReductionWidget->setObjectName(QString::fromUtf8("NoiseReductionWidget"));
        NoiseReductionWidget->resize(598, 255);
        verticalLayout = new QVBoxLayout(NoiseReductionWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabs_noiseReduction = new QTabWidget(NoiseReductionWidget);
        tabs_noiseReduction->setObjectName(QString::fromUtf8("tabs_noiseReduction"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabs_noiseReduction->sizePolicy().hasHeightForWidth());
        tabs_noiseReduction->setSizePolicy(sizePolicy);
        tab_GREYC = new QWidget();
        tab_GREYC->setObjectName(QString::fromUtf8("tab_GREYC"));
        verticalLayout_9 = new QVBoxLayout(tab_GREYC);
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        tabs_GREYC = new QTabWidget(tab_GREYC);
        tabs_GREYC->setObjectName(QString::fromUtf8("tabs_GREYC"));
        sizePolicy.setHeightForWidth(tabs_GREYC->sizePolicy().hasHeightForWidth());
        tabs_GREYC->setSizePolicy(sizePolicy);
        tab_regularization = new QWidget();
        tab_regularization->setObjectName(QString::fromUtf8("tab_regularization"));
        verticalLayout_10 = new QVBoxLayout(tab_regularization);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        checkBox_regularizationEnabled = new QCheckBox(tab_regularization);
        checkBox_regularizationEnabled->setObjectName(QString::fromUtf8("checkBox_regularizationEnabled"));
        checkBox_regularizationEnabled->setEnabled(true);

        gridLayout_4->addWidget(checkBox_regularizationEnabled, 0, 0, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        checkBox_fastApproximation = new QCheckBox(tab_regularization);
        checkBox_fastApproximation->setObjectName(QString::fromUtf8("checkBox_fastApproximation"));

        gridLayout_4->addWidget(checkBox_fastApproximation, 0, 3, 1, 2);

        label_iterations = new QLabel(tab_regularization);
        label_iterations->setObjectName(QString::fromUtf8("label_iterations"));

        gridLayout_4->addWidget(label_iterations, 1, 0, 1, 1);

        slider_iterations = new QSlider(tab_regularization);
        slider_iterations->setObjectName(QString::fromUtf8("slider_iterations"));
        slider_iterations->setMaximum(512);
        slider_iterations->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(slider_iterations, 1, 1, 1, 3);

        spinBox_iterations = new QDoubleSpinBox(tab_regularization);
        spinBox_iterations->setObjectName(QString::fromUtf8("spinBox_iterations"));
        spinBox_iterations->setKeyboardTracking(false);
        spinBox_iterations->setMaximum(16);
        spinBox_iterations->setSingleStep(1);

        gridLayout_4->addWidget(spinBox_iterations, 1, 4, 1, 1);

        label_amplitude = new QLabel(tab_regularization);
        label_amplitude->setObjectName(QString::fromUtf8("label_amplitude"));

        gridLayout_4->addWidget(label_amplitude, 2, 0, 1, 1);

        slider_amplitude = new QSlider(tab_regularization);
        slider_amplitude->setObjectName(QString::fromUtf8("slider_amplitude"));
        slider_amplitude->setMaximum(512);
        slider_amplitude->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(slider_amplitude, 2, 1, 1, 3);

        spinBox_amplitude = new QDoubleSpinBox(tab_regularization);
        spinBox_amplitude->setObjectName(QString::fromUtf8("spinBox_amplitude"));
        spinBox_amplitude->setKeyboardTracking(false);
        spinBox_amplitude->setMaximum(200);
        spinBox_amplitude->setSingleStep(5);

        gridLayout_4->addWidget(spinBox_amplitude, 2, 4, 1, 1);

        label_precission = new QLabel(tab_regularization);
        label_precission->setObjectName(QString::fromUtf8("label_precission"));

        gridLayout_4->addWidget(label_precission, 3, 0, 1, 1);

        slider_precision = new QSlider(tab_regularization);
        slider_precision->setObjectName(QString::fromUtf8("slider_precision"));
        slider_precision->setMaximum(512);
        slider_precision->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(slider_precision, 3, 1, 1, 3);

        spinBox_precision = new QDoubleSpinBox(tab_regularization);
        spinBox_precision->setObjectName(QString::fromUtf8("spinBox_precision"));
        spinBox_precision->setKeyboardTracking(false);
        spinBox_precision->setMaximum(12);
        spinBox_precision->setSingleStep(0.5);

        gridLayout_4->addWidget(spinBox_precision, 3, 4, 1, 1);


        verticalLayout_10->addLayout(gridLayout_4);

        verticalSpacer_9 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        verticalLayout_10->addItem(verticalSpacer_9);

        tabs_GREYC->addTab(tab_regularization, QString());
        tab_adv = new QWidget();
        tab_adv->setObjectName(QString::fromUtf8("tab_adv"));
        verticalLayout_13 = new QVBoxLayout(tab_adv);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        groupBox_integration = new QGroupBox(tab_adv);
        groupBox_integration->setObjectName(QString::fromUtf8("groupBox_integration"));
        verticalLayout_12 = new QVBoxLayout(groupBox_integration);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_angular = new QLabel(groupBox_integration);
        label_angular->setObjectName(QString::fromUtf8("label_angular"));

        gridLayout_6->addWidget(label_angular, 0, 0, 1, 1);

        slider_spatial = new QSlider(groupBox_integration);
        slider_spatial->setObjectName(QString::fromUtf8("slider_spatial"));
        slider_spatial->setMaximum(512);
        slider_spatial->setOrientation(Qt::Horizontal);

        gridLayout_6->addWidget(slider_spatial, 0, 1, 1, 1);

        spinBox_spatial = new QDoubleSpinBox(groupBox_integration);
        spinBox_spatial->setObjectName(QString::fromUtf8("spinBox_spatial"));
        spinBox_spatial->setKeyboardTracking(false);
        spinBox_spatial->setDecimals(3);
        spinBox_spatial->setMaximum(1);
        spinBox_spatial->setSingleStep(0.05);

        gridLayout_6->addWidget(spinBox_spatial, 0, 2, 1, 1);

        label_spatial = new QLabel(groupBox_integration);
        label_spatial->setObjectName(QString::fromUtf8("label_spatial"));

        gridLayout_6->addWidget(label_spatial, 1, 0, 1, 1);

        slider_angular = new QSlider(groupBox_integration);
        slider_angular->setObjectName(QString::fromUtf8("slider_angular"));
        slider_angular->setMaximum(512);
        slider_angular->setOrientation(Qt::Horizontal);

        gridLayout_6->addWidget(slider_angular, 1, 1, 1, 1);

        spinBox_angular = new QDoubleSpinBox(groupBox_integration);
        spinBox_angular->setObjectName(QString::fromUtf8("spinBox_angular"));
        spinBox_angular->setKeyboardTracking(false);
        spinBox_angular->setDecimals(1);
        spinBox_angular->setMaximum(90);

        gridLayout_6->addWidget(spinBox_angular, 1, 2, 1, 1);


        verticalLayout_12->addLayout(gridLayout_6);


        gridLayout_7->addWidget(groupBox_integration, 0, 0, 1, 2);

        label_interplType = new QLabel(tab_adv);
        label_interplType->setObjectName(QString::fromUtf8("label_interplType"));

        gridLayout_7->addWidget(label_interplType, 1, 0, 1, 1);

        comboBox_interpolType = new QComboBox(tab_adv);
        comboBox_interpolType->setObjectName(QString::fromUtf8("comboBox_interpolType"));

        gridLayout_7->addWidget(comboBox_interpolType, 1, 1, 1, 1);


        verticalLayout_13->addLayout(gridLayout_7);

        verticalSpacer_11 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        verticalLayout_13->addItem(verticalSpacer_11);

        tabs_GREYC->addTab(tab_adv, QString());
        tab_filter = new QWidget();
        tab_filter->setObjectName(QString::fromUtf8("tab_filter"));
        verticalLayout_11 = new QVBoxLayout(tab_filter);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_alpha = new QLabel(tab_filter);
        label_alpha->setObjectName(QString::fromUtf8("label_alpha"));

        gridLayout_5->addWidget(label_alpha, 0, 0, 1, 1);

        slider_alpha = new QSlider(tab_filter);
        slider_alpha->setObjectName(QString::fromUtf8("slider_alpha"));
        slider_alpha->setMaximum(512);
        slider_alpha->setOrientation(Qt::Horizontal);

        gridLayout_5->addWidget(slider_alpha, 0, 1, 1, 1);

        spinBox_alpha = new QDoubleSpinBox(tab_filter);
        spinBox_alpha->setObjectName(QString::fromUtf8("spinBox_alpha"));
        spinBox_alpha->setKeyboardTracking(false);
        spinBox_alpha->setMaximum(12);
        spinBox_alpha->setSingleStep(0.5);

        gridLayout_5->addWidget(spinBox_alpha, 0, 2, 1, 1);

        label_sigma = new QLabel(tab_filter);
        label_sigma->setObjectName(QString::fromUtf8("label_sigma"));

        gridLayout_5->addWidget(label_sigma, 1, 0, 1, 1);

        spinBox_sigma = new QDoubleSpinBox(tab_filter);
        spinBox_sigma->setObjectName(QString::fromUtf8("spinBox_sigma"));
        spinBox_sigma->setKeyboardTracking(false);
        spinBox_sigma->setMaximum(12);
        spinBox_sigma->setSingleStep(0.5);

        gridLayout_5->addWidget(spinBox_sigma, 1, 2, 1, 1);

        label_sharpness = new QLabel(tab_filter);
        label_sharpness->setObjectName(QString::fromUtf8("label_sharpness"));

        gridLayout_5->addWidget(label_sharpness, 2, 0, 1, 1);

        slider_sharpness = new QSlider(tab_filter);
        slider_sharpness->setObjectName(QString::fromUtf8("slider_sharpness"));
        slider_sharpness->setMaximum(512);
        slider_sharpness->setOrientation(Qt::Horizontal);

        gridLayout_5->addWidget(slider_sharpness, 2, 1, 1, 1);

        spinBox_sharpness = new QDoubleSpinBox(tab_filter);
        spinBox_sharpness->setObjectName(QString::fromUtf8("spinBox_sharpness"));
        spinBox_sharpness->setKeyboardTracking(false);
        spinBox_sharpness->setMaximum(2);
        spinBox_sharpness->setSingleStep(0.1);

        gridLayout_5->addWidget(spinBox_sharpness, 2, 2, 1, 1);

        label_aniso = new QLabel(tab_filter);
        label_aniso->setObjectName(QString::fromUtf8("label_aniso"));

        gridLayout_5->addWidget(label_aniso, 3, 0, 1, 1);

        slider_aniso = new QSlider(tab_filter);
        slider_aniso->setObjectName(QString::fromUtf8("slider_aniso"));
        slider_aniso->setMaximum(512);
        slider_aniso->setOrientation(Qt::Horizontal);

        gridLayout_5->addWidget(slider_aniso, 3, 1, 1, 1);

        spinBox_aniso = new QDoubleSpinBox(tab_filter);
        spinBox_aniso->setObjectName(QString::fromUtf8("spinBox_aniso"));
        spinBox_aniso->setKeyboardTracking(false);
        spinBox_aniso->setDecimals(3);
        spinBox_aniso->setMaximum(1);
        spinBox_aniso->setSingleStep(0.05);

        gridLayout_5->addWidget(spinBox_aniso, 3, 2, 1, 1);

        slider_sigma = new QSlider(tab_filter);
        slider_sigma->setObjectName(QString::fromUtf8("slider_sigma"));
        slider_sigma->setMaximum(512);
        slider_sigma->setOrientation(Qt::Horizontal);

        gridLayout_5->addWidget(slider_sigma, 1, 1, 1, 1);


        verticalLayout_11->addLayout(gridLayout_5);

        verticalSpacer_10 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        verticalLayout_11->addItem(verticalSpacer_10);

        tabs_GREYC->addTab(tab_filter, QString());

        verticalLayout_9->addWidget(tabs_GREYC);

        tabs_noiseReduction->addTab(tab_GREYC, QString());
        tab_chiu = new QWidget();
        tab_chiu->setObjectName(QString::fromUtf8("tab_chiu"));
        verticalLayout_14 = new QVBoxLayout(tab_chiu);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        checkBox_chiuEnabled = new QCheckBox(tab_chiu);
        checkBox_chiuEnabled->setObjectName(QString::fromUtf8("checkBox_chiuEnabled"));

        gridLayout_8->addWidget(checkBox_chiuEnabled, 0, 0, 1, 2);

        horizontalSpacer_3 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        checkBox_includeCenter = new QCheckBox(tab_chiu);
        checkBox_includeCenter->setObjectName(QString::fromUtf8("checkBox_includeCenter"));

        gridLayout_8->addWidget(checkBox_includeCenter, 0, 3, 1, 2);

        label_chiuRadius = new QLabel(tab_chiu);
        label_chiuRadius->setObjectName(QString::fromUtf8("label_chiuRadius"));

        gridLayout_8->addWidget(label_chiuRadius, 1, 0, 1, 1);

        slider_chiuRadius = new QSlider(tab_chiu);
        slider_chiuRadius->setObjectName(QString::fromUtf8("slider_chiuRadius"));
        slider_chiuRadius->setMaximum(512);
        slider_chiuRadius->setOrientation(Qt::Horizontal);

        gridLayout_8->addWidget(slider_chiuRadius, 1, 1, 1, 3);

        spinBox_chiuRadius = new QDoubleSpinBox(tab_chiu);
        spinBox_chiuRadius->setObjectName(QString::fromUtf8("spinBox_chiuRadius"));
        spinBox_chiuRadius->setKeyboardTracking(false);
        spinBox_chiuRadius->setMinimum(1);
        spinBox_chiuRadius->setMaximum(9);
        spinBox_chiuRadius->setSingleStep(0.1);

        gridLayout_8->addWidget(spinBox_chiuRadius, 1, 4, 1, 1);


        verticalLayout_14->addLayout(gridLayout_8);

        verticalSpacer_13 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        verticalLayout_14->addItem(verticalSpacer_13);

        tabs_noiseReduction->addTab(tab_chiu, QString());

        verticalLayout->addWidget(tabs_noiseReduction);

#ifndef QT_NO_SHORTCUT
        label_iterations->setBuddy(slider_iterations);
        label_amplitude->setBuddy(slider_amplitude);
        label_precission->setBuddy(slider_precision);
        label_angular->setBuddy(slider_spatial);
        label_spatial->setBuddy(slider_angular);
        label_alpha->setBuddy(slider_alpha);
        label_sigma->setBuddy(slider_sigma);
        label_sharpness->setBuddy(slider_sharpness);
        label_aniso->setBuddy(slider_aniso);
        label_chiuRadius->setBuddy(slider_chiuRadius);
#endif // QT_NO_SHORTCUT

        retranslateUi(NoiseReductionWidget);

        tabs_noiseReduction->setCurrentIndex(0);
        tabs_GREYC->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(NoiseReductionWidget);
    } // setupUi

    void retranslateUi(QWidget *NoiseReductionWidget)
    {
        NoiseReductionWidget->setWindowTitle(QApplication::translate("NoiseReductionWidget", "Form", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox_regularizationEnabled->setToolTip(QApplication::translate("NoiseReductionWidget", "Enable GREYCStoration Noise Reduction Filter", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        checkBox_regularizationEnabled->setText(QApplication::translate("NoiseReductionWidget", "Enabled", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox_fastApproximation->setToolTip(QApplication::translate("NoiseReductionWidget", "Use Fast Approximation", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        checkBox_fastApproximation->setText(QApplication::translate("NoiseReductionWidget", "Fast approximation", 0, QApplication::UnicodeUTF8));
        label_iterations->setText(QApplication::translate("NoiseReductionWidget", "Iterations", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        slider_iterations->setToolTip(QApplication::translate("NoiseReductionWidget", "Adjust number of Iterations", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinBox_iterations->setToolTip(QApplication::translate("NoiseReductionWidget", "Adjust number of Iterations Value", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_amplitude->setText(QApplication::translate("NoiseReductionWidget", "Amplitude", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        slider_amplitude->setToolTip(QApplication::translate("NoiseReductionWidget", "Adjust Filter Strength/Amplitude", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinBox_amplitude->setToolTip(QApplication::translate("NoiseReductionWidget", "Adjust Filter Strength/Amplitude Value", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_precission->setText(QApplication::translate("NoiseReductionWidget", "Precision", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        slider_precision->setToolTip(QApplication::translate("NoiseReductionWidget", "Adjust precision of Gaussian Filter Kernel", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinBox_precision->setToolTip(QApplication::translate("NoiseReductionWidget", "Adjust precision of Gaussian Filter Kernel Value", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        tabs_GREYC->setTabText(tabs_GREYC->indexOf(tab_regularization), QApplication::translate("NoiseReductionWidget", "Regularization", 0, QApplication::UnicodeUTF8));
        groupBox_integration->setTitle(QApplication::translate("NoiseReductionWidget", "Integration", 0, QApplication::UnicodeUTF8));
        label_angular->setText(QApplication::translate("NoiseReductionWidget", "Spatial", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        slider_spatial->setToolTip(QApplication::translate("NoiseReductionWidget", "Amount of Spatial Integration", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinBox_spatial->setToolTip(QApplication::translate("NoiseReductionWidget", "Amount of Spatial Integration Value", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_spatial->setText(QApplication::translate("NoiseReductionWidget", "Angular", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        slider_angular->setToolTip(QApplication::translate("NoiseReductionWidget", "Amount of Angular Integration", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinBox_angular->setToolTip(QApplication::translate("NoiseReductionWidget", "Amount of Angular Integration Value", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_interplType->setText(QApplication::translate("NoiseReductionWidget", "Interpolation type:", 0, QApplication::UnicodeUTF8));
        comboBox_interpolType->clear();
        comboBox_interpolType->insertItems(0, QStringList()
         << QApplication::translate("NoiseReductionWidget", "Nearest-Neighbour", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NoiseReductionWidget", "Linear", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NoiseReductionWidget", "Runge-Kutta", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        comboBox_interpolType->setToolTip(QApplication::translate("NoiseReductionWidget", "Choose Interpolation Kernel Type", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        tabs_GREYC->setTabText(tabs_GREYC->indexOf(tab_adv), QApplication::translate("NoiseReductionWidget", "Adv", 0, QApplication::UnicodeUTF8));
        label_alpha->setText(QApplication::translate("NoiseReductionWidget", "Alpha", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        slider_alpha->setToolTip(QApplication::translate("NoiseReductionWidget", "Adjust Gaussian Filter Alpha", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinBox_alpha->setToolTip(QApplication::translate("NoiseReductionWidget", "Adjust Gaussian Filter Alpha Value", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_sigma->setText(QApplication::translate("NoiseReductionWidget", "Sigma", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        spinBox_sigma->setToolTip(QApplication::translate("NoiseReductionWidget", "Adjust Gaussian Filter Sigma Value", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_sharpness->setText(QApplication::translate("NoiseReductionWidget", "Sharpness", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        slider_sharpness->setToolTip(QApplication::translate("NoiseReductionWidget", "Adjust Sharpness", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinBox_sharpness->setToolTip(QApplication::translate("NoiseReductionWidget", "Adjust Sharpness Value", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_aniso->setText(QApplication::translate("NoiseReductionWidget", "Aniso", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        slider_aniso->setToolTip(QApplication::translate("NoiseReductionWidget", "Adjust Filter Anisotropy", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinBox_aniso->setToolTip(QApplication::translate("NoiseReductionWidget", "Adjust Filter Anisotropy Value", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        slider_sigma->setToolTip(QApplication::translate("NoiseReductionWidget", "Adjust Gaussian Filter Sigma", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        tabs_GREYC->setTabText(tabs_GREYC->indexOf(tab_filter), QApplication::translate("NoiseReductionWidget", "Filter", 0, QApplication::UnicodeUTF8));
        tabs_noiseReduction->setTabText(tabs_noiseReduction->indexOf(tab_GREYC), QApplication::translate("NoiseReductionWidget", "GREYCStoration", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox_chiuEnabled->setToolTip(QApplication::translate("NoiseReductionWidget", "Enable Chiu Noise Reduction Filter", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        checkBox_chiuEnabled->setText(QApplication::translate("NoiseReductionWidget", "Enabled", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox_includeCenter->setToolTip(QApplication::translate("NoiseReductionWidget", "Include Center Pixel in Filter", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        checkBox_includeCenter->setText(QApplication::translate("NoiseReductionWidget", "Include center", 0, QApplication::UnicodeUTF8));
        label_chiuRadius->setText(QApplication::translate("NoiseReductionWidget", "Radius", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        slider_chiuRadius->setToolTip(QApplication::translate("NoiseReductionWidget", "Adjust Filter Radius", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinBox_chiuRadius->setToolTip(QApplication::translate("NoiseReductionWidget", "Adjust Filter Radius Value", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        tabs_noiseReduction->setTabText(tabs_noiseReduction->indexOf(tab_chiu), QApplication::translate("NoiseReductionWidget", "Chiu", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NoiseReductionWidget: public Ui_NoiseReductionWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOISEREDUCTION_H
