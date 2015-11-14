#include "HoldtheLine.h"
#include <stdlib.h>
#include <QPainter>
#include <QApplication>

HoldLine::HoldLine(QWidget *parent) : QWidget(parent){
  XLOC = 36;
  level = 0;
  points = 0;
  gameOver = false;
  gameWon = false;
  paused = false;
  gameStarted = false;
  moving = false;
  prot = new Protagonist();
  quiver = new Quiver();
  trapBag = new TrapBag();
  protect = new Protect();
  protectItem = new ProtectItem();

  ammoList.push_back(quiver);
  ammoList.push_back(trapBag);

  
  MAXENEMIES = 10;
  createBullets(3);
  createArrows(8);
  createTraps(5);
  createTrees(4);

}

HoldLine::~HoldLine(){
  delete prot;
  delete quiver;
  delete trapBag;
  delete protect;
  delete protectItem;
  deleteTraps();
  deleteTrees();
  deleteBullets();
  deleteEnemies();
  deleteArrows();

}

void HoldLine::deleteAmmo(){
  for(int i = 0; i < ammoList.size(); i++){
      delete ammoList[i];
  }
}

void HoldLine::deleteBullets(){
  for(int i = 0; i < bulletList.size(); i++){
      delete bulletList[i];
  }
}

void HoldLine::deleteArrows(){
  for(int i = 0; i < arrowList.size(); i++){
      delete arrowList[i];
  }
}

void HoldLine::deleteTraps(){
  for(int i = 0; i < trapList.size(); i++){
      delete trapList[i];
  }
}

void HoldLine::deleteEnemies(){
  for(int i = 0; i < enemyList.size(); i++){
      delete enemyList[i];
  }
}

void HoldLine::deleteTrees(){
  for(int i = 0; i < treeList.size(); i++){
      delete treeList[i];
  }
}

void HoldLine::createArrows(int numArrows){
   for(int i = 0; i < numArrows; i++){
      arrow = new Arrow();
      arrowList.push_back(arrow);
   }
}

void HoldLine::createBullets(int numBullets){
   for(int i = 0; i < numBullets; i++){
      bullet = new Bullet();
      bulletList.push_back(bullet);
   }

   for(int i = 0; i < 2; i++){
      skBullet = new SeekerBullet();
      bulletList.push_back(skBullet);
   }
}

void HoldLine::createTraps(int numTraps){
   for(int i = 0; i < numTraps; i++){
      trap = new Trap();
      trapList.push_back(trap);
   }
}

void HoldLine::createEnemies(int numEnemies){
   if(level == 1){
      for(int i = 0; i < numEnemies; i++){
         enemy = new Enemy();
         enemyList.push_back(enemy);
      }
   }

   if(level == 2){
      for(int i = 0; i < numEnemies; i++){
          if(i < 3){
            enemy2 = new Enemy2();
            enemyList.push_back(enemy2);
          }
          
          else{
             enemy = new Enemy();
             enemyList.push_back(enemy);
          }
      }// end for
   }//end level2

      if(level == 3){
      for(int i = 0; i < numEnemies; i++){
          if(i < 2){
            enemy3 = new Enemy3();
            enemyList.push_back(enemy3);
          }
          
          else{
             enemy = new Enemy();
             enemyList.push_back(enemy);
          }
      }// end for
   }//end level3
}

void HoldLine::createTrees(int numTrees){
   for(int i = 0; i < numTrees; i++){
      tree = new Tree();
      treeList.push_back(tree);
   }
}


