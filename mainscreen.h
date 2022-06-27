#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QWidget>
#include"qtimer.h"
#include "QKeyEvent"

#include "Gamemap.h"

#include "background.h"
#include "player.h"

#include "config.h"
static Gamemap map[12][100];
static int camara_x;//镜头起始位置
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
    int begin;//地图生成起点
    void init();
    void Mapinit();
    void gamestart();
    void updateposition();
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
};

#endif // MAINSCREEN_H
