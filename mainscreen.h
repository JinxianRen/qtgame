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

#include "qpainter.h"

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
    monster mons[20];
    QPixmap block1,block2,block3,block4;
    QFont font;
    QLabel *label1,*label2;
    QLabel *labelblood1,*labelblood2;
    bool leftpress=0;
    bool rightpress=0;
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
