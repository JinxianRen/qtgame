#ifndef MAINSCREEN_SECOND_H
#define MAINSCREEN_SECOND_H

#include <QWidget>
#include "qtimer.h"
#include "QKeyEvent"
#include <QLabel>
#include <QFont>
#include "background.h"
#include "player.h"
#include "monster.h"
#include "qdebug.h"
#include "qpainter.h"
#include <QString>
#include "config.h"
#include "monster_bullet.h"

namespace Ui {
class mainscreen_second;
}

class mainscreen_second : public QWidget
{
    Q_OBJECT

public:
    explicit mainscreen_second(int nowgold_=0,int allgold1_=0,double time1_=0.00,QWidget *parent = nullptr);
    ~mainscreen_second();

private:
    Ui::mainscreen_second *ui;

public:
    QTimer Timer;
    BackGround background;
    player pl;
    monster mons[20];
    monster_bullet mons_bullet[20];
    double nowtime=0.000001,time1;
    QPixmap block1,block2,block3,block4,block5,block6,block7;
    QFont font;
    QLabel *label1,*label2;
    QLabel *labelblood1,*labelblood2;
    QLabel *labeltime1,*labeltime2;
    QString print,printblood,printtime;
    int updatenum=0;
    bool leftpress=0;
    double time=0.000001;
    bool rightpress=0;
    bool begin=false;
    void init();
    void Mapinit();
    void gamestart();
    void gamewin();
    void updateposition();
    void paintEvent(QPaintEvent *event);
    void drawgold();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void gamelose();
private slots:
    void on_pushButton_clicked();
};

#endif // MAINSCREEN_SECOND_H
