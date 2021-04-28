/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QListWidget *listWidget;
    QLabel *menuLabel;
    QLabel *userLabel;
    QComboBox *UserName;
    QLabel *nameLabel;
    QComboBox *LevelName;
    QPushButton *StartButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(794, 500);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 794, 500));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(279, 53, 264, 360));
        menuLabel = new QLabel(centralwidget);
        menuLabel->setObjectName(QString::fromUtf8("menuLabel"));
        menuLabel->setGeometry(QRect(390, 70, 41, 22));
        QFont font;
        font.setPointSize(11);
        menuLabel->setFont(font);
        userLabel = new QLabel(centralwidget);
        userLabel->setObjectName(QString::fromUtf8("userLabel"));
        userLabel->setGeometry(QRect(299, 110, 31, 22));
        UserName = new QComboBox(centralwidget);
        UserName->addItem(QString());
        UserName->addItem(QString());
        UserName->addItem(QString());
        UserName->addItem(QString());
        UserName->setObjectName(QString::fromUtf8("UserName"));
        UserName->setGeometry(QRect(350, 110, 161, 22));
        nameLabel = new QLabel(centralwidget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setGeometry(QRect(299, 150, 41, 22));
        LevelName = new QComboBox(centralwidget);
        LevelName->addItem(QString());
        LevelName->setObjectName(QString::fromUtf8("LevelName"));
        LevelName->setGeometry(QRect(350, 150, 161, 22));
        StartButton = new QPushButton(centralwidget);
        StartButton->setObjectName(QString::fromUtf8("StartButton"));
        StartButton->setGeometry(QRect(373, 300, 75, 23));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 794, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        menuLabel->setText(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        userLabel->setText(QCoreApplication::translate("MainWindow", "User:", nullptr));
        UserName->setItemText(0, QCoreApplication::translate("MainWindow", "Denis", nullptr));
        UserName->setItemText(1, QCoreApplication::translate("MainWindow", "Anton", nullptr));
        UserName->setItemText(2, QCoreApplication::translate("MainWindow", "Dima", nullptr));
        UserName->setItemText(3, QCoreApplication::translate("MainWindow", "Sani", nullptr));

        nameLabel->setText(QCoreApplication::translate("MainWindow", "Level:", nullptr));
        LevelName->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));

        StartButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
