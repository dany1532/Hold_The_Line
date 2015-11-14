#include "Protagonist.h"
#include <iostream>

using namespace std;

Protagonist::Protagonist(){
  xdir = 0;
  ydir = 0;
  lives = 5;
  image.load("ProtFront.png");

  rect = image.rect(); 
  resetState();
}

Protagonist::~Protagonist(){
  cout << ("Protagonist deleted\n");
}

void Protagonist::resetState(){
  rect.moveTo(230,650);
}

void Protagonist::move(){
  rect.translate(xdir,ydir);
  
  if(rect.left() < 0)
   rect.moveTo(0,rect.top());

  if(rect.right() > 400)
   rect.moveTo(377,rect.top());

  if(rect.top() < 0)
   rect.moveTo(rect.left(),0);

  if(rect.bottom() > 700)
   rect.moveTo(rect.left(),655);
}

void Protagonist::setHealth(){
  this->lives = 5;
}

int Protagonist::getLives(){
  return this->lives;
}

void Protagonist::damage(){
   this->lives -= 1;
}

void Protagonist::setDir(int x, int y){
  this->xdir = x;
  this->ydir = y;
}

QRect Protagonist::getRect(){
  return this-> rect;
}

QImage &Protagonist::getImage(){
  return this->image;
}
