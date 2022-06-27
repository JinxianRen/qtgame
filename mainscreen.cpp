#include "mainscreen.h"
#include "ui_mainscreen.h"
#include "config.h"
#include "qpainter.h"
#include "QKeyEvent"
extern Map map[24][24];
mainscreen::mainscreen(QWidget *parent) : QWidget(parent), ui(new Ui::mainscreen)
{
  ui->setupUi(this);
  init();
  gamestart();
}

mainscreen::~mainscreen()
{
  delete ui;
}
void mainscreen::init()
{ //初始化
  setFixedSize(XSIZE, YSIZE);
  setWindowTitle(TITLE);
  Timer.setInterval(GAME_TICK);
  Mapinit();
}
void mainscreen::Mapinit(){//地图初始化
    for(int i=0;i<24;i++){
        for(int j=23;j>21;j--){
            map[i][j].id=1;
        }
    }
    for(int i=0;i<24;i++)
        for(int j=0;j<24;j++){
            if(i==j)map[i][j].id=1;
        }
}
void mainscreen::gamestart()
{
  Timer.start();
  connect(&Timer, &QTimer::timeout, [=]()
          {
            if(pl.is_ground())pl.is_jump=1;
            if(pl.is_jump)pl.fall();
            if(leftpress){
                background.mappositionl();
                pl.left();
            }
            if(rightpress){
                background.mappositionr();
                pl.right();
            }
        update(); });
}

void mainscreen::paintEvent(QPaintEvent *event) //绘制事件
{
  QPainter painter(this);
  painter.drawPixmap(background.map1_x, 0, background.map1); //绘制背景图
  painter.drawPixmap(background.map2_x, 0, background.map2);
  painter.drawPixmap(background.map3_x, 0, background.map3);
  painter.drawPixmap(pl.x, pl.y, W, H, pl.picture); //绘制角色
  block1.load(BLOCK1);//地图绘制
    for(int i=0;i<24;i++)
        for(int j=0;j<24;j++){
            switch(map[i][j].id){
            case 1:
                painter.drawPixmap(i*B, j*B,W,W, block1);
                break;
            }
        }

}
void mainscreen::keyPressEvent(QKeyEvent *event) //按键事件
{
  if (event->key() == Qt::Key_A && event->type())
  {
    leftpress = 1;
  }
  if (event->key() == Qt::Key_D)
  {
    rightpress = 1;
  }
  if (event->key() == Qt::Key_Space && !pl.is_jump)
  {
    pl.jump();
  }
  if (event->key() == Qt::Key_J) //可能会有的攻击
  {
  }
  update();
}
void mainscreen::keyReleaseEvent(QKeyEvent *event)
{ //松开按键事件
  if (event->key() == Qt::Key_A && event->type())
  {
    leftpress = 0;
  }
  if (event->key() == Qt::Key_D)
  {
    rightpress = 0;
  }
  update();
}
