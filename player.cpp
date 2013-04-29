#include "player.h"

using namespace std;

Player::Player() {}

Player::Player(int xLoc, int yLoc, Board* board) 
  : GamePiece(xLoc, yLoc, board) {
  
}

string Player::display() {
  return "images/warrior1.png";
}

bool Player::isPlayer() {
  return true;
}

bool Player::isSpace() {
  return false;
}

bool Player::canMoveRight(vector<vector<GamePiece*> > *board) {
  GamePiece* right = board->at(x)[y+1];
  return y+1 != dim && !right->isMonster();
}
bool Player::canMoveLeft(vector<vector<GamePiece*> > *board){
  GamePiece* left = board->at(x)[y-1];
  return y != 0 && !left->isMonster();
}
