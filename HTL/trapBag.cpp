#include "trapBag.h"
#include <iostream>

using namespace std;

TrapBag::TrapBag(){

  this->image.load("trapBag.png");

  this->rect = this->image.rect();
  resetState();
}

TrapBag::~TrapBag(){
  cout << ("TrapBag deleted\n");
}

void TrapBag::resetState(){
  this->rect.moveTo(368,660);
}

QRect TrapBag::getRect(){
  return this-> rect;
}

QPixmap &TrapBag::getImage(){
  return this->image;
}
