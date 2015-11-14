#include <iostream>
#include <cstdlib>
#include "Enemy3.h"

using namespace std;

Enemy3::Enemy3(){
  this->xdir = 2;
  this->ydir = 0;
  this->destroyed = false;

  this->image.load("enemy3.png");

  this->rect = this->image.rect();
  resetState();
}

Enemy3::~Enemy3(){
  cout << ("Enemy3 deleted\n");
}

void Enemy3::resetState(){
  int locx, locy;
  
  locx = (rand() % 8) * 50;
  locy = (rand() % 200);
  rect.moveTo(locx,locy);
}

void Enemy3::move(){
  rect.translate(this->xdir,this->ydir);

  if(rect.right() > 400)
      xdir = -1;

  if(rect.left() < 0)
      xdir = 1;
}

bool Enemy3::isDestroyed(){
  return this->destroyed;
}

void Enemy3::setDestroyed(bool destroy){
  this->destroyed = destroy;
}

void Enemy3::setDir(int x, int y){
  this->xdir = x;
  this->ydir = y;
}

QRect Enemy3::getRect(){
  return this-> rect;
}

QPixmap & Enemy3::getImage(){
  return this->image;
}
