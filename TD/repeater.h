#ifndef REPEATER_H
#define REPEATER_H


#include <QObject>
#include <QMovie>
#include <QLabel>
#include <QPainter>
#include "gameobject.h"

class Repeater : public QObject, public GameObject
{
    Q_OBJECT;

public:
    Repeater();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    void setupGameObject();
};

#endif // REPEATER_H
