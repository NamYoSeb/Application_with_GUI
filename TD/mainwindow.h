#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTimer>
#include "gamescene.h"
#include <QLabel>
#include <QGraphicsPixmapItem>
#include "powergenerator.h"
#include "shooter.h"
#include "wallnut.h"
#include "potatomine.h"
#include "repeater.h"
#include "gameobject.h"
#include "enemy.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static QList<GameObject *> zombieObjects;
    static QList<GameObject *> plantObjects;

    void setupGameScene();
    void hideMenu();
    void createGameplayUi();
    void addRow(int x, int y);
    void addHomeRow();
    void setRows();
    void addPortalRow();
    void plantGenerator(GameObject* object);


private slots:
    void enemyGenerator();
    void on_StartButton_clicked();

    void moveEnemies();
    void powerGeneratorButtonClicked();
    void shooterButtonClicked();
    void wallButtonClicked();
    void mineButtonClicked();
    void superShooterButtonClicked();

    void powerGeneratorPlacement();
    void shooterPlacement();
    void wallPlacement();
    void minePlacement();
    void superShooterPlacement();

public:
    static QPointF mouseCoordinates;
    static QPointF mousePressCoordinates;
    static QGraphicsScene* gameScene;

private:
    Ui::MainWindow *ui;

    QLabel* sunValue;
    QLabel* sunImage;
    QLabel* plantHover;

    QTimer* plantTimer;
    QTimer* moveTimer;
    QTimer* zombieTimer;
    QList<int> zombieStartRows;

    QPushButton* powerGeneratorButton;
    QPushButton* shooterButton;
    QPushButton* wallButton;
    QPushButton* mineButton;
    QPushButton* superShooterButton;
};
#endif // MAINWINDOW_H
