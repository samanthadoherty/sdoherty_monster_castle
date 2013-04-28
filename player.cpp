#include "player.h"

using namespace std;

Player::Player() {}

Player::Player(int xLoc, int yLoc) 
  : GamePiece(xLoc, yLoc) {
  
}

string Player::display() {
  return "P";
}
