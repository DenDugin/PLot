/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "../../qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionInsert_Plot;
    QAction *actionSave_Document;
    QAction *actionSpectr;
    QAction *actionStatis;
    QAction *actionOpenFile;
    QAction *actionCos_sin;
    QAction *actionConstilation;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QScrollBar *horizontalScrollBar;
    QScrollBar *verticalScrollBar;
    QSpinBox *spinBox;
    QSlider *h_Slider;
    QCustomPlot *plot;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuSpectr;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(528, 598);
        actionInsert_Plot = new QAction(MainWindow);
        actionInsert_Plot->setObjectName(QStringLiteral("actionInsert_Plot"));
        actionSave_Document = new QAction(MainWindow);
        actionSave_Document->setObjectName(QStringLiteral("actionSave_Document"));
        actionSpectr = new QAction(MainWindow);
        actionSpectr->setObjectName(QStringLiteral("actionSpectr"));
        actionSpectr->setCheckable(true);
        actionStatis = new QAction(MainWindow);
        actionStatis->setObjectName(QStringLiteral("actionStatis"));
        actionStatis->setCheckable(true);
        actionOpenFile = new QAction(MainWindow);
        actionOpenFile->setObjectName(QStringLiteral("actionOpenFile"));
        actionOpenFile->setCheckable(true);
        actionCos_sin = new QAction(MainWindow);
        actionCos_sin->setObjectName(QStringLiteral("actionCos_sin"));
        actionCos_sin->setCheckable(true);
        actionConstilation = new QAction(MainWindow);
        actionConstilation->setObjectName(QStringLiteral("actionConstilation"));
        actionConstilation->setCheckable(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalScrollBar = new QScrollBar(centralWidget);
        horizontalScrollBar->setObjectName(QStringLiteral("horizontalScrollBar"));
        horizontalScrollBar->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalScrollBar, 1, 0, 1, 1);

        verticalScrollBar = new QScrollBar(centralWidget);
        verticalScrollBar->setObjectName(QStringLiteral("verticalScrollBar"));
        verticalScrollBar->setOrientation(Qt::Vertical);

        gridLayout->addWidget(verticalScrollBar, 0, 1, 1, 1);

        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        gridLayout->addWidget(spinBox, 4, 0, 1, 1);

        h_Slider = new QSlider(centralWidget);
        h_Slider->setObjectName(QStringLiteral("h_Slider"));
        h_Slider->setMinimumSize(QSize(25, 0));
        h_Slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(h_Slider, 3, 0, 1, 1);

        plot = new QCustomPlot(centralWidget);
        plot->setObjectName(QStringLiteral("plot"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plot->sizePolicy().hasHeightForWidth());
        plot->setSizePolicy(sizePolicy);
        pushButton = new QPushButton(plot);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(40, 10, 21, 23));
        pushButton_2 = new QPushButton(plot);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(70, 10, 21, 23));

        gridLayout->addWidget(plot, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        h_Slider->raise();
        plot->raise();
        verticalScrollBar->raise();
        horizontalScrollBar->raise();
        spinBox->raise();
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 528, 21));
        menuSpectr = new QMenu(menuBar);
        menuSpectr->setObjectName(QStringLiteral("menuSpectr"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuSpectr->menuAction());
        menuSpectr->addAction(actionOpenFile);
        menuSpectr->addAction(actionSpectr);
        menuSpectr->addAction(actionStatis);
        menuSpectr->addAction(actionCos_sin);
        menuSpectr->addAction(actionConstilation);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "QCustomPlot Scrollbar Axis Range Control Demo", 0));
        actionInsert_Plot->setText(QApplication::translate("MainWindow", "Insert Plot", 0));
        actionSave_Document->setText(QApplication::translate("MainWindow", "Save Document...", 0));
        actionSpectr->setText(QApplication::translate("MainWindow", "Spectr", 0));
        actionStatis->setText(QApplication::translate("MainWindow", "Statis", 0));
        actionOpenFile->setText(QApplication::translate("MainWindow", "OpenFile", 0));
        actionCos_sin->setText(QApplication::translate("MainWindow", "Re_Im", 0));
        actionConstilation->setText(QApplication::translate("MainWindow", "Constilation", 0));
        pushButton->setText(QApplication::translate("MainWindow", "+", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "-", 0));
        menuSpectr->setTitle(QApplication::translate("MainWindow", "Menu", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
