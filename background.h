#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <QPixmap>

class BackGround
{
public:
  BackGround();
  void mappositionr();
  void mappositionl();

  QPixmap map1;
  QPixmap map2;
  QPixmap map3;
  int map1_x;
  int map2_x;
  int map3_x;
  int m_scroll_speed;
};

#endif // MAP_H
