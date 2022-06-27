#include "player.h"
#include "mainscreen.h"
#include "config.h"
#include "stdio.h"

extern  Map map[24][24];
#include "qtimer.h"
player::player()
{
  x = X, y = Y, h = H, w = W;
  hp = INIT_HP;
  is_jump = 0;
  v0 = 0, t = 0;
  picture.load(PLAYER_PIC);
}
bool player::is_ground()
{
          if(map[(x+w/2)/B][(y+h)/B].id!=0)
          {
           return 1;
          }
      return 0;

}
void player::right()
{
  x = (x + MOVE_SPEED < XSIZE - w) ? x + MOVE_SPEED : XSIZE - w;
}
void player::left()
{
  x = (x - MOVE_SPEED > 0) ? x - MOVE_SPEED : 0;
}
void player::jump()
{
  v0 = -sqrt(2 * G * HIGHT);
  is_jump = 1;
  fall();
}
void player::fall()
{
  t = sqrt(2 * HIGHT / G) / 14;
  h=(v0*t+G*pow(t,2)/2>10)?10:v0*t+G*pow(t,2)/2;
  y+=(int)(h+0.5);
  if(v0>0){
  if(is_ground()){
       y=y/B*B;
       v0=0;
       is_jump=0;
  }
  }
  else {
    y += (int)(h + 0.5);
  }
      v0=v0+G*t;
}
