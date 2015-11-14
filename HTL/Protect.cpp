#include <iostream>
#include <math.h>
#include "Protect.h"

using namespace std;

Protect::Protect(){
  xdir = 0;
  ydir = 0;
  posX = 0;
  posY = 0;
  destroyed = true;
  positive = true;

  image.load("protect.png");

  rect = image.rect();
  resetState(-100,50);
}

Protect::~Protect(){
  cout << ("protect deleted\n");
}

void Protect::resetState(int newx, int newy){
  rect.moveTo(newx+36,newy);
}

void Protect::move(){
  rect.moveTo(posX,posY);

}

void Protect:: setPositive(bool a){
   this->positive = a;
}

bool Protect::getPositive(){
   return this->positive;
}

void Protect::calculatePosition(int protX, int protY, int locX){

     int result = (36 * 36) - (locX * locX);
    
     if(positive)
       result = (int) sqrt((double) result);
     else
       result = ((int) sqrt((double) result)) * -1;


     this->posX = protX + locX;
     this->posY = protY + result;

}



void Protect::setDir(int x, int y){
  this->xdir = x;
  this->ydir = y;
}

bool Protect::isDestroyed(){
  return this->destroyed;
}

void Protect::setDestroyed(bool destroy){
   this->destroyed = destroy;
}

QRect Protect::getRect(){
  return this-> rect;
}

QImage & Protect::getImage(){
  return this->image;
}
