#ifndef YOULOSE_H
#define YOULOSE_H

#include <QDialog>
#include <QLabel>
#include <QFont>
#include <QString>

namespace Ui {
class youlose;
}

class youlose : public QDialog
{
    Q_OBJECT

public:
    explicit youlose(int allgoldnum_,double time_,QWidget *parent = 0);
    ~youlose();
    QFont font;
    QLabel *label1,*label2;
    QString print;
    int allgoldnum;
    double time;
    void drawgold();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::youlose *ui;
};

#endif // YOULOSE_H
