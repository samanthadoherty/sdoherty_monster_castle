#ifndef BOARD_H
#define BOARD_H
#include "gamepiece.h"
#include "player.h"
#include "monster.h"
#include "gold.h"
#include "dynamite.h"
#include "bullet.h"
#include "candy.h"
#include <vector>
#include <QGraphicsScene>

using namespace std;

class Board {
public:
   Board();
   Board(QGraphicsScene*);
   void display(); 
   void removeFromList(int, int);
   void moveMonster();
   void moveMonsterDown();
   void moveCandy();
   void moveGold();
   void moveDynamite();
   void moveBullet();
   void moveRight(int, int);
   void moveLeft(int, int);
   void moveDown(int x, int y);
   void moveUp(int x, int y);
   void moveDiagonalRight(int, int);
   void moveDiagonalLeft(int, int);
   void movePlayerLeft();
   void movePlayerRight();
   void shoot();
   void addMonster();
   void addCandy();
   void addGold();
   void addDynamite();
   bool checkLife();
   int getDim();
   int getScore();
   int getLives();
   int getNumMonsters();
   void resetList();
private:
   vector<vector<GamePiece*> > *board;
   vector<GamePiece*>* monsterList;
   vector<GamePiece*>* candyList;
   vector<GamePiece*>* dynamiteList;
   vector<GamePiece*>* goldList;
   vector<GamePiece*>* bulletList;
   int dim;
   int px;
   int py;
   int lives;
   int score;
   QGraphicsScene* scene;
};

#endif
