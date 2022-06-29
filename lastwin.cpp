#include "lastwin.h"
#include "ui_lastwin.h"
#include "widget.h"
#include "config.h"
#include "mainscreen_second.h"
#include "dialog.h"

lastwin::lastwin(int allgold_,double alltime_,int blood_,QWidget *parent) :
    QDialog(parent),allgold(allgold_),alltime(alltime_),blood(blood_),
    ui(new Ui::lastwin)
{
    ui->setupUi(this);
    setWindowTitle(TITLE);
    setWindowIcon(QIcon(GAMEICON));
    int width = 768;
    int height = 768;
    this->setFixedSize(width,height); //设置窗体固定大小
    drawgold();
}

lastwin::~lastwin()
{
    delete ui;
}

void lastwin::drawgold()
{
    label2 =new QLabel(this);
    font.setFamily("Fusion Pixel");//字体
    font.setBold(true);
    font.setPointSize(15);//文字大小

    print="恭喜你通关了!\n\n""通关用时为：";
    print+=QString::number(alltime,'lf',2).append('s');
    print+="\n";
    print+="\n你共获得的金币为：";
    print+=QString::number(allgold).append('/');
    print+=QString::number(GOLDFIRST+GOLDSECOND);
    print+="\n";
    //成就系统
    printach = "\n恭喜你获得成就——";
    bool checkif = 0;
    if(allgold==GOLDFIRST+GOLDSECOND)  //金币收集大师
    {
        printach+="金币收集大师 ";
        checkif=1;
    }
    if(alltime<=15.000001)   //速通达人
    {
        printach+="速通达人 ";
        checkif=1;
    }
    if(blood==100)  //满血通关
    {
        printach+="满血通关 ";
        checkif=1;
    }
    if(checkif==0)
    {
        printach = "";
    }

    label2->setText(print+printach);
    label2->setStyleSheet("color: black");
    label2->move(200,200);
    label2->setFont(font);
    label2->show();

}


void lastwin::on_pushButton_clicked() //再来一局
{
    mainscreen *d = new mainscreen;
    d->setAttribute(Qt::WA_DeleteOnClose, true);
    d->show();
    close();
}

void lastwin::on_pushButton_2_clicked()  //返回主菜单
{
    Widget *w = new Widget;
    w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->music->stop();
    w->show();
    close();
}
