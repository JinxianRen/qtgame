#ifndef GOLDBUY_H
#define GOLDBUY_H

#include <QDialog>
#include "player.h"

namespace Ui {
class goldbuy;
}

class goldbuy : public QDialog
{
    Q_OBJECT

public:
    explicit goldbuy(player& play,QWidget *parent = 0);
    ~goldbuy();
    player pl;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::goldbuy *ui;
};

#endif // GOLDBUY_H
