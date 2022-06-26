#ifndef MAP_H
#define MAP_H
#include<QPixmap>

class BackGround
{
public:
    BackGround();
    void mapposition();

    QPixmap map1;
    QPixmap map2;
    int map1_x;
    int map2_x;
    int m_scroll_speed;
};

#endif // MAP_H
