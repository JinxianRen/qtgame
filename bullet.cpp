#include "bullet.h"
#include "config.h"
extern int map[24][24];

bullet::bullet(bool direction,int x_,int y_)
{
    picture.load(BULLET_PIC);
    y=y_,is_right=direction;

    if(is_right)
        x=x_+B;
    else
        x=x_-B;
}

void bullet::move()
{
    if(is_right&&!right_touch())
        right();
    else if(is_right&&right_touch())
        is_alive=0;
    else if(!is_right&&!left_touch())
        left();
    else if(!is_right&&left_touch())
        is_alive=0;
}

bool bullet::right_touch()
{
    if(map[x/B+1][y/B]!=1&&x + BULLET_MOVE_SPEED < XSIZE - w)
        return 0;
    return 1;
}
bool bullet::left_touch()
{
    if(map[(x-5)/B][y/B]!=1&&x - BULLET_MOVE_SPEED > 0)
        return 0;
    return 1;
}
void bullet::right()
{
    if(!right_touch())
        x = (x + BULLET_MOVE_SPEED < XSIZE - w) ? x + BULLET_MOVE_SPEED : XSIZE - w;
}
void bullet::left()
{
    if(!left_touch())
        x = (x - BULLET_MOVE_SPEED > 0) ? x - BULLET_MOVE_SPEED : 0;
}
