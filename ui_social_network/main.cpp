#include "socialnetworkwindow.h"
#include "network.h"
#include "user.h"
#include "post.h"
#include "incoming_post.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SocialNetworkWindow w;
    w.show();

    Network *network = new Network();

    network->read_users("social_network.txt");
    network->readPosts("posts.txt");




    std::cout << "num users" << network->num_users() << std::endl;
    std::cout << "worked" << std::endl;



    return a.exec();
}
