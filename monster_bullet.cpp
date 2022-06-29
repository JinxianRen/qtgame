#include "monster_bullet.h"
#include "config.h"
extern int map[24][24];

monster_bullet::monster_bullet()
{
    is_right=1;
    picture.load(MONSTER_PIC12);
}
monster_bullet::monster_bullet(int n)
{
    is_right=1;
    if(n==1)
    {
        for(int i=0;i<30;i++)
            biu[i]=bullet(1);
        picture.load(MONSTER_PIC12);
    }
    if(n==2)
    {
        for(int i=0;i<30;i++)
            biu[i]=bullet(2);
        picture.load(MONSTER_PIC22);
    }
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
