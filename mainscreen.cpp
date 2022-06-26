#include "mainscreen.h"
#include "ui_mainscreen.h"
#include "config.h"
#include"qpainter.h"
#include "QKeyEvent"

mainscreen::mainscreen(QWidget *parent) :
    QWidget(parent),ui(new Ui::mainscreen)
{
    ui->setupUi(this);
    init();
    gamestart();
}

mainscreen::~mainscreen()
{
    delete ui;
}
void mainscreen::init(){
    setFixedSize(XSIZE,YSIZE);
    setWindowTitle("游戏主界面");
    Timer.setInterval(GAME_TICK);
}
void mainscreen::gamestart(){
    Timer.start();
    connect(&Timer,&QTimer::timeout,[=](){
        update();
    });
}

void mainscreen::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(background.map1_x ,0, background.map1);
    painter.drawPixmap(background.map2_x ,0, background.map2);
   // painter.drawPixmap(X,Y,player.picture);
}
void mainscreen::keyPressEvent(QKeyEvent *event)
{
        if(event->key() == Qt::Key_Left)
        {


        }
        if(event->key() == Qt::Key_Right)
        {
            background.mapposition();
           // startX=(startX+1+image.width ()>width)?startX:startX+1;

        }
        if(event->key() == Qt::Key_Up)
        {
           // startY=(startY-1<0)?startY:startY-1;

        }
        if(event->key() == Qt::Key_Down)
        {
           // startY=(startY+1+image.height()>height)?startY:startY+1;

        }
    update();
}

