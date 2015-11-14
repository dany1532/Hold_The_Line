#ifndef TRAPBAG_H
#define TRAPBAG_H

#include <QPixmap>
#include <QRect>
#include "Ammunition.h"

class TrapBag : public Ammunition{

 private:
    //QPixmap image;
    //QRect rect;

 public:
    TrapBag();
    ~TrapBag();

 public:
    void resetState();
    void resetState(int, int){};
    QRect getRect();
    QPixmap &getImage();
};

#endif
