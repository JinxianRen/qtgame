#ifndef MAINMAP_H
#define MAINMAP_H

#include <QDialog>

namespace Ui {
class mainmap;
}

class mainmap : public QDialog
{
    Q_OBJECT

public:
    explicit mainmap(QWidget *parent = nullptr);
    ~mainmap();

private:
    Ui::mainmap *ui;
};

#endif // MAINMAP_H
