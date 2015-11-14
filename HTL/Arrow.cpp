#include "Arrow.h"
#include <iostream>

using namespace std;

Arrow::Arrow(){
  xdir = 0;
  ydir = -15;
  destroyed = true;

  image.load("Arrow3.png");

  rect = image.rect();
  resetState(-10,0);
}

Arrow::~Arrow(){
  cout << ("Arrow deleted\n");
}

void Arrow::resetState(int newx, int newy){
  rect.moveTo(newx,newy);
}

void Arrow::move(){
  rect.translate(xdir,ydir);

  if(rect.top() < 0){
   rect.moveTo(rect.left(),0);
   this->destroyed = true;
  }
}

void Arrow::setDir(int x, int y){
  this->xdir = x;
  this->ydir = y;
}

bool Arrow::isDestroyed(){
  return this->destroyed;
}

void Arrow::setDestroyed(bool destroy){
   this->destroyed = destroy;
}

QRect Arrow::getRect(){
  return this-> rect;
}

QImage & Arrow::getImage(){
  return this->image;
}
