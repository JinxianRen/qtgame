#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setFixedSize(768,512);
    setWindowTitle("游戏");
    setWindowIcon(QIcon(":/res/stone.png"));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    mainmap d;
    d.exec();
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
