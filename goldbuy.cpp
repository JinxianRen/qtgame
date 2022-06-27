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

void goldbuy::on_pushButton_2_clicked()
{
    //假设买它需要花1个金币
    if(pl.goldnum>=1)
    {
        pl.goldnum-=1;
        //获得什么待补充 //为什么传不回去呢好奇怪，我明明用的是直接引用啊
        label1->close();
        label1->setText(QString::number(pl.goldnum));
        label1->show();
    }
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
