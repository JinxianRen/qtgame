#ifndef CONFIG_H
#define CONFIG_H

#endif // CONFIG_H

#include<math.h>
#define BACK_GROUND ":/res/背景.png"
#define BG_SPEED 2//背景移动速度
#define GAME_TICK 20//游戏多少毫秒刷新一次

#define G 9.8                      //重力加速度
#define XSIZE 1024                  //屏幕大小
#define YSIZE 576
#define X 64                       //主角起始位置
#define Y 192
#define W 32                       //主角的宽和高
#define H 32
#define STEP 4                     //主角走一步相距的像素个数
#define HIGH (2*role.w+1)          //主角跳跃的最大高度

#define	CMD_LEFT 1                 //方向键的宏定义
#define	CMD_RIGHT 2
#define	CMD_UP 4
#define CMD_DOWN 8
#define CMD_SHOOT 16
#define CMD_ESC 32
