#ifndef PROTAGONIST_H
#define PROTAGONIST_H

#include <QImage>
#include <QRect>

class Protagonist{

 private:
    int xdir,ydir;
    int lives;
    QImage image;
    QRect rect;

 public:
    Protagonist();
    ~Protagonist();

 public:
    void resetState();
    void setDir(int,int);
    int getLives();
    void damage();
    void setHealth();
    void move();
    QRect getRect();
    QImage &getImage();
};

#endif
