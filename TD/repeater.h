#ifndef REPEATER_H
#define REPEATER_H


#include <QObject>
#include <QMovie>
#include <QLabel>
#include <QPainter>
#include "gameobject.h"
#include "bullet.h"

class Repeater : public QObject, public GameObject
{
    Q_OBJECT;

public:
    static int cost;
    Repeater();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    void setupGameObject();

private slots:
    void fireBullet();
};

#endif // REPEATER_H
