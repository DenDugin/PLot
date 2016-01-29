/********************************************************************************
** Form generated from reading UI file 'new_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEW_DIALOG_H
#define UI_NEW_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include "../../qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_new_Dialog
{
public:
    QGridLayout *gridLayout;
    QCustomPlot *plot;
    QCustomPlot *plot_2;

    void setupUi(QDialog *new_Dialog)
    {
        if (new_Dialog->objectName().isEmpty())
            new_Dialog->setObjectName(QStringLiteral("new_Dialog"));
        new_Dialog->resize(850, 655);
        gridLayout = new QGridLayout(new_Dialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        plot = new QCustomPlot(new_Dialog);
        plot->setObjectName(QStringLiteral("plot"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plot->sizePolicy().hasHeightForWidth());
        plot->setSizePolicy(sizePolicy);
        plot->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(plot, 0, 0, 1, 1);

        plot_2 = new QCustomPlot(new_Dialog);
        plot_2->setObjectName(QStringLiteral("plot_2"));
        sizePolicy.setHeightForWidth(plot_2->sizePolicy().hasHeightForWidth());
        plot_2->setSizePolicy(sizePolicy);
        plot_2->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(plot_2, 1, 0, 1, 1);


        retranslateUi(new_Dialog);

        QMetaObject::connectSlotsByName(new_Dialog);
    } // setupUi

    void retranslateUi(QDialog *new_Dialog)
    {
        new_Dialog->setWindowTitle(QApplication::translate("new_Dialog", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class new_Dialog: public Ui_new_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEW_DIALOG_H
