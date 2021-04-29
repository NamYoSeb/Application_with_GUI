#include "enemy.h"
#include "mainwindow.h"
#include "gameobject.h"
#include <QLabel>
#include <QTimer>

Enemy::Enemy()    //Default constructor
{
    width = 40;
    height = 62;
    attack = 10;
    health = 100;

    timer = new QTimer();
    timer->setSingleShot(true);
    timer->stop();
}

Enemy::~Enemy()   //Destructor
{}

void Enemy::setupGameObject()    //Setup and initialize the game object
{
    gameObjectGif = new QLabel();
    //Set the label to have a transparent background
    gameObjectGif->setAttribute(Qt::WA_TranslucentBackground,true);
    //Create a new qmovie with the zombie gif
    QMovie *zombie_gif = new QMovie(":/images/normal-zombie.gif");
    //Set the position and size of the zombie gif
    gameObjectGif->setGeometry(this->scenePos().x()+5,this->scenePos().y()+5,width,height);
    //Set the zombie gif to the label
    gameObjectGif->setMovie(zombie_gif);
    //Start the gif
    gameObjectGif->movie()->start();
    //Add the label to the game scene
    MainWindow::gameScene->addWidget(gameObjectGif);
}



QRectF Enemy::boundingRect() const
{
    return QRectF(0,0,width,height);
}

void Enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    //Loop through all plant zombies
    for (int i = 0; i < MainWindow::plantObjects.size(); i++)
    {
        //If the zombie collides with a plant
        if ((this->x() >= MainWindow::plantObjects.at(i)->x() &&
                this->x() <= (MainWindow::plantObjects.at(i)->x() + 71) &&
                this->y() >= MainWindow::plantObjects.at(i)->y() &&
                this->y() <= (MainWindow::plantObjects.at(i)->y() + 71)) && !timer->isActive())
        {
            //Stop the x velocity of the zombie
            this->setVelocity(0);
            //Subtract health from plant object
           MainWindow::plantObjects.at(i)->setHealth(MainWindow::plantObjects.at(i)->getHealth() - attack);
            //Check life of plant
            if (MainWindow::plantObjects.at(i)->getHealth() <= 0)
            {
                this->setVelocity(1);
                break;
            }
            timer->start(1000);
            break;
        }
    }
    //Check timer
  /*  if (multiUseTimer->isActive() && multiUseTimer->remainingTime() <= (rate / 2 * 1000))
    {
        this->setXVelocity(-0.5);
    }*/
    //Set the position of the zombie gif to match the position of the game object
    gameObjectGif->setGeometry(this->scenePos().x()+5,this->scenePos().y()+5,width,height);
   /* //Check if the zombies health is less than or equal to zero
    if (this->getLife() <= 0)
    {
        //Delete the game label holding the gif
        delete gameObjectGif;
        gameObjectGif = 0;
        //Remove the game object from the game scene
        MainWindow::gameScene->removeItem(this);
        //Remove the game object from the zombie list
        for (int i = 0; i < MainWindow::zombieObjects.size(); i++)
        {
            if (this == MainWindow::zombieObjects.at(i))
            {
                MainWindow::zombieObjects.removeAt(i);
                break;
            }
        }
    }*/
    this->setZValue(301);
    //Set the game object to be transparent
    painter->setOpacity(0);
    //Set the size of the game object
    painter->drawRect(boundingRect());
}

