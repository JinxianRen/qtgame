#include "mainscreen.h"
#include "ui_mainscreen.h"
#include "config.h"
#include "qpainter.h"
#include "map.h"
#include "QKeyEvent"
#include "firstwin.h"
#include "goldbuy.h"

int map[24][24];
mainscreen::mainscreen(QWidget *parent) : QWidget(parent), ui(new Ui::mainscreen)
{
  ui->setupUi(this);
  init();
  drawgold();
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
            map[i][j]=1;
        }
    }
    for(int i=0;i<24;i++)
        for(int j=0;j<24;j++){
            if(i==j)map[i][j]=1;
        }
    map[15][15]=0;
    for(int i=18;i<24;i++)map[i][15]=1;
    map[18][14]=map[18][13]=1;
    map[21][21]=map[20][20]=0;
    map[0][21]=2;
    map[4][21]=3;
    map[6][21]=3;

}
void mainscreen::gamestart()
{
  Timer.start();
  connect(&Timer, &QTimer::timeout, [=]()
          {
            if(!pl.is_ground())pl.is_jump=1;
            if(pl.is_jump)pl.fall();
            if(leftpress){
                background.mappositionl();
                pl.left();
            }
            if(rightpress){
                background.mappositionr();
                pl.right();
            }
            if(pl.wincheck())
            {
                gamewin();
                close();
                Timer.stop();
            }
            if(pl.goldcheck())
            {
                pl.goldnum++;
                label1->close();
                label1->setText(QString::number(pl.goldnum));
                label1->show();
                map[pl.x/B][pl.y/B]=0;
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
  block2.load(BLOCK2);
  block3.load(BLOCK3);
    for(int i=0;i<24;i++)
        for(int j=0;j<24;j++){
            switch(map[i][j]){
            case 1:
                painter.drawPixmap(i*B, j*B,W,W, block1);
                break;
            case 2:
                painter.drawPixmap(i*B, j*B,W,W, block2);
                break;
            case 3:
                painter.drawPixmap(i*B, j*B,W,W, block3);
                break;
            }
        }
}

void mainscreen::drawgold()
{
    label1 =new QLabel(this);
    label2 =new QLabel(this);
    font.setFamily("SimHei");//字体
    font.setPointSize(10);//文字大小
    label1->setText(QString::number(pl.goldnum));
    label1->setStyleSheet("color: black");
    label1->move(620,20);
    label1->setFont(font);
    label1->show();
    label2->setText("金币数");
    label2->setStyleSheet("color: black");
    label2->move(520,20);
    label2->setFont(font);
    label2->show();
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

void mainscreen::gamewin()
{
    firstwin *win= new firstwin;
    win->show();

}

void mainscreen::on_pushButton_clicked()
{
    //金币商店part
    goldbuy *buy= new goldbuy(pl);
    buy->show();
}
