#ifndef ARROW_H
#define ARROW_H

#include <QImage>
#include <QRect>

class Arrow{

 private:
    int xdir,ydir;
    bool destroyed;
    QImage image;
    QRect rect;

 public:
    Arrow();
    ~Arrow();

 public:
    void resetState(int,int);
    void setDir(int,int);
    void move();
    bool isDestroyed();
    void setDestroyed(bool);
    QRect getRect();
    QImage &getImage();
};

#endif
