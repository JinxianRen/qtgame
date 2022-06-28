#ifndef NONE_H
#define NONE_H

#include <QDialog>

namespace Ui {
class none;
}

class none : public QDialog
{
    Q_OBJECT

public:
    explicit none(QWidget *parent = nullptr);
    ~none();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::none *ui;
};

#endif // NONE_H
