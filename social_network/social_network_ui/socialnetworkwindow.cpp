#include "socialnetworkwindow.h"
#include "ui_socialnetworkwindow.h"

SocialNetworkWindow::SocialNetworkWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SocialNetworkWindow)
{
    ui->setupUi(this);


}

SocialNetworkWindow::~SocialNetworkWindow()
{
    delete ui;
}

