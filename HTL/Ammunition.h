#ifndef AMMUNITION_H
#define AMMUNITION_H

#include <QPixmap>
#include <QRect>

class Ammunition{
 protected:
    QPixmap image;
    QRect rect;

 public:
    virtual ~Ammunition(){};

 public:
    virtual void resetState() = 0;
    virtual void resetState(int,int) = 0;
    virtual QRect getRect() = 0;
    virtual QPixmap &getImage() = 0;
};

#endif
