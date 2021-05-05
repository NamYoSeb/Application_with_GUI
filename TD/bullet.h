#ifndef BULLET_H
#define BULLET_H

#include "gameobject.h"

class Bullet : public GameObject
{
public:
    Bullet();

    QRectF boundingRect() const;
    //Set appearence of the game object
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*);
    //Empty initialization
    void setupGameObject()
    {}
};

#endif // BULLET_H
