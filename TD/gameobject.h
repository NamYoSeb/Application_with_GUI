#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QGraphicsItem>
#include <QLabel>

class GameObject : public QGraphicsItem
{
public:
    GameObject();
    QLabel *gameObjectGif;

    void setCoordinates(int x, int y);
    virtual void setupGameObject() = 0;
    virtual QRectF boundingRect() const = 0;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) = 0;


protected:
    int width;
    int height;
};

#endif // GAMEOBJECT_H
