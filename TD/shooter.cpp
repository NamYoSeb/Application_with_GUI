#include "shooter.h"
#include "mainwindow.h"

int Shooter::cost = 100;


Shooter::Shooter()
{
    width = 72;
    height = 71;

    health = 100;
    attack = 20;

    imageUrl = ":/images/pea-shooter.gif";
    imageUrlWidth = 62;
    imageUrlHeight = 62;
}

QRectF Shooter::boundingRect() const
{
    return QRectF(0, 0, width, height);
}

void Shooter::paint(QPainter* painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    if (this->getHealth() <= 0)
    {
        delete gameObjectGif;
        gameObjectGif = 0;
        multiUseTimer->stop();

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

void Shooter::setupGameObject()
{
    QMovie *plant_gif = new QMovie(imageUrl);

    gameObjectGif = new QLabel();
    gameObjectGif->setAttribute(Qt::WA_TranslucentBackground);
    gameObjectGif->setMovie(plant_gif);
    gameObjectGif->setGeometry((72 - imageUrlWidth)  / 2 + scenePos().x(),
                               (72 - imageUrlHeight) / 2 + scenePos().y(),
                               imageUrlWidth,
                               imageUrlHeight);

    gameObjectGif->movie()->start();

    MainWindow::gameScene->addWidget(gameObjectGif);

    multiUseTimer = new QTimer();
    connect(multiUseTimer,SIGNAL(timeout()),this,SLOT(fireBullet()));
    multiUseTimer->start(2000);
}

void Shooter::fireBullet()
{
    for (int i = 0; i < MainWindow::zombieObjects.size(); i++)
    {
        //Check if the zombie is in range of the pea shooter
        if ((this->scenePos().x() < MainWindow::zombieObjects.at(i)->scenePos().x()) &&
                (this->scenePos().y()-72 <= MainWindow::zombieObjects.at(i)->scenePos().y()) &&
                (this->scenePos().y() >= MainWindow::zombieObjects.at(i)->scenePos().y()))
        {
            GameObject *bullet = new Bullet();
            bullet->setCoordinates(this->scenePos().x() + 20,
                                   this->scenePos().y() + 20);

            MainWindow::gameScene->addItem(bullet);
            MainWindow::bulletObjects.append(bullet);
            break;
        }
    }
}
