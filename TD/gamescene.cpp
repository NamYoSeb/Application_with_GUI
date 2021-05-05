#include "gamescene.h"
#include <QGraphicsSceneMouseEvent>
#include "mainwindow.h"

GameScene::GameScene() : QGraphicsScene()
{

}

void GameScene::mousePressEvent(QGraphicsSceneMouseEvent *pressEvent)
{
    MainWindow::mousePressCoordinates = pressEvent->scenePos();

    QGraphicsScene::mousePressEvent(pressEvent);
}

void GameScene::mouseMoveEvent(QGraphicsSceneMouseEvent *moveEvent)
{
    MainWindow::mouseCoordinates = moveEvent->scenePos();
    QGraphicsScene::mouseMoveEvent(moveEvent);
}
