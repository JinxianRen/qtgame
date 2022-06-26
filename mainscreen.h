#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QWidget>
#include"qtimer.h"
#include "QKeyEvent"

#include "background.h"
#include "player.h"

#include "config.h"

namespace Ui {
class mainscreen;
}

class mainscreen : public QWidget
{
    Q_OBJECT

public:
    explicit mainscreen(QWidget *parent = nullptr);
    ~mainscreen();

private:
    Ui::mainscreen *ui;

public:
    QTimer Timer;
    BackGround background;
    player pl;
    void init();
    void gamestart();
    void updateposition();
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
};

#endif // MAINSCREEN_H
