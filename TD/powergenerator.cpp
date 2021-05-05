#include "powergenerator.h"
#include "mainwindow.h"
#include "sun.h"

int PowerGenerator::cost = 50;

PowerGenerator::PowerGenerator()
{
    health = 50;
    attack = 0;
}

QRectF PowerGenerator::boundingRect() const
{
    return QRectF(0,0,width,height);
}

void PowerGenerator::paint(QPainter* painter, const QStyleOptionGraphicsItem *, QWidget *)
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

void PowerGenerator::setupGameObject()
{
    QMovie *plant_gif = new QMovie(":/images/sunflower.gif");

    gameObjectGif = new QLabel();
    gameObjectGif->setAttribute(Qt::WA_TranslucentBackground);
    gameObjectGif->setMovie(plant_gif);
    gameObjectGif->setGeometry((72-62)/2 + scenePos().x(),(72-62)/2+ scenePos().y(), 62, 62);
    gameObjectGif->movie()->start();

    MainWindow::gameScene->addWidget(gameObjectGif);

    multiUseTimer = new QTimer();
    connect(multiUseTimer, SIGNAL(timeout()), this, SLOT(createSun()));
    multiUseTimer->start(1000);
}

void PowerGenerator::createSun()
{
    multiUseTimer->stop();

    GameObject *sun = new Sun();
    sun->setCoordinates(this->x() + 17, this->y() + 30);
    MainWindow::gameScene->addItem(sun);

    multiUseTimer->start(5000);
}
