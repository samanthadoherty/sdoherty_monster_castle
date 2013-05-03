#include "dynamite.h"

using namespace std;

Dynamite::Dynamite() {}

Dynamite::Dynamite(int xLoc, int yLoc, Board* board)
  : GamePiece(xLoc, yLoc, board) {
  
}

string Dynamite::display() {
  return "images/realdynamite.png";
}

bool Dynamite::isDynamite() {
  return true;
}

bool Dynamite::canMoveDown(vector<vector<GamePiece*> > *board) {
  GamePiece* pieceBelow = board->at(x)[y];
  if (!pieceBelow->isMonster() && !pieceBelow->isBullet()) {
     return x + 1 != dim;
  }
  else
     return false;
}
