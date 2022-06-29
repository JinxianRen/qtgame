#include "mainscreen_second.h"
#include "ui_mainscreen_second.h"
#include "config.h"

#include "qpainter.h"
#include "QKeyEvent"
#include "bullet.h"
#include <QListIterator>
#include "lastwin.h"
#include "goldbuy.h"
#include "youlose.h"
#include <QDebug>
#include <QIcon>

extern int map[24][24];
int map2[24][24];
mainscreen_second::mainscreen_second(int nowgold_,int allgold1_,double time1_,QWidget *parent) :
    QWidget(parent),time1(time1_),
    ui(new Ui::mainscreen_second)
{
    ui->setupUi(this);
    memset(map,0,sizeof(map));
    memset(map2,0,sizeof(map2));
    setWindowTitle(TITLE);
    setWindowIcon(QIcon(GAMEICON));
    background=BackGround(2);
    for(int i = 0;i<MSTRNUM;i++)
        mons[i]=monster(2);
    for(int i=0;i<MSTRNUM_BULLET;i++)
        mons_bullet[i]=monster_bullet(2);
    init();
    gamestart();
    pl.goldnum = nowgold_;
    pl.allgoldnum = allgold1_;
    pl.goldnum_second = allgold1_;
    updatenum = 0;
}

mainscreen_second::~mainscreen_second()
{
    delete ui;
}

void mainscreen_second::init()//初始化
{
    setFixedSize(XSIZE, YSIZE);
    setWindowTitle(TITLE);
    Timer.setInterval(GAME_TICK);
    Mapinit();
    drawgold();
}

void mainscreen_second::Mapinit() {//地图初始化

    for (int i = 0; i < 24; i++)
        map[i][21] = 1;
    for (int i = 2; i < 5; i++)
        map[i][18] = 1;
    for (int i = 6; i < 11; i++)
        map[i][15] = 1;
    map[2][2]=map[1][2]=map[2][5]=map[4][10]=map[6][6]=
    map[9][9]=map[12][6]=map[13][6]=map[14][6]=map[15][6]=
    map[16][6]=map[15][9]=map[19][9]=map[17][14]=map[21][16]=
    map[22][4]=map[18][6]=map[12][12]=map[20][6]=1;
    map[7][14]=map[8][14]=map[9][14]=7;
    for (int i = 0; i < 24; i++)
        for (int j = 0; j < 24; j++)
            if(map[i][j]==1)
                map2[i][j]=6;
    for (int i = 0; i < 24; i++)
        map2[i][21] = 5;
    for (int i = 0; i < 24; i++)
        for (int j = 23; j > 21; j--)
        {
            map[i][j] = 1;
            map2[i][j]=1;
        }
    map[1][1] = 2;
    map[2][10] = map[22][3]=map[21][15]=3;
    mons[0].is_alive = 1, mons[0].x = 12 * B0, mons[0].y = 0;
    mons[1].is_alive=1,mons[1].x=4*B0,mons[1].y=20*B0;
    mons_bullet[0].is_alive = 1, mons_bullet[0].x = 4 * B0, mons_bullet[0].y = 17 * B0;
}

void mainscreen_second::gamestart()//主循环
{
    Timer.start();
    connect(&Timer, &QTimer::timeout, [=]()
        {//每帧执行任务
            printblood = "目前血量：";
            printblood += QString::number(pl.blood);
            labelblood2->setText(printblood);
            labelblood2->adjustSize();
            printtime = "用时：";
            printtime += QString::number(nowtime, 'lf', 2).append('s');
            labeltime2->setText(printtime);
            labeltime2->adjustSize();
            print = "可用金币数：";
            print += QString::number(pl.goldnum);
            label2->setText(print);
            label2->adjustSize();

            if (begin == true)
            {
                updatenum++;
                nowtime = double(updatenum) / 50;
                //qDebug() << QString::number(updatenum,10);
            }
            for (int i = 0; i < MSTRNUM; i++) {//怪物行为
                if (mons[i].is_alive) {
                    if (!mons[i].is_ground())
                        mons[i].fall();
                    else
                        mons[i].move();
                    if (pl.touch(mons[i]))
                        pl.injure();
                }
            }
            for (int i = 0; i < MSTRNUM_BULLET; i++)
            {
                if (mons_bullet[i].is_alive)
                {
                    if (!mons_bullet[i].is_ground())
                        mons_bullet[i].fall();
                    else
                        mons_bullet[i].move();
                    if (pl.touch(mons_bullet[i]))
                        pl.injure();
                    if (begin == true && updatenum % BULLET_TIME == 0) //生成子弹
                    {
                        mons_bullet[i].newbullet();
                    }
                    mons_bullet[i].bulletmove();
                    if (begin == true)
                    {
                        for (int j = 0; j < 30; j++)
                        {
                            if (mons_bullet[i].biu[j].is_alive == 1)
                            {
                                //qDebug() << mons_bullet[i].biu[j].x<< mons_bullet[i].biu[j].y;
                                if (pl.touch(mons_bullet[i].biu[j]))
                                {
                                    mons_bullet[i].biu[j].is_alive = 0;
                                    pl.bulletinjure();
                                }
                            }
                        }
                    }
                }
            }
            if (pl.hittimer != 0)
                pl.hittimer++;
            if (pl.hittimer > 20)
                pl.hittimer = 0;//受伤无敌时间
            if (!pl.is_ground())
                pl.is_jump = 1;//运动部分
            if (pl.is_jump)
                pl.fall();
            if (leftpress)
            {
                background.mappositionl();
                pl.left();
                if (begin == false)
                    begin = true;
            }
            if (rightpress)
            {
                background.mappositionr();
                pl.right();
                if (begin == false)
                    begin = true;
            }
            if (pl.wincheck())//胜利检查
            {
                gamewin();
                close();
                Timer.stop();
            }
            if (pl.goldcheck() == 1)//金币数获取
            {
                pl.goldnum++;
                pl.allgoldnum++;
                map[pl.x / B0][pl.y / B0] = 0;
            }
            if (pl.goldcheck() == 2)//金币数获取
            {
                pl.goldnum++;
                pl.allgoldnum++;
                map[(pl.x + W) / B0][pl.y / B0] = 0;
            }
            if (pl.dicicheck())//受伤及死亡
            {
                pl.injure();
            }
            if (pl.blood <= 0)
            {
                gamelose();
                close();
                Timer.stop();
            }
            update(); //绘制
        });
}

