#include "widget.h"
#include "ui_widget.h"
#include "config.h"
#include "dialog.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget)
{
  ui->setupUi(this);
  setWindowTitle(TITLE);
  setWindowIcon(QIcon(GAMEICON));
  int width = 864;
  int height = 576;
  this->setFixedSize(width,height);//设置窗体固定大小
  music= new QSoundEffect;
  music->setSource(QUrl(BEGIN_BGM));
  music->setLoopCount(10);
  music->setVolume(0.05f);
  music->play();
}

Widget::~Widget()
{
  delete ui;

}

void Widget::on_pushButton_clicked()
{
  mainscreen *d = new mainscreen;
  d->setAttribute(Qt::WA_DeleteOnClose, true);
  d->show();
  close();
}

void Widget::on_pushButton_3_clicked()
{
  music->stop();
  close();
  delete ui;
}

void Widget::on_pushButton_2_clicked()
{
  none *d= new none;
  d->setAttribute(Qt::WA_DeleteOnClose, true);
  d->show();
  close();
}

void Widget::on_pushButton_4_clicked()
{
    Dialog *dlg= new Dialog;
    dlg->setAttribute(Qt::WA_DeleteOnClose, true);
    dlg->show();
    close();
}
