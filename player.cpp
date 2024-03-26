#include "player.h"
#include <QKeyEvent>
#include "bullet.h"
#include <QGraphicsScene>
#include <QDebug>
#include "enemy.h"

Player::Player(QGraphicsScene *scene) : QGraphicsPixmapItem(), health(3), score(0) {
    // Load the player image
    setPixmap(QPixmap(":/images/images/ship.png").scaled(100,100));
    setFlag(QGraphicsPixmapItem::ItemIsFocusable); // Set the focus flag for the Player object
    setFocus(); // Set the focus to the Player object

    healthDisplay = new QGraphicsTextItem();
    healthDisplay->setPlainText("Health: " + QString::number(health));
    healthDisplay->setDefaultTextColor(Qt::red);
    healthDisplay->setPos(10, 10);
    scene->addItem(healthDisplay);

    // Create score display
    scoreDisplay = new QGraphicsTextItem();
    scoreDisplay->setPlainText("Score: " + QString::number(score));
    scoreDisplay->setDefaultTextColor(Qt::blue);
    scoreDisplay->setPos(10, 30);
    scene->addItem(scoreDisplay);

    // Create message box
    msgBox = new QMessageBox();
}


void Player::decrease() {
    health--;
    healthDisplay->setPlainText("Health: " + QString::number(health));
    healthDisplay->setDefaultTextColor(Qt::red);
    if (health < 1) {
        msgBox->setText("Game Over!\nScore: " + QString::number(score));
        msgBox->setWindowTitle("Game Over");
        msgBox->exec();
        // Additional actions for game over can be added here like going to homescreen
    }
}

void Player::increase() {
    score++;
    scoreDisplay->setPlainText("Score: " + QString::number(score));
    scoreDisplay->setDefaultTextColor(Qt::blue);
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

int Player::getHealth(){
    return health;
}

// CreateEnemy function used to create the enemies
void Player::createEnemy()
{
    Enemy* enemy = new Enemy();
    scene()->addItem(enemy);
}
