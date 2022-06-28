#include "none.h"
#include "ui_none.h"
#include "config.h"
#include "widget.h"
#include "config.h"
#include "mainscreen_second.h"
#include "dialog.h"
#include "mainscreen.h"

none::none(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::none)
{
    ui->setupUi(this);
    setWindowTitle(TITLE);
    setWindowIcon(QIcon(GAMEICON));
}

none::~none()
{
    delete ui;
}

void none::on_pushButton_clicked()
{
    mainscreen *d = new mainscreen;
    d->setAttribute(Qt::WA_DeleteOnClose, true);
    d->show();
    close();
}

void none::on_pushButton_2_clicked()
{
    mainscreen_second *d = new mainscreen_second; //(int allgoldnum);
    //应该传送的是上一轮剩下的金币，这里待修改
    d->setAttribute(Qt::WA_DeleteOnClose, true);
    d->show();
    close();
}

void none::on_pushButton_3_clicked()
{
    Widget *w = new Widget;
    w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
    close();
}
