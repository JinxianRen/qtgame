#include "goldbuy.h"
#include "ui_goldbuy.h"
#include "mainscreen.h"

goldbuy::goldbuy(player& play,QWidget *parent) :
    QDialog(parent),pl(play),
    ui(new Ui::goldbuy)
{
    ui->setupUi(this);
    drawgold();
}

goldbuy::~goldbuy()
{
    delete ui;
}

void goldbuy::on_pushButton_clicked()
{
    close();
}

void goldbuy::drawgold()
{
    label1 =new QLabel(this);
    label2 =new QLabel(this);
    font.setFamily("SimHei");//字体
    font.setPointSize(10);//文字大小
    label1->setText(QString::number(pl.goldnum));
    label1->setStyleSheet("color: black");
    label1->move(280,50);
    label1->setFont(font);
    label1->show();
    label2->setText("剩余金币数");
    label2->setStyleSheet("color: black");
    label2->move(120,50);
    label2->setFont(font);
    label2->show();
}

int goldbuy::nowgold()
{
    return pl.goldnum;
}

void goldbuy::on_pushButton_2_clicked()
{
    //假设买它需要花1个金币
    if(pl.goldnum>=1)
    {
        pl.goldnum-=1;
        label1->close();
        label1->setText(QString::number(pl.goldnum));
        label1->show();
        if(pl.blood<=90)
            pl.blood+=10;
        else
            pl.blood=100;
    }
}
void goldbuy::on_pushButton_3_clicked()
{
    //假设买它需要花5个金币，买了可以无敌3s
    //可以考虑换一个人物图片，代表处于无敌状态，3s后消失
    //无敌的具体实现，可以考虑换算成刷新次数，设置一个值为刷新次数，刷新一次就减一
    if(pl.goldnum>=5)
    {
        pl.goldnum-=5;
        label1->close();
        label1->setText(QString::number(pl.goldnum));
        label1->show();


    }
}

void goldbuy::on_pushButton_4_clicked()
{
    //假设买它需要花10个金币，买了可以获得一次重生机会

}


