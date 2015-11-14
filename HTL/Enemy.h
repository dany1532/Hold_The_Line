#ifndef ENEMY_H
#define ENEMY_H

#include "EnemyObject.h"

class Enemy : public EnemyObject{

 public:
    Enemy();
    ~Enemy();

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
