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

private:
    Ui::none *ui;
};

#endif // NONE_H
