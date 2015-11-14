#include "ProtectItem.h"
#include <iostream>

using namespace std;

ProtectItem::ProtectItem(){
  destroyed = true;

  this->image.load("ChainBall.png");

  this->rect = this->image.rect();
  resetState(-100,40);
}

ProtectItem::~ProtectItem(){
  cout << ("ProtectItem deleted\n");
}

void ProtectItem::resetState(int newX, int newY){
  this->rect.moveTo(newX,newY);
}

bool ProtectItem::isDestroyed(){
  return this->destroyed;
}

void ProtectItem::setDestroyed(bool destroy){
   this->destroyed = destroy;
}


QRect ProtectItem::getRect(){
  return this-> rect;
}

QPixmap &ProtectItem::getImage(){
  return this->image;
}
