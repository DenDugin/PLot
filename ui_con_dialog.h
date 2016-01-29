/********************************************************************************
** Form generated from reading UI file 'con_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CON_DIALOG_H
#define UI_CON_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include "../../qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_con_Dialog
{
public:
    QGridLayout *gridLayout;
    QCustomPlot *plot;

    void setupUi(QDialog *con_Dialog)
    {
        if (con_Dialog->objectName().isEmpty())
            con_Dialog->setObjectName(QStringLiteral("con_Dialog"));
        con_Dialog->resize(807, 560);
        gridLayout = new QGridLayout(con_Dialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        plot = new QCustomPlot(con_Dialog);
        plot->setObjectName(QStringLiteral("plot"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plot->sizePolicy().hasHeightForWidth());
        plot->setSizePolicy(sizePolicy);
        plot->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(plot, 0, 0, 1, 1);


        retranslateUi(con_Dialog);

        QMetaObject::connectSlotsByName(con_Dialog);
    } // setupUi

    void retranslateUi(QDialog *con_Dialog)
    {
        con_Dialog->setWindowTitle(QApplication::translate("con_Dialog", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class con_Dialog: public Ui_con_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CON_DIALOG_H
