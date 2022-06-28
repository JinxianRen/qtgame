#ifndef MAINSCREEN_SECOND_H
#define MAINSCREEN_SECOND_H

#include <QDialog>

namespace Ui {
class mainscreen_second;
}

class mainscreen_second : public QDialog
{
    Q_OBJECT

public:
    explicit mainscreen_second(int nowgold1_=0,int allgold1_=0,double time1_=0.00,QWidget *parent = 0);
    int nowgold,gold1,allgold;
    double nowtime,time1,alltime;
    ~mainscreen_second();

private:
    Ui::mainscreen_second *ui;
};

#endif // MAINSCREEN_SECOND_H
