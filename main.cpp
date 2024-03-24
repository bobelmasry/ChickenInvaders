#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "player.h"
#include <QTimer>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // ******* Create the Scene ********
    QGraphicsScene * scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    scene->setBackgroundBrush(Qt::white);

    // *******  Create the View ********
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
