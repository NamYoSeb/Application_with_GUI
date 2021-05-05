#include "wallnut.h"
#include "mainwindow.h"

int Wallnut::cost = 50;


Wallnut::Wallnut()
{
    health = 300;
    attack = 0;
}

QRectF Wallnut::boundingRect() const
{
    return QRectF(0,0,width,height);
}

void Wallnut::paint(QPainter* painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    if (this->getHealth() <= 0)
    {
        delete gameObjectGif;
        gameObjectGif = 0;

        MainWindow::gameScene->removeItem(this);
        for (int i = 0; i < MainWindow::plantObjects.size(); i++)
        {
            if (this == MainWindow::plantObjects.at(i))
            {
                MainWindow::plantObjects.removeAt(i);
                break;
            }
        }
    }

    painter->setOpacity(0);
    painter->drawRect(boundingRect());
}

void Wallnut::setupGameObject()
{
    QMovie *plant_gif = new QMovie(":/images/wallnut.gif");

    gameObjectGif = new QLabel();
    gameObjectGif->setAttribute(Qt::WA_TranslucentBackground);
    gameObjectGif->setMovie(plant_gif);
    gameObjectGif->setGeometry((72-62)/2 + scenePos().x(),(72-62)/2+ scenePos().y(), 62, 62);
    gameObjectGif->movie()->start();

    MainWindow::gameScene->addWidget(gameObjectGif);
}
