#ifndef ENEMY2_H
#define ENEMY2_H

#include "EnemyObject.h"

class Enemy2 : public EnemyObject{
 public:
    Enemy2();
    ~Enemy2();

 public:
    void resetState();
    void setDir(int,int);
    void move();
    bool isDestroyed();
    void setDestroyed(bool);
    QRect getRect();
    QPixmap &getImage();
};

#endif
