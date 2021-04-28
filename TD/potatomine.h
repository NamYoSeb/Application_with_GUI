#ifndef POTATOMINE_H
#define POTATOMINE_H

#include <QObject>
#include <QMovie>
#include <QLabel>
#include <QPainter>
#include "gameobject.h"

class PotatoMine : public QObject, public GameObject
{
    Q_OBJECT;

public:
    PotatoMine();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    void setupGameObject();
};

#endif // POTATOMINE_H
