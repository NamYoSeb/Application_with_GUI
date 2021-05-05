#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTimer>
#include <QLabel>
#include <QGraphicsPixmapItem>
#include "gamescene.h"
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
    static QList<GameObject *> bulletObjects;
    static int currentSunAmount;

    void setupGameScene();
    void hideMenu();
    void createGameplayUi();
    void addRow(int x, int y);
    void addHomeRow();
    void setRows();
    void addPortalRow();
    void plantGenerator(GameObject* object);
    void enablePlantButtons();


private slots:
    void enemyGenerator();
    void on_StartButton_clicked();

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
    void refresh();

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
    QTimer* refreshTimer;
    QTimer* zombieTimer;
    QList<int> zombieStartRows;

    QPushButton* powerGeneratorButton;
    QPushButton* shooterButton;
    QPushButton* wallButton;
    QPushButton* mineButton;
    QPushButton* superShooterButton;
};
#endif // MAINWINDOW_H
