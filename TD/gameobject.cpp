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

void GameObject::setVelocity(double velocity)
{
    this->velocity = velocity;
}

int GameObject::x()
{
    return xCoordinate;
}

int GameObject::y()
{
    return yCoordinate;
}

int GameObject::getHealth() const
{
    return health;
}

void GameObject::setHealth(int value)
{
    health = value;
}

QString GameObject::getType() const
{
    return type;
}

void GameObject::move()
{
    this->xCoordinate -= this->velocity;
    setCoordinates(xCoordinate, yCoordinate);
}
