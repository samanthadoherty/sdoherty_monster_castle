#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include "gamepiece.h"

using namespace std;

class Player : public GamePiece {
public:
  Player();
  Player(int xLoc, int yLoc, Board* board);
  string display();
private:

};

#endif
