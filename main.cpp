#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "player.h"
#include <QTimer>
#include <QDebug>
#include <QBrush>


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
    view-> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // *******  Create the Player ********
    Player * rect = new Player();
    rect->setRect(0, 0, 100, 100);
    rect->setBrush(Qt::magenta);
    scene->addItem(rect);
    // *******  Setting the foucs to the Player ********
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();
    // *******  Adjust the location of the Player (middle of the screen) ********
    rect->setPos(view->width()/2, view->height()-rect->rect().height());
    // *******   Assign scene to the view   ***************
    view->show();
    // *******  Create the Enemies automatically ********
    QTimer * time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()),rect,SLOT(createEnemy()));
    time->start(2000);


    return a.exec();
}
