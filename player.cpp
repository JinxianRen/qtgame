#include "player.h"

#include "config.h"

#include "qtimer.h"
#include "qdatetime.h"
player::player()
{
    x=X,y=Y,h=H,w=W;
    hp=INIT_HP;
    is_jump=0;
    v0=0,t=0;
    picture.load(PLAYER_PIC);
}
void sleep(int msec)//自定义Qt延时函数,单位毫秒
    {
        QDateTime last = QDateTime::currentDateTime();
        QDateTime now;
        while (1)
        {
            now = QDateTime::currentDateTime();
            if (last.msecsTo(now) >= msec)
            {
                break;
            }
        }
    }
bool player::is_ground(){
    if(y<300){
        return 0;
    }
    else {
        y=300;
        t=0;
        is_jump=0;
        return 1;
    }
}
void player::right(){
    x=(x+MOVE_SPEED<XSIZE-w)?x+MOVE_SPEED:XSIZE-w;
}
void player::left(){
    x=(x-MOVE_SPEED>0)?x-MOVE_SPEED:0;
}
void player::jump(){
        v0=-sqrt(2*G*HIGHT);
        is_jump=1;
        fall();
}
void player::fall()
{
    t+=0.02;
    h=v0*t+G*pow(t,2)/2;
        y+=h;
        v0=v0+G*t;
}
