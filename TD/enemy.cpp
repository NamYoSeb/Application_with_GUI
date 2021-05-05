#include "enemy.h"
#include "mainwindow.h"
#include "gameobject.h"
#include <QLabel>
#include <QTimer>

Enemy::Enemy()
{
    width = 40;
    height = 62;

    attack = 10;
    health = 100;

    imageUrl = ":/images/normal-zombie.gif";
    imageUrlWidth = 40;
    imageUrlHeight = 62;

    multiUseTimer = new QTimer();
    multiUseTimer->setSingleShot(true);
    multiUseTimer->stop();
}

Enemy::~Enemy()
{}

void Enemy::setupGameObject()
{
    gameObjectGif = new QLabel();
    gameObjectGif->setAttribute(Qt::WA_TranslucentBackground,true);

    QMovie *zombie_gif = new QMovie(imageUrl);
    gameObjectGif->setGeometry(this->scenePos().x() + 5,
                               this->scenePos().y() + 5,
                               imageUrlWidth,
                               imageUrlHeight);

    gameObjectGif->setMovie(zombie_gif);
    gameObjectGif->movie()->start();

    MainWindow::gameScene->addWidget(gameObjectGif);
}



QRectF Enemy::boundingRect() const
{
    return QRectF(0, 0, width, height);
}

void Enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    for (int i = 0; i < MainWindow::plantObjects.size(); i++)
    {
        if ((this->x() >= MainWindow::plantObjects.at(i)->x() &&
                this->x() <= (MainWindow::plantObjects.at(i)->x() + 71) &&
                this->y() >= MainWindow::plantObjects.at(i)->y() &&
                this->y() <= (MainWindow::plantObjects.at(i)->y() + 71)) && !multiUseTimer->isActive())
        {
            if (MainWindow::plantObjects.at(i)->getType() == "activeMine")
                break;

            this->setVelocity(0);
            MainWindow::plantObjects.at(i)->setHealth(MainWindow::plantObjects.at(i)->getHealth() - attack);
            if (MainWindow::plantObjects.at(i)->getHealth() <= 0)
            {
                this->setVelocity(1);
                break;
            }
            multiUseTimer->start(1000);
            break;
        }
    }
    if (!multiUseTimer->isActive())
        this->setVelocity(1);

    if (this->getHealth() <= 0)
    {
        delete gameObjectGif;
        gameObjectGif = 0;

        MainWindow::gameScene->removeItem(this);
        for (int i = 0; i < MainWindow::zombieObjects.size(); i++)
        {
            if (this == MainWindow::zombieObjects.at(i))
            {
                MainWindow::zombieObjects.removeAt(i);
                break;
            }
        }

        return;
    }

    gameObjectGif->setGeometry(this->scenePos().x()+5,this->scenePos().y()+5,width,height);
    this->setZValue(301);

    painter->setOpacity(0);
    painter->drawRect(boundingRect());
}

