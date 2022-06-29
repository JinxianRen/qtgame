#ifndef MAINSCREEN_H
#define MAINSCREEN_H

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
#include "audiothread.h"

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
    BackGround background;
    player pl;
    monster mons[20];
    monster_bullet mons_bullet[20];
    QPixmap block1,block2,block3,block4,block5;
    QFont font;
    QLabel *label1,*label2;
    QLabel *labelblood1,*labelblood2;
    QLabel *labeltime1,*labeltime2;
    QString print,printblood,printtime;
    AudioThread audio;
    int updatenum=0;
    bool leftpress=0;
    double time=0.000001;
    bool rightpress=0;
    bool begin=false;
    int wintime=0;
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

#endif // MAINSCREEN_H
