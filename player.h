#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include "gamepiece.h"

using namespace std;

class Player : public GamePiece {
public:
  Player();
  Player(int xLoc, int yLoc);
  string display();
private:

};

#endif
