#ifndef MONSTER_H
#define MONSTER_H
#include "player.h"

class monster:public player
{
public:
    monster();
    monster(int n);
    virtual void left();
    virtual void right();
    virtual bool right_touch();
    virtual bool left_touch();
    bool is_alive;
    void move();
};

#endif // MONSTER_H
