#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTimer>
#include "gamescene.h"
#include <QLabel>
#include <QGraphicsPixmapItem>
#include "powergenerator.h"
#include "gameobject.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setupGameScene();
    void hideMenu();
    void createGameplayUi();
    void addRow(int x, int y);
    void addHomeRow();
    void setRows();
    void addPortalRow();
    void plantGenerator(GameObject* object);


private slots:
    void on_StartButton_clicked();

    void powerGeneratorButtonClicked();
    void powerGeneratorPlacement();

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

    QPushButton* powerGeneratorButton;
    QPushButton* shooterButton;
    QPushButton* wallButton;
    QPushButton* mineButton;
    QPushButton* superShooterButton;
};
#endif // MAINWINDOW_H
