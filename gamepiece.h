#ifndef GAMEPIECE_H
#define GAMEPIECE_H
#include <QTimer>
#include <QLabel>
#include <iostream>

using namespace std;
class Board;
class GamePiece : public QLabel {
public:
   GamePiece();
   GamePiece(int xLoc, int yLoc, Board* board_);
   ~GamePiece();
   void scrollBoard();
   void moveDiagonalRight();
   void moveDiagonalLeft();
   void moveRight();
   void moveLeft();
   void moveDown();
   void moveUp();
   int getX();
   int getY();
   virtual string display();
   virtual bool isCandy();
   virtual bool isMonster();
   virtual bool isSpace();
   virtual bool isGold();
   virtual bool isDynamite();
   virtual bool isBullet();
   virtual bool isPlayer();
   virtual void move();
   virtual bool canMoveRight(vector<vector<GamePiece*> > *board);
   virtual bool canMoveLeft(vector<vector<GamePiece*> > *board);
   virtual bool canMoveDiagonalRight(vector<vector<GamePiece*> > *board);
   virtual bool canMoveDiagonalLeft(vector<vector<GamePiece*> > *board);
   virtual bool canMoveDown(vector<vector<GamePiece*> > *board);

protected:
   QTimer timer;
   int x;
   int y;
   int dim;
   Board* board;
};

#endif
