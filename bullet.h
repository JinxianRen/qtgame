#ifndef BULLET_H
#define BULLET_H

#include "player.h"

class bullet:public player
{
public:
    bullet(bool dir_right=1,int x_=0,int y_=0);
    bullet(const bullet& a);
    bullet(int n);
    bool is_alive = 0;
    void move();
    virtual void left();
    virtual void right();
    virtual bool right_touch();
    virtual bool left_touch();
};


#endif // BULLET_H
