#include "gameobject.h"

GameObject::GameObject()
{

}

void GameObject::setCoordinates(int x, int y)
{
    xCoordinate = x;
    yCoordinate = y;
    this->setPos(xCoordinate, yCoordinate);
}

void GameObject::setVelocity(int velocity)
{
    this->velocity = velocity;
}

void GameObject::move()
{
    this->xCoordinate -= this->velocity;
    setCoordinates(xCoordinate, yCoordinate);
}
