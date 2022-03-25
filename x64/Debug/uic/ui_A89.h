/********************************************************************************
** Form generated from reading UI file 'A89.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_A89_H
#define UI_A89_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_A89Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *A89Class)
    {
        if (A89Class->objectName().isEmpty())
            A89Class->setObjectName(QString::fromUtf8("A89Class"));
        A89Class->resize(600, 400);
        menuBar = new QMenuBar(A89Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        A89Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(A89Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        A89Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(A89Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        A89Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(A89Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        A89Class->setStatusBar(statusBar);

        retranslateUi(A89Class);

        QMetaObject::connectSlotsByName(A89Class);
    } // setupUi

    void retranslateUi(QMainWindow *A89Class)
    {
        A89Class->setWindowTitle(QCoreApplication::translate("A89Class", "A89", nullptr));
    } // retranslateUi

};

namespace Ui {
    class A89Class: public Ui_A89Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_A89_H
