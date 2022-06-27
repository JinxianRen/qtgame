#include "firstwin.h"
#include "ui_firstwin.h"
#include "widget.h"
#include "config.h"
#include "dialog.h"

firstwin::firstwin(int allgoldnum_,QWidget *parent) :
    QDialog(parent),allgoldnum(allgoldnum_),
    ui(new Ui::firstwin)
{
    ui->setupUi(this);
    int width = 1032;
    int height = 736;
    this->setFixedSize(width,height); //设置窗体固定大小
    drawgold();
}

firstwin::~firstwin()
{
    delete ui;
}

void firstwin::on_pushButton_2_clicked()
{
    close();
    Widget *w = new Widget;
    w->show();
}

void firstwin::on_pushButton_clicked()
{
     close();
     mainscreen *d = new mainscreen;
     d->show();
}

void firstwin::drawgold()
{
    label1 =new QLabel(this);
    label2 =new QLabel(this);
    font.setFamily("SimHei");//字体
    font.setPointSize(10);//文字大小
    label1->setText(QString::number(allgoldnum));
    label1->setStyleSheet("color: white");
    label1->move(600,250);
    label1->setFont(font);
    label1->show();
    label2->setText("恭喜你获胜了\n""你共获得的金币为：");
    label2->setStyleSheet("color: white");
    label2->move(320,220);
    label2->setFont(font);
    label2->show();
}
