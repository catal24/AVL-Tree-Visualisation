/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *closeButton;
    QLabel *label_2;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout_3;
    QLineEdit *nr;
    QPushButton *pushButton;
    QLineEdit *nrs;
    QPushButton *button;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1043, 574);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        closeButton = new QPushButton(centralWidget);
        closeButton->setObjectName("closeButton");
        closeButton->setGeometry(QRect(20, 140, 93, 28));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(280, 20, 63, 20));
        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(20, 50, 221, 80));
        formLayout_3 = new QFormLayout(formLayoutWidget);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName("formLayout_3");
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        nr = new QLineEdit(formLayoutWidget);
        nr->setObjectName("nr");

        formLayout_3->setWidget(0, QFormLayout::LabelRole, nr);

        pushButton = new QPushButton(formLayoutWidget);
        pushButton->setObjectName("pushButton");

        formLayout_3->setWidget(0, QFormLayout::FieldRole, pushButton);

        nrs = new QLineEdit(formLayoutWidget);
        nrs->setObjectName("nrs");

        formLayout_3->setWidget(1, QFormLayout::LabelRole, nrs);

        button = new QPushButton(formLayoutWidget);
        button->setObjectName("button");

        formLayout_3->setWidget(1, QFormLayout::FieldRole, button);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "AVL Grafic", nullptr));
        closeButton->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        label_2->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "insereaza", nullptr));
        button->setText(QCoreApplication::translate("MainWindow", "sterge", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
