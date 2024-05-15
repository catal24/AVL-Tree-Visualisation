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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *button;
    QLabel *label;
    QPushButton *closeButton;
    QLineEdit *nr;
    QPushButton *pushButton;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QMenuBar *menuBar;
    QMenu *menuok;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(611, 398);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        button = new QPushButton(centralWidget);
        button->setObjectName("button");
        button->setGeometry(QRect(410, 10, 93, 28));
        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(240, 300, 111, 20));
        closeButton = new QPushButton(centralWidget);
        closeButton->setObjectName("closeButton");
        closeButton->setGeometry(QRect(420, 290, 93, 28));
        nr = new QLineEdit(centralWidget);
        nr->setObjectName("nr");
        nr->setGeometry(QRect(20, 10, 113, 28));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(150, 10, 83, 29));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(280, 20, 63, 20));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(280, 10, 113, 28));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 611, 25));
        menuok = new QMenu(menuBar);
        menuok->setObjectName("menuok");
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuok->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Cea mai fereastra", nullptr));
        button->setText(QCoreApplication::translate("MainWindow", "sterge", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "adauga numaru", nullptr));
        closeButton->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "insereaza", nullptr));
        label_2->setText(QString());
        menuok->setTitle(QCoreApplication::translate("MainWindow", "ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
