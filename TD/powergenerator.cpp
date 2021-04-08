#include "powergenerator.h"
#include "mainwindow.h"

PowerGenerator::PowerGenerator()
{

}

QRectF PowerGenerator::boundingRect() const
{
    return QRectF(0,0,width,height);
}

void PowerGenerator::paint(QPainter* painter, const QStyleOptionGraphicsItem *, QWidget *)
{
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
}
