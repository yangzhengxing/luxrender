/********************************************************************************
** Form generated from reading UI file 'lightgroup.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIGHTGROUP_H
#define UI_LIGHTGROUP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LightGroupWidget
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_gain;
    QSlider *slider_gain;
    QDoubleSpinBox *spinBox_gain;
    QCheckBox *checkBox_enableRGB;
    QCheckBox *checkBox_enableBB;
    QLabel *label_colortemp;
    QSlider *slider_colortemp;
    QDoubleSpinBox *spinBox_colortemp;
    QLabel *toolButton_colorfield;
    QToolButton *toolButton_colorpicker;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *LightGroupWidget)
    {
        if (LightGroupWidget->objectName().isEmpty())
            LightGroupWidget->setObjectName(QString::fromUtf8("LightGroupWidget"));
        LightGroupWidget->resize(464, 134);
        verticalLayout = new QVBoxLayout(LightGroupWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(6, 6, 6, 7);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(6);
        label_gain = new QLabel(LightGroupWidget);
        label_gain->setObjectName(QString::fromUtf8("label_gain"));
        label_gain->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_gain, 1, 0, 1, 1);

        slider_gain = new QSlider(LightGroupWidget);
        slider_gain->setObjectName(QString::fromUtf8("slider_gain"));
        slider_gain->setMinimumSize(QSize(150, 0));
        slider_gain->setMaximum(512);
        slider_gain->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(slider_gain, 1, 1, 1, 1);

        spinBox_gain = new QDoubleSpinBox(LightGroupWidget);
        spinBox_gain->setObjectName(QString::fromUtf8("spinBox_gain"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(spinBox_gain->sizePolicy().hasHeightForWidth());
        spinBox_gain->setSizePolicy(sizePolicy);
        spinBox_gain->setMinimumSize(QSize(84, 0));
        spinBox_gain->setMaximumSize(QSize(100, 25));
        spinBox_gain->setKeyboardTracking(false);
        spinBox_gain->setDecimals(7);
        spinBox_gain->setMaximum(10000);
        spinBox_gain->setSingleStep(0.1);

        gridLayout->addWidget(spinBox_gain, 1, 2, 1, 1);

        checkBox_enableRGB = new QCheckBox(LightGroupWidget);
        checkBox_enableRGB->setObjectName(QString::fromUtf8("checkBox_enableRGB"));

        gridLayout->addWidget(checkBox_enableRGB, 2, 0, 1, 1);

        checkBox_enableBB = new QCheckBox(LightGroupWidget);
        checkBox_enableBB->setObjectName(QString::fromUtf8("checkBox_enableBB"));

        gridLayout->addWidget(checkBox_enableBB, 2, 1, 1, 1);

        label_colortemp = new QLabel(LightGroupWidget);
        label_colortemp->setObjectName(QString::fromUtf8("label_colortemp"));
        label_colortemp->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_colortemp->sizePolicy().hasHeightForWidth());
        label_colortemp->setSizePolicy(sizePolicy1);
        label_colortemp->setMinimumSize(QSize(150, 0));
        label_colortemp->setPixmap(QPixmap(QString::fromUtf8(":/images/colortemp.png")));
        label_colortemp->setScaledContents(true);

        gridLayout->addWidget(label_colortemp, 4, 1, 1, 1);

        slider_colortemp = new QSlider(LightGroupWidget);
        slider_colortemp->setObjectName(QString::fromUtf8("slider_colortemp"));
        slider_colortemp->setEnabled(true);
        slider_colortemp->setMinimumSize(QSize(150, 0));
        slider_colortemp->setMaximum(512);
        slider_colortemp->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(slider_colortemp, 5, 1, 1, 1);

        spinBox_colortemp = new QDoubleSpinBox(LightGroupWidget);
        spinBox_colortemp->setObjectName(QString::fromUtf8("spinBox_colortemp"));
        sizePolicy.setHeightForWidth(spinBox_colortemp->sizePolicy().hasHeightForWidth());
        spinBox_colortemp->setSizePolicy(sizePolicy);
        spinBox_colortemp->setMinimumSize(QSize(84, 0));
        spinBox_colortemp->setMaximumSize(QSize(100, 25));
        spinBox_colortemp->setKeyboardTracking(false);
        spinBox_colortemp->setDecimals(0);
        spinBox_colortemp->setMinimum(1000);
        spinBox_colortemp->setMaximum(10000);
        spinBox_colortemp->setSingleStep(100);

        gridLayout->addWidget(spinBox_colortemp, 5, 2, 1, 1);

        toolButton_colorfield = new QLabel(LightGroupWidget);
        toolButton_colorfield->setObjectName(QString::fromUtf8("toolButton_colorfield"));
        toolButton_colorfield->setFrameShape(QFrame::Box);
        toolButton_colorfield->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(toolButton_colorfield, 4, 0, 1, 1);

        toolButton_colorpicker = new QToolButton(LightGroupWidget);
        toolButton_colorpicker->setObjectName(QString::fromUtf8("toolButton_colorpicker"));
        toolButton_colorpicker->setLayoutDirection(Qt::LeftToRight);
        toolButton_colorpicker->setAutoFillBackground(false);
        toolButton_colorpicker->setIconSize(QSize(32, 32));

        gridLayout->addWidget(toolButton_colorpicker, 5, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer);

        QWidget::setTabOrder(slider_gain, spinBox_gain);
        QWidget::setTabOrder(spinBox_gain, checkBox_enableRGB);
        QWidget::setTabOrder(checkBox_enableRGB, checkBox_enableBB);
        QWidget::setTabOrder(checkBox_enableBB, slider_colortemp);
        QWidget::setTabOrder(slider_colortemp, spinBox_colortemp);

        retranslateUi(LightGroupWidget);

        QMetaObject::connectSlotsByName(LightGroupWidget);
    } // setupUi

    void retranslateUi(QWidget *LightGroupWidget)
    {
        LightGroupWidget->setWindowTitle(QApplication::translate("LightGroupWidget", "Form", 0, QApplication::UnicodeUTF8));
        label_gain->setText(QApplication::translate("LightGroupWidget", "Gain", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        slider_gain->setToolTip(QApplication::translate("LightGroupWidget", "Adjust LightGroup Gain/Intensity", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinBox_gain->setToolTip(QApplication::translate("LightGroupWidget", "Adjust LightGroup Gain/Intensity Value", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        checkBox_enableRGB->setToolTip(QApplication::translate("LightGroupWidget", "Enable RGB Colour adjustment", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        checkBox_enableRGB->setText(QApplication::translate("LightGroupWidget", "RGB", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox_enableBB->setToolTip(QApplication::translate("LightGroupWidget", "Enable BlackBody Temperature Adjustment", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        checkBox_enableBB->setText(QApplication::translate("LightGroupWidget", "Black Body Temperature", 0, QApplication::UnicodeUTF8));
        label_colortemp->setText(QString());
#ifndef QT_NO_TOOLTIP
        slider_colortemp->setToolTip(QApplication::translate("LightGroupWidget", "Adjust BlackBody Temperature", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinBox_colortemp->setToolTip(QApplication::translate("LightGroupWidget", "Adjust BlackBody Temperature Value", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButton_colorfield->setText(QString());
#ifndef QT_NO_TOOLTIP
        toolButton_colorpicker->setToolTip(QApplication::translate("LightGroupWidget", "Adjust RGB Colour", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButton_colorpicker->setText(QApplication::translate("LightGroupWidget", "Picker", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LightGroupWidget: public Ui_LightGroupWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIGHTGROUP_H
