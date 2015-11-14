#include "Tree.h"
#include <iostream>

using namespace std;

Tree::Tree(){

  image.load("Tree1.png");

  rect = image.rect();
  resetState();
}

Tree::~Tree(){
  cout << ("Tree deleted\n");
}

void Tree::resetState(){
    int locx, locy;

    locx = (rand() % 8) * 50;
    locy = (rand() % 300);
    rect.moveTo(locx,locy);
}

QRect Tree::getRect(){
  return this-> rect;
}

QPixmap & Tree::getImage(){
  return this->image;
}

