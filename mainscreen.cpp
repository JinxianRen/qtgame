#include "mainscreen.h"
#include "ui_mainscreen.h"

#include "config.h"

#include "qpainter.h"
#include "QKeyEvent"
#include "bullet.h"
#include <QListIterator>
#include "firstwin.h"
#include "goldbuy.h"
#include "youlose.h"
#include <QDebug>
#include <QIcon>

extern int map[24][24];
int map1[24][24];
extern int wudi_time;
extern int extra_life;
mainscreen::mainscreen(QWidget *parent) : QWidget(parent), ui(new Ui::mainscreen)
{
  ui->setupUi(this);
  memset(map,0,sizeof(map));
  background=BackGround(1);
  for(int i=0;i<MSTRNUM;i++)//初始化第一关怪物
      mons[i] = monster(1);
  for(int i=0;i<MSTRNUM_BULLET;i++)
      mons_bullet[i] = monster_bullet(1);
  setWindowTitle(TITLE);
  setWindowIcon(QIcon(GAMEICON));
  init();
  gamestart();
  updatenum=0;
}

mainscreen::~mainscreen()
{
  delete ui;
}

void mainscreen::init()//初始化
{
  setFixedSize(XSIZE, YSIZE);
  setWindowTitle(TITLE);
  Timer.setInterval(GAME_TICK);
  Mapinit();
  drawgold();

}

void mainscreen::Mapinit(){//地图初始化
    for(int i=0;i<24;i++)
    for(int j=23;j>20;j--)
        map[i][j]=1;
    for(int i=0;i<17;i++)
        map[i][19]=1;
    for(int i=23;i>17;i--)
        map[i][18]=1;
    for(int i=7;i<22;i++)
        map[i][16]=1;
    for(int i=0;i<14;i++)
        map[i][13]=1;
    for(int i=4;i<9;i++)
        map[i][5]=1;
    for(int i=0;i<3;i++)
        map[i][2]=1;

    map[4][18]=map[20][15]=map[13][14]=map[16][14]=
    map[17][14]=map[18][14]=map[21][14]=map[22][13]=
    map[22][12]=map[20][12]=map[19][12]=map[18][12]=
    map[2][11]=map[3][11]=map[22][11]=map[13][10]=
    map[16][10]=map[17][10]=map[21][10]=map[0][9]=
    map[1][9]=map[6][9]=map[7][9]=map[5][9]=
    map[12][9]=map[19][9]=map[20][9]=map[21][9]=
    map[11][8]=map[15][8]=map[16][8]=map[2][7]=
    map[3][7]=map[10][7]=map[9][6]=map[17][6]=
    map[18][6]=map[19][6]=map[23][6]=map[15][5]=
    map[14][5]=map[20][5]=map[22][5]=map[12][4]=
    map[13][4]=map[22][4]=map[4][3]=map[5][3]=
    map[11][3]=map[10][2]=map[9][1]=map[9][0]=1;
    for(int i=0;i<24;i++)
        for(int j=0;j<24;j++)
            map1[i][j]=map[i][j];
    for(int i=0;i<24;i++)
    for(int j=23;j>21;j--)
        map1[i][j]=2;

    map[1][1]=2;
    map[1][17]=map[10][15]=map[21][15]=map[15][12]=
    map[2][10]=map[11][6]=map[2][4]=map[23][4]=
    map[16][3]=3;

    mons[0].is_alive=1,mons[0].x=4*B0,mons[0].y=0;
    mons[1].is_alive=1,mons[1].x=4*B0,mons[1].y=20*B0;
    mons_bullet[0].is_alive=1,mons_bullet[0].x=4*B0,mons_bullet[0].y=12*B0;
}

