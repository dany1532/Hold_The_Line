#include "SeekerBullet.h"
#include <iostream>

using namespace std;

SeekerBullet::SeekerBullet(){
  xdir = 0;
  ydir = 0;
  lastX = 0;
  lastY = 0;
  destroyed = true;

  image.load("ball2.png");

  rect = image.rect();
  resetState(-100,50);
}

SeekerBullet::~SeekerBullet(){
  cout << ("ball2 deleted\n");
}

void SeekerBullet::resetState(int newx, int newy){
  rect.moveTo(newx,newy);
}

void SeekerBullet::move(){
  rect.translate(xdir,ydir);

  if(rect.top() < 0){
   rect.moveTo(rect.left(),0);
   this->destroyed = true;
  }
}


void SeekerBullet::determineDirection(int protX, int protY){
   this->xdir = (protX - lastX) / 20;
   this->ydir = (protY - lastY) / 20;
}

void SeekerBullet::setlastLocation(int newX ,int newY){
   this->lastX = newX;
   this->lastY = newY;
}

void SeekerBullet::setDir(int x, int y){
  this->xdir = x;
  this->ydir = y;
}

bool SeekerBullet::isDestroyed(){
  return this->destroyed;
}

void SeekerBullet::setDestroyed(bool destroy){
   this->destroyed = destroy;
}

QRect SeekerBullet::getRect(){
  return this-> rect;
}

QImage & SeekerBullet::getImage(){
  return this->image;
}
