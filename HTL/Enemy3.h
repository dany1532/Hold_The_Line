#ifndef ENEMY3_H
#define ENEMY3_H

#include "EnemyObject.h"

class Enemy3 : public EnemyObject{

 public:
    Enemy3();
    ~Enemy3();

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
