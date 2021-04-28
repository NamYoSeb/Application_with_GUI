#ifndef ENEMY_H
#define ENEMY_H
#include "gameobject.h"

class Enemy : public GameObject
{
public:
    //Constructor
    Enemy();
    //Current position and size of the game object
    QRectF boundingRect() const;
    //Set the appearence of the game object
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    //Setup and initialize the zombie object
    void setupGameObject();    //Destructor

    ~Enemy();

private:

};

#endif // ENEMY_H
