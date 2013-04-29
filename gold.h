#ifndef GOLD_H
#define GOLD_H
#include <iostream>
#include <string>
#include "gamepiece.h"
#include "board.h"

using namespace std;

class Gold : public GamePiece {
public:
  Gold();
  Gold(int xLoc, int yLoc, Board* board);
  string display();
  bool isGold();
  bool isSpace();
  bool canMoveDown(vector<vector<GamePiece*> > *board);
private:

};
#endif
