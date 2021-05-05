#include "repeater.h"
#include "mainwindow.h"

int Repeater::cost = 200;

Repeater::Repeater()
{
    health = 100;
    attack = 20;
}

QRectF Repeater::boundingRect() const
{
    return QRectF(0,0,width,height);
}

void Repeater::paint(QPainter* painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setOpacity(0);
    painter->drawRect(boundingRect());
}

void Repeater::setupGameObject()
{
    QMovie *plant_gif = new QMovie(":/images/repeater.gif");

    gameObjectGif = new QLabel();
    gameObjectGif->setAttribute(Qt::WA_TranslucentBackground);
    gameObjectGif->setMovie(plant_gif);
    gameObjectGif->setGeometry((72-62)/2 + scenePos().x(),(72-62)/2+ scenePos().y(), 62, 62);
    gameObjectGif->movie()->start();

    MainWindow::gameScene->addWidget(gameObjectGif);

    multiUseTimer = new QTimer();
    connect(multiUseTimer,SIGNAL(timeout()),this,SLOT(fireBullet()));
    multiUseTimer->start(2500);
}

void Repeater::fireBullet()
{
    for (int i = 0; i < MainWindow::zombieObjects.size(); i++)
    {
        if ((this->scenePos().x() < MainWindow::zombieObjects.at(i)->scenePos().x()) &&
                (this->scenePos().y()-72 <= MainWindow::zombieObjects.at(i)->scenePos().y()) &&
                (this->scenePos().y() >= MainWindow::zombieObjects.at(i)->scenePos().y()))
        {
            GameObject *bullet1 = new Bullet();
            GameObject *bullet2 = new Bullet();
            bullet1->setCoordinates(this->scenePos().x() + 20,
                                   this->scenePos().y() + 20);
            bullet2->setCoordinates(this->scenePos().x() + 50,
                                    this->scenePos().y() + 20);

            MainWindow::gameScene->addItem(bullet1);
            MainWindow::bulletObjects.append(bullet1);
            MainWindow::gameScene->addItem(bullet2);
            MainWindow::bulletObjects.append(bullet2);
            break;
        }
    }
}
