#include "player.h"
#include <QKeyEvent>
#include "bullet.h"
#include <QGraphicsScene>
#include <QDebug>
#include "enemy.h"

Player::Player() : QGraphicsPixmapItem() {
    // Load the player image
    setPixmap(QPixmap("D:/python_projects/other shit/CS/ChickenInvaders/images/ship.png").scaled(100,100));
    setFlag(QGraphicsPixmapItem::ItemIsFocusable); // Set the focus flag for the Player object
    setFocus(); // Set the focus to the Player object
}

void Player::keyPressEvent(QKeyEvent *event)
{
    // *******  Event Handling for the Player ********
    if(event->key()== Qt::Key_Left)
    {
        if(x()>0) // to prevent the player from getting out of the screen
        {
            setPos(x()-20,y());
        }
    }
    else if(event->key()== Qt::Key_Right)

    { if(x()+100<800) // to prevent the player from getting out of the screen
            setPos(x()+20,y());
    }
    else if(event->key()== Qt::Key_Space)
    {
        Bullet * bullet = new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);
    }
}

// CreateEnemy function used to create the enemies
void Player::createEnemy()
{
    Enemy* enemy = new Enemy();
    scene()->addItem(enemy);
}
