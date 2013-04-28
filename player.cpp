#include "player.h"

using namespace std;

Player::Player() {}

Player::Player(int xLoc, int yLoc, Board* board) 
  : GamePiece(xLoc, yLoc, board) {
  
}

string Player::display() {
  return "P";
}
