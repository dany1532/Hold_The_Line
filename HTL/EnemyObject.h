#ifndef ENEMYOBJECT_H
#define ENEMYOBJECT_H

#include <QPixmap>
#include <QRect>

class EnemyObject{

 protected:
    int xdir,ydir;
    bool destroyed;
    QPixmap image;
    QRect rect;

 public:
   virtual ~EnemyObject(){};

 public:
    virtual void resetState() = 0;
    virtual void setDir(int,int) = 0;
    virtual void move() = 0;
    virtual bool isDestroyed() = 0;
    virtual void setDestroyed(bool) = 0;
    virtual QRect getRect() = 0;
    virtual QPixmap &getImage() = 0;
};

#endif
