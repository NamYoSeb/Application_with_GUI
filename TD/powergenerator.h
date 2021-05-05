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
    static int cost;
    PowerGenerator();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    void setupGameObject();

private slots:
    void createSun();
};

#endif // POWERGENERATOR_H
