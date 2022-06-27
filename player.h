#ifndef PLAYER_H
#define PLAYER_H

#include "qpixmap.h"
#include "qtimer.h"
class player
{
public:
    player();
    int hp;
    int x;
    int y;//界面位置
    int xr;//实际位置
    int h;
    int w;//大小
    double t;//离地时间
    double v0;//向下的速度
    bool is_jump;//是否跳跃
    int towards;//角色朝向
    QPixmap picture;
    void left();
    void right();
    void jump();
    void fall();
    bool is_ground();

};

#endif // PLAYER_H
