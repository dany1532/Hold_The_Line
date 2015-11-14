#include "Quiver.h"
#include <iostream>

using namespace std;

Quiver::Quiver(){

  this->image.load("Quiver.png");

  this->rect = this->image.rect();
  resetState();
}

Quiver::~Quiver(){
  cout << ("Quiver deleted\n");
}

void Quiver::resetState(){
  this->rect.moveTo(12,650);
}

QRect Quiver::getRect(){
  return this-> rect;
}

QPixmap &Quiver::getImage(){
  return this->image;
}
