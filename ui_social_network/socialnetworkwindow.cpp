#include <stack>

#include "socialnetworkwindow.h"
#include "ui_socialnetworkwindow.h"
#include "network.h"
#include "user.h"

SocialNetworkWindow::SocialNetworkWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SocialNetworkWindow)
    , network(new Network)
    , logged_in_user(new User)
    , current_user(new User)
{
    network->read_users("social_network.txt");
    network->readPosts("posts.txt");

    ui->setupUi(this);
    loginPage();

    connect(ui->loginButton, &QPushButton::clicked, this, &SocialNetworkWindow::myLoginClick);

    connect(ui->friendList, &QTableWidget::cellClicked, this, &SocialNetworkWindow::friendListClick);

    connect(ui->homeButton, &QPushButton::clicked, this, &SocialNetworkWindow::homeButtonClick);

    connect(ui->addFriendButton, &QPushButton::clicked, this, &SocialNetworkWindow::addFriendButtonClick);

    connect(ui->suggestFriendList, &QTableWidget::cellClicked, this, &SocialNetworkWindow::suggestFriendListClick);

    connect(ui->backButton, &QPushButton::clicked, this, &SocialNetworkWindow::backButtonClick);


}

void SocialNetworkWindow::loginPage()
{
    ui->loginText->setText("");

    ui->loginButton->show();
    ui->loginLabel->show();
    ui->loginText->show();

    ui->profileLabel->hide();
    ui->friendList->hide();
    ui->suggestFriendList->hide();
    ui->postsLabel->hide();
    ui->homeButton->hide();
    ui->addFriendButton->hide();
    ui->backButton->hide();
}

void SocialNetworkWindow::myLoginClick()
{
    // get name of user and set them to logged in user
    std::string name = ui->loginText->toPlainText().toStdString();
    size_t id = network->get_id(name);
    if (!(id == std::string::npos))
    {
        ui->loginButton->hide();
        ui->loginLabel->hide();
        ui->loginText->hide();

        logged_in_user = network->get_user(id);
        current_user = network->get_user(id);

        userProfile();
    }
    else
    {
        ui->loginLabel->setText("Please enter valid name.");
        ui->loginText->clear();
    }

}

void SocialNetworkWindow::homeButtonClick()
{
    // add the current page to the stack and change the ui to the logged in user page
    backStack.push(current_user->get_name());
    userProfile();
}


void SocialNetworkWindow::friendListClick(int row, int column)
{
    backStack.push(current_user->get_name());

    std::string current_user_name = (ui->friendList->item(row, column)->text().toStdString()); // get user from cell
    current_user = network->get_user(network->get_id(current_user_name));

    if (current_user == logged_in_user)
    {
        userProfile();
    }
    else
    {
        friendProfile();
    }
}

void SocialNetworkWindow::userProfile()
{
    ui->profileLabel->show();
    ui->friendList->show();
    ui->postsLabel->show();
    ui->backButton->show();


    ui->profileLabel->setText("My Profile");
    ui->homeButton->hide();
    ui->addFriendButton->hide();
    ui->suggestFriendList->show();


    std::vector<size_t> friends = logged_in_user->get_friends(); //update freinds table
    ui->friendList->setRowCount(friends.size());
    ui->friendList->setColumnCount(1);

    int count = 0;
    for (size_t amigo : friends) // update friends table
    {
        QString qstr = QString::fromStdString(network->get_user(amigo)->get_name());
        QTableWidgetItem *friend_name = new QTableWidgetItem(qstr);

        ui->friendList->setItem(count, 0, friend_name);
        count++;
    }

    count = 0;
    size_t score;
    std::vector<size_t> suggested_friends = network->suggestFriends(logged_in_user->get_id(), score);
    ui->suggestFriendList->setRowCount(suggested_friends.size());
    ui->suggestFriendList->setColumnCount(1);
    for (size_t suggested_friend : suggested_friends) // update suggested friends table
    {
        QString qstr = QString::fromStdString(network->get_user(suggested_friend)->get_name());
        QTableWidgetItem *friend_name = new QTableWidgetItem(qstr);

        ui->suggestFriendList->setItem(count, 0, friend_name);
        count++;
    }

    QString posts = QString::fromStdString(network->displayPost(logged_in_user->get_name(), 5, false));
    ui->postsLabel->setText(posts); // set posts for logged in user

}


void SocialNetworkWindow::friendProfile()
{
    QString banner = QString::fromStdString(current_user->get_name() + "'s Profile");
    ui->profileLabel->setText(banner);

    std::vector<size_t> friends = current_user->get_friends();
    ui->friendList->setRowCount(friends.size());

    ui->homeButton->show(); // show home button
    ui->addFriendButton->show();
    ui->suggestFriendList->hide();

    int count = 0;
    for (size_t amigo : friends) // update friends table
    {
        QString qstr = QString::fromStdString(network->get_user(amigo)->get_name());
        QTableWidgetItem *friend_name = new QTableWidgetItem(qstr);

        ui->friendList->setItem(count, 0, friend_name);
        count++;
    }

    QString posts = QString::fromStdString(network->displayPost(current_user->get_name(), 5, true));
    ui->postsLabel->setText(posts);

}

void SocialNetworkWindow::suggestFriendListClick(int row, int column)
{
    // add friend to friends list and update userProfile
    std::string current_user_name = (ui->suggestFriendList->item(row, column)->text().toStdString()); // get user from cell

    network->add_connection(logged_in_user->get_name(), current_user_name);
    userProfile();

}

void SocialNetworkWindow::addFriendButtonClick()
{
    network->add_connection(logged_in_user->get_name(), current_user->get_name());
}

void SocialNetworkWindow::backButtonClick()

{
    // send us to login page if stack empty otherwise send us to previous page

    if (backStack.empty())
    {
        loginPage();
    }
    else if (backStack.top() == logged_in_user->get_name())
    {
        backStack.pop();
        userProfile();
    }
    else
    {
        current_user = network->get_user(network->get_id(backStack.top()));
        backStack.pop();
        friendProfile();
    }
}

SocialNetworkWindow::~SocialNetworkWindow()
{
    delete ui;
}

