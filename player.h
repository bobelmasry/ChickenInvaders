#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QKeyEvent>
#include <QGraphicsTextItem>
#include <QMessageBox>

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    int health;
    int score;
    QGraphicsTextItem* healthDisplay;
    QGraphicsTextItem* scoreDisplay;
    QMessageBox* msgBox;
public:
    Player(QGraphicsScene *scene);
    void keyPressEvent(QKeyEvent *event);
public slots:
    void createEnemy();
    void decrease();
    void increase();
};

#endif // PLAYER_H
