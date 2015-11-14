#include "HoldtheLine.h"
#include <QDesktopWidget>
#include <QApplication>

void center(QWidget &widget){
  int x,y;
  int screenWidth;
  int screenHeight;

  int WIDTH = 400;
  int HEIGHT = 700;


  QDesktopWidget *desktop = QApplication::desktop();
 
  screenWidth  = desktop->width();
  screenHeight = desktop->height();

  x = (screenWidth  - WIDTH) /2;
  y = (screenHeight - HEIGHT) /2;


  widget.setGeometry(x,0,WIDTH,HEIGHT);
  widget.setFixedSize(WIDTH,HEIGHT);


}


int main(int argc, char *argv[]){
  QApplication app(argc, argv);

  HoldLine window;

  window.setWindowTitle("Hold The Line");
  window.show();
  center(window);

  return app.exec();
}
