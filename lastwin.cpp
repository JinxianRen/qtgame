#include "lastwin.h"
#include "ui_lastwin.h"
#include "widget.h"
#include "config.h"
#include "mainscreen_second.h"
#include "dialog.h"

lastwin::lastwin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lastwin)
{
    ui->setupUi(this);
    setWindowTitle(TITLE);
    setWindowIcon(QIcon(GAMEICON));
}

lastwin::~lastwin()
{
    delete ui;
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
    w->show();
    close();
}
