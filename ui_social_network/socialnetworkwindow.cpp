#include "socialnetworkwindow.h"
#include "ui_socialnetworkwindow.h"
#include "network.h"

SocialNetworkWindow::SocialNetworkWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SocialNetworkWindow)
    , network(new Network)
{
    ui->setupUi(this);

    network->read_users("social_network.txt");
    network->readPosts("posts.txt");

    connect(ui->loginButton, &QPushButton::clicked, this,
            &SocialNetworkWindow::myLoginClick);

}

void SocialNetworkWindow::myLoginClick()
{
    std::string name = ui->loginText->toPlainText().toStdString();
    std::cout << name << network->get_id(name) << std::endl;
    if (network->get_id(name))
    {
        ui->loginButton->hide();
        ui->loginLabel->hide();
        ui->loginText->hide();
    }


}

SocialNetworkWindow::~SocialNetworkWindow()
{
    delete ui;
}

