#ifndef LASTWIN_H
#define LASTWIN_H

#include <QDialog>
#include <QLabel>
#include <QFont>
#include <QString>

namespace Ui {
class lastwin;
}

class lastwin : public QDialog
{
    Q_OBJECT

public:
    explicit lastwin(QWidget *parent = 0);
    ~lastwin();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::lastwin *ui;
};

#endif // LASTWIN_H
