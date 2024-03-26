#include "enemy.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include "player.h"

Enemy::Enemy() {
    // Load the enemy image
    setPixmap(QPixmap(":/images/images/chicken.png").scaled(100,100));

    // Setting the postion of the enemy within the view dimensions
    int random_number = QRandomGenerator::global()->bounded(0, 700);
    setPos(random_number, 0);

    // Moving the enemies downwards automatically every 50 milliseconds
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}
// Function move: move the enemy downwards untill the end of the scene then remove it and delete it
void Enemy::move() {
    setPos(x(), y() + 5); // Move the enemy downwards

    // Check if the enemy is out of the scene's bounds
    if (y() + pixmap().height() > 800) {
        scene()->removeItem(this);
        delete this;
        return;
    }

    // Check for collisions with the player
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for (int i = 0; i < colliding_items.size(); ++i) {
        if (typeid(*(colliding_items[i])) == typeid(Player)) {
            // Remove both the enemy and the player
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }
}
