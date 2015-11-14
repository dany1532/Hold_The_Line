#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include <QImage>
#include <QRect>

class EnemyBullet{

 protected:
    int xdir,ydir;
    int lastX, lastY;
    bool destroyed;
    QImage image;
    QRect rect;

 public:
    virtual ~EnemyBullet(){};

 public:
    virtual void resetState(int,int)=0;
    virtual void setlastLocation(int,int)=0;
    virtual void determineDirection(int,int)=0;
    virtual void setDir(int,int)=0;
    virtual void move()=0;
    virtual bool isDestroyed()=0;
    virtual void setDestroyed(bool)=0;
    virtual QRect getRect()=0;
    virtual QImage &getImage()=0;
};

#endif
