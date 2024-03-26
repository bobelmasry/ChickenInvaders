#include"bullet.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include <enemy.h>
#include <player.h>
#include <QPixmap>

Bullet::Bullet() : QGraphicsPixmapItem() {
    // Load the bullet image
    setPixmap(QPixmap(":/images/images/laser.png").scaled(100,100));
        setPos(x() + pixmap().width() / 2, y()); // Adjust the position as needed

        // Start a timer to move the bullet
        QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(move()));
        timer->start(50); // Adjust the timer interval as needed
    }

// Move function is used to

    void Bullet::move()
    {
        // Handle the collision of the bullets with enemies
        QList<QGraphicsItem*> colliding_items = collidingItems();
        for(int i = 0; i < colliding_items.size(); ++i)
        {
            if(typeid(*(colliding_items[i])) == typeid(Enemy))
            {
                // Increment the score through the scene if the colliding item is an enemy
                QList<QGraphicsItem*> scene_items = scene()->items();
                for (int j = 0; j < scene_items.size(); ++j) {
                    Player *player = dynamic_cast<Player*>(scene_items[j]);
                    if (player) {
                        player->increase(); // Call the increase function of the player
                        break; // Once score is incremented, exit the loop
                    }
                }

                // Remove both the enemy and the bullet
                scene()->removeItem(colliding_items[i]); // Remove the enemy
                scene()->removeItem(this); // Remove the bullet
                delete colliding_items[i]; // Delete the enemy
                delete this; // Delete the bullet
                return;
            }
        }

        // Move the bullet upward
        setPos(x(), y() - 10);

        // Remove the bullet if it goes out of the scene
        if(pos().y() + pixmap().height() < 0)
        {
            scene()->removeItem(this);
            delete this;
        }
    }