void mainscreen::gamestart()//主循环
{
  Timer.start();
  connect(&Timer, &QTimer::timeout, [=]()
          {//每帧执行任务
            printblood="目前血量：";
            printblood+=QString::number(pl.blood);
            labelblood2->setText(printblood);
            labelblood2->adjustSize();
            printtime="用时：";
            printtime+=QString::number(time,'lf',2).append('s');
            labeltime2->setText(printtime);
            labeltime2->adjustSize();
            print="金币数：";
            print+=QString::number(pl.goldnum);
            label2->setText(print);
            label2->adjustSize();
            for (int i=0;i<MSTRNUM;i++){//怪物行为
                if(mons[i].is_alive){
                    if(!mons[i].is_ground())
                        mons[i].fall();
                    else
                        mons[i].move();
                    if(pl.touch(mons[i]))
                    {
                        if(pl.injure())
                            audio.play(2);
                    }

                }
            }
            for(int i=0;i<MSTRNUM_BULLET;i++)
            {
                if(mons_bullet[i].is_alive)
                {
                        if(!mons_bullet[i].is_ground())
                            mons_bullet[i].fall();
                        else
                            mons_bullet[i].move();
                        if(pl.touch(mons_bullet[i]))
                        {
                            if(pl.injure())
                                audio.play(2);
                        }
                        if(begin==true && updatenum % BULLET_TIME==0) //生成子弹
                        {
                            mons_bullet[i].newbullet();
                        }
                        mons_bullet[i].bulletmove();
                        if(begin==true)
                        {
                            for(int j=0;j<30;j++)
                            {
                                if(mons_bullet[i].biu[j].is_alive==1)
                                {
                                    //qDebug() << mons_bullet[i].biu[j].x<< mons_bullet[i].biu[j].y;
                                    if(pl.touch(mons_bullet[i].biu[j]))
                                    {
                                        mons_bullet[i].biu[j].is_alive=0;
                                        {
                                            if(pl.bulletinjure())
                                                audio.play(2);
                                        }
                                    }
                                }
                            }
                        }
                }
            }
            if(wintime==0)
            {
                if(begin==true)
                {
                    updatenum++;
                    time=double(updatenum)/50;
                    //qDebug() << QString::number(updatenum,10);
                }

                if(pl.hittimer!=0)pl.hittimer++;
                if(pl.hittimer>20)pl.hittimer=0;//受伤无敌时间
                if(!pl.is_ground())pl.is_jump=1;//运动部分
                if(pl.is_jump)pl.fall();
                if(leftpress){
                    background.mappositionl();
                    pl.left();
                    if(begin==false)
                        begin=true;
                }
                if(rightpress){
                    background.mappositionr();
                    pl.right();
                    if(begin==false)
                        begin=true;
                }
                if(pl.wincheck())//胜利检查
                {
                    audio.play(4);
                    wintime=1;
                }
                if(pl.goldcheck()==1)//金币数获取
                {
                    audio.play(1);
                    pl.goldnum++;
                    pl.allgoldnum++;
                    map[pl.x/B0][pl.y/B0]=0;
                }
                if(pl.goldcheck()==2)//金币数获取
                {
                    audio.play(1);
                    pl.goldnum++;
                    pl.allgoldnum++;
                    map[(pl.x+W)/B0][pl.y/B0]=0;
                }
                if(pl.dicicheck())//受伤及死亡
                  {
                        if(pl.injure())
                            audio.play(2);
                  }
                if(pl.blood <= 0){
                    if(extra_life)extra_life--,pl.blood=100;
                    else{
                   gamelose();
                   close();
                   Timer.stop();
                    }
                }
                if(wudi_time)wudi_time--;//无敌时间的流逝
                }
            else
            {
                wintime++;
                if(wintime>=100)
                {
                    gamewin();
                    close();
                    Timer.stop();
                }
            }
        update(); //绘制
  });
}

