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
    QLabel *postsLabel;
    QPushButton *homeButton;
    QPushButton *addFriendButton;
    QTableWidget *suggestFriendList;
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
        loginLabel->setGeometry(QRect(310, 150, 171, 16));
        loginLabel->setAlignment(Qt::AlignCenter);
        loginButton = new QPushButton(centralwidget);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(340, 190, 111, 32));
        loginText = new QTextEdit(centralwidget);
        loginText->setObjectName("loginText");
        loginText->setGeometry(QRect(340, 170, 111, 16));
        profileLabel = new QLabel(centralwidget);
        profileLabel->setObjectName("profileLabel");
        profileLabel->setGeometry(QRect(260, 20, 271, 51));
        profileLabel->setAutoFillBackground(false);
        profileLabel->setScaledContents(false);
        profileLabel->setAlignment(Qt::AlignCenter);
        friendList = new QTableWidget(centralwidget);
        if (friendList->columnCount() < 1)
            friendList->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        friendList->setHorizontalHeaderItem(0, __qtablewidgetitem);
        friendList->setObjectName("friendList");
        friendList->setEnabled(true);
        friendList->setGeometry(QRect(0, 320, 221, 201));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(friendList->sizePolicy().hasHeightForWidth());
        friendList->setSizePolicy(sizePolicy);
        friendList->setShowGrid(false);
        friendList->horizontalHeader()->setVisible(true);
        friendList->horizontalHeader()->setCascadingSectionResizes(false);
        friendList->horizontalHeader()->setDefaultSectionSize(200);
        friendList->horizontalHeader()->setHighlightSections(true);
        postsLabel = new QLabel(centralwidget);
        postsLabel->setObjectName("postsLabel");
        postsLabel->setGeometry(QRect(230, 240, 561, 261));
        homeButton = new QPushButton(centralwidget);
        homeButton->setObjectName("homeButton");
        homeButton->setGeometry(QRect(10, 10, 100, 32));
        addFriendButton = new QPushButton(centralwidget);
        addFriendButton->setObjectName("addFriendButton");
        addFriendButton->setGeometry(QRect(10, 40, 100, 32));
        suggestFriendList = new QTableWidget(centralwidget);
        if (suggestFriendList->columnCount() < 1)
            suggestFriendList->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        suggestFriendList->setHorizontalHeaderItem(0, __qtablewidgetitem1);
        suggestFriendList->setObjectName("suggestFriendList");
        suggestFriendList->setGeometry(QRect(565, 10, 221, 192));
        suggestFriendList->horizontalHeader()->setMinimumSectionSize(19);
        suggestFriendList->horizontalHeader()->setDefaultSectionSize(200);
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
        profileLabel->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = friendList->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("SocialNetworkWindow", "Friends", nullptr));
        postsLabel->setText(QString());
        homeButton->setText(QCoreApplication::translate("SocialNetworkWindow", "Home", nullptr));
        addFriendButton->setText(QCoreApplication::translate("SocialNetworkWindow", "Add Friend", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = suggestFriendList->horizontalHeaderItem(0);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("SocialNetworkWindow", "Suggested Friends", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SocialNetworkWindow: public Ui_SocialNetworkWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOCIALNETWORKWINDOW_H
