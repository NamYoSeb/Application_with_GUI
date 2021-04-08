#include "mainwindow.h"
#include "ui_mainwindow.h"

QPointF MainWindow::mouseCoordinates;
QPointF MainWindow::mousePressCoordinates;
QGraphicsScene *MainWindow::gameScene;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    gameScene = new GameScene();
    plantHover = new QLabel();
    plantHover->setGeometry(-5,-5,0,0);
    gameScene->addWidget(plantHover);

    createGameplayUi();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupGameScene()
{
    gameScene->addWidget(powerGeneratorButton);
    gameScene->addWidget(shooterButton);
    gameScene->addWidget(wallButton);
    gameScene->addWidget(mineButton);
    gameScene->addWidget(superShooterButton);
    gameScene->addWidget(sunValue);
    gameScene->addWidget(sunImage);

    setRows();

    ui->graphicsView->setScene(gameScene);
    gameScene->setSceneRect(0, 0, 794, 470);
}

void MainWindow::createGameplayUi()
{
    powerGeneratorButton = new QPushButton();
    powerGeneratorButton->setIcon(QIcon(":/images/sunflower-button.jpg"));
    powerGeneratorButton->setIconSize(QSize(59,82));
    powerGeneratorButton->setGeometry(72,0,59,82);

    shooterButton = new QPushButton();
    shooterButton->setIcon(QIcon(":/images/pea-shooter-button.jpg"));
    shooterButton->setIconSize(QSize(59,82));
    shooterButton->setGeometry(134,0,59,82);

    wallButton = new QPushButton();
    wallButton->setIcon(QIcon(":/images/wallnut-button.jpg"));
    wallButton->setIconSize(QSize(59,82));
    wallButton->setGeometry(196,0,59,82);

    mineButton = new QPushButton();
    mineButton->setIcon(QIcon(":/images/potato-mine-button.jpg"));
    mineButton->setIconSize(QSize(59,82));
    mineButton->setGeometry(258,0,59,82);

    superShooterButton = new QPushButton();
    superShooterButton->setIcon(QIcon(":/images/repeater-button.jpg"));
    superShooterButton->setIconSize(QSize(59,82));
    superShooterButton->setGeometry(320,0,59,82);

    connect(powerGeneratorButton, SIGNAL(clicked()), this, SLOT(powerGeneratorButtonClicked()));

    sunValue = new QLabel();
    sunValue->setAttribute(Qt::WA_TranslucentBackground);
    sunValue->setGeometry(10,65,52,15);
    sunValue->setAlignment(Qt::AlignCenter);
    sunValue->setText("0");

    sunImage = new QLabel();
    sunImage->setAttribute(Qt::WA_TranslucentBackground);
    sunImage->setGeometry(20,20,35,35);
    sunImage->setPixmap(QPixmap(":/images/sun.png"));
}

void MainWindow::addRow(int x, int y)
{
    QGraphicsPixmapItem *row = new QGraphicsPixmapItem();
    row->setPixmap(QPixmap(":/images/grass-row-alt.png"));
    row->setPos(x,y);
    row->setZValue(-5);
    gameScene->addItem(row);
}

void MainWindow::addHomeRow()
{
    QGraphicsPixmapItem *row = new QGraphicsPixmapItem();
    row->setPixmap(QPixmap(":/images/home-row.png"));
    row->setPos(0, 102);
    row->setZValue(-5);
    gameScene->addItem(row);
}

void MainWindow::setRows()
{
    addRow(72, 100);
    addRow(72, 172);
    addRow(72, 244);
    addRow(72, 316);
    addRow(72, 388);
    addHomeRow();
    addPortalRow();
}

void MainWindow::addPortalRow()
{
    QGraphicsPixmapItem *row = new QGraphicsPixmapItem();
    row->setPixmap(QPixmap(":/images/portal-row.png"));
    row->setPos(720, 102);
    row->setZValue(-5);
    gameScene->addItem(row);
}

void MainWindow::plantGenerator(GameObject* plant)
{
    plantTimer->stop();

    const int mouse_press_x = mousePressCoordinates.x();
    const int mouse_press_y = mousePressCoordinates.y();

    if (mouse_press_x > 72 && mouse_press_x < 720 && mouse_press_y > 82 && mouse_press_y < 442)
    {
        if (1)
        {
            int x = mouse_press_x - ((mouse_press_x - 72) % 72);
            int y = mouse_press_y - ((mouse_press_y - 82) % 72);
            plant->setCoordinates(x, y);
            gameScene->addItem(plant);
            plant->setupGameObject();
        }
        else
        {
            plantTimer->start();
            delete plant;
            plant = 0;
            return;
        }
    }

    plantHover->setGeometry(-70,-70,0,0);
}

void MainWindow::powerGeneratorPlacement()
{
    plantHover->setPixmap(QPixmap(":/images/sunflower.png"));
    plantHover->setGeometry(mouseCoordinates.x() - 21, mouseCoordinates.y() - 21, 42, 42);

    if (mousePressCoordinates.x() != 0 || mousePressCoordinates.y() != 0)
    {
        GameObject* sunflower = new PowerGenerator();
        plantGenerator(sunflower);
    }
}

void MainWindow::hideMenu()
{
    ui->LevelName->hide();
    ui->UserName->hide();
    ui->listWidget->hide();
    ui->menuLabel->hide();
    ui->nameLabel->hide();
    ui->StartButton->hide();
    ui->userLabel->hide();

}


void MainWindow::on_StartButton_clicked()
{
    QString curUser = ui->UserName->currentText();
    QString curLvl = ui->LevelName->currentText();

    hideMenu();
    setupGameScene();
}

void MainWindow::powerGeneratorButtonClicked()
{
    plantTimer = new QTimer();
    connect(plantTimer,SIGNAL(timeout()),this,SLOT(powerGeneratorPlacement()));
    mousePressCoordinates = QPointF(0,0);
    plantTimer->start(20);
}

























