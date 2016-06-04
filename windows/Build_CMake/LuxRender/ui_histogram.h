/********************************************************************************
** Form generated from reading UI file 'histogram.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTOGRAM_H
#define UI_HISTOGRAM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HistogramWidget
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_3;
    QLabel *label_histogramChannel;
    QComboBox *comboBox_histogramChannel;
    QSpacerItem *horizontalSpacer;
    QCheckBox *checkBox_histogramLog;
    QFrame *frame_histogram;
    QGridLayout *histogramLayout;
    QLabel *label_HistogramLog;

    void setupUi(QWidget *HistogramWidget)
    {
        if (HistogramWidget->objectName().isEmpty())
            HistogramWidget->setObjectName(QString::fromUtf8("HistogramWidget"));
        HistogramWidget->resize(536, 229);
        verticalLayout = new QVBoxLayout(HistogramWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_histogramChannel = new QLabel(HistogramWidget);
        label_histogramChannel->setObjectName(QString::fromUtf8("label_histogramChannel"));

        gridLayout_3->addWidget(label_histogramChannel, 0, 0, 1, 1);

        comboBox_histogramChannel = new QComboBox(HistogramWidget);
        comboBox_histogramChannel->setObjectName(QString::fromUtf8("comboBox_histogramChannel"));

        gridLayout_3->addWidget(comboBox_histogramChannel, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 2, 1, 1);

        checkBox_histogramLog = new QCheckBox(HistogramWidget);
        checkBox_histogramLog->setObjectName(QString::fromUtf8("checkBox_histogramLog"));

        gridLayout_3->addWidget(checkBox_histogramLog, 0, 4, 1, 1);

        frame_histogram = new QFrame(HistogramWidget);
        frame_histogram->setObjectName(QString::fromUtf8("frame_histogram"));
        frame_histogram->setMinimumSize(QSize(0, 150));
        frame_histogram->setMaximumSize(QSize(16777215, 150));
        frame_histogram->setFrameShape(QFrame::Panel);
        frame_histogram->setFrameShadow(QFrame::Sunken);
        histogramLayout = new QGridLayout(frame_histogram);
        histogramLayout->setContentsMargins(0, 0, 0, 0);
        histogramLayout->setObjectName(QString::fromUtf8("histogramLayout"));

        gridLayout_3->addWidget(frame_histogram, 1, 0, 1, 5);

        label_HistogramLog = new QLabel(HistogramWidget);
        label_HistogramLog->setObjectName(QString::fromUtf8("label_HistogramLog"));

        gridLayout_3->addWidget(label_HistogramLog, 0, 3, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

#ifndef QT_NO_SHORTCUT
        label_histogramChannel->setBuddy(comboBox_histogramChannel);
        label_HistogramLog->setBuddy(checkBox_histogramLog);
#endif // QT_NO_SHORTCUT

        retranslateUi(HistogramWidget);

        comboBox_histogramChannel->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(HistogramWidget);
    } // setupUi

    void retranslateUi(QWidget *HistogramWidget)
    {
        HistogramWidget->setWindowTitle(QApplication::translate("HistogramWidget", "Form", 0, QApplication::UnicodeUTF8));
        label_histogramChannel->setText(QApplication::translate("HistogramWidget", "Channel:", 0, QApplication::UnicodeUTF8));
        comboBox_histogramChannel->clear();
        comboBox_histogramChannel->insertItems(0, QStringList()
         << QApplication::translate("HistogramWidget", "R+G+B", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HistogramWidget", "RGB", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HistogramWidget", "Red", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HistogramWidget", "Green", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HistogramWidget", "Blue", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HistogramWidget", "Value", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        comboBox_histogramChannel->setToolTip(QApplication::translate("HistogramWidget", "Pick a channel displayed on the histogram", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        checkBox_histogramLog->setToolTip(QApplication::translate("HistogramWidget", "Toggle between logarithm and linear histogram output", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        checkBox_histogramLog->setText(QApplication::translate("HistogramWidget", "Log", 0, QApplication::UnicodeUTF8));
        label_HistogramLog->setText(QApplication::translate("HistogramWidget", "Output: ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HistogramWidget: public Ui_HistogramWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTOGRAM_H
