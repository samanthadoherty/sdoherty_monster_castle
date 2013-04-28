#ifndef BOARD_H
#define BOARD_H
#include "gamepiece.h"
#include "player.h"
#include "monster.h"
#include <vector>
#include <QGraphicsScene>

using namespace std;

class Board {
public:
   Board();
   Board(QGraphicsScene*);
   void display(); 
   void moveMonster();
   void moveRight(int, int);
   void moveLeft(int, int);
   int getDim();
private:
   vector<vector<GamePiece*> > *board;
   vector<GamePiece*>* monsterList;
   int dim;
   int px;
   int py;
   QGraphicsScene* scene;
};

#endif
