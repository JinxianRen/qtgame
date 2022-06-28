#include "widget.h"
#include "ui_widget.h"
#include "config.h"
#include "dialog.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget)
{
  ui->setupUi(this);
  setFixedSize(XSIZE, YSIZE);
  setWindowTitle(TITLE);
  setWindowIcon(QIcon(GAMEICON));
  int width = 1032;
  int height = 736;
  this->setFixedSize(width,height);//设置窗体固定大小
}

Widget::~Widget()
{
  delete ui;
}

void Widget::on_pushButton_clicked()
{
  mainscreen *d = new mainscreen;
  d->setAttribute(Qt::WA_DeleteOnClose, true);
  d->show();
  close();
}

void Widget::on_pushButton_3_clicked()
{
  close();
  delete ui;
}

void Widget::on_pushButton_2_clicked()
{
  none *d= new none;
  d->setAttribute(Qt::WA_DeleteOnClose, true);
  d->show();
  close();
}

void Widget::on_pushButton_4_clicked()
{
    Dialog *dlg= new Dialog;
    dlg->setAttribute(Qt::WA_DeleteOnClose, true);
    dlg->show();
    close();
}
