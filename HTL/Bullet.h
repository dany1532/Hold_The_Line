#ifndef BULLET_H
#define BULLET_H

#include "EnemyBullet.h"

class Bullet : public EnemyBullet{
 public:
    Bullet();
    ~Bullet();

 public:
    void resetState(int,int);
    void setlastLocation(int,int);
    void determineDirection(int,int);
    void setDir(int,int);
    void move();
    bool isDestroyed();
    void setDestroyed(bool);
    QRect getRect();
    QImage &getImage();
};

#endif
