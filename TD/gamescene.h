#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>

class GameScene : public QGraphicsScene
{
    Q_OBJECT;

public:
    GameScene();

    void mousePressEvent(QGraphicsSceneMouseEvent *pressEvent);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *moveEvent);

};

#endif // GAMESCENE_H
