#ifndef SKY_H
#define SKY_H

#include "gameobject.h"
#include "sun.h"
#include <QObject>
#include <QTimer>

class Sky : public QObject
{
    Q_OBJECT;

public:
    Sky();

private slots:
    void generateSun();

private:
    QTimer* timer;
};

#endif // SKY_H
