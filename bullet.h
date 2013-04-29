#ifndef BULLET_H
#define BULLET_H
#include <iostream>
#include <string>
#include "gamepiece.h"
#include "board.h"

class Bullet : public GamePiece{
public:
  Bullet();
  Bullet(int xLoc, int yLoc, Board* board);
  string display();
  bool isBullet();
  bool isSpace();
  //bool canMoveDown(vector<vector<GamePiece*> > *board);
};
#endif
