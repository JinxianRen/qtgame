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
void mainscreen::init(){//初始化
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

void mainscreen::paintEvent(QPaintEvent *event)//绘制事件
{
    QPainter painter(this);
    painter.drawPixmap(background.map1_x ,0, background.map1);//绘制背景图
    painter.drawPixmap(background.map2_x ,0, background.map2);
    painter.drawPixmap(background.map3_x ,0, background.map3);
    painter.drawPixmap(pl.x,pl.y,pl.picture);//绘制角色
}
void mainscreen::keyPressEvent(QKeyEvent *event)//按键事件
{
        if(event->key() == Qt::Key_A)
        {
            background.mappositionl();
            pl.left();

        }
        if(event->key() == Qt::Key_D)
        {
            background.mappositionr();
            pl.right();
           // startX=(startX+1+image.width ()>width)?startX:startX+1;

        }
        if(event->key() == Qt::Key_Space)
        {
           // startY=(startY-1<0)?startY:startY-1;

        }
        if(event->key() == Qt::Key_J)
        {
           // startY=(startY+1+image.height()>height)?startY:startY+1;

        }
    update();
}

