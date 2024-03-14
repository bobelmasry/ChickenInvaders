#include "player.h"

#include <QKeyEvent>
#include <QGraphicsScene>

Player::Player(QGraphicsTextItem * inScore)
{
    score = inScore;
    scoreValue = 0;
}

void Player::keyPressEvent(QKeyEvent * event)
{
    if (event->key() == Qt::Key_Left)
    {
        setPos(x()-30, y());
    }
    else if (event->key() == Qt::Key_Right)
    {
        setPos(x()+30, y());
    }
    else if (event->key() == Qt::Key_Up)
    {
        setPos(x(), y()-30);
    }
    else if (event->key() == Qt::Key_Down)
    {
        setPos(x(), y()+30);
    }

    QList<QGraphicsItem *> colliding_items = collidingItems(); // list of poiners
    for(int i = 0; i < colliding_items.size(); i++)
    {
        scene()->removeItem(colliding_items[i]); // need to #include
        scoreValue++;
        score->setPlainText("Score: " + QString::number(scoreValue));
    }
}
