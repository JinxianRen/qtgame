#ifndef GOLDBUY_H
#define GOLDBUY_H

#include <QDialog>
#include "player.h"
#include <QLabel>
#include <QFont>
#include "audiothread.h"

namespace Ui {
class goldbuy;
}

class goldbuy : public QDialog
{
    Q_OBJECT

public:
    explicit goldbuy(player& play,QWidget *parent = 0);
    ~goldbuy();
    player &pl;
    int nowgold();
    void drawgold();
    QFont font;
    QLabel *label1,*label2;
    AudioThread audio;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();
private:
    Ui::goldbuy *ui;
};

#endif // GOLDBUY_H
