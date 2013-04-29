#include "gamepiece.h"

using namespace std;

GamePiece::GamePiece() {}

GamePiece::GamePiece(int xLoc, int yLoc, Board* board_) : QLabel() {
  x = xLoc;
  y = yLoc;
  board = board_;
  dim = 10;
}

GamePiece::~GamePiece() {}

string GamePiece::display() {
 return "images/tile.png";
}

bool GamePiece::isCandy() {
  return false;
}

bool GamePiece::isMonster() {
  return false;
}

bool GamePiece::isGold() {
  return false;
}

bool GamePiece::isSpace() {
  return true;
}

bool GamePiece::isDynamite() {
  return false;
}

bool GamePiece::isBullet() {
  return false;
}

bool GamePiece::isPlayer() {
  return false;
}

int GamePiece::getX() {
  return x;
}

int GamePiece::getY() {
  return y;
}

void GamePiece::move() {}

void GamePiece::moveDiagonalRight() {
  x++;
  y++;
}

void GamePiece::moveDiagonalLeft() {
  x++;
  y--;
}

void GamePiece::moveRight() {
  y++;
}

void GamePiece::moveLeft() {
  y--;
}

void GamePiece::moveDown() {
  x++;
}

void GamePiece::moveUp() {
  x--;
}

bool GamePiece::canMoveRight(vector<vector<GamePiece*> >* board) {
  board->at(x)[y]->display();
  return true;
}

bool GamePiece::canMoveLeft(vector<vector<GamePiece*> > *board) {
  board->at(x)[y]->display();
 return true;
}

bool GamePiece::canMoveDown(vector<vector<GamePiece*> > *board) {
  board->at(x)[y]->display();
  return true;
}

bool GamePiece::canMoveDiagonalRight(vector<vector<GamePiece*> > *board) {
  board->at(x)[y]->display();
  return true;
}

bool GamePiece::canMoveDiagonalLeft(vector<vector<GamePiece*> > *board) {
  board->at(x)[y]->display();
  return true;
}
