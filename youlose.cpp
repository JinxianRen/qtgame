#include "youlose.h"
#include "ui_youlose.h"
#include "widget.h"
#include "config.h"
#include "dialog.h"

youlose::youlose(int allgoldnum_,double time_,int guan_,QWidget *parent) :
    QDialog(parent),allgoldnum(allgoldnum_),time(time_),guan(guan_),
    ui(new Ui::youlose)
{
    ui->setupUi(this);
    setWindowTitle(TITLE);
    setWindowIcon(QIcon(GAMEICON));
    int width = 768;
    int height = 768;
    this->setFixedSize(width,height); //设置窗体固定大小
    drawgold();
}

youlose::~youlose()
{
    delete ui;
}

void youlose::drawgold()
{
    if(guan==1)
    {
        print="你输在了第一关！\n";
    }
    else
    {
        print="你输在了第二关！\n";
    }

    print+="你共坚持了";
    print+=QString::number(time,'lf',2).append('s');
    print+="\n在本关你获得的金币为：";
    print+=QString::number(allgoldnum).append('/');
    if(guan==1)
    {
        print+=QString::number(GOLDFIRST);
    }
    else
    {
        print+=QString::number(GOLDSECOND);
    }
  //  label1 =new QLabel(this);
    label2 =new QLabel(this);
    font.setFamily("SimHei");//字体
    font.setPointSize(15);//文字大小
    font.setBold(true);
    label2->setText(print);
    label2->setStyleSheet("color: black");
    label2->move(200,200);
    label2->setFont(font);
    label2->show();
}

void youlose::on_pushButton_clicked()
{

    mainscreen *d = new mainscreen;
    d->setAttribute(Qt::WA_DeleteOnClose, true);
    d->show();
    close();
}

void youlose::on_pushButton_2_clicked()
{
    Widget *w = new Widget;
    w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
    close();
}
