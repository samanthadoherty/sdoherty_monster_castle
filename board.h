#ifndef BOARD_H
#define BOARD_H
#include "gamepiece.h"
#include "player.h"
#include <vector>
#include <QGraphicsScene>

using namespace std;

class Board {
public:
   Board();
   Board(int, QGraphicsScene*);
   void display(); 
private:
   vector<vector<GamePiece*> > board;
   int dim;
   int px;
   int py;
   QGraphicsScene* scene;
};

#endif
