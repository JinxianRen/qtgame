#include "youlose.h"
#include "ui_youlose.h"
#include "widget.h"
#include "config.h"
#include "dialog.h"

youlose::youlose(int allgoldnum_,double time_,QWidget *parent) :
    QDialog(parent),allgoldnum(allgoldnum_),time(time_),
    ui(new Ui::youlose)
{
    ui->setupUi(this);
    setWindowTitle(TITLE);
    setWindowIcon(QIcon(GAMEICON));
    int width = 1032;
    int height = 736;
    this->setFixedSize(width,height); //设置窗体固定大小
    drawgold();
}

youlose::~youlose()
{
    delete ui;
}

void youlose::drawgold()
{
    print="You Lose!\n""你共坚持了";
    print+=QString::number(time,'lf',2).append('s');
    print+="\n共获得的金币为：";
    print+=QString::number(allgoldnum);

  //  label1 =new QLabel(this);
    label2 =new QLabel(this);
    font.setFamily("SimHei");//字体
    font.setPointSize(10);//文字大小
    label2->setText(print);
    label2->setStyleSheet("color: black");
    label2->move(320,220);
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
