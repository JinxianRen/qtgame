#ifndef FIRSTWIN_H
#define FIRSTWIN_H
#include <QDialog>

namespace Ui {
class firstwin;
}

class firstwin : public QDialog
{
    Q_OBJECT

public:
    explicit firstwin(QWidget *parent = 0);
    ~firstwin();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::firstwin *ui;
};

#endif // FIRSTWIN_H
