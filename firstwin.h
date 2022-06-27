#ifndef FIRSTWIN_H
#define FIRSTWIN_H
#include <QDialog>
#include <QLabel>
#include <QFont>

namespace Ui {
class firstwin;
}

class firstwin : public QDialog
{
    Q_OBJECT

public:
    explicit firstwin(int allgoldnum_,QWidget *parent = 0);
    ~firstwin();
    int allgoldnum;
    void drawgold();
    QFont font;
    QLabel *label1,*label2;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::firstwin *ui;
};

#endif // FIRSTWIN_H
