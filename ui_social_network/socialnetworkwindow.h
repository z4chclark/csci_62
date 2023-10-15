#ifndef SOCIALNETWORKWINDOW_H
#define SOCIALNETWORKWINDOW_H

#include <QMainWindow>
#include "network.h"
#include "user.h"
#include "post.h"
#include "incoming_post.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SocialNetworkWindow; }
QT_END_NAMESPACE

class SocialNetworkWindow : public QMainWindow
{
    Q_OBJECT

public:
    SocialNetworkWindow(QWidget *parent = nullptr);
    ~SocialNetworkWindow();

    void myLoginClick();


private:
    Ui::SocialNetworkWindow *ui;
    Network *network;
};
#endif // SOCIALNETWORKWINDOW_H
