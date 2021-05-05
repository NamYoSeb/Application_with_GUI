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
    static int cost;
    PotatoMine();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    void setupGameObject();

private slots:
    void activateMine();
    void explodeMine();

private:
    QString imageUrlAlt;
    int imageUrlAltWidth;
    int imageUrlAltHeight;

    QString explosianImage;
    int explosianImageWidth;
    int explosianImageHeight;
};

#endif // POTATOMINE_H
