#include "board.h"

using namespace std;

Board::Board() {}

Board::Board(QGraphicsScene* scene_) {
   px = py = 2;
   dim = 10;
   scene = scene_;
   monsterList = new vector<GamePiece*>;
   board = new vector<vector<GamePiece*> >;
   for (int i = 0; i < dim; i++) {
      vector<GamePiece*> col;
      for (int i = 0; i < dim; i++) {
        GamePiece* gp = new GamePiece(i, i, this);
        col.push_back(gp);
      }
      board->push_back(col);
   }
   GamePiece* player = new Player(px, py, this);
   board->at(px)[py] = player;
   GamePiece* monster = new Monster(3, 4, this);
   board->at(3)[4]= monster;
   monsterList->push_back(monster);
   
}

void Board::moveMonster() {
   for (int i = 0 ; i < monsterList->size(); i++) {
     GamePiece* monster = monsterList->at(i);
     if (monster->canMoveRight(board)) {
        moveRight(monster->getX(), monster->getY());
     } else if (monster->canMoveLeft(board)) { 
        moveLeft(monster->getX(), monster->getY());
     }
   }
}

void Board::display() {  
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
       QString x = board->at(i)[j]->display().c_str();
       QLabel* label = new QLabel();
       label->setText(x);
       label->setGeometry(QRect(20*j,20 * i, 20,20));
       scene->addWidget(label);
       cout << board->at(i)[j]->display();
       cout << " ";
    }
    cout << endl;
  }
}

void Board::moveRight(int x, int y) {
  GamePiece* gp = board->at(x)[y];
  GamePiece* blank = new GamePiece(x, y, this);
  board->at(x)[y] = blank;
  board->at(x)[y+1] = gp;
  board->at(x)[y+1]->moveRight();
}

void Board::moveLeft(int x, int y) {
  GamePiece* gp = board->at(x)[y];
  GamePiece* blank = new GamePiece(x, y, this);
  board->at(x)[y] = blank;
  board->at(x)[y-1] = gp;
  board->at(x)[y-1]->moveLeft();
}

int Board::getDim() {
  return dim;
}
   
