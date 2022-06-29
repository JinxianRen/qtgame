#include "firstwin.h"
#include "ui_firstwin.h"
#include "widget.h"
#include "config.h"
#include "mainscreen_second.h"
#include "dialog.h"

firstwin::firstwin(int nowgoldnum_,int allgoldnum_,double time_,QWidget *parent) :
    QDialog(parent),nowgoldnum(nowgoldnum_),allgoldnum(allgoldnum_),time(time_),
    ui(new Ui::firstwin)
{
    ui->setupUi(this);
    setWindowTitle(TITLE);
    setWindowIcon(QIcon(GAMEICON));
    int width = 1024;
    int height = 576;
    this->setFixedSize(width,height); //设置窗体固定大小
    drawgold();
}

firstwin::~firstwin()
{
    delete ui;
}

void firstwin::on_pushButton_2_clicked()
{
    Widget *w = new Widget;
    w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
    close();
}

void firstwin::on_pushButton_clicked()
{
     mainscreen *d = new mainscreen;
     d->setAttribute(Qt::WA_DeleteOnClose, true);
     d->show();
     close();
}

void firstwin::drawgold()
{
    label2 =new QLabel(this);
    font.setFamily("SimHei");//字体
    font.setPointSize(10);//文字大小

    print="恭喜你通过了第一关!\n""通过第一关的用时为：";
    print+=QString::number(time,'lf',2).append('s');
    print+="\n在第一关你获得的金币为：";
    print+=QString::number(allgoldnum).append('/');
    print+=QString::number(GOLDFIRST);

    label2->setText(print);
    label2->setStyleSheet("color: white");
    label2->move(320,220);
    label2->setFont(font);
    label2->show();
}

void firstwin::on_pushButton_3_clicked()
{
    mainscreen_second *d = new mainscreen_second(nowgoldnum,allgoldnum,time); //(int allgoldnum);
    //应该传送的是上一轮剩下的金币，这里待修改
    d->setAttribute(Qt::WA_DeleteOnClose, true);
    d->show();
    close();
}
