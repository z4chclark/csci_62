#include <iostream>
#include <string>

#include "clickgamewindow.h"
#include "ui_clickgamewindow.h"


ClickGameWindow::ClickGameWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ClickGameWindow)
{
    ui->setupUi(this);
    ui->label_2->hide();

    connect(ui->pushButton, &QPushButton::clicked, this,
            &ClickGameWindow::pushButtonClick);

}

void ClickGameWindow::pushButtonClick()
{
    counter.add();
    ui->label->setText(QString::fromStdString("Number of Clicks: " +
                                                std::to_string(counter.getCount())));

    if (counter.getCount() == 10) {
        ui->pushButton->hide();
        ui->label->hide();
        ui->label_2->show();
    }

}


ClickGameWindow::~ClickGameWindow()
{
    delete ui;
}

