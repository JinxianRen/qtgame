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
  d->show();
}

void Widget::on_pushButton_3_clicked()
{
  close();
}

void Widget::on_pushButton_2_clicked()
{
  none d;
  d.exec();
}

void Widget::on_pushButton_4_clicked()
{
    close();
    Dialog *dlg= new Dialog;
    dlg->show();
}
