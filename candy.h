#ifndef CANDY_H
#define CANDY_H
#include <iostream>
#include <string>
#include "gamepiece.h"
#include "board.h"

using namespace std;

class Candy : public GamePiece {

public:
  Candy();
  Candy(int xLoc, int yLoc, Board* board);
  string display();
  bool isCandy();
  bool isSpace();
  bool canMoveDown(vector<vector<GamePiece*> > *board);  
private:
  //bool isMovingRight;
};
#endif
