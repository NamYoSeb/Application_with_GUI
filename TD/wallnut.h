#ifndef WALLNUT_H
#define WALLNUT_H

#include <QObject>
#include <QMovie>
#include <QLabel>
#include <QPainter>
#include "gameobject.h"

class Wallnut : public QObject, public GameObject
{
    Q_OBJECT;

public:
    Wallnut();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    void setupGameObject();
};

#endif // WALLNUT_H

