#include "board.h"

using namespace std;

Board::Board() {}

Board::Board(int dim_, QGraphicsScene* scene_) {
   px = py = 2;
   dim = 10;
   scene = scene_;
   for (int i = 0; i < dim; i++) {
      vector<GamePiece*> col;
      for (int i = 0; i < dim; i++) {
        GamePiece* gp = new GamePiece(i, i);
        col.push_back(gp);
      }
      board.push_back(col);
   }
   GamePiece* player = new Player(px, py);
   board[px][py] = player;
}

void Board::display() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
       QString x = "s";
       board[i][j]->setText(x);
       scene->addWidget(board[i][j]);
       cout << board[i][j]->display();
       cout << " ";
    }
    cout << endl;
  }
}
   
