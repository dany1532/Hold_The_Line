#ifndef SEEKERBULLET_H
#define SEEKERBULLET_H

#include "EnemyBullet.h"

class SeekerBullet : public EnemyBullet{
 public:
    SeekerBullet();
    ~SeekerBullet();

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
