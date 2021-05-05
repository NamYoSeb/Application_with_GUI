#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QGraphicsItem>
#include <QLabel>

class GameObject : public QGraphicsItem
{
public:
    GameObject();
    QLabel *gameObjectGif;
    QTimer *multiUseTimer;

    void setCoordinates(int x, int y);
    void move();
    void setVelocity(double velocity);
    int x();
    int y();

    virtual void setupGameObject() = 0;
    virtual QRectF boundingRect() const = 0;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) = 0;


    int getHealth() const;
    void setHealth(int value);

    QString getType() const;

protected:
    int width;
    int height;
    double velocity;

    int xCoordinate;
    int yCoordinate;

    int attack;
    int health;

    QString type;

    QString imageUrl;
    int imageUrlWidth;
    int imageUrlHeight;
};

#endif // GAMEOBJECT_H