void mainscreen_second::paintEvent(QPaintEvent* event) //绘制事件
{
    QPainter painter(this);
    painter.drawPixmap(background.map1_x, 0,XSIZE+5,YSIZE, background.map1); //绘制背景图
    painter.drawPixmap(background.map2_x, 0,XSIZE+5,YSIZE, background.map2);
    painter.drawPixmap(background.map3_x, 0,XSIZE+5,YSIZE, background.map3);
    painter.drawPixmap(pl.x, pl.y, W, H, pl.picture); //绘制角色
    block1.load(BLOCK20);//地图绘制
    block2.load(BLOCK2);
    block3.load(BLOCK3);
    block4.load(BLOCK4);
    block5.load(BLOCK21);
    block6.load(BLOCK22);
    block7.load(BLOCKD);
    for (int i = 0; i < 24; i++)
        for (int j = 0; j < 24; j++)
        {
            switch (map[i][j]) {
            case 2:
                painter.drawPixmap(i * B0, j * B0, W, W, block2);
                break;
            case 3:
                painter.drawPixmap(i * B0, j * B0, W, W, block3);
                break;
            case 7:
                painter.drawPixmap(i * B0, j * B0, W, W, block7);
                break;
            }
            switch (map2[i][j]) {
            case 1:
                painter.drawPixmap(i * B0, j * B0, W, W, block1);
                break;
            case 5:
                painter.drawPixmap(i * B0, j * B0, W, W, block5);
                break;
            case 6:
                painter.drawPixmap(i * B0, j * B0, W, W, block6);
                break;
            }
        }
    for (int i = 0; i < MSTRNUM; i++)
    {
        if (mons[i].is_alive)
        {
            painter.drawPixmap(mons[i].x, mons[i].y, W, H, mons[i].picture);
        }
    }
    for (int i = 0; i < MSTRNUM_BULLET; i++)
    {
        if (mons_bullet[i].is_alive)
        {
            painter.drawPixmap(mons_bullet[i].x, mons_bullet[i].y, W, H, mons_bullet[i].picture);
            //qDebug() << mons_bullet[i].x<< mons_bullet[i].y;
            for (int j = 0; j < 30; j++)
            {
                if (mons_bullet[i].biu[j].is_alive == 1)
                {
                    painter.drawPixmap(mons_bullet[i].biu[j].x, mons_bullet[i].biu[j].y, W, H, mons_bullet[i].biu[j].picture);
                    //qDebug() << mons_bullet[i].biu[j].x<< mons_bullet[i].biu[j].y;
                }
            }
        }

    }
}

void mainscreen_second::drawgold()
{

    label2 =new QLabel(this);
    font.setFamily("SimHei");//字体
    font.setPointSize(10);//文字大小

    print="金币数：";
    print+=QString::number(pl.goldnum);
    label2->setText(print);
    label2->setStyleSheet("color: white");
    label2->move(520,20);
    label2->setFont(font);

       labelblood2 =new QLabel(this);
       printblood="目前血量：";
       printblood+=QString::number(pl.blood);
       labelblood2->setText(printblood);
       labelblood2->setStyleSheet("color: white");
       labelblood2->move(520,50);
       labelblood2->setFont(font);
       labelblood2->show();

       labeltime2 =new QLabel(this);
       printtime="用时：";
       printtime+=QString::number(nowtime,'lf',2).append('s');
       labeltime2->setText(printtime);
       labeltime2->setStyleSheet("color: white");
       labeltime2->move(520,80);
       labeltime2->setFont(font);
       labeltime2->show();

}
void mainscreen_second::keyPressEvent(QKeyEvent* event) //按键事件
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

void mainscreen_second::keyReleaseEvent(QKeyEvent* event)//松开按键事件
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

void mainscreen_second::gamewin()//胜利界面
{
    lastwin* win = new lastwin(pl.allgoldnum,nowtime+time1);
    win->setAttribute(Qt::WA_DeleteOnClose, true);
    win->show();
}

void mainscreen_second::on_pushButton_clicked()//金币商店
{
    begin = false;
    goldbuy* buy = new goldbuy(pl);
    buy->show();
    pl.goldnum = buy->nowgold();
    update();
}

void mainscreen_second::gamelose()  //失败界面
{
    youlose* lose = new youlose(pl.allgoldnum-pl.goldnum_second, nowtime,2);
    lose->setAttribute(Qt::WA_DeleteOnClose, true);
    lose->show();
}
