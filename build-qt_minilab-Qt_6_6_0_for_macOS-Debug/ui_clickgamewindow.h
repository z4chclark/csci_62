/********************************************************************************
** Form generated from reading UI file 'clickgamewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLICKGAMEWINDOW_H
#define UI_CLICKGAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClickGameWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ClickGameWindow)
    {
        if (ClickGameWindow->objectName().isEmpty())
            ClickGameWindow->setObjectName("ClickGameWindow");
        ClickGameWindow->resize(800, 600);
        centralwidget = new QWidget(ClickGameWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(290, 210, 100, 32));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(250, 180, 181, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(250, 50, 211, 31));
        ClickGameWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ClickGameWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 36));
        ClickGameWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ClickGameWindow);
        statusbar->setObjectName("statusbar");
        ClickGameWindow->setStatusBar(statusbar);

        retranslateUi(ClickGameWindow);

        QMetaObject::connectSlotsByName(ClickGameWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ClickGameWindow)
    {
        ClickGameWindow->setWindowTitle(QCoreApplication::translate("ClickGameWindow", "ClickGameWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("ClickGameWindow", "Click Me", nullptr));
        label->setText(QCoreApplication::translate("ClickGameWindow", "Number of Clicks: 0", nullptr));
        label_2->setText(QCoreApplication::translate("ClickGameWindow", "You Win!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClickGameWindow: public Ui_ClickGameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLICKGAMEWINDOW_H
