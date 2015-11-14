#ifndef QUIVER_H
#define QUIVER_H

#include <QPixmap>
#include <QRect>
#include "Ammunition.h"

class Quiver : public Ammunition{

 public:
    Quiver();
    ~Quiver();

 public:
    void resetState();
    void resetState(int,int){};
    QRect getRect();
    QPixmap &getImage();
};

#endif
