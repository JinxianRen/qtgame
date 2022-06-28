#ifndef CONFIG_H
#define CONFIG_H

#endif // CONFIG_H


#define TITLE "游戏名称"

#define BACK_GROUND ":/res/background.png"
#define PLAYER_PIC ":/res/grass.png"
#define MONSTER_PIC ":/res/monster.png"
#define MONSTER_BULLET_PIC ":/res/monster.png"
#define BULLET_PIC ":/res/monster.png"
#define GAMEICON ":/res/stone.png"
#define BLOCK1 ":/res/stone.png"
#define BLOCK2 ":/res/star.png"
#define BLOCK3 ":/res/gold.png"
#define BLOCK4 ":/res/player.png"

#define BG_SPEED 1                 //背景移动速度
#define GAME_TICK 20               //游戏多少毫秒刷新一次

#define G 9.8                      //重力加速度
#define XSIZE 768                 //屏幕大小
#define YSIZE 768
#define X 400                       //主角起始位置
#define Y 640
#define W 32                       //主角的宽和高
#define H 32
#define B 32                       //方块边长
#define MSTRNUM 2                 //怪物最大数量
#define MSTRNUM_BULLET 1
#define INIT_HP 100               //初始血量
#define HIT_TIME 20               //受伤无敌帧数
#define MOVE_SPEED 8               //主角走一步相距的像素个数
#define MONSTER_MOVE_SPEED 2               //怪物走一步相距的像素个数
#define BULLET_MOVE_SPEED 8
#define HIGHT (2*W+1)          //主角跳跃的最大高度
#define BULLET_TIME 50         //刷新x次，发射一个子弹
