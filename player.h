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
    int is_right;//角色朝向
    int goldnum;//金币数量
    int allgoldnum;
    int picnumber;//现在是动画第几帧
    QPixmap picture;
    virtual void left();
    virtual void right();
    void jump();
    void fall();
    virtual bool left_touch();
    virtual bool right_touch();
    bool head_touch();
    bool is_ground();
    bool wincheck();
    bool goldcheck();
};

#endif // PLAYER_H
