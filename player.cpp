#include "player.h"

using namespace std;

Player::Player() {}

Player::Player(int xLoc, int yLoc, Board* board) 
  : GamePiece(xLoc, yLoc, board) {
  
}

string Player::display() {
  return "images/realplayer.png";
}

bool Player::isPlayer() {
  return true;
}

bool Player::isSpace() {
  return false;
}

bool Player::canMoveRight(vector<vector<GamePiece*> > *board) {
  if (board->at(x)[y+1] == isMonster()) {
     return y + 1 != dim;
  }
  else
     return y + 1 != dim;
}
bool Player::canMoveLeft(vector<vector<GamePiece*> > *board){
  if (board->at(x)[y-1] == isMonster()) {
     return y != 0;
  }
  else
     return y != 0;
}
