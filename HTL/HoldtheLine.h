#ifndef HOLDTHELINE_H
#define HOLDTHELINE_H

#include "Protagonist.h"
#include "Enemy.h"
#include "EnemyObject.h"
#include "Enemy2.h"
#include "Enemy3.h"
#include "Arrow.h"
#include "Quiver.h"
#include "Trap.h"
#include "trapBag.h"
#include "Tree.h"
#include "Bullet.h"
#include "SeekerBullet.h"
#include "EnemyBullet.h"
#include "Ammunition.h"
#include "Protect.h"
#include "ProtectItem.h"
#include <QWidget>
#include <QLabel>
#include <QKeyEvent>
#include <vector>


class HoldLine : public QWidget{
  Q_OBJECT

  public:
    HoldLine(QWidget *parent = 0);
    ~HoldLine();

  protected:
    void paintEvent(QPaintEvent *event);
    void startGame();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void timerEvent(QTimerEvent *event);
    void checkCollision();
    void shootArrow();
    void deployTrap();
    void moveProtagonist(int,int); 
    void createEnemies(int);
    void createArrows(int);
    void createBullets(int);
    void createTraps(int);
    void createTrees(int);
    void deleteArrows();
    void deleteEnemies();
    void deleteTraps();
    void deleteTrees();
    void deleteBullets();
    void deleteAmmo();
    void stopGame();
    void victory();
    void pauseGame();
    void startTimers();
    void killTimers();
    void checkCrossLine();
    
  private:
    Protagonist *prot;
    EnemyObject *enemy;
    EnemyObject *enemy2;
    EnemyObject *enemy3;
    Arrow *arrow;
    Ammunition *quiver;
    Ammunition *trapBag;
    ProtectItem *protectItem;
    Trap *trap;
    Tree *tree;
    EnemyBullet *bullet;
    EnemyBullet *skBullet;
    Protect *protect;
    std::vector<Ammunition*> ammoList;
    std::vector<EnemyObject*> enemyList;
    std::vector<EnemyBullet*> bulletList;
    std::vector<Arrow*> arrowList;
    std::vector<Trap*>  trapList;
    std::vector<Tree*> treeList;
    int level;
    int points;
    int numRand;
    int XLOC;
    int MAXENEMIES;
    int timeridProt;
    int timeridEnemy;
    int timeridDisappear;
    int timeridShoot;
    int timeridShoot2;
    int timeridArrow;
    int timeridBullet;
    int timeridskBullet;
    int timeridAnimation;
    int timeridInvincible;
    int timeridItem;
    int arrowCount;
    int trapCount;
    int remainingArrows;
    int remainingTraps;
    int enemyCount;
    int crossedLine;
    bool gameOver;
    bool gameWon;
    bool gameStarted;
    bool paused;
    bool moving;
    
};

#endif
