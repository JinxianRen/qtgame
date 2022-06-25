#include "none.h"
#include "ui_none.h"

none::none(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::none)
{
    ui->setupUi(this);
}

none::~none()
{
    delete ui;
}
