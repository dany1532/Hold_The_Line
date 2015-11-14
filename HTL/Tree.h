#ifndef TREE_H
#define TREE_H

#include <QPixmap>
#include <QRect>

class Tree{

 private:
    QPixmap image;
    QRect rect;

 public:
    Tree();
    ~Tree();

 public:
    void resetState();
    QRect getRect();
    QPixmap &getImage();
};

#endif // TREE_H
