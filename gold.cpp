#include "gold.h"

using namespace std;

Gold::Gold() {}

Gold::Gold(int xLoc, int yLoc, Board* board)
  : GamePiece(xLoc, yLoc, board) {
  
}

string Gold::display() {
  return "G";
}

bool Gold::isGold() {
  return true;
}

bool Gold::isSpace() {
  return false;
}

bool Gold::canMoveDown(vector<vector<GamePiece*> > *board) {
  GamePiece* pieceBelow = board->at(x)[y];
  return x + 1 != dim && !pieceBelow->isMonster();
}
