#include "potatomine.h"
#include "mainwindow.h"

int PotatoMine::cost = 25;

PotatoMine::PotatoMine()
{
    type = "inactiveMine";

    width = 72;
    height = 71;

    health = 30;
    attack = 1000;

    imageUrl = ":/images/potato-mine-inactive.gif";
    imageUrlWidth = 62;
    imageUrlHeight = 46;

    imageUrlAlt = ":/images/potato-mine-active.gif";
    imageUrlAltWidth = 62;
    imageUrlAltHeight = 46;

    explosianImage = ":/images/cherry-bomb-explosian";
    explosianImageWidth = 114;
    explosianImageHeight = 158;

    multiUseTimer = new QTimer();
    multiUseTimer->setSingleShot(true);
    connect(multiUseTimer,SIGNAL(timeout()),this,SLOT(activateMine()));
    multiUseTimer->start(5000);

    gameObjectGif = new QLabel();
}

QRectF PotatoMine::boundingRect() const
{
    return QRectF(0,0,width,height);
}

void PotatoMine::paint(QPainter* painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    //Check if life is less than or equal to zero
    if (this->getHealth() <= 0)
    {
        multiUseTimer->stop();
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
    for (int i = 0; i < MainWindow::zombieObjects.size(); i++)
    {
        if (this->collidesWithItem(MainWindow::zombieObjects.at(i)) &&
            this->getType() == "activeMine")
        {
            QMovie *activated_mine = new QMovie(explosianImage);
            gameObjectGif->setMovie(activated_mine);
            gameObjectGif->setGeometry(x()-21,y()-43,114,158);
            gameObjectGif->movie()->start();
            multiUseTimer = new QTimer();
            multiUseTimer->setSingleShot(true);
            connect(multiUseTimer,SIGNAL(timeout()),this,SLOT(explodeMine()));
            multiUseTimer->start(800);
            MainWindow::zombieObjects.at(i)->setHealth(0);
            break;
        }
    }

    painter->setOpacity(0);
    painter->drawRect(boundingRect());
}

void PotatoMine::setupGameObject()
{
    QMovie *plant_gif = new QMovie(imageUrl);

    gameObjectGif->setAttribute(Qt::WA_TranslucentBackground);
    gameObjectGif->setMovie(plant_gif);
    gameObjectGif->setGeometry((72-62)/2 + scenePos().x(),(72-62)/2+ scenePos().y(), 62, 62);
    gameObjectGif->movie()->start();

    MainWindow::gameScene->addWidget(gameObjectGif);
}

void PotatoMine::activateMine()
{
    type = "activeMine";
    QMovie *activated_mine = new QMovie(imageUrlAlt);
    gameObjectGif->setMovie(activated_mine);
    gameObjectGif->movie()->start();
}

void PotatoMine::explodeMine()
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

























