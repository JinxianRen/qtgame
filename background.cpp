#include "background.h"
#include "config.h"
BackGround::BackGround()
{
    map1.load(BACK_GROUND);//设置背景
    map2.load(BACK_GROUND);
    map3.load(BACK_GROUND);
    map1_x=XSIZE;
    map2_x=0;
    map3_x=-XSIZE;
    m_scroll_speed=BG_SPEED;
}
void BackGround::mappositionr(){
    map1_x-=BG_SPEED,map2_x-=BG_SPEED,map3_x-=BG_SPEED;
    if(map1_x<=0)map1_x=XSIZE,map2_x=0,map3_x=-XSIZE;
}
void BackGround::mappositionl(){
    map1_x+=BG_SPEED,map2_x+=BG_SPEED,map3_x+=BG_SPEED;
    if(map2_x>=XSIZE)map1_x=XSIZE,map2_x=0,map3_x=-XSIZE;
}
