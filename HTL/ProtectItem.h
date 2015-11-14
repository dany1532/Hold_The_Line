#ifndef PROTECTITEM_H
#define PROTECTITEM_H

#include <QPixmap>
#include <QRect>
#include "Ammunition.h"

class ProtectItem {
 private:
    bool destroyed;
    QRect rect;
    QPixmap image;
 public:
    ProtectItem();
    ~ProtectItem();

 public:
    void resetState(){};
    void resetState(int, int);
    bool isDestroyed();
    void setDestroyed(bool);
    QRect getRect();
    QPixmap &getImage();
};

#endif
