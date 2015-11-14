#include "Bullet.h"
#include <iostream>

using namespace std;

Bullet::Bullet(){
  xdir = 0;
  ydir = 0;
  lastX = 0;
  lastY = 0;
  destroyed = true;

  image.load("ball.png");

  rect = image.rect();
  resetState(100,50);
}

Bullet::~Bullet(){
  cout << ("ball deleted\n");
}

void Bullet::resetState(int newx, int newy){
  rect.moveTo(newx,newy);
}

void Bullet::move(){
  rect.translate(xdir,ydir);

  if(rect.top() > 700){
   this->destroyed = true;
   resetState(100,50);
  }
}

void Bullet::setlastLocation(int newX ,int newY){
   this->lastX = newX;
   this->lastY = newY;
}

void Bullet::determineDirection(int protX, int protY){
   this->xdir = (protX - lastX) / 30;
   this->ydir = (protY - lastY) / 30;
}

void Bullet::setDir(int x, int y){
  this->xdir = x;
  this->ydir = y;
}

bool Bullet::isDestroyed(){
  return this->destroyed;
}

void Bullet::setDestroyed(bool destroy){
   this->destroyed = destroy;
}

QRect Bullet::getRect(){
  return this-> rect;
}

QImage & Bullet::getImage(){
  return this->image;
}
