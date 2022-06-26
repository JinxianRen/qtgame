#include "widget.h"
#include "ui_widget.h"
#include "config.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget)
{
  ui->setupUi(this);
  setFixedSize(XSIZE, YSIZE);
  setWindowTitle("游戏");
  setWindowIcon(QIcon(":/res/stone.png"));
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
