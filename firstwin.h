#ifndef FIRSTWIN_H
#define FIRSTWIN_H
#include <QDialog>
#include <QLabel>
#include <QFont>
#include <QString>

namespace Ui {
class firstwin;
}

class firstwin : public QDialog
{
    Q_OBJECT

public:
    explicit firstwin(int nowgoldnum_,int allgoldnum_,double time_,QWidget *parent = 0);
    ~firstwin();
    int nowgoldnum;
    int allgoldnum;
    double time;
    QString print;
    void drawgold();
    QFont font;
    QLabel *label1,*label2;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::firstwin *ui;
};

#endif // FIRSTWIN_H
