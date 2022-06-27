#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QWidget>
#include"qtimer.h"
#include "QKeyEvent"

#include "background.h"
#include "map.h"
#include "player.h"

#include "config.h"
namespace Ui {
class mainscreen;
}

class mainscreen : public QWidget
{
    Q_OBJECT

public:
    explicit mainscreen(QWidget *parent = nullptr);
    ~mainscreen();

private:
    Ui::mainscreen *ui;

public:
    QTimer Timer;
    QTimer jumptimer;
    BackGround background;
    player pl;
    QPixmap block1,block2,block3;
    bool leftpress=0;
    bool rightpress=0;
    void init();
    void Mapinit();
    void gamestart();
    void updateposition();
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
};

#endif // MAINSCREEN_H
