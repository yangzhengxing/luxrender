/********************************************************************************
** Form generated from reading UI file 'luxrender.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LUXRENDER_H
#define UI_LUXRENDER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QSplitter>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QTimeEdit>
#include <QtGui/QToolButton>
#include <QtGui/QTreeView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_openFile;
    QAction *action_resumeFLM;
    QAction *action_loadFLM;
    QAction *action_saveFLM;
    QAction *action_exitAppSave;
    QAction *action_exitApp;
    QAction *action_resumeRender;
    QAction *action_pauseRender;
    QAction *action_stopRender;
    QAction *action_endRender;
    QAction *action_viewToolbar;
    QAction *action_viewStatusbar;
    QAction *action_viewSidePane;
    QAction *action_panMode;
    QAction *action_zoomMode;
    QAction *action_copyLog;
    QAction *action_clearLog;
    QAction *action_overlayStatsView;
    QAction *action_fullScreen;
    QAction *action_rulerDisabled;
    QAction *action_rulerPixels;
    QAction *action_rulerNormalized;
    QAction *action_aboutDialog;
    QAction *action_documentation;
    QAction *action_forums;
    QAction *actionOpen_Recent;
    QAction *action_normalScreen;
    QAction *action_outputTonemapped;
    QAction *action_outputHDR;
    QAction *action_outputBufferGroupsTonemapped;
    QAction *action_outputBufferGroupsHDR;
    QAction *action_batchProcess;
    QAction *action_useAlpha;
    QAction *action_useAlphaHDR;
    QAction *action_overlayStats;
    QAction *action_HDR_tonemapped;
    QAction *action_gallery;
    QAction *action_bugtracker;
    QAction *action_Save_Panel_Settings;
    QAction *action_Load_Panel_Settings;
    QAction *action_Show_Side_Panel;
    QAction *action_showAlphaView;
    QAction *action_showUserSamplingMapView;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabs_main;
    QWidget *tab_render;
    QGridLayout *gridLayout_12;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *writeIntervalLabel_1;
    QLabel *writeIntervalLabel_2;
    QLabel *writeIntervalLabel_3;
    QSpinBox *spinBox_overrideWriteInterval;
    QSpacerItem *writeIntervalHorizontalSpacer;
    QLabel *displayIntervalLabel_1;
    QLabel *displayIntervalLabel_2;
    QLabel *displayIntervalLabel_3;
    QSpinBox *spinBox_overrideDisplayInterval;
    QLabel *resolutioniconLabel;
    QLabel *resinfoLabel;
    QLabel *zoomiconlabel;
    QLabel *zoominfoLabel;
    QGridLayout *gridLayout_4;
    QToolButton *button_resume;
    QToolButton *button_pause;
    QToolButton *button_stop;
    QFrame *line;
    QLabel *label_threadCount;
    QSpinBox *spinBox_Threads;
    QFrame *line_2;
    QToolButton *button_copyToClipboard;
    QSplitter *splitter;
    QTabWidget *outputTabs;
    QWidget *tab_imaging;
    QGridLayout *gridLayout_29;
    QPushButton *button_imagingReset;
    QCheckBox *checkBox_imagingAuto;
    QPushButton *button_imagingApply;
    QScrollArea *panesArea;
    QWidget *panesAreaContents;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *panesLayout;
    QSpacerItem *horizontalSpacer;
    QWidget *tab_lightGroups;
    QVBoxLayout *verticalLayout_15;
    QScrollArea *lightGroupsArea;
    QWidget *lightGroupsAreaContents;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *lightGroupsLayout;
    QWidget *tab_usersampling;
    QGridLayout *gridLayout_3;
    QScrollArea *scrollArea;
    QWidget *userSamplingArea;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QPushButton *button_usAddPenButton;
    QPushButton *button_usSubPenButton;
    QLabel *label_2;
    QPushButton *button_usResetButton;
    QPushButton *button_usApplyButton;
    QPushButton *button_usUndoButton;
    QLabel *label_3;
    QSlider *slider_usPenSize;
    QLabel *label_4;
    QSlider *slider_usOpacity;
    QLabel *label_5;
    QSlider *slider_usPenStrength;
    QWidget *tab_advanced;
    QVBoxLayout *verticalLayout_18;
    QScrollArea *advancedArea;
    QWidget *advancedAreaContents;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *advancedLayout;
    QFrame *frame_render;
    QGridLayout *renderLayout;
    QWidget *tab_queue;
    QGridLayout *gridLayout_13;
    QTreeView *tree_queue;
    QHBoxLayout *horizontalLayout_6;
    QToolButton *button_addQueueFiles;
    QToolButton *button_removeQueueFiles;
    QGroupBox *groupBox_haltConditions;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_haltConditions;
    QCheckBox *checkBox_haltTime;
    QTimeEdit *timeEdit_overrideHaltTime;
    QCheckBox *checkBox_haltProgress;
    QSpinBox *spinBox_overrideHaltProgress;
    QCheckBox *checkBox_haltThreshold;
    QDoubleSpinBox *doubleSpinBox_overrideHaltThreshold;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *groupBox_queueControls;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_queueControls;
    QCheckBox *checkBox_loopQueue;
    QCheckBox *checkBox_overrideWriteFlm;
    QSpacerItem *horizontalSpacer_5;
    QWidget *tab_network;
    QGridLayout *gridLayout_11;
    QTableWidget *table_servers;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_servers;
    QLineEdit *lineEdit_server;
    QToolButton *button_addServer;
    QToolButton *button_removeServer;
    QToolButton *button_resetServer;
    QFrame *line_3;
    QLabel *label_interval;
    QComboBox *comboBox_updateInterval;
    QLabel *label_serversStatus;
    QWidget *tab_log;
    QGridLayout *gridLayout_9;
    QTextEdit *textEdit_log;
    QHBoxLayout *horizontalLayout_log;
    QLabel *label_verbosity;
    QComboBox *comboBox_verbosity;
    QSpacerItem *horizontalSpacer_3;
    QMenuBar *menubar;
    QMenu *menu_render;
    QMenu *menu_view;
    QMenu *menu_help;
    QMenu *menu_file;
    QMenu *menuOpen_Recent;
    QMenu *menuExport_to_Image;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(775, 585);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/luxrender.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);
        action_openFile = new QAction(MainWindow);
        action_openFile->setObjectName(QString::fromUtf8("action_openFile"));
        action_openFile->setShortcutContext(Qt::ApplicationShortcut);
        action_resumeFLM = new QAction(MainWindow);
        action_resumeFLM->setObjectName(QString::fromUtf8("action_resumeFLM"));
        action_loadFLM = new QAction(MainWindow);
        action_loadFLM->setObjectName(QString::fromUtf8("action_loadFLM"));
        action_saveFLM = new QAction(MainWindow);
        action_saveFLM->setObjectName(QString::fromUtf8("action_saveFLM"));
        action_exitAppSave = new QAction(MainWindow);
        action_exitAppSave->setObjectName(QString::fromUtf8("action_exitAppSave"));
        action_exitAppSave->setShortcutContext(Qt::ApplicationShortcut);
        action_exitApp = new QAction(MainWindow);
        action_exitApp->setObjectName(QString::fromUtf8("action_exitApp"));
        action_exitApp->setShortcutContext(Qt::ApplicationShortcut);
        action_exitApp->setMenuRole(QAction::QuitRole);
        action_resumeRender = new QAction(MainWindow);
        action_resumeRender->setObjectName(QString::fromUtf8("action_resumeRender"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/resumeicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_resumeRender->setIcon(icon1);
        action_pauseRender = new QAction(MainWindow);
        action_pauseRender->setObjectName(QString::fromUtf8("action_pauseRender"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/pauseicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_pauseRender->setIcon(icon2);
        action_stopRender = new QAction(MainWindow);
        action_stopRender->setObjectName(QString::fromUtf8("action_stopRender"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/stopicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_stopRender->setIcon(icon3);
        action_endRender = new QAction(MainWindow);
        action_endRender->setObjectName(QString::fromUtf8("action_endRender"));
        action_endRender->setIcon(icon3);
        action_viewToolbar = new QAction(MainWindow);
        action_viewToolbar->setObjectName(QString::fromUtf8("action_viewToolbar"));
        action_viewToolbar->setCheckable(true);
        action_viewToolbar->setChecked(true);
        action_viewToolbar->setEnabled(true);
        action_viewStatusbar = new QAction(MainWindow);
        action_viewStatusbar->setObjectName(QString::fromUtf8("action_viewStatusbar"));
        action_viewStatusbar->setCheckable(true);
        action_viewStatusbar->setChecked(true);
        action_viewSidePane = new QAction(MainWindow);
        action_viewSidePane->setObjectName(QString::fromUtf8("action_viewSidePane"));
        action_viewSidePane->setCheckable(true);
        action_viewSidePane->setChecked(true);
        action_panMode = new QAction(MainWindow);
        action_panMode->setObjectName(QString::fromUtf8("action_panMode"));
        action_panMode->setCheckable(true);
        action_zoomMode = new QAction(MainWindow);
        action_zoomMode->setObjectName(QString::fromUtf8("action_zoomMode"));
        action_zoomMode->setCheckable(true);
        action_copyLog = new QAction(MainWindow);
        action_copyLog->setObjectName(QString::fromUtf8("action_copyLog"));
        action_clearLog = new QAction(MainWindow);
        action_clearLog->setObjectName(QString::fromUtf8("action_clearLog"));
        action_overlayStatsView = new QAction(MainWindow);
        action_overlayStatsView->setObjectName(QString::fromUtf8("action_overlayStatsView"));
        action_overlayStatsView->setCheckable(true);
        action_overlayStatsView->setShortcutContext(Qt::ApplicationShortcut);
        action_fullScreen = new QAction(MainWindow);
        action_fullScreen->setObjectName(QString::fromUtf8("action_fullScreen"));
        action_fullScreen->setShortcutContext(Qt::ApplicationShortcut);
        action_fullScreen->setMenuRole(QAction::TextHeuristicRole);
        action_rulerDisabled = new QAction(MainWindow);
        action_rulerDisabled->setObjectName(QString::fromUtf8("action_rulerDisabled"));
        action_rulerPixels = new QAction(MainWindow);
        action_rulerPixels->setObjectName(QString::fromUtf8("action_rulerPixels"));
        action_rulerPixels->setCheckable(true);
        action_rulerNormalized = new QAction(MainWindow);
        action_rulerNormalized->setObjectName(QString::fromUtf8("action_rulerNormalized"));
        action_rulerNormalized->setCheckable(true);
        action_aboutDialog = new QAction(MainWindow);
        action_aboutDialog->setObjectName(QString::fromUtf8("action_aboutDialog"));
        action_documentation = new QAction(MainWindow);
        action_documentation->setObjectName(QString::fromUtf8("action_documentation"));
        action_forums = new QAction(MainWindow);
        action_forums->setObjectName(QString::fromUtf8("action_forums"));
        actionOpen_Recent = new QAction(MainWindow);
        actionOpen_Recent->setObjectName(QString::fromUtf8("actionOpen_Recent"));
        action_normalScreen = new QAction(MainWindow);
        action_normalScreen->setObjectName(QString::fromUtf8("action_normalScreen"));
        action_normalScreen->setEnabled(false);
        action_normalScreen->setShortcutContext(Qt::ApplicationShortcut);
        action_normalScreen->setIconVisibleInMenu(true);
        action_outputTonemapped = new QAction(MainWindow);
        action_outputTonemapped->setObjectName(QString::fromUtf8("action_outputTonemapped"));
        action_outputHDR = new QAction(MainWindow);
        action_outputHDR->setObjectName(QString::fromUtf8("action_outputHDR"));
        action_outputBufferGroupsTonemapped = new QAction(MainWindow);
        action_outputBufferGroupsTonemapped->setObjectName(QString::fromUtf8("action_outputBufferGroupsTonemapped"));
        action_outputBufferGroupsHDR = new QAction(MainWindow);
        action_outputBufferGroupsHDR->setObjectName(QString::fromUtf8("action_outputBufferGroupsHDR"));
        action_batchProcess = new QAction(MainWindow);
        action_batchProcess->setObjectName(QString::fromUtf8("action_batchProcess"));
        action_useAlpha = new QAction(MainWindow);
        action_useAlpha->setObjectName(QString::fromUtf8("action_useAlpha"));
        action_useAlpha->setCheckable(true);
        action_useAlphaHDR = new QAction(MainWindow);
        action_useAlphaHDR->setObjectName(QString::fromUtf8("action_useAlphaHDR"));
        action_useAlphaHDR->setCheckable(true);
        action_useAlphaHDR->setVisible(false);
        action_overlayStats = new QAction(MainWindow);
        action_overlayStats->setObjectName(QString::fromUtf8("action_overlayStats"));
        action_overlayStats->setCheckable(true);
        action_HDR_tonemapped = new QAction(MainWindow);
        action_HDR_tonemapped->setObjectName(QString::fromUtf8("action_HDR_tonemapped"));
        action_HDR_tonemapped->setCheckable(true);
        action_gallery = new QAction(MainWindow);
        action_gallery->setObjectName(QString::fromUtf8("action_gallery"));
        action_bugtracker = new QAction(MainWindow);
        action_bugtracker->setObjectName(QString::fromUtf8("action_bugtracker"));
        action_Save_Panel_Settings = new QAction(MainWindow);
        action_Save_Panel_Settings->setObjectName(QString::fromUtf8("action_Save_Panel_Settings"));
        action_Load_Panel_Settings = new QAction(MainWindow);
        action_Load_Panel_Settings->setObjectName(QString::fromUtf8("action_Load_Panel_Settings"));
        action_Show_Side_Panel = new QAction(MainWindow);
        action_Show_Side_Panel->setObjectName(QString::fromUtf8("action_Show_Side_Panel"));
        action_Show_Side_Panel->setCheckable(true);
        action_Show_Side_Panel->setChecked(true);
        action_Show_Side_Panel->setShortcutContext(Qt::ApplicationShortcut);
        action_showAlphaView = new QAction(MainWindow);
        action_showAlphaView->setObjectName(QString::fromUtf8("action_showAlphaView"));
        action_showAlphaView->setCheckable(true);
        action_showUserSamplingMapView = new QAction(MainWindow);
        action_showUserSamplingMapView->setObjectName(QString::fromUtf8("action_showUserSamplingMapView"));
        action_showUserSamplingMapView->setCheckable(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabs_main = new QTabWidget(centralwidget);
        tabs_main->setObjectName(QString::fromUtf8("tabs_main"));
        tabs_main->setMinimumSize(QSize(751, 521));
        tab_render = new QWidget();
        tab_render->setObjectName(QString::fromUtf8("tab_render"));
        tab_render->setEnabled(true);
        sizePolicy.setHeightForWidth(tab_render->sizePolicy().hasHeightForWidth());
        tab_render->setSizePolicy(sizePolicy);
        gridLayout_12 = new QGridLayout(tab_render);
        gridLayout_12->setContentsMargins(12, 12, 12, 12);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_12->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, -1, 0, -1);
        writeIntervalLabel_1 = new QLabel(tab_render);
        writeIntervalLabel_1->setObjectName(QString::fromUtf8("writeIntervalLabel_1"));
        writeIntervalLabel_1->setPixmap(QPixmap(QString::fromUtf8(":/icons/analogclockicon.png")));
        writeIntervalLabel_1->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(writeIntervalLabel_1);

        writeIntervalLabel_2 = new QLabel(tab_render);
        writeIntervalLabel_2->setObjectName(QString::fromUtf8("writeIntervalLabel_2"));
        writeIntervalLabel_2->setPixmap(QPixmap(QString::fromUtf8(":/icons/arrowicon.png")));
        writeIntervalLabel_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(writeIntervalLabel_2);

        writeIntervalLabel_3 = new QLabel(tab_render);
        writeIntervalLabel_3->setObjectName(QString::fromUtf8("writeIntervalLabel_3"));
        writeIntervalLabel_3->setMinimumSize(QSize(22, 0));
        writeIntervalLabel_3->setPixmap(QPixmap(QString::fromUtf8(":/icons/imageicon.png")));
        writeIntervalLabel_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(writeIntervalLabel_3);

        spinBox_overrideWriteInterval = new QSpinBox(tab_render);
        spinBox_overrideWriteInterval->setObjectName(QString::fromUtf8("spinBox_overrideWriteInterval"));
        spinBox_overrideWriteInterval->setMinimumSize(QSize(75, 0));
        spinBox_overrideWriteInterval->setMinimum(3);
        spinBox_overrideWriteInterval->setMaximum(3600);
        spinBox_overrideWriteInterval->setSingleStep(60);
        spinBox_overrideWriteInterval->setValue(300);

        horizontalLayout_5->addWidget(spinBox_overrideWriteInterval);

        writeIntervalHorizontalSpacer = new QSpacerItem(7, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(writeIntervalHorizontalSpacer);

        displayIntervalLabel_1 = new QLabel(tab_render);
        displayIntervalLabel_1->setObjectName(QString::fromUtf8("displayIntervalLabel_1"));
        displayIntervalLabel_1->setPixmap(QPixmap(QString::fromUtf8(":/icons/analogclockicon.png")));
        displayIntervalLabel_1->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(displayIntervalLabel_1);

        displayIntervalLabel_2 = new QLabel(tab_render);
        displayIntervalLabel_2->setObjectName(QString::fromUtf8("displayIntervalLabel_2"));
        displayIntervalLabel_2->setPixmap(QPixmap(QString::fromUtf8(":/icons/arrowicon.png")));
        displayIntervalLabel_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(displayIntervalLabel_2);

        displayIntervalLabel_3 = new QLabel(tab_render);
        displayIntervalLabel_3->setObjectName(QString::fromUtf8("displayIntervalLabel_3"));
        displayIntervalLabel_3->setMinimumSize(QSize(22, 0));
        displayIntervalLabel_3->setPixmap(QPixmap(QString::fromUtf8(":/icons/viewicon.png")));
        displayIntervalLabel_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(displayIntervalLabel_3);

        spinBox_overrideDisplayInterval = new QSpinBox(tab_render);
        spinBox_overrideDisplayInterval->setObjectName(QString::fromUtf8("spinBox_overrideDisplayInterval"));
        spinBox_overrideDisplayInterval->setMinimumSize(QSize(75, 0));
        spinBox_overrideDisplayInterval->setMinimum(3);
        spinBox_overrideDisplayInterval->setMaximum(3600);
        spinBox_overrideDisplayInterval->setSingleStep(10);
        spinBox_overrideDisplayInterval->setValue(3);

        horizontalLayout_5->addWidget(spinBox_overrideDisplayInterval);

        resolutioniconLabel = new QLabel(tab_render);
        resolutioniconLabel->setObjectName(QString::fromUtf8("resolutioniconLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(resolutioniconLabel->sizePolicy().hasHeightForWidth());
        resolutioniconLabel->setSizePolicy(sizePolicy1);
        resolutioniconLabel->setMinimumSize(QSize(30, 0));
        resolutioniconLabel->setTextFormat(Qt::AutoText);
        resolutioniconLabel->setScaledContents(false);
        resolutioniconLabel->setAlignment(Qt::AlignCenter);
        resolutioniconLabel->setWordWrap(false);
        resolutioniconLabel->setMargin(0);

        horizontalLayout_5->addWidget(resolutioniconLabel);

        resinfoLabel = new QLabel(tab_render);
        resinfoLabel->setObjectName(QString::fromUtf8("resinfoLabel"));
        resinfoLabel->setMinimumSize(QSize(0, 0));
        resinfoLabel->setFrameShape(QFrame::Box);
        resinfoLabel->setFrameShadow(QFrame::Sunken);

        horizontalLayout_5->addWidget(resinfoLabel);

        zoomiconlabel = new QLabel(tab_render);
        zoomiconlabel->setObjectName(QString::fromUtf8("zoomiconlabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(zoomiconlabel->sizePolicy().hasHeightForWidth());
        zoomiconlabel->setSizePolicy(sizePolicy2);
        zoomiconlabel->setMinimumSize(QSize(30, 0));
        zoomiconlabel->setLineWidth(1);
        zoomiconlabel->setPixmap(QPixmap(QString::fromUtf8(":/icons/zoomicon.png")));
        zoomiconlabel->setScaledContents(false);
        zoomiconlabel->setAlignment(Qt::AlignCenter);
        zoomiconlabel->setMargin(0);
        zoomiconlabel->setIndent(-1);

        horizontalLayout_5->addWidget(zoomiconlabel);

        zoominfoLabel = new QLabel(tab_render);
        zoominfoLabel->setObjectName(QString::fromUtf8("zoominfoLabel"));
        zoominfoLabel->setMinimumSize(QSize(0, 0));
        zoominfoLabel->setFrameShape(QFrame::Box);
        zoominfoLabel->setFrameShadow(QFrame::Sunken);
        zoominfoLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(zoominfoLabel);


        gridLayout_12->addLayout(horizontalLayout_5, 0, 5, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setHorizontalSpacing(-1);
        button_resume = new QToolButton(tab_render);
        button_resume->setObjectName(QString::fromUtf8("button_resume"));
        button_resume->setIcon(icon1);

        gridLayout_4->addWidget(button_resume, 0, 0, 1, 1);

        button_pause = new QToolButton(tab_render);
        button_pause->setObjectName(QString::fromUtf8("button_pause"));
        button_pause->setIcon(icon2);

        gridLayout_4->addWidget(button_pause, 0, 1, 1, 1);

        button_stop = new QToolButton(tab_render);
        button_stop->setObjectName(QString::fromUtf8("button_stop"));
        button_stop->setIcon(icon3);

        gridLayout_4->addWidget(button_stop, 0, 2, 1, 1);

        line = new QFrame(tab_render);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line, 0, 3, 1, 1);

        label_threadCount = new QLabel(tab_render);
        label_threadCount->setObjectName(QString::fromUtf8("label_threadCount"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_threadCount->sizePolicy().hasHeightForWidth());
        label_threadCount->setSizePolicy(sizePolicy3);
        label_threadCount->setMinimumSize(QSize(0, 0));
        label_threadCount->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_threadCount, 0, 4, 1, 1);

        spinBox_Threads = new QSpinBox(tab_render);
        spinBox_Threads->setObjectName(QString::fromUtf8("spinBox_Threads"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(spinBox_Threads->sizePolicy().hasHeightForWidth());
        spinBox_Threads->setSizePolicy(sizePolicy4);
        spinBox_Threads->setMinimumSize(QSize(44, 0));
        spinBox_Threads->setLayoutDirection(Qt::LeftToRight);
        spinBox_Threads->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        spinBox_Threads->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBox_Threads->setKeyboardTracking(false);
        spinBox_Threads->setMinimum(1);
        spinBox_Threads->setMaximum(32);
        spinBox_Threads->setValue(4);

        gridLayout_4->addWidget(spinBox_Threads, 0, 5, 1, 1);

        line_2 = new QFrame(tab_render);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(line_2->sizePolicy().hasHeightForWidth());
        line_2->setSizePolicy(sizePolicy5);
        line_2->setMinimumSize(QSize(40, 0));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_2, 0, 6, 1, 1);

        button_copyToClipboard = new QToolButton(tab_render);
        button_copyToClipboard->setObjectName(QString::fromUtf8("button_copyToClipboard"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/clipboardicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_copyToClipboard->setIcon(icon4);

        gridLayout_4->addWidget(button_copyToClipboard, 0, 7, 1, 1);

        gridLayout_4->setColumnMinimumWidth(4, 90);

        gridLayout_12->addLayout(gridLayout_4, 0, 0, 1, 1);

        splitter = new QSplitter(tab_render);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setEnabled(true);
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setMinimumSize(QSize(768, 0));
        splitter->setOrientation(Qt::Horizontal);
        outputTabs = new QTabWidget(splitter);
        outputTabs->setObjectName(QString::fromUtf8("outputTabs"));
        outputTabs->setEnabled(true);
        sizePolicy.setHeightForWidth(outputTabs->sizePolicy().hasHeightForWidth());
        outputTabs->setSizePolicy(sizePolicy);
        outputTabs->setMinimumSize(QSize(380, 0));
        outputTabs->setMaximumSize(QSize(500, 16777215));
        outputTabs->setElideMode(Qt::ElideRight);
        outputTabs->setUsesScrollButtons(false);
        tab_imaging = new QWidget();
        tab_imaging->setObjectName(QString::fromUtf8("tab_imaging"));
        tab_imaging->setEnabled(true);
        QSizePolicy sizePolicy6(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(tab_imaging->sizePolicy().hasHeightForWidth());
        tab_imaging->setSizePolicy(sizePolicy6);
        gridLayout_29 = new QGridLayout(tab_imaging);
        gridLayout_29->setObjectName(QString::fromUtf8("gridLayout_29"));
        gridLayout_29->setContentsMargins(4, 4, 4, 0);
        button_imagingReset = new QPushButton(tab_imaging);
        button_imagingReset->setObjectName(QString::fromUtf8("button_imagingReset"));
        button_imagingReset->setEnabled(true);
        QSizePolicy sizePolicy7(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(button_imagingReset->sizePolicy().hasHeightForWidth());
        button_imagingReset->setSizePolicy(sizePolicy7);

        gridLayout_29->addWidget(button_imagingReset, 1, 0, 1, 1);

        checkBox_imagingAuto = new QCheckBox(tab_imaging);
        checkBox_imagingAuto->setObjectName(QString::fromUtf8("checkBox_imagingAuto"));
        checkBox_imagingAuto->setEnabled(true);
        sizePolicy7.setHeightForWidth(checkBox_imagingAuto->sizePolicy().hasHeightForWidth());
        checkBox_imagingAuto->setSizePolicy(sizePolicy7);
        checkBox_imagingAuto->setMinimumSize(QSize(48, 0));
        checkBox_imagingAuto->setChecked(true);

        gridLayout_29->addWidget(checkBox_imagingAuto, 1, 1, 1, 1);

        button_imagingApply = new QPushButton(tab_imaging);
        button_imagingApply->setObjectName(QString::fromUtf8("button_imagingApply"));
        button_imagingApply->setEnabled(true);
        QSizePolicy sizePolicy8(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(button_imagingApply->sizePolicy().hasHeightForWidth());
        button_imagingApply->setSizePolicy(sizePolicy8);
        button_imagingApply->setMinimumSize(QSize(200, 0));

        gridLayout_29->addWidget(button_imagingApply, 1, 3, 1, 1);

        panesArea = new QScrollArea(tab_imaging);
        panesArea->setObjectName(QString::fromUtf8("panesArea"));
        panesArea->setFrameShape(QFrame::NoFrame);
        panesArea->setWidgetResizable(true);
        panesAreaContents = new QWidget();
        panesAreaContents->setObjectName(QString::fromUtf8("panesAreaContents"));
        panesAreaContents->setGeometry(QRect(0, 0, 362, 363));
        QSizePolicy sizePolicy9(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(panesAreaContents->sizePolicy().hasHeightForWidth());
        panesAreaContents->setSizePolicy(sizePolicy9);
        verticalLayout = new QVBoxLayout(panesAreaContents);
        verticalLayout->setContentsMargins(4, 4, 4, 4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        panesLayout = new QVBoxLayout();
        panesLayout->setObjectName(QString::fromUtf8("panesLayout"));
        panesLayout->setContentsMargins(-1, -1, 0, -1);

        verticalLayout->addLayout(panesLayout);

        panesArea->setWidget(panesAreaContents);

        gridLayout_29->addWidget(panesArea, 0, 0, 1, 4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_29->addItem(horizontalSpacer, 1, 2, 1, 1);

        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/tonemapicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        outputTabs->addTab(tab_imaging, icon5, QString());
        tab_lightGroups = new QWidget();
        tab_lightGroups->setObjectName(QString::fromUtf8("tab_lightGroups"));
        sizePolicy6.setHeightForWidth(tab_lightGroups->sizePolicy().hasHeightForWidth());
        tab_lightGroups->setSizePolicy(sizePolicy6);
        verticalLayout_15 = new QVBoxLayout(tab_lightGroups);
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        verticalLayout_15->setContentsMargins(6, 4, 6, 4);
        lightGroupsArea = new QScrollArea(tab_lightGroups);
        lightGroupsArea->setObjectName(QString::fromUtf8("lightGroupsArea"));
        lightGroupsArea->setFrameShape(QFrame::NoFrame);
        lightGroupsArea->setWidgetResizable(true);
        lightGroupsAreaContents = new QWidget();
        lightGroupsAreaContents->setObjectName(QString::fromUtf8("lightGroupsAreaContents"));
        lightGroupsAreaContents->setGeometry(QRect(0, 0, 100, 30));
        verticalLayout_3 = new QVBoxLayout(lightGroupsAreaContents);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(4, 4, 4, 0);
        lightGroupsLayout = new QVBoxLayout();
        lightGroupsLayout->setObjectName(QString::fromUtf8("lightGroupsLayout"));
        lightGroupsLayout->setContentsMargins(-1, -1, 0, -1);

        verticalLayout_3->addLayout(lightGroupsLayout);

        lightGroupsArea->setWidget(lightGroupsAreaContents);

        verticalLayout_15->addWidget(lightGroupsArea);

        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/lightgroupsicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        outputTabs->addTab(tab_lightGroups, icon6, QString());
        tab_usersampling = new QWidget();
        tab_usersampling->setObjectName(QString::fromUtf8("tab_usersampling"));
        tab_usersampling->setEnabled(true);
        sizePolicy6.setHeightForWidth(tab_usersampling->sizePolicy().hasHeightForWidth());
        tab_usersampling->setSizePolicy(sizePolicy6);
        gridLayout_3 = new QGridLayout(tab_usersampling);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        scrollArea = new QScrollArea(tab_usersampling);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        userSamplingArea = new QWidget();
        userSamplingArea->setObjectName(QString::fromUtf8("userSamplingArea"));
        userSamplingArea->setGeometry(QRect(0, 0, 339, 324));
        gridLayout_2 = new QGridLayout(userSamplingArea);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 10, 0, 1, 4);

        button_usAddPenButton = new QPushButton(userSamplingArea);
        button_usAddPenButton->setObjectName(QString::fromUtf8("button_usAddPenButton"));

        gridLayout_2->addWidget(button_usAddPenButton, 1, 0, 1, 2);

        button_usSubPenButton = new QPushButton(userSamplingArea);
        button_usSubPenButton->setObjectName(QString::fromUtf8("button_usSubPenButton"));

        gridLayout_2->addWidget(button_usSubPenButton, 1, 2, 1, 2);

        label_2 = new QLabel(userSamplingArea);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_2, 0, 0, 1, 4);

        button_usResetButton = new QPushButton(userSamplingArea);
        button_usResetButton->setObjectName(QString::fromUtf8("button_usResetButton"));

        gridLayout_2->addWidget(button_usResetButton, 11, 0, 1, 2);

        button_usApplyButton = new QPushButton(userSamplingArea);
        button_usApplyButton->setObjectName(QString::fromUtf8("button_usApplyButton"));

        gridLayout_2->addWidget(button_usApplyButton, 12, 0, 1, 4);

        button_usUndoButton = new QPushButton(userSamplingArea);
        button_usUndoButton->setObjectName(QString::fromUtf8("button_usUndoButton"));

        gridLayout_2->addWidget(button_usUndoButton, 11, 2, 1, 2);

        label_3 = new QLabel(userSamplingArea);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_3, 3, 0, 1, 4);

        slider_usPenSize = new QSlider(userSamplingArea);
        slider_usPenSize->setObjectName(QString::fromUtf8("slider_usPenSize"));
        slider_usPenSize->setMinimum(8);
        slider_usPenSize->setMaximum(512);
        slider_usPenSize->setValue(50);
        slider_usPenSize->setOrientation(Qt::Horizontal);
        slider_usPenSize->setInvertedAppearance(false);
        slider_usPenSize->setInvertedControls(false);
        slider_usPenSize->setTickPosition(QSlider::TicksBelow);
        slider_usPenSize->setTickInterval(10);

        gridLayout_2->addWidget(slider_usPenSize, 4, 0, 1, 4);

        label_4 = new QLabel(userSamplingArea);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_4, 7, 0, 1, 4);

        slider_usOpacity = new QSlider(userSamplingArea);
        slider_usOpacity->setObjectName(QString::fromUtf8("slider_usOpacity"));
        slider_usOpacity->setMaximum(100);
        slider_usOpacity->setValue(50);
        slider_usOpacity->setOrientation(Qt::Horizontal);
        slider_usOpacity->setTickPosition(QSlider::TicksBelow);
        slider_usOpacity->setTickInterval(10);

        gridLayout_2->addWidget(slider_usOpacity, 8, 0, 1, 4);

        label_5 = new QLabel(userSamplingArea);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_5, 5, 0, 1, 4);

        slider_usPenStrength = new QSlider(userSamplingArea);
        slider_usPenStrength->setObjectName(QString::fromUtf8("slider_usPenStrength"));
        slider_usPenStrength->setMinimum(1);
        slider_usPenStrength->setMaximum(100);
        slider_usPenStrength->setValue(10);
        slider_usPenStrength->setOrientation(Qt::Horizontal);
        slider_usPenStrength->setTickPosition(QSlider::TicksBelow);
        slider_usPenStrength->setTickInterval(10);

        gridLayout_2->addWidget(slider_usPenStrength, 6, 0, 1, 4);

        scrollArea->setWidget(userSamplingArea);

        gridLayout_3->addWidget(scrollArea, 0, 0, 1, 1);

        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/mappainticon.png"), QSize(), QIcon::Normal, QIcon::Off);
        outputTabs->addTab(tab_usersampling, icon7, QString());
        tab_advanced = new QWidget();
        tab_advanced->setObjectName(QString::fromUtf8("tab_advanced"));
        sizePolicy6.setHeightForWidth(tab_advanced->sizePolicy().hasHeightForWidth());
        tab_advanced->setSizePolicy(sizePolicy6);
        verticalLayout_18 = new QVBoxLayout(tab_advanced);
        verticalLayout_18->setSpacing(6);
        verticalLayout_18->setObjectName(QString::fromUtf8("verticalLayout_18"));
        verticalLayout_18->setContentsMargins(6, 4, 6, 4);
        advancedArea = new QScrollArea(tab_advanced);
        advancedArea->setObjectName(QString::fromUtf8("advancedArea"));
        advancedArea->setFrameShape(QFrame::NoFrame);
        advancedArea->setWidgetResizable(true);
        advancedAreaContents = new QWidget();
        advancedAreaContents->setObjectName(QString::fromUtf8("advancedAreaContents"));
        advancedAreaContents->setGeometry(QRect(0, 0, 100, 30));
        sizePolicy9.setHeightForWidth(advancedAreaContents->sizePolicy().hasHeightForWidth());
        advancedAreaContents->setSizePolicy(sizePolicy9);
        verticalLayout_4 = new QVBoxLayout(advancedAreaContents);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(4, 4, 4, 0);
        advancedLayout = new QVBoxLayout();
        advancedLayout->setObjectName(QString::fromUtf8("advancedLayout"));
        advancedLayout->setContentsMargins(-1, -1, 0, -1);

        verticalLayout_4->addLayout(advancedLayout);

        advancedArea->setWidget(advancedAreaContents);

        verticalLayout_18->addWidget(advancedArea);

        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icons/advancedicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        outputTabs->addTab(tab_advanced, icon8, QString());
        splitter->addWidget(outputTabs);
        frame_render = new QFrame(splitter);
        frame_render->setObjectName(QString::fromUtf8("frame_render"));
        frame_render->setEnabled(true);
        sizePolicy.setHeightForWidth(frame_render->sizePolicy().hasHeightForWidth());
        frame_render->setSizePolicy(sizePolicy);
        frame_render->setMinimumSize(QSize(400, 0));
        frame_render->setBaseSize(QSize(270, 0));
        frame_render->setFrameShape(QFrame::Panel);
        frame_render->setFrameShadow(QFrame::Sunken);
        renderLayout = new QGridLayout(frame_render);
        renderLayout->setContentsMargins(0, 0, 0, 0);
        renderLayout->setObjectName(QString::fromUtf8("renderLayout"));
        splitter->addWidget(frame_render);

        gridLayout_12->addWidget(splitter, 1, 0, 1, 6);

        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icons/rendertabicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabs_main->addTab(tab_render, icon9, QString());
        tab_queue = new QWidget();
        tab_queue->setObjectName(QString::fromUtf8("tab_queue"));
        sizePolicy.setHeightForWidth(tab_queue->sizePolicy().hasHeightForWidth());
        tab_queue->setSizePolicy(sizePolicy);
        gridLayout_13 = new QGridLayout(tab_queue);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        tree_queue = new QTreeView(tab_queue);
        tree_queue->setObjectName(QString::fromUtf8("tree_queue"));
        tree_queue->header()->setStretchLastSection(false);

        gridLayout_13->addWidget(tree_queue, 4, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        button_addQueueFiles = new QToolButton(tab_queue);
        button_addQueueFiles->setObjectName(QString::fromUtf8("button_addQueueFiles"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icons/plusicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_addQueueFiles->setIcon(icon10);
        button_addQueueFiles->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_6->addWidget(button_addQueueFiles);

        button_removeQueueFiles = new QToolButton(tab_queue);
        button_removeQueueFiles->setObjectName(QString::fromUtf8("button_removeQueueFiles"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/icons/minusicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_removeQueueFiles->setIcon(icon11);

        horizontalLayout_6->addWidget(button_removeQueueFiles);

        groupBox_haltConditions = new QGroupBox(tab_queue);
        groupBox_haltConditions->setObjectName(QString::fromUtf8("groupBox_haltConditions"));
        sizePolicy3.setHeightForWidth(groupBox_haltConditions->sizePolicy().hasHeightForWidth());
        groupBox_haltConditions->setSizePolicy(sizePolicy3);
        groupBox_haltConditions->setMinimumSize(QSize(458, 40));
        verticalLayout_2 = new QVBoxLayout(groupBox_haltConditions);
        verticalLayout_2->setSpacing(-1);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_haltConditions = new QHBoxLayout();
        horizontalLayout_haltConditions->setObjectName(QString::fromUtf8("horizontalLayout_haltConditions"));
        checkBox_haltTime = new QCheckBox(groupBox_haltConditions);
        checkBox_haltTime->setObjectName(QString::fromUtf8("checkBox_haltTime"));
        checkBox_haltTime->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_haltConditions->addWidget(checkBox_haltTime);

        timeEdit_overrideHaltTime = new QTimeEdit(groupBox_haltConditions);
        timeEdit_overrideHaltTime->setObjectName(QString::fromUtf8("timeEdit_overrideHaltTime"));
        timeEdit_overrideHaltTime->setEnabled(false);
        QSizePolicy sizePolicy10(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy10.setHorizontalStretch(0);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(timeEdit_overrideHaltTime->sizePolicy().hasHeightForWidth());
        timeEdit_overrideHaltTime->setSizePolicy(sizePolicy10);
        timeEdit_overrideHaltTime->setMinimumSize(QSize(0, 0));
        timeEdit_overrideHaltTime->setKeyboardTracking(false);
        timeEdit_overrideHaltTime->setTime(QTime(23, 59, 59));
        timeEdit_overrideHaltTime->setMinimumTime(QTime(0, 0, 1));
        timeEdit_overrideHaltTime->setCalendarPopup(false);

        horizontalLayout_haltConditions->addWidget(timeEdit_overrideHaltTime);

        checkBox_haltProgress = new QCheckBox(groupBox_haltConditions);
        checkBox_haltProgress->setObjectName(QString::fromUtf8("checkBox_haltProgress"));
        checkBox_haltProgress->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_haltConditions->addWidget(checkBox_haltProgress);

        spinBox_overrideHaltProgress = new QSpinBox(groupBox_haltConditions);
        spinBox_overrideHaltProgress->setObjectName(QString::fromUtf8("spinBox_overrideHaltProgress"));
        spinBox_overrideHaltProgress->setEnabled(false);
        spinBox_overrideHaltProgress->setMinimumSize(QSize(0, 0));
        spinBox_overrideHaltProgress->setKeyboardTracking(false);
        spinBox_overrideHaltProgress->setMinimum(1);
        spinBox_overrideHaltProgress->setMaximum(10000);
        spinBox_overrideHaltProgress->setSingleStep(50);
        spinBox_overrideHaltProgress->setValue(10000);

        horizontalLayout_haltConditions->addWidget(spinBox_overrideHaltProgress);

        checkBox_haltThreshold = new QCheckBox(groupBox_haltConditions);
        checkBox_haltThreshold->setObjectName(QString::fromUtf8("checkBox_haltThreshold"));
        checkBox_haltThreshold->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_haltConditions->addWidget(checkBox_haltThreshold);

        doubleSpinBox_overrideHaltThreshold = new QDoubleSpinBox(groupBox_haltConditions);
        doubleSpinBox_overrideHaltThreshold->setObjectName(QString::fromUtf8("doubleSpinBox_overrideHaltThreshold"));
        doubleSpinBox_overrideHaltThreshold->setEnabled(false);
        doubleSpinBox_overrideHaltThreshold->setMinimumSize(QSize(0, 0));
        doubleSpinBox_overrideHaltThreshold->setKeyboardTracking(false);
        doubleSpinBox_overrideHaltThreshold->setDecimals(3);
        doubleSpinBox_overrideHaltThreshold->setMaximum(100);
        doubleSpinBox_overrideHaltThreshold->setValue(100);

        horizontalLayout_haltConditions->addWidget(doubleSpinBox_overrideHaltThreshold);

        horizontalSpacer_4 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_haltConditions->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_haltConditions);


        horizontalLayout_6->addWidget(groupBox_haltConditions);

        groupBox_queueControls = new QGroupBox(tab_queue);
        groupBox_queueControls->setObjectName(QString::fromUtf8("groupBox_queueControls"));
        QSizePolicy sizePolicy11(QSizePolicy::Ignored, QSizePolicy::Preferred);
        sizePolicy11.setHorizontalStretch(0);
        sizePolicy11.setVerticalStretch(0);
        sizePolicy11.setHeightForWidth(groupBox_queueControls->sizePolicy().hasHeightForWidth());
        groupBox_queueControls->setSizePolicy(sizePolicy11);
        groupBox_queueControls->setMinimumSize(QSize(0, 40));
        verticalLayout_5 = new QVBoxLayout(groupBox_queueControls);
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_queueControls = new QHBoxLayout();
        horizontalLayout_queueControls->setObjectName(QString::fromUtf8("horizontalLayout_queueControls"));
        checkBox_loopQueue = new QCheckBox(groupBox_queueControls);
        checkBox_loopQueue->setObjectName(QString::fromUtf8("checkBox_loopQueue"));
        checkBox_loopQueue->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_queueControls->addWidget(checkBox_loopQueue);

        checkBox_overrideWriteFlm = new QCheckBox(groupBox_queueControls);
        checkBox_overrideWriteFlm->setObjectName(QString::fromUtf8("checkBox_overrideWriteFlm"));
        checkBox_overrideWriteFlm->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_queueControls->addWidget(checkBox_overrideWriteFlm);

        horizontalSpacer_5 = new QSpacerItem(10, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout_queueControls->addItem(horizontalSpacer_5);


        verticalLayout_5->addLayout(horizontalLayout_queueControls);


        horizontalLayout_6->addWidget(groupBox_queueControls);


        gridLayout_13->addLayout(horizontalLayout_6, 1, 0, 3, 1);

        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/icons/queuetabicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabs_main->addTab(tab_queue, icon12, QString());
        tab_network = new QWidget();
        tab_network->setObjectName(QString::fromUtf8("tab_network"));
        sizePolicy.setHeightForWidth(tab_network->sizePolicy().hasHeightForWidth());
        tab_network->setSizePolicy(sizePolicy);
        gridLayout_11 = new QGridLayout(tab_network);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        table_servers = new QTableWidget(tab_network);
        if (table_servers->columnCount() < 5)
            table_servers->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_servers->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_servers->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_servers->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table_servers->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table_servers->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        table_servers->setObjectName(QString::fromUtf8("table_servers"));
        table_servers->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table_servers->setSelectionMode(QAbstractItemView::SingleSelection);
        table_servers->setSelectionBehavior(QAbstractItemView::SelectRows);
        table_servers->setWordWrap(true);
        table_servers->horizontalHeader()->setHighlightSections(false);

        gridLayout_11->addWidget(table_servers, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_servers = new QLabel(tab_network);
        label_servers->setObjectName(QString::fromUtf8("label_servers"));

        horizontalLayout_3->addWidget(label_servers);

        lineEdit_server = new QLineEdit(tab_network);
        lineEdit_server->setObjectName(QString::fromUtf8("lineEdit_server"));

        horizontalLayout_3->addWidget(lineEdit_server);

        button_addServer = new QToolButton(tab_network);
        button_addServer->setObjectName(QString::fromUtf8("button_addServer"));
        button_addServer->setIcon(icon10);

        horizontalLayout_3->addWidget(button_addServer);

        button_removeServer = new QToolButton(tab_network);
        button_removeServer->setObjectName(QString::fromUtf8("button_removeServer"));
        button_removeServer->setIcon(icon11);

        horizontalLayout_3->addWidget(button_removeServer);

        button_resetServer = new QToolButton(tab_network);
        button_resetServer->setObjectName(QString::fromUtf8("button_resetServer"));
        sizePolicy3.setHeightForWidth(button_resetServer->sizePolicy().hasHeightForWidth());
        button_resetServer->setSizePolicy(sizePolicy3);

        horizontalLayout_3->addWidget(button_resetServer);

        line_3 = new QFrame(tab_network);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_3);

        label_interval = new QLabel(tab_network);
        label_interval->setObjectName(QString::fromUtf8("label_interval"));

        horizontalLayout_3->addWidget(label_interval);

        comboBox_updateInterval = new QComboBox(tab_network);
        comboBox_updateInterval->setObjectName(QString::fromUtf8("comboBox_updateInterval"));
        sizePolicy10.setHeightForWidth(comboBox_updateInterval->sizePolicy().hasHeightForWidth());
        comboBox_updateInterval->setSizePolicy(sizePolicy10);
        comboBox_updateInterval->setMinimumSize(QSize(100, 0));
        comboBox_updateInterval->setEditable(true);
        comboBox_updateInterval->setInsertPolicy(QComboBox::NoInsert);

        horizontalLayout_3->addWidget(comboBox_updateInterval);


        gridLayout_11->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        label_serversStatus = new QLabel(tab_network);
        label_serversStatus->setObjectName(QString::fromUtf8("label_serversStatus"));

        gridLayout_11->addWidget(label_serversStatus, 3, 0, 1, 1);

        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/icons/networktabicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabs_main->addTab(tab_network, icon13, QString());
        tab_log = new QWidget();
        tab_log->setObjectName(QString::fromUtf8("tab_log"));
        sizePolicy.setHeightForWidth(tab_log->sizePolicy().hasHeightForWidth());
        tab_log->setSizePolicy(sizePolicy);
        gridLayout_9 = new QGridLayout(tab_log);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        textEdit_log = new QTextEdit(tab_log);
        textEdit_log->setObjectName(QString::fromUtf8("textEdit_log"));
        textEdit_log->setReadOnly(true);

        gridLayout_9->addWidget(textEdit_log, 6, 0, 1, 1);

        horizontalLayout_log = new QHBoxLayout();
        horizontalLayout_log->setObjectName(QString::fromUtf8("horizontalLayout_log"));
        horizontalLayout_log->setContentsMargins(0, 0, -1, -1);
        label_verbosity = new QLabel(tab_log);
        label_verbosity->setObjectName(QString::fromUtf8("label_verbosity"));

        horizontalLayout_log->addWidget(label_verbosity);

        comboBox_verbosity = new QComboBox(tab_log);
        comboBox_verbosity->setObjectName(QString::fromUtf8("comboBox_verbosity"));
        comboBox_verbosity->setMaxVisibleItems(4);

        horizontalLayout_log->addWidget(comboBox_verbosity);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_log->addItem(horizontalSpacer_3);


        gridLayout_9->addLayout(horizontalLayout_log, 1, 0, 1, 1);

        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/icons/logtabicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabs_main->addTab(tab_log, icon14, QString());

        gridLayout->addWidget(tabs_main, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 775, 22));
        menubar->setNativeMenuBar(false);
        menu_render = new QMenu(menubar);
        menu_render->setObjectName(QString::fromUtf8("menu_render"));
        menu_view = new QMenu(menubar);
        menu_view->setObjectName(QString::fromUtf8("menu_view"));
        menu_help = new QMenu(menubar);
        menu_help->setObjectName(QString::fromUtf8("menu_help"));
        menu_file = new QMenu(menubar);
        menu_file->setObjectName(QString::fromUtf8("menu_file"));
        menuOpen_Recent = new QMenu(menu_file);
        menuOpen_Recent->setObjectName(QString::fromUtf8("menuOpen_Recent"));
        menuExport_to_Image = new QMenu(menu_file);
        menuExport_to_Image->setObjectName(QString::fromUtf8("menuExport_to_Image"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
#ifndef QT_NO_SHORTCUT
        label_servers->setBuddy(lineEdit_server);
        label_interval->setBuddy(comboBox_updateInterval);
#endif // QT_NO_SHORTCUT

        menubar->addAction(menu_file->menuAction());
        menubar->addAction(menu_render->menuAction());
        menubar->addAction(menu_view->menuAction());
        menubar->addAction(menu_help->menuAction());
        menu_render->addAction(action_resumeRender);
        menu_render->addAction(action_pauseRender);
        menu_render->addAction(action_stopRender);
        menu_render->addAction(action_endRender);
        menu_view->addAction(action_copyLog);
        menu_view->addAction(action_clearLog);
        menu_view->addSeparator();
        menu_view->addAction(action_fullScreen);
        menu_view->addAction(action_normalScreen);
        menu_view->addAction(action_overlayStatsView);
        menu_view->addAction(action_showAlphaView);
        menu_view->addAction(action_showUserSamplingMapView);
        menu_view->addSeparator();
        menu_view->addAction(action_Show_Side_Panel);
        menu_help->addAction(action_documentation);
        menu_help->addAction(action_forums);
        menu_help->addAction(action_gallery);
        menu_help->addAction(action_bugtracker);
        menu_help->addSeparator();
        menu_help->addAction(action_aboutDialog);
        menu_file->addAction(action_openFile);
        menu_file->addAction(menuOpen_Recent->menuAction());
        menu_file->addSeparator();
        menu_file->addAction(action_resumeFLM);
        menu_file->addAction(action_loadFLM);
        menu_file->addAction(action_saveFLM);
        menu_file->addSeparator();
        menu_file->addAction(action_Save_Panel_Settings);
        menu_file->addAction(action_Load_Panel_Settings);
        menu_file->addSeparator();
        menu_file->addAction(menuExport_to_Image->menuAction());
        menu_file->addSeparator();
        menu_file->addAction(action_exitAppSave);
        menu_file->addAction(action_exitApp);
        menuExport_to_Image->addAction(action_outputTonemapped);
        menuExport_to_Image->addAction(action_outputBufferGroupsTonemapped);
        menuExport_to_Image->addAction(action_useAlpha);
        menuExport_to_Image->addAction(action_overlayStats);
        menuExport_to_Image->addSeparator();
        menuExport_to_Image->addAction(action_outputHDR);
        menuExport_to_Image->addAction(action_outputBufferGroupsHDR);
        menuExport_to_Image->addAction(action_HDR_tonemapped);
        menuExport_to_Image->addAction(action_useAlphaHDR);
        menuExport_to_Image->addSeparator();
        menuExport_to_Image->addSeparator();
        menuExport_to_Image->addAction(action_batchProcess);

        retranslateUi(MainWindow);
        QObject::connect(action_exitApp, SIGNAL(triggered()), MainWindow, SLOT(close()));

        tabs_main->setCurrentIndex(0);
        outputTabs->setCurrentIndex(0);
        comboBox_verbosity->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "LuxRender", 0, QApplication::UnicodeUTF8));
        action_openFile->setText(QApplication::translate("MainWindow", "Open...", 0, QApplication::UnicodeUTF8));
        action_openFile->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        action_resumeFLM->setText(QApplication::translate("MainWindow", "Resume FLM...", 0, QApplication::UnicodeUTF8));
        action_loadFLM->setText(QApplication::translate("MainWindow", "Load FLM...", 0, QApplication::UnicodeUTF8));
        action_saveFLM->setText(QApplication::translate("MainWindow", "Save FLM...", 0, QApplication::UnicodeUTF8));
        action_exitAppSave->setText(QApplication::translate("MainWindow", "Save and Exit", 0, QApplication::UnicodeUTF8));
        action_exitAppSave->setShortcut(QApplication::translate("MainWindow", "Alt+Shift+Q", 0, QApplication::UnicodeUTF8));
        action_exitApp->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        action_exitApp->setShortcut(QApplication::translate("MainWindow", "Alt+Q", 0, QApplication::UnicodeUTF8));
        action_resumeRender->setText(QApplication::translate("MainWindow", "Resume", 0, QApplication::UnicodeUTF8));
        action_resumeRender->setShortcut(QApplication::translate("MainWindow", "Ctrl+Alt+R", 0, QApplication::UnicodeUTF8));
        action_pauseRender->setText(QApplication::translate("MainWindow", "Pause", 0, QApplication::UnicodeUTF8));
        action_pauseRender->setShortcut(QApplication::translate("MainWindow", "Ctrl+Alt+P", 0, QApplication::UnicodeUTF8));
        action_stopRender->setText(QApplication::translate("MainWindow", "Stop", 0, QApplication::UnicodeUTF8));
        action_stopRender->setShortcut(QApplication::translate("MainWindow", "Ctrl+Alt+S", 0, QApplication::UnicodeUTF8));
        action_endRender->setText(QApplication::translate("MainWindow", "End Rendering", 0, QApplication::UnicodeUTF8));
        action_viewToolbar->setText(QApplication::translate("MainWindow", "Toolbar", 0, QApplication::UnicodeUTF8));
        action_viewStatusbar->setText(QApplication::translate("MainWindow", "Statusbar", 0, QApplication::UnicodeUTF8));
        action_viewSidePane->setText(QApplication::translate("MainWindow", "Side pane", 0, QApplication::UnicodeUTF8));
        action_panMode->setText(QApplication::translate("MainWindow", "Pan mode", 0, QApplication::UnicodeUTF8));
        action_zoomMode->setText(QApplication::translate("MainWindow", "Zoom mode", 0, QApplication::UnicodeUTF8));
        action_copyLog->setText(QApplication::translate("MainWindow", "Copy Log", 0, QApplication::UnicodeUTF8));
        action_copyLog->setShortcut(QApplication::translate("MainWindow", "Ctrl+Alt+C", 0, QApplication::UnicodeUTF8));
        action_clearLog->setText(QApplication::translate("MainWindow", "Clear Log", 0, QApplication::UnicodeUTF8));
        action_clearLog->setShortcut(QApplication::translate("MainWindow", "Ctrl+Alt+W", 0, QApplication::UnicodeUTF8));
        action_overlayStatsView->setText(QApplication::translate("MainWindow", "Overlay Statistics", 0, QApplication::UnicodeUTF8));
        action_overlayStatsView->setShortcut(QApplication::translate("MainWindow", "Ctrl+Alt+O", 0, QApplication::UnicodeUTF8));
        action_fullScreen->setText(QApplication::translate("MainWindow", "Full Screen", 0, QApplication::UnicodeUTF8));
        action_fullScreen->setShortcut(QApplication::translate("MainWindow", "Ctrl+Alt+F", 0, QApplication::UnicodeUTF8));
        action_rulerDisabled->setText(QApplication::translate("MainWindow", "Disabled", 0, QApplication::UnicodeUTF8));
        action_rulerPixels->setText(QApplication::translate("MainWindow", "Pixels", 0, QApplication::UnicodeUTF8));
        action_rulerNormalized->setText(QApplication::translate("MainWindow", "Normalized", 0, QApplication::UnicodeUTF8));
        action_aboutDialog->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        action_documentation->setText(QApplication::translate("MainWindow", "Online Documentation", 0, QApplication::UnicodeUTF8));
        action_forums->setText(QApplication::translate("MainWindow", "Forums", 0, QApplication::UnicodeUTF8));
        actionOpen_Recent->setText(QApplication::translate("MainWindow", "Open Recent", 0, QApplication::UnicodeUTF8));
        action_normalScreen->setText(QApplication::translate("MainWindow", "Normal Screen", 0, QApplication::UnicodeUTF8));
        action_normalScreen->setIconText(QApplication::translate("MainWindow", "Normal Screen", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_normalScreen->setToolTip(QApplication::translate("MainWindow", "Normal screen", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_normalScreen->setShortcut(QApplication::translate("MainWindow", "Esc", 0, QApplication::UnicodeUTF8));
        action_outputTonemapped->setText(QApplication::translate("MainWindow", "Tonemapped Low Dynamic Range Image...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_outputTonemapped->setToolTip(QApplication::translate("MainWindow", "Save the current framebuffer (with tonemapping) to a standard image file.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_outputHDR->setText(QApplication::translate("MainWindow", "High Dynamic Range Image...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_outputHDR->setToolTip(QApplication::translate("MainWindow", "Save the current image in a high dynamic range, floating-point image format.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_outputBufferGroupsTonemapped->setText(QApplication::translate("MainWindow", "Light Groups to Tonemapped LDR Images...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_outputBufferGroupsTonemapped->setToolTip(QApplication::translate("MainWindow", "Save the each individual light group as a tonemapped image.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_outputBufferGroupsHDR->setText(QApplication::translate("MainWindow", "Light Groups to High Dynamic Range Images...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_outputBufferGroupsHDR->setToolTip(QApplication::translate("MainWindow", "Save the each individual light group as an OpenEXR image in high dynamic range.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_batchProcess->setText(QApplication::translate("MainWindow", "Batch Process FLM files...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_batchProcess->setToolTip(QApplication::translate("MainWindow", "Process a directory of 'flm' film files.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_useAlpha->setText(QApplication::translate("MainWindow", "Output Alpha Channel", 0, QApplication::UnicodeUTF8));
        action_useAlphaHDR->setText(QApplication::translate("MainWindow", "Output HDR Alpha Channel", 0, QApplication::UnicodeUTF8));
        action_overlayStats->setText(QApplication::translate("MainWindow", "Overlay Statistics", 0, QApplication::UnicodeUTF8));
        action_HDR_tonemapped->setText(QApplication::translate("MainWindow", "Output HDR Images Tonemapped", 0, QApplication::UnicodeUTF8));
        action_gallery->setText(QApplication::translate("MainWindow", "Gallery", 0, QApplication::UnicodeUTF8));
        action_bugtracker->setText(QApplication::translate("MainWindow", "Bug Tracker", 0, QApplication::UnicodeUTF8));
        action_Save_Panel_Settings->setText(QApplication::translate("MainWindow", "Save Panel Settings...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_Save_Panel_Settings->setToolTip(QApplication::translate("MainWindow", "Save Settings for the tonemapping, lightgroups and gamma panels to a .ini file", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        action_Save_Panel_Settings->setStatusTip(QApplication::translate("MainWindow", "Save Settings for the tonemapping, lightgroups and gamma panels to a .ini file", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        action_Load_Panel_Settings->setText(QApplication::translate("MainWindow", "Load Panel Settings...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_Load_Panel_Settings->setToolTip(QApplication::translate("MainWindow", "Load Settings for the tonemapping, lightgroups and gamma panels from a .ini file", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        action_Load_Panel_Settings->setStatusTip(QApplication::translate("MainWindow", "Load Settings for the tonemapping, lightgroups and gamma panels from a .ini file", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        action_Show_Side_Panel->setText(QApplication::translate("MainWindow", "Show Side Panel", 0, QApplication::UnicodeUTF8));
        action_Show_Side_Panel->setShortcut(QApplication::translate("MainWindow", "Ctrl+Alt+I", 0, QApplication::UnicodeUTF8));
        action_showAlphaView->setText(QApplication::translate("MainWindow", "Show Alpha", 0, QApplication::UnicodeUTF8));
        action_showAlphaView->setShortcut(QApplication::translate("MainWindow", "Ctrl+Alt+A", 0, QApplication::UnicodeUTF8));
        action_showUserSamplingMapView->setText(QApplication::translate("MainWindow", "Show Sampling Map", 0, QApplication::UnicodeUTF8));
        action_showUserSamplingMapView->setShortcut(QApplication::translate("MainWindow", "Ctrl+Alt+U", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        spinBox_overrideWriteInterval->setToolTip(QApplication::translate("MainWindow", "Override write interval (seconds)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        spinBox_overrideWriteInterval->setSuffix(QApplication::translate("MainWindow", " sec", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        spinBox_overrideDisplayInterval->setToolTip(QApplication::translate("MainWindow", "Override display interval (seconds)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        spinBox_overrideDisplayInterval->setSuffix(QApplication::translate("MainWindow", " sec", 0, QApplication::UnicodeUTF8));
        resolutioniconLabel->setText(QString());
        resinfoLabel->setText(QString());
        zoomiconlabel->setText(QString());
        zoominfoLabel->setText(QString());
#ifndef QT_NO_TOOLTIP
        button_resume->setToolTip(QApplication::translate("MainWindow", "Resume rendering", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        button_resume->setText(QString());
#ifndef QT_NO_TOOLTIP
        button_pause->setToolTip(QApplication::translate("MainWindow", "Pause current rendering", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        button_pause->setText(QApplication::translate("MainWindow", "||", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        button_stop->setToolTip(QApplication::translate("MainWindow", "Stop current rendering", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        button_stop->setText(QApplication::translate("MainWindow", "[]", 0, QApplication::UnicodeUTF8));
        label_threadCount->setText(QApplication::translate("MainWindow", "Threads:", 0, QApplication::UnicodeUTF8));
        spinBox_Threads->setPrefix(QString());
#ifndef QT_NO_TOOLTIP
        button_copyToClipboard->setToolTip(QApplication::translate("MainWindow", "Copy rendering image to clipboard.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        button_copyToClipboard->setText(QApplication::translate("MainWindow", "[]", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        button_imagingReset->setToolTip(QApplication::translate("MainWindow", "Reset Tone Mapping to default values", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        button_imagingReset->setText(QApplication::translate("MainWindow", "Reset", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox_imagingAuto->setToolTip(QApplication::translate("MainWindow", "Enable automatic updates", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        checkBox_imagingAuto->setText(QApplication::translate("MainWindow", "Auto", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        button_imagingApply->setToolTip(QApplication::translate("MainWindow", "Apply changes", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        button_imagingApply->setText(QApplication::translate("MainWindow", "Apply", 0, QApplication::UnicodeUTF8));
        outputTabs->setTabText(outputTabs->indexOf(tab_imaging), QApplication::translate("MainWindow", "Imaging", 0, QApplication::UnicodeUTF8));
        outputTabs->setTabText(outputTabs->indexOf(tab_lightGroups), QApplication::translate("MainWindow", "Light Groups", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        button_usAddPenButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Use add importance pen</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        button_usAddPenButton->setText(QApplication::translate("MainWindow", "Add Importance Pen", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        button_usSubPenButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Use subtract importance pen</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        button_usSubPenButton->setText(QApplication::translate("MainWindow", "Sub. Importance Pen", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Pen type:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        button_usResetButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Reset the sampling map</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        button_usResetButton->setText(QApplication::translate("MainWindow", "Reset", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        button_usApplyButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Apply changes</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        button_usApplyButton->setText(QApplication::translate("MainWindow", "Apply", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        button_usUndoButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Back to the last applied map</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        button_usUndoButton->setText(QApplication::translate("MainWindow", "Undo", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Pen size:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Overlay opacity:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Pen strength:", 0, QApplication::UnicodeUTF8));
        outputTabs->setTabText(outputTabs->indexOf(tab_usersampling), QApplication::translate("MainWindow", "Refine Brush", 0, QApplication::UnicodeUTF8));
        outputTabs->setTabText(outputTabs->indexOf(tab_advanced), QApplication::translate("MainWindow", "Advanced", 0, QApplication::UnicodeUTF8));
        tabs_main->setTabText(tabs_main->indexOf(tab_render), QApplication::translate("MainWindow", "Render", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        button_addQueueFiles->setToolTip(QApplication::translate("MainWindow", "Add files to queue", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        button_addQueueFiles->setText(QApplication::translate("MainWindow", "Add files...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        button_removeQueueFiles->setToolTip(QApplication::translate("MainWindow", "Remove selected files from queue", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        button_removeQueueFiles->setText(QApplication::translate("MainWindow", "Remove files", 0, QApplication::UnicodeUTF8));
        groupBox_haltConditions->setTitle(QApplication::translate("MainWindow", "Override scene halt conditions", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox_haltTime->setToolTip(QApplication::translate("MainWindow", "Override the halt time condition", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        checkBox_haltTime->setText(QApplication::translate("MainWindow", "Time", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        timeEdit_overrideHaltTime->setToolTip(QApplication::translate("MainWindow", "Time to render", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        timeEdit_overrideHaltTime->setDisplayFormat(QApplication::translate("MainWindow", "HH:mm:ss", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox_haltProgress->setToolTip(QApplication::translate("MainWindow", "Override the halt sample-per-pixel or passes condition", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        checkBox_haltProgress->setText(QApplication::translate("MainWindow", "Progress", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        spinBox_overrideHaltProgress->setToolTip(QApplication::translate("MainWindow", "Average sample-per-pixel or passes to render", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        checkBox_haltThreshold->setToolTip(QApplication::translate("MainWindow", "Override the noise elimination threshold", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        checkBox_haltThreshold->setText(QApplication::translate("MainWindow", "Noise", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        doubleSpinBox_overrideHaltThreshold->setToolTip(QApplication::translate("MainWindow", "Convergence threshold to render", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        doubleSpinBox_overrideHaltThreshold->setSuffix(QApplication::translate("MainWindow", "%", 0, QApplication::UnicodeUTF8));
        groupBox_queueControls->setTitle(QApplication::translate("MainWindow", "Queue controls", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox_loopQueue->setToolTip(QApplication::translate("MainWindow", "Continuously loop queue", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        checkBox_loopQueue->setText(QApplication::translate("MainWindow", "Loop", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox_overrideWriteFlm->setToolTip(QApplication::translate("MainWindow", "Overrides writing and use of resume FLM file.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        checkBox_overrideWriteFlm->setText(QApplication::translate("MainWindow", "Write FLM", 0, QApplication::UnicodeUTF8));
        tabs_main->setTabText(tabs_main->indexOf(tab_queue), QApplication::translate("MainWindow", "Queue", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = table_servers->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Host", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = table_servers->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Port", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = table_servers->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Status", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = table_servers->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Progress", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = table_servers->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Rate", 0, QApplication::UnicodeUTF8));
        label_servers->setText(QApplication::translate("MainWindow", "Server:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit_server->setToolTip(QApplication::translate("MainWindow", "Type the address of a network server", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        button_addServer->setToolTip(QApplication::translate("MainWindow", "Add Server", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        button_addServer->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        button_removeServer->setToolTip(QApplication::translate("MainWindow", "Remove Server", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        button_removeServer->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        button_resetServer->setToolTip(QApplication::translate("MainWindow", "Reset Server", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        button_resetServer->setText(QApplication::translate("MainWindow", "Reset", 0, QApplication::UnicodeUTF8));
        label_interval->setText(QApplication::translate("MainWindow", "Update interval:", 0, QApplication::UnicodeUTF8));
        comboBox_updateInterval->clear();
        comboBox_updateInterval->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "60", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "180", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "900", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "1800", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "3600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "5400", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "7200", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        comboBox_updateInterval->setToolTip(QApplication::translate("MainWindow", "The number of seconds between server updates", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_serversStatus->setText(QString());
        tabs_main->setTabText(tabs_main->indexOf(tab_network), QApplication::translate("MainWindow", "Network", 0, QApplication::UnicodeUTF8));
        label_verbosity->setText(QApplication::translate("MainWindow", "Log Level:", 0, QApplication::UnicodeUTF8));
        comboBox_verbosity->clear();
        comboBox_verbosity->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Info", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Debug", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Warning", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Error", 0, QApplication::UnicodeUTF8)
        );
        tabs_main->setTabText(tabs_main->indexOf(tab_log), QApplication::translate("MainWindow", "Log", 0, QApplication::UnicodeUTF8));
        menu_render->setTitle(QApplication::translate("MainWindow", "&Render", 0, QApplication::UnicodeUTF8));
        menu_view->setTitle(QApplication::translate("MainWindow", "&View", 0, QApplication::UnicodeUTF8));
        menu_help->setTitle(QApplication::translate("MainWindow", "&Help", 0, QApplication::UnicodeUTF8));
        menu_file->setTitle(QApplication::translate("MainWindow", "&File", 0, QApplication::UnicodeUTF8));
        menuOpen_Recent->setTitle(QApplication::translate("MainWindow", "Open Recent", 0, QApplication::UnicodeUTF8));
        menuExport_to_Image->setTitle(QApplication::translate("MainWindow", "Export to Image", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LUXRENDER_H
