#include "dialog.h"
#include "ui_dialog.h"
#include "widget.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowTitle(TITLE);
    setWindowIcon(QIcon(GAMEICON));
    int width = 768;
    int height = 768;
    this->setFixedSize(width,height); //设置窗体固定大小
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
        close();
       Widget *w = new Widget;
        w->music->stop();
        w->show();
}

void Dialog::on_pushButton_2_clicked()
{
    close();
   Widget *w = new Widget;
    w->music->stop();
    w->show();
}
