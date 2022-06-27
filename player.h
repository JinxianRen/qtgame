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
    int y;//位置
    int h;
    int w;//大小
    int h1;//距离
    double t;//离地时间
    double v0;//向下的速度
    bool is_jump;//是否跳跃
    int towards;//角色朝向
    int goldnum;
    QPixmap picture;
    void left();
    void right();
    void jump();
    void fall();
    bool left_touch();
    bool right_touch();
    bool head_touch();
    bool is_ground();
    bool wincheck();
    bool goldcheck();
};

#endif // PLAYER_H
