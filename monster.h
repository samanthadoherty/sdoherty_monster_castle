#ifndef MONSTER_H
#define MONSTER_H
#include <iostream>
#include <string>
#include "gamepiece.h"

using namespace std;

class Monster : public GamePiece {
public:
  Monster();
  Monster(int xLoc, int yLoc, Board* board);
  string display();
  bool isMonster();
  bool canMoveRight(vector<vector<GamePiece*> > *board);
  bool canMoveLeft(vector<vector<GamePiece*> > *board);
private:
  bool isMovingRight;


};
#endif
