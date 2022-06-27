#include "goldbuy.h"
#include "ui_goldbuy.h"
#include "mainscreen.h"

goldbuy::goldbuy(player& play,QWidget *parent) :
    QDialog(parent),pl(play),
    ui(new Ui::goldbuy)
{
    ui->setupUi(this);
}

goldbuy::~goldbuy()
{
    delete ui;
}

void goldbuy::on_pushButton_clicked()
{
    close();
}

void goldbuy::on_pushButton_2_clicked()
{
    //假设它是1个金币
    if(pl.goldnum>=1)
    {
        pl.goldnum-=1;
        //获得什么待补充

    }
}
