#ifndef MONSTER_BULLET_H
#define MONSTER_BULLET_H
#include "player.h"
#include "monster.h"
#include "bullet.h"
#include <QList>

class monster_bullet:public monster
{
public:
    monster_bullet();
    monster_bullet(int n);
    //QList<bullet> biu;
    bullet biu[30];
    void newbullet();
    void bulletmove();
};

#endif // MONSTER_BULLET_H