void HoldLine::paintEvent(QPaintEvent *event){
  QPainter painter(this);

  painter.setBackgroundMode (Qt::TransparentMode);
  painter.drawPixmap(QPointF(0,0),QPixmap("grass.png"));

  painter.drawLine(QPoint(0,600),QPoint(400,600));

  if(gameOver && enemyCount < MAXENEMIES){
    QFont font("Courier",15,QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.width("Game Over");

    painter.setFont(font);
    int h = height();
    int w = width();

    painter.translate(QPoint(w/2,h/2));
    painter.drawText(-textWidth/2,0,"GameOver");
    painter.drawText(-textWidth/2-50,30,"Press S to Restart");
    deleteEnemies();
    enemyList.resize(0);
    MAXENEMIES = 10;
    points = 0;
    level = 0;
  }
  else if(gameOver && enemyCount == MAXENEMIES && level < 3){
      QFont font("Courier",15,QFont::DemiBold);
      QFontMetrics fm(font);
      int textWidth = fm.width("Level Complete");

      painter.setFont(font);
      int h = height();
      int w = width();

      painter.translate(QPoint(w/2,h/2));
      painter.drawText(-textWidth/2,0,"Level Complete");
      painter.drawText(-textWidth/2-90,30,"Press S to go to Next Level");

  }

  else if(gameOver && enemyCount == MAXENEMIES && level == 3){
      QFont font("Courier",15,QFont::DemiBold);
      QFontMetrics fm(font);
      int textWidth = fm.width("You Held the Line");
      QString Score = "Score: ";
      Score.append(QString("%1").arg(points));

      painter.setFont(font);
      int h = height();
      int w = width();

      painter.translate(QPoint(w/2,h/2));
      painter.drawText(-textWidth/2-30,0,"You Held the Line");
      painter.drawText(-textWidth/2,30, Score);
      painter.drawText(-textWidth/2-20,60,"Press S to Restart");
      deleteEnemies();
      enemyList.resize(0);
      MAXENEMIES = 10;
      level = 0;
      points = 0;
  }

  else if(!gameStarted){
      QFont font("Courier",15,QFont::DemiBold);
      QFontMetrics fm(font);
      int textWidth = fm.width("Hold The Line");

      painter.setFont(font);
      int h = height();
      int w = width();

      painter.translate(QPoint(w/2,h/2));
      painter.drawText(-textWidth/2,0,"Hold The Line");
      painter.drawText(-textWidth/2-35,30,"Press S to Start");
  }
  else{
   painter.drawImage(prot->getRect(), prot->getImage());

   if(!protect->isDestroyed())
      painter.drawImage(protect->getRect(),protect->getImage());

   if(!protectItem->isDestroyed())
      painter.drawPixmap(protectItem->getRect(),protectItem->getImage());

   painter.drawPixmap(quiver->getRect(),quiver->getImage());
   painter.drawPixmap(trapBag->getRect(),trapBag->getImage());
	
   for(int i = 0; i < enemyList.size(); i++){
       if(!(enemyList[i]->isDestroyed()) && enemyList[i]->getRect().top() < 700)
       painter.drawPixmap(enemyList[i]->getRect(), enemyList[i]->getImage());
   }

   for(int i = 0; i < bulletList.size(); i++){
     if(!(bulletList[i]->isDestroyed()))
       painter.drawImage(bulletList[i]->getRect(), bulletList[i]->getImage());
   }

   for(int i = 0; i < arrowList.size(); i++){
     if(!(arrowList[i]->isDestroyed()))
       painter.drawImage(arrowList[i]->getRect(), arrowList[i]->getImage());
   }

   for(int i = 0; i < trapList.size(); i++){
     if(!(trapList[i]->isDestroyed()))
       painter.drawPixmap(trapList[i]->getRect(), trapList[i]->getImage());
   }

   for(int i = 0; i < treeList.size(); i++)
       painter.drawPixmap(treeList[i]->getRect(), treeList[i]->getImage());


   QString UI = "Arrow: ";
   UI.append(QString("%1").arg(remainingArrows));
   UI += "  Lives: ";
   UI.append(QString("%1").arg(prot->getLives()));
   UI += "  Traps: ";
   UI.append(QString("%1").arg(remainingTraps));
   QFont font("Courier",15,QFont::DemiBold);
   painter.setFont(font);
   painter.drawText(QPoint(10,12), UI);
   QString bla = "Score: ";
   bla.append(QString("%1").arg(enemyCount));
   painter.drawText(QPoint(10,42), bla);
  }//end else


}

void HoldLine::timerEvent(QTimerEvent *event){
   if(event->timerId() == timeridProt){
      if(!protect->isDestroyed()){
          if(XLOC == 38) protect->setPositive(true);
          else if(XLOC == -38) protect->setPositive(false);

          if(protect->getPositive()) XLOC -= 2;
          else if(!protect->getPositive()) XLOC+=2;
    
          protect->calculatePosition(prot->getRect().left(),prot->getRect().top()+10, XLOC);
          protect->move();
          checkCollision();
      }

      if(moving){
         prot->move();
         checkCollision();
      }

   }

   if(event->timerId() == timeridShoot){
      EnemyObject* a;
      int indexBullet = 0;

      if(bulletList[0]->isDestroyed()){
          for(int i = 0; i < enemyList.size(); i++){
              a = dynamic_cast <Enemy2*> (enemyList[i]);

              if(a != NULL && !enemyList[i]->isDestroyed()){
                 bulletList[indexBullet]->setDestroyed(false);
                 bulletList[indexBullet]->resetState(enemyList[i]->getRect().left(),enemyList[i]->getRect().top());
                 bulletList[indexBullet]->setlastLocation(enemyList[i]->getRect().left(),enemyList[i]->getRect().top());
                 bulletList[indexBullet]->determineDirection(prot->getRect().left(),prot->getRect().top());
                 indexBullet++;
              }
          }
      }
   } 

   if(event->timerId() == timeridShoot2){
      EnemyObject *g;
      int indexBullet = 3;

      if(bulletList[3]->isDestroyed()){
          for(int i = 0; i < enemyList.size(); i++){
	      g = dynamic_cast <Enemy3*> (enemyList[i]);

              if(g != NULL && !enemyList[i]->isDestroyed()){
                 bulletList[indexBullet]->setDestroyed(false);
                 bulletList[indexBullet]->resetState(enemyList[i]->getRect().left(),enemyList[i]->getRect().top());
                 indexBullet++;
              }
           }
       }
    }

   if(event->timerId() == timeridskBullet){
      EnemyBullet* c;

      for(int i = 0; i < bulletList.size(); i++){
          c = dynamic_cast <SeekerBullet*> (bulletList[i]);

          if(c != NULL){
              bulletList[i]->setlastLocation(bulletList[i]->getRect().left(),bulletList[i]->getRect().top());
              bulletList[i]->determineDirection(prot->getRect().left(),prot->getRect().top());
              bulletList[i]->move();
          }
      }

   }

   if(event->timerId() == timeridDisappear){
      EnemyObject* d;

      for(int i = 0; i < enemyList.size(); i++){
              d = dynamic_cast <Enemy3*> (enemyList[i]);

              if(d != NULL){
                  enemyList[i]->resetState();
              }
      }

   }


   if(event->timerId() == timeridEnemy){
     for(int i = 0; i < enemyList.size(); i++)
        enemyList[i]->move();
     checkCollision(); 
     checkCrossLine();
   }

   if(event->timerId() == timeridArrow){
     for(int i = 0; i < arrowList.size(); i++)
        arrowList[i]->move();
     checkCollision();

     for(int i = 0; i < arrowList.size(); i++){
         if(!arrowList[i]->isDestroyed())
            break;

         if(i == arrowList.size()-1){
             if(arrowList.size() != 8){
                deleteArrows();
                arrowList.resize(0);
                createArrows(8);
                arrowCount = 0;
             }
         }
     }
   }

   if(event->timerId() == timeridItem){
       protectItem->setDestroyed(true);
       killTimer(timeridItem);
   }

   if(event->timerId() == timeridInvincible){
      protect->setDestroyed(true);
      killTimer(timeridInvincible);
   }

  if(event->timerId() == timeridBullet){
      EnemyBullet* e;

      for(int i = 0; i < bulletList.size(); i++){

         e = dynamic_cast <Bullet*> (bulletList[i]);

         if(e != NULL)
            bulletList[i]->move();
      }
   }

   if(event->timerId() == timeridAnimation)
       repaint();
}

void HoldLine::checkCrossLine(){
    for(int i = 0; i < enemyList.size(); i++){
        if(enemyList[i]->getRect().bottom() > 600){
            enemyList[i]->setDir(0,10);
            if(enemyList[i]->getRect().top() > 700 && !enemyList[i]->isDestroyed()){
                enemyList[i]->setDestroyed(true);
                enemyList[i]->resetState();
                enemyCount++;
                crossedLine++;
                if(enemyCount == MAXENEMIES) stopGame();
            }
        }

    }
}

void HoldLine::keyPressEvent(QKeyEvent *event){

  switch (event->key()){
    case Qt::Key_Up:    if(!paused) moveProtagonist(0,-6);
                        break;

    case Qt::Key_Down:  if(!paused) moveProtagonist(0,6);
                        break;

    case Qt::Key_Right: if(!paused) moveProtagonist(6,0);
                        break;

    case Qt::Key_Left:  if(!paused) moveProtagonist(-6,0);
                        break;

    case Qt::Key_X:     if(!paused && remainingArrows != 0) shootArrow();
                        break;
   
    case Qt::Key_Z:     if(!paused && remainingTraps != 0) deployTrap();
                        break;

    case Qt::Key_Escape: qApp->exit();
                         break;
   
    case Qt::Key_P:    pauseGame();
                       break;

    case Qt::Key_S:   startGame();
                       break;

    default: QWidget::keyPressEvent(event);
  }

}



void HoldLine::moveProtagonist(int dirX, int dirY){
  prot->setDir(dirX,dirY);
  moving = true;
}

void HoldLine::shootArrow(){
   if(arrowCount < arrowList.size()){
       arrowList[arrowCount]->setDestroyed(false);
       arrowList[arrowCount]->resetState(prot->getRect().left(),prot->getRect().top()-20);
       arrowCount++;
       remainingArrows--;
   }
}

void HoldLine::deployTrap(){
   if(trapCount < trapList.size()){
       trapList[trapCount]->setDestroyed(false);
       trapList[trapCount]->resetState(prot->getRect().left(),prot->getRect().top()-30);
       trapCount++;
       remainingTraps--;
   }
}

void HoldLine::keyReleaseEvent(QKeyEvent *event){

    if(event->key()){
       if((Qt::Key_Up) && (Qt::Key_Down) && (Qt::Key_Right) && (Qt::Key_Left))
          moving = false;
    }

}

void HoldLine::startGame(){
  if(!gameStarted) { 
     prot->resetState();
     arrowCount = 0;
     remainingArrows = 8;
     trapCount = 0;
     remainingTraps = 5;
     enemyCount = 0;
     crossedLine = 0;
     prot->setHealth();
     level++;

     if(level == 1){
          createEnemies(MAXENEMIES);

         for(int i = 0; i < arrowList.size(); i++)
            arrowList[i]->setDestroyed(true);

         for(int i = 0; i < trapList.size(); i++)
            trapList[i]->setDestroyed(true);

         for(int i = 0; i < bulletList.size(); i++)
            bulletList[i]->setDestroyed(true); 

         protectItem->setDestroyed(true);
         protect->setDestroyed(true);

     }

     else if(level == 2){
         for(int i = 0; i < enemyList.size(); i++){
             enemyList[i]->setDestroyed(false);
             enemyList[i]->setDir(0,3);
             enemyList[i]->resetState();
         }
         createEnemies(13);
 
         MAXENEMIES += 13;

         deleteArrows();
         arrowList.resize(0);
         createArrows(8);

         deleteTraps();
         trapList.resize(0);
         createTraps(5);


         for(int i = 0; i < arrowList.size(); i++)
            arrowList[i]->setDestroyed(true);

         for(int i = 0; i < trapList.size(); i++)
            trapList[i]->setDestroyed(true);

         for(int i = 0; i < bulletList.size(); i++)
            bulletList[i]->setDestroyed(true); 

         protectItem->setDestroyed(true);
         protect->setDestroyed(true);
     }//end level 2

     else if(level == 3){
         EnemyObject* f;

         for(int i = 0; i < enemyList.size(); i++){
             enemyList[i]->setDestroyed(false);
             f = dynamic_cast <Enemy*> (enemyList[i]);

             if(f != NULL)
                 enemyList[i]->setDir(0,3);

             enemyList[i]->resetState();
         }

         createEnemies(12);

         MAXENEMIES += 12;

         deleteArrows();
         arrowList.resize(0);
         createArrows(8);

         deleteTraps();
         trapList.resize(0);
         createTraps(5);

         for(int i = 0; i < arrowList.size(); i++)
            arrowList[i]->setDestroyed(true);

         for(int i = 0; i < trapList.size(); i++)
            trapList[i]->setDestroyed(true);

         protectItem->setDestroyed(true);
         protect->setDestroyed(true);
     }//end level 3
     

     startTimers();

     gameOver = false;
     gameWon = false;
     gameStarted = true;
  }
}

void HoldLine::stopGame(){
      killTimers();
      gameOver = true;
      gameStarted = false;
      repaint();
}

void HoldLine::pauseGame(){
   if(paused){
     startTimers();
     paused = false;
   }
   else{
     if(!gameOver && gameStarted){
        paused = true;
        killTimers();
     }
   }
}

void HoldLine::victory(){
   killTimers();
   gameWon = true;
   gameStarted = false;
}

void HoldLine::killTimers(){
  killTimer(timeridProt);
  killTimer(timeridEnemy);
  killTimer(timeridArrow);
  killTimer(timeridAnimation);
  killTimer(timeridBullet);
  killTimer(timeridskBullet);
  killTimer(timeridShoot);
  killTimer(timeridDisappear);
  
}

void HoldLine::startTimers(){
  timeridProt = startTimer(3);
  timeridEnemy = startTimer(17);
  timeridArrow = startTimer(2);
  timeridBullet = startTimer(60);
  timeridskBullet = startTimer(120);
  timeridAnimation = startTimer(10);
  timeridShoot = startTimer(400);
  timeridShoot2 = startTimer(500);
  timeridDisappear = startTimer(2000);
}

void HoldLine::checkCollision(){
   for(int i = 0; i < enemyList.size(); i++){
      if(!(enemyList[i]->isDestroyed())){
         if((prot->getRect()).intersects(enemyList[i]->getRect())){
            enemyList[i]->setDestroyed(true);
            enemyList[i]->resetState();
            
            if(protect->isDestroyed()){
                prot->resetState();
                prot->damage();
                points += 100;
            } 

            enemyCount++;
            if(enemyCount == MAXENEMIES) stopGame();
            if(prot->getLives() == 0)
               stopGame();
            break;
         }//end if
      }//end if
   }//end for

   for(int i = 0; i < enemyList.size(); i++){
      if(!(enemyList[i]->isDestroyed())){
          if(!protect->isDestroyed()){
            if((protect->getRect()).intersects(enemyList[i]->getRect())){
                enemyList[i]->setDestroyed(true);
                 enemyList[i]->resetState();
                 enemyCount++;
                 points += 100;
                 if(enemyCount == MAXENEMIES) stopGame();
                 break;
            }//end if
          }
      }//end if
   }//end for

  for(int i = 0; i < arrowList.size(); i++){
     if(!(arrowList[i]->isDestroyed())){
        for(int j = 0; j < enemyList.size(); j++){
            if(!(enemyList[j]->isDestroyed())){
               if((arrowList[i]->getRect()).intersects(enemyList[j]->getRect())){
                 numRand = rand() % 100;
                 if(numRand < 10 && protectItem->isDestroyed() && protect->isDestroyed()){
                    protectItem->resetState(enemyList[j]->getRect().left(),enemyList[j]->getRect().top());
                    protectItem->setDestroyed(false);
                    timeridItem = startTimer(5000);
                 }
                 arrowList[i]->setDestroyed(true);
                 enemyList[j]->setDestroyed(true);
                 enemyList[j]->resetState();
                 enemyCount++;
                 points += 100;
                 if(enemyCount == MAXENEMIES) stopGame();
                 break;
              }//end if
            }//end if
        }//end for
     }//end if
  }//end for  

  for(int i = 0; i < ammoList.size(); i++){
      if((prot->getRect()).intersects(ammoList[i]->getRect())){
          Ammunition *a;
          a = dynamic_cast <Quiver*> (ammoList[i]);

          if(a != NULL){
            createArrows(8);
            remainingArrows = 8;
            break;
          }

          else{
           createTraps(5);
           remainingTraps = 5;
           break;
          }
     }
  }
  
  if(!protectItem->isDestroyed()){
     if((prot->getRect()).intersects(protectItem->getRect())){
        protectItem->setDestroyed(true);
        killTimer(timeridItem);
        protect->setDestroyed(false);
        protect->resetState(prot->getRect().right(),prot->getRect().top());
        timeridInvincible = startTimer(4000);
     }
  }

  for(int i = 0; i< trapList.size();i++){
     if(!trapList[i]->isDestroyed()){
        if((prot->getRect()).intersects(trapList[i]->getRect())){

            if(protect->isDestroyed()){
                prot->resetState();
                prot->damage();
            } 

            trapList[i]->setDestroyed(true);
            if(prot->getLives() == 0)
               stopGame();
            break;
        }//end if
     }//end if
  }//end for


    for(int i = 0; i< bulletList.size();i++){
     if(!bulletList[i]->isDestroyed()){
        if((prot->getRect()).intersects(bulletList[i]->getRect())){

            if(protect->isDestroyed()){
                prot->resetState();
                prot->damage();
            } 

            bulletList[i]->setDestroyed(true);
            if(prot->getLives() == 0)
               stopGame();
            break;
        }//end if
     }//end if
  }//end for


  for(int i = 0; i < trapList.size(); i++){
     if(!(trapList[i]->isDestroyed())){
        for(int j = 0; j < enemyList.size(); j++){
            if(!(enemyList[j]->isDestroyed())){
               if((trapList[i]->getRect()).intersects(enemyList[j]->getRect())){

                 numRand = rand() % 100;
                 if(numRand < 20 && protectItem->isDestroyed() && protect->isDestroyed()){
                    protectItem->resetState(enemyList[j]->getRect().left(),enemyList[j]->getRect().top());
                    protectItem->setDestroyed(false);
                    timeridItem = startTimer(5000);
                 }

                 trapList[i]->setDestroyed(true);
                 enemyList[j]->setDestroyed(true);
                 enemyList[j]->resetState();
                 enemyCount++;
                 points += 100;

                 if(enemyCount == MAXENEMIES) stopGame();
                 break;
              }//end if
            }//end if
        }//end for
     }//end if
  }//end for

  for(int i = 0; i < arrowList.size(); i++){
     if(!(arrowList[i]->isDestroyed())){
        for(int j = 0; j < treeList.size(); j++){
               if((arrowList[i]->getRect()).intersects(treeList[j]->getRect())){
                 arrowList[i]->setDestroyed(true);
                 break;
              }//end if
        }//end for
     }//end if
  }//end for

}


