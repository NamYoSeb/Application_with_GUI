#ifndef SHOOTER_H
#define SHOOTER_H

#include <QObject>
#include <QMovie>
#include <QLabel>
#include <QPainter>
#include "gameobject.h"
#include "bullet.h"

class Shooter : public QObject, public GameObject
{
    Q_OBJECT;

public:
    static int cost;
    Shooter();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    void setupGameObject();

private slots:
    void fireBullet();
};


#endif // SHOOTER_H
