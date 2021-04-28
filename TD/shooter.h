#ifndef SHOOTER_H
#define SHOOTER_H

#include <QObject>
#include <QMovie>
#include <QLabel>
#include <QPainter>
#include "gameobject.h"

class Shooter : public QObject, public GameObject
{
    Q_OBJECT;

public:
    Shooter();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    void setupGameObject();
};


#endif // SHOOTER_H
