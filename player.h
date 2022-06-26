#ifndef PLAYER_H
#define PLAYER_H

#include "qpixmap.h"
class player
{
public:
    player();
    int hp;
    int x;
    int y;//位置
    int h;
    int w;//大小
    int v0;//向上的速度
    bool is_jump;//是否跳跃
    int towards;//角色朝向
    QPixmap picture;
    void left();
    void right();
    void jump();
    void fall();

};

#endif // PLAYER_H
