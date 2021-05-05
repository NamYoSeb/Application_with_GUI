#include "sun.h"
#include "mainwindow.h"

Sun::Sun(QObject *)
{
    width = 35;
    height = 35;

    imageUrl = ":/images/sun.png";
    imageUrlWidth = 35;
    imageUrlHeight = 35;
}

QRectF Sun::boundingRect() const
{
    return QRectF(0,0,width,height);
}

void Sun::paint(QPainter* painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(0,0,imageUrlWidth,imageUrlHeight,QPixmap(imageUrl));
    this->setZValue(600);
}

void Sun::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    MainWindow::currentSunAmount += 25;
    MainWindow::gameScene->removeItem(this);
    this->setVisible(false);
}
