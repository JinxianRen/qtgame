#include "mainscreen_second.h"
#include "ui_mainscreen_second.h"
#include "config.h"
#include "qpainter.h"
#include "QKeyEvent"
#include "lastwin.h"
#include "goldbuy.h"
#include "youlose.h"

//int map[24][24];

mainscreen_second::mainscreen_second(int nowgold1_,int allgold1_,double time1_,QWidget *parent) :
    QDialog(parent),nowgold(nowgold1_),gold1(allgold1_),time1(time1_),
    ui(new Ui::mainscreen_second)
{
    ui->setupUi(this);
    setWindowTitle(TITLE);
    setWindowIcon(QIcon(GAMEICON));
   // init();
   // gamestart();
   // updatenum=0;
}

mainscreen_second::~mainscreen_second()
{
    delete ui;
}
