#include "player.h"
#include"config.h"
player::player()
{
    x=X,y=Y,h=H,w=W;
    hp=INIT_HP;
    is_jump=0;
    v0=0;
    picture.load(PLAYER_PIC);
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
}
