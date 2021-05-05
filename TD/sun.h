#ifndef SUN_H
#define SUN_H

#include "gameobject.h"
#include <QPainter>
#include <QGraphicsScene>
#include <QObject>

class Sun : public QObject, public GameObject
{
    Q_OBJECT;

public:
    explicit Sun(QObject *parent = 0);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    void setupGameObject() {};

public slots:
    void mousePressEvent(QGraphicsSceneMouseEvent *);
};

#endif // SUN_H
