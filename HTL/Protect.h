#ifndef PROTECT_H
#define PROTECT_H

#include <QImage>
#include <QRect>

class Protect{

 private:
    int xdir,ydir;
    int posX, posY;
    bool destroyed;
    bool positive;
    QImage image;
    QRect rect;

 public:
    Protect();
    ~Protect();

 public:
    void resetState(int,int);
    void calculatePosition(int,int,int);
    void setDir(int,int);
    void setPositive(bool);
    bool getPositive();
    void move();
    bool isDestroyed();
    void setDestroyed(bool);
    QRect getRect();
    QImage &getImage();
};

#endif
