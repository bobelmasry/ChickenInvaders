#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "player.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsPixmapItem> // Include for using QGraphicsPixmapItem

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // ******* Create the Scene ********
    QGraphicsScene * scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);

    // ******* Add Background Image ********
    QPixmap backgroundImage(":/images/images/SpaceBackground.jpg"); // Load background image from resources
    QGraphicsPixmapItem *background = new QGraphicsPixmapItem(backgroundImage);
    scene->addItem(background);
    background->setPos(0, 0); // Set position of the background to the top-left corner of the scene

    // ******* Create the View ********
    QGraphicsView * view = new QGraphicsView(scene);
    view->setFixedSize(800,600);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // *******  Create the Player ********
    Player * player = new Player(scene);
    scene->addItem(player);
    player->setPos(scene->width() / 2 - player->pixmap().width() / 2, scene->height() - player->pixmap().height());

    // *******  Setting the focus to the Player ********
    view->setFocus();
    // *******  Create the Enemies automatically ********
    QTimer * time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()), player, SLOT(createEnemy()));
    time->start(2000);

    // *******   Assign scene to the view   ***************
    view->show();

    return a.exec();
}
