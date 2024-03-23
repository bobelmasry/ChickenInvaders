#include "enemy.h"
#include <QGraphicsScene>
#include <stdlib.h> // rand() -> to generate really large integer
#include <QTimer>
#include <QDebug>
#include "player.h"

Enemy::Enemy() {
    // *******  Setting the size of the enemy ********
    setRect(0,0,100,100);

    // *******  Setting the postion of the enemy within the view dimensions ********
    int random_number = rand() % 700;
    setPos(random_number,0);

    // *******  Moving the enemies downwards automatically every 50 milli second ********
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);



}
// Function move: move the enemy downwards untill the end of the scene then remove it and delete it
void Enemy:: move()
{
    setPos(x(),y()+5);
    if(y()+rect().height()>800)
    {
        scene()->removeItem(this);
        delete this;
    }


    QList<QGraphicsItem*> colliding_items=collidingItems();
    for(int i=0, n=colliding_items.size(); i<n;++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(Player))
        {
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete this;
            delete colliding_items[i];
        }
    }
}
