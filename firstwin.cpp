#include "firstwin.h"
#include "ui_firstwin.h"
#include "widget.h"
#include "config.h"
#include "dialog.h"

firstwin::firstwin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::firstwin)
{
    ui->setupUi(this);
    int width = 1032;
    int height = 736;
    this->setFixedSize(width,height); //设置窗体固定大小
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
