#include "bullet.h"
#include "mainwindow.h"

Bullet::Bullet()
{
    attack = 20;
    health = 999;

    imageUrl = ":/images/pea-shooter-bullet.png";
    imageUrlWidth = 26;
    imageUrlHeight = 26;

    velocity = -4;

}

QRectF Bullet::boundingRect() const
{
    return QRectF(0, 0, imageUrlWidth, imageUrlHeight);
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    if (this->getHealth() <= 0)
    {
        MainWindow::gameScene->removeItem(this);
        for (int j = 0; j < MainWindow::bulletObjects.size(); j++)
        {
            if (this == MainWindow::bulletObjects.at(j))
            {
                MainWindow::bulletObjects.removeAt(j);
                break;
            }
        }
    }

    for (int i = 0; i < MainWindow::zombieObjects.size(); i++)
    {
        if (this->collidesWithItem(MainWindow::zombieObjects.at(i)))
        {
            MainWindow::zombieObjects.at(i)->setHealth(
                        MainWindow::zombieObjects.at(i)->getHealth() - attack);

            MainWindow::gameScene->removeItem(this);
            for (int j = 0; j < MainWindow::bulletObjects.size(); j++)
            {
                if (this == MainWindow::bulletObjects.at(j))
                {
                    MainWindow::bulletObjects.removeAt(j);
                    break;
                }
            }
            break;
        }
    }

    if (this->scenePos().x() > 794)
    {
        MainWindow::gameScene->removeItem(this);
        for (int j = 0; j < MainWindow::bulletObjects.size(); j++)
        {
            if (this == MainWindow::bulletObjects.at(j))
            {
                MainWindow::bulletObjects.removeAt(j);
                break;
            }
        }
    }

    painter->drawPixmap(QPoint(0,0),QPixmap(imageUrl));
    this->setZValue(500);
}
