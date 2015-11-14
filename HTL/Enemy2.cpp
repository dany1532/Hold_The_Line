#include <iostream>
#include <cstdlib>
#include "Enemy2.h"

using namespace std;

Enemy2::Enemy2(){
  this->xdir = 3;
  this->ydir = 0;
  this->destroyed = false;

  this->image.load("enemy2.png");

  this->rect = this->image.rect();
  resetState();
}

Enemy2::~Enemy2(){
  cout << ("Enemy2 deleted\n");
}

void Enemy2::resetState(){
  int locx, locy;
  
  locx = (rand() % 8) * 50;
  locy = (rand() % 100);
  rect.moveTo(locx,locy);
}

void Enemy2::move(){
  rect.translate(this->xdir,this->ydir);

  if(rect.right() > 400)
      xdir = -1;

  if(rect.left() < 0)
      xdir = 1;
}

bool Enemy2::isDestroyed(){
  return this->destroyed;
}

void Enemy2::setDestroyed(bool destroy){
  this->destroyed = destroy;
}

void Enemy2::setDir(int x, int y){
  this->xdir = x;
  this->ydir = y;
}

QRect Enemy2::getRect(){
  return this-> rect;
}

QPixmap & Enemy2::getImage(){
  return this->image;
}
