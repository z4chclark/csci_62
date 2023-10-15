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
    ui->posts->hide();

    network->read_users("social_network.txt");
    network->readPosts("posts.txt");

    connect(ui->loginButton, &QPushButton::clicked, this, &SocialNetworkWindow::myLoginClick);
    //connect(ui->loginButton, &QKeyEvent:: , this, &SocialNetworkWindow::myLoginClick);



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

        std::vector<size_t> friends = logged_in_user->get_friends(); //update freinds table
        ui->friendList->setRowCount(friends.size());
        ui->friendList->setColumnCount(1);
        for (size_t i = 0; i < friends.size(); ++i)
        {
            //ui->friendList->setCurrentCell(i, 0, friends());
        }





        ui->profileLabel->show();
        ui->friendList->show();
        ui->posts->show();
    } else
    {
        ui->loginLabel->setText("Please enter valid name.");
        ui->loginText->clear();
    }


}

SocialNetworkWindow::~SocialNetworkWindow()
{
    delete ui;
}

