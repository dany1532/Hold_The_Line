#include "Enemy.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Enemy::Enemy(){
  xdir = 0;
  ydir = 2;
  destroyed = false;

  image.load("Enemy.png");

  rect = image.rect();
  resetState();
}

Enemy::~Enemy(){
  cout << ("Enemy deleted\n");
}

void Enemy::resetState(){
  int locx, locy;
  
  locx = (rand() % 8) * 50;
  locy = (rand() % 2200) * -1;
  rect.moveTo(locx,locy);
}

void Enemy::move(){
  rect.translate(xdir,ydir);
}

bool Enemy::isDestroyed(){
  return this->destroyed;
}

void Enemy::setDestroyed(bool destroy){
  this->destroyed = destroy;
}

void Enemy::setDir(int x, int y){
  this->xdir = x;
  this->ydir = y;
}

QRect Enemy::getRect(){
  return this-> rect;
}

QPixmap & Enemy::getImage(){
  return this->image;
}
