/********************************************************************************
** Form generated from reading UI file 'socialnetworkwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOCIALNETWORKWINDOW_H
#define UI_SOCIALNETWORKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SocialNetworkWindow
{
public:
    QWidget *centralwidget;
    QLabel *loginLabel;
    QPushButton *loginButton;
    QTextEdit *loginText;
    QLabel *profileLabel;
    QTableWidget *friendList;
    QLabel *posts;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SocialNetworkWindow)
    {
        if (SocialNetworkWindow->objectName().isEmpty())
            SocialNetworkWindow->setObjectName("SocialNetworkWindow");
        SocialNetworkWindow->resize(800, 600);
        centralwidget = new QWidget(SocialNetworkWindow);
        centralwidget->setObjectName("centralwidget");
        loginLabel = new QLabel(centralwidget);
        loginLabel->setObjectName("loginLabel");
        loginLabel->setGeometry(QRect(340, 150, 171, 16));
        loginButton = new QPushButton(centralwidget);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(340, 190, 100, 32));
        loginText = new QTextEdit(centralwidget);
        loginText->setObjectName("loginText");
        loginText->setGeometry(QRect(340, 170, 104, 16));
        profileLabel = new QLabel(centralwidget);
        profileLabel->setObjectName("profileLabel");
        profileLabel->setGeometry(QRect(340, 20, 101, 81));
        profileLabel->setAutoFillBackground(false);
        profileLabel->setScaledContents(false);
        friendList = new QTableWidget(centralwidget);
        if (friendList->columnCount() < 1)
            friendList->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        friendList->setHorizontalHeaderItem(0, __qtablewidgetitem);
        friendList->setObjectName("friendList");
        friendList->setGeometry(QRect(10, 330, 256, 192));
        posts = new QLabel(centralwidget);
        posts->setObjectName("posts");
        posts->setGeometry(QRect(340, 240, 131, 221));
        SocialNetworkWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SocialNetworkWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 36));
        SocialNetworkWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SocialNetworkWindow);
        statusbar->setObjectName("statusbar");
        SocialNetworkWindow->setStatusBar(statusbar);

        retranslateUi(SocialNetworkWindow);

        QMetaObject::connectSlotsByName(SocialNetworkWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SocialNetworkWindow)
    {
        SocialNetworkWindow->setWindowTitle(QCoreApplication::translate("SocialNetworkWindow", "SocialNetworkWindow", nullptr));
        loginLabel->setText(QCoreApplication::translate("SocialNetworkWindow", "Enter your name.", nullptr));
        loginButton->setText(QCoreApplication::translate("SocialNetworkWindow", "Login", nullptr));
        profileLabel->setText(QCoreApplication::translate("SocialNetworkWindow", "My Profile", nullptr));
        QTableWidgetItem *___qtablewidgetitem = friendList->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("SocialNetworkWindow", "New Column", nullptr));
        posts->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SocialNetworkWindow: public Ui_SocialNetworkWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOCIALNETWORKWINDOW_H
