#include "Trap.h"
#include <iostream>

using namespace std;

Trap::Trap(){

  destroyed = true;
  image.load("trap.png");

  rect = image.rect();
  resetState(-10,0);
}

Trap::~Trap(){
  cout << ("Trap deleted\n");
}

void Trap::resetState(int newx, int newy){
  rect.moveTo(newx,newy);
}

bool Trap::isDestroyed(){
  return this->destroyed;
}

void Trap::setDestroyed(bool destroy){
   this->destroyed = destroy;
}

QRect Trap::getRect(){
  return this-> rect;
}

QPixmap & Trap::getImage(){
  return this->image;
}
