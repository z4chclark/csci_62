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
    ui->setupUi(this);
    ui->profileLabel->hide();
    ui->friendList->hide();
    ui->suggestFriendList->hide();
    ui->postsLabel->hide();
    ui->homeButton->hide();
    ui->addFriendButton->hide();

    network->read_users("social_network.txt");
    network->readPosts("posts.txt");

    connect(ui->loginButton, &QPushButton::clicked, this, &SocialNetworkWindow::myLoginClick);
    //connect(ui->loginButton, &QKeyEvent:: , this, &SocialNetworkWindow::myLoginClick);

    connect(ui->friendList, &QTableWidget::cellClicked, this, &SocialNetworkWindow::friendListClick);

    connect(ui->homeButton, &QPushButton::clicked, this, &SocialNetworkWindow::homeButtonClick);

    connect(ui->addFriendButton, &QPushButton::clicked, this, &SocialNetworkWindow::addFriendButtonClick);

    connect(ui->suggestFriendList, &QTableWidget::cellClicked, this, &SocialNetworkWindow::suggestFriendListClick);



}

void SocialNetworkWindow::myLoginClick()
{
    std::string name = ui->loginText->toPlainText().toStdString();
    size_t id = network->get_id(name);
    if (!(id == std::string::npos))
    {

        ui->loginButton->hide(); // hide login page
        ui->loginLabel->hide();
        ui->loginText->hide();
        logged_in_user = network->get_user(id);
        current_user = network->get_user(id);

        userProfile();

        ui->profileLabel->show();
        ui->friendList->show();
        ui->postsLabel->show();
    }
    else
    {
        ui->loginLabel->setText("Please enter valid name.");
        ui->loginText->clear();
    }


}


void SocialNetworkWindow::friendListClick(int row, int column)
{

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




    QString posts = QString::fromStdString(logged_in_user->displayPosts(5, false));
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

    QString posts = QString::fromStdString(current_user->displayPosts(5, true));
    ui->postsLabel->setText(posts);


}

void SocialNetworkWindow::suggestFriendListClick(int row, int column)
{
    std::string current_user_name = (ui->suggestFriendList->item(row, column)->text().toStdString()); // get user from cell

    //std::cout << current_user_name << std::endl;

    network->add_connection(logged_in_user->get_name(), current_user_name);
    userProfile();

}



void SocialNetworkWindow::homeButtonClick()
{
    userProfile();
}

void SocialNetworkWindow::addFriendButtonClick()
{
    network->add_connection(logged_in_user->get_name(), current_user->get_name());
}

SocialNetworkWindow::~SocialNetworkWindow()
{
    delete ui;
}

