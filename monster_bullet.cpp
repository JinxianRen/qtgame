#include "monster_bullet.h"
#include "config.h"
extern int map[24][24];

monster_bullet::monster_bullet()
{
    is_right=1;
    picture.load(MONSTER_BULLET_PIC);
}


void monster_bullet::newbullet()
{
    for(int i=0;i<30;i++)
    {
        if(biu[i].y==0)
        {
            biu[i].y=y,biu[i].is_right=is_right;
            if(is_right)
                biu[i].x=x+B0;
            else
                biu[i].x=x-B0;
            biu[i].is_alive=1;
            break;
        }
    }
}

void monster_bullet::bulletmove()
{
    for(int i=0;i<30;i++)
    {
        if(biu[i].is_alive==1)
        {
            biu[i].move();
        }
    }
}
