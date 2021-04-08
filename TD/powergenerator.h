#ifndef POWERGENERATOR_H
#define POWERGENERATOR_H

#include <QObject>
#include <QMovie>
#include <QLabel>
#include <QPainter>
#include "gameobject.h"

class PowerGenerator : public QObject, public GameObject
{
    Q_OBJECT;

public:
    PowerGenerator();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    void setupGameObject();
};

#endif // POWERGENERATOR_H
