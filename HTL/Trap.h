#ifndef TRAP_H
#define TRAP_H

#include <QPixmap>
#include <QRect>

class Trap{

 private:
    QPixmap image;
    QRect rect;
    bool destroyed;

 public:
    Trap();
    ~Trap();

 public:
    void resetState(int, int);
    bool isDestroyed();
    void setDestroyed(bool);
    QRect getRect();
    QPixmap &getImage();
};

#endif
