#ifndef DYNAMITE_H
#define DYNAMITE_H
#include <iostream>
#include <string>
#include "gamepiece.h"
#include "board.h"

class Dynamite : public GamePiece{
public:
  Dynamite();
  Dynamite(int xLoc, int yLoc, Board* board);
  string display();
  bool isDynamite();
  bool canMoveDown(vector<vector<GamePiece*> > *board);
private:
};
#endif
