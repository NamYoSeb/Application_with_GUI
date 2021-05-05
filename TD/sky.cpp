#include "sky.h"
#include "mainwindow.h"

Sky::Sky()
{
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(generateSun()));
    timer->start(15000);
}

void Sky::generateSun()
{
    GameObject* sun = new Sun();
    sun->setCoordinates();

    MainWindow::skyGeneratedObjects.append(sun);
}
