#include "mainmap.h"
#include "ui_mainmap.h"

mainmap::mainmap(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainmap)
{
    ui->setupUi(this);
}

mainmap::~mainmap()
{
    delete ui;
}
