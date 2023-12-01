#ifndef SOCIALNETWORKWINDOW_H
#define SOCIALNETWORKWINDOW_H

#include <QMainWindow>
#include <stack>
#include "network.h"
#include "user.h"


QT_BEGIN_NAMESPACE
namespace Ui { class SocialNetworkWindow; }
QT_END_NAMESPACE

class SocialNetworkWindow : public QMainWindow
{
    Q_OBJECT

public:
    SocialNetworkWindow(QWidget *parent = nullptr);
    ~SocialNetworkWindow();

    void loginPage();
    void myLoginClick();
    void homeButtonClick();
    void friendListClick(int row, int column);
    void userProfile();
    void friendProfile();
    void addFriendButtonClick();
    void suggestFriendListClick(int row, int column);
    void backButtonClick();

private:
    Ui::SocialNetworkWindow *ui;
    Network *network;
    User *logged_in_user;
    User *current_user;
    std::stack<User*> backStack;

};
#endif // SOCIALNETWORKWINDOW_H
