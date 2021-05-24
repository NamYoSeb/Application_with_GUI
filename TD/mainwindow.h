#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTimer>
#include <QTextCodec>
#include <QFile>
#include <QLabel>
#include <QDir>
#include <QMessageBox>
#include <QGraphicsPixmapItem>
#include "gamescene.h"
#include "powergenerator.h"
#include "shooter.h"
#include "wallnut.h"
#include "potatomine.h"
#include "repeater.h"
#include "gameobject.h"
#include "defaultenemy.h"
#include "bucketheadenemy.h"
#include "coneheadenemy.h"
#include "flagenemy.h"

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
    void levelGenerator();
    void hideMenu();
    void loadMenu();
    void createGameplayUi();
    void addRow(int x, int y);
    void addHomeRow();
    void setRows();
    void addPortalRow();
    void plantGenerator(GameObject* object);
    void enablePlantButtons();


private slots:
    void lastZombieWaveGenerator();
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
    QTimer* lastZombieWaveTimer;
    QList<int> zombieStartRows;

    std::string zombieList;
    int zombieCounter;
    QString curLvl;

    QPushButton* powerGeneratorButton;
    QPushButton* shooterButton;
    QPushButton* wallButton;
    QPushButton* mineButton;
    QPushButton* superShooterButton;

};
#endif // MAINWINDOW_H