void mainscreen::paintEvent(QPaintEvent *event) //绘制事件
{
  QPainter painter(this);
  painter.drawPixmap(background.map1_x, 0,XSIZE+5,YSIZE, background.map1); //绘制背景图
  painter.drawPixmap(background.map2_x, 0,XSIZE+5,YSIZE, background.map2);
  painter.drawPixmap(background.map3_x, 0,XSIZE+5,YSIZE, background.map3);
  painter.drawPixmap(pl.x, pl.y, W, H, pl.picture); //绘制角色
  block1.load(BLOCK10);//地图绘制
  block2.load(BLOCK2);
  block3.load(BLOCK3);
  block4.load(BLOCK4);
  block5.load(BLOCK11);
    for(int i=0;i<24;i++)
        for(int j=0;j<24;j++)
        {
            switch(map[i][j]){
            case 2:
                painter.drawPixmap(i*B0, j*B0,W,W, block2);
                break;
            case 3:
                painter.drawPixmap(i*B0, j*B0,W,W, block3);
                break;
            }
            switch(map1[i][j]){
            case 1:
                painter.drawPixmap(i*B0, j*B0,W,W, block5);
                break;
            case 2:
                painter.drawPixmap(i*B0, j*B0,W,W, block1);
                break;
            }
        }
  for(int i=0;i<MSTRNUM;i++)
  {
      if(mons[i].is_alive)
      {
          painter.drawPixmap(mons[i].x, mons[i].y, W, H, mons[i].picture);
      }
  }
  for(int i=0;i<MSTRNUM_BULLET;i++)
  {
      if(mons_bullet[i].is_alive)
      {
          painter.drawPixmap(mons_bullet[i].x, mons_bullet[i].y, W, H, mons_bullet[i].picture);
          //qDebug() << mons_bullet[i].x<< mons_bullet[i].y;
          for(int j=0;j<30;j++)
          {
              if(mons_bullet[i].biu[j].is_alive==1)
              {
                   painter.drawPixmap(mons_bullet[i].biu[j].x, mons_bullet[i].biu[j].y, W, H, mons_bullet[i].biu[j].picture);
                   //qDebug() << mons_bullet[i].biu[j].x<< mons_bullet[i].biu[j].y;
              }
          }
      }

  }
}

void mainscreen::drawgold()
{

    label2 =new QLabel(this);
    font.setFamily("SimHei");//字体
    font.setPointSize(10);//文字大小

    print="可用金币数：";
    print+=QString::number(pl.goldnum);
    label2->setText(print);
    label2->setStyleSheet("color: black");
    label2->move(520,20);
    label2->setFont(font);

       labelblood2 =new QLabel(this);
       printblood="目前血量：";
       printblood+=QString::number(pl.blood);
       labelblood2->setText(printblood);
       labelblood2->setStyleSheet("color: black");
       labelblood2->move(520,50);
       labelblood2->setFont(font);
       labelblood2->show();

       labeltime2 =new QLabel(this);
       printtime="用时：";
       printtime+=QString::number(time,'lf',2).append('s');
       labeltime2->setText(printtime);
       labeltime2->setStyleSheet("color: black");
       labeltime2->move(520,80);
       labeltime2->setFont(font);
       labeltime2->show();

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
  if (event->key() == Qt::Key_K && !pl.is_jump)
  {
    pl.jump();
  }
  update();
}

void mainscreen::keyReleaseEvent(QKeyEvent *event)//松开按键事件
{
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

void mainscreen::gamewin()//胜利界面
{
    firstwin *win= new firstwin(pl.goldnum,pl.allgoldnum,time);
    win->setAttribute(Qt::WA_DeleteOnClose, true);
    win->show();
}

void mainscreen::on_pushButton_clicked()//金币商店
{
    begin=false;
    goldbuy *buy= new goldbuy(pl);
    buy->show();
    pl.goldnum=buy->nowgold();
    update();
}

void mainscreen::gamelose()  //失败界面
{
    youlose *lose= new youlose(pl.allgoldnum,time,1);
    lose->setAttribute(Qt::WA_DeleteOnClose, true);
    lose->show();
}
