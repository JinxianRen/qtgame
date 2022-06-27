#ifndef YOULOSE_H
#define YOULOSE_H

#include <QDialog>
#include <QLabel>
#include <QFont>

namespace Ui {
class youlose;
}

class youlose : public QDialog
{
    Q_OBJECT

public:
    explicit youlose(int allgoldnum_,QWidget *parent = 0);
    ~youlose();
    QFont font;
    QLabel *label1,*label2;
    int allgoldnum;
    void drawgold();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::youlose *ui;
};

#endif // YOULOSE_H
