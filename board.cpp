#include "board.h"

using namespace std;

Board::Board() {}

Board::Board(QGraphicsScene* scene_) {
   px = 9; py = 5;
   dim = 10;
   lives = 2;
   score = 0;
   scene = scene_;
   
   monsterList = new vector<GamePiece*>;
   candyList = new vector<GamePiece*>;
   goldList = new vector<GamePiece*>;
   dynamiteList = new vector<GamePiece*>;
   bulletList = new vector<GamePiece*>;
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
   
   /*GamePiece* monster = new Monster(3, 4, this);
   board->at(3)[4] = monster;
   monsterList->push_back(monster);
   GamePiece* candy = new Candy(0, 6, this);
   board->at(0)[6] = candy;
   candyList->push_back(candy);
   GamePiece* gold = new Gold(3, 0, this);
   board->at(3)[0] = gold; 
   goldList->push_back(gold);
   GamePiece* dynamite = new Dynamite(5, 0, this);
   board->at(5)[0] = dynamite;
   dynamiteList->push_back(dynamite); */
}

void Board::resetList() {
  for (int i = 0; i < dim; i++) {
     for (int j = 0; j < dim; j++) {
        if (board->at(i)[j]->isMonster()) {
           monsterList->clear();
           monsterList->push_back(board->at(i)[j]);
        } else  if (board->at(i)[j]->isCandy()) {
           candyList->clear();
           candyList->push_back(board->at(i)[j]);
        } else if (board->at(i)[j]->isDynamite()) {
           dynamiteList->clear();
           dynamiteList->push_back(board->at(i)[j]);
        } else if (board->at(i)[j]->isBullet()) {
           bulletList->clear();
           bulletList->push_back(board->at(i)[j]);
        } else if (board->at(i)[j]->isGold()) {
           goldList->clear();
           goldList->push_back(board->at(i)[j]);
        } else  if (board->at(i)[j]->isPlayer()) {
           px = i; py = j;
        }
     }
   }
}
void Board::moveCandy() {
   for (unsigned int i = 0; i < candyList->size(); i++) {
     GamePiece* candy = candyList->at(i);
     int x = candy->getX();
     int y = candy->getY();
     if(x + 1 != dim) {
        if (x + 1 == px && y == py) {
          board->at(x)[y] = new GamePiece(x, y, this);
          removeFromList(x, y);
          lives++;
        } else {
          moveDown(candy->getX(), candy->getY());
        }
     } else {
       board->at(x)[y] = new GamePiece(x, y, this);
       removeFromList(x, y);
     }
  }
}

void Board::moveMonster() {
   for (unsigned int i = 0 ; i < monsterList->size(); i++) {
     GamePiece* monster = monsterList->at(i);
     if (monster->canMoveRight(board)) {
        moveRight(monster->getX(), monster->getY());
     } else if (monster->canMoveLeft(board)) { 
        moveLeft(monster->getX(), monster->getY());
     }
   }
}

void Board:: moveMonsterDown() {
   for (unsigned int i = 0 ; i < monsterList->size(); i++) {
     GamePiece* monster = monsterList->at(i);
     int y = monster->getY();
     if (monster->getX() != dim-1) {
       moveDown(monster->getX(), monster->getY());
     } else {
       board->at(dim-1)[monster->getY()] = new GamePiece(dim-1, monster->getY(), this);
       removeFromList(dim-1, y);
     }
   }
} 

void Board::moveBullet() {
  for (unsigned int i = 0; i < bulletList->size(); i++) {
    GamePiece* bullet = bulletList->at(i);
    int x = bullet->getX();
    int y = bullet->getY();
    if (x == 0) {
      board->at(x)[y] = new GamePiece(x, y, this);
    } else if (board->at(x-1)[y]->isSpace()) {
        moveUp(x, y);
    } else {
      score += 100;
      delete bullet;
      removeFromList(x+1, y);
      moveUp(x, y);
      board->at(x-1)[y] = new GamePiece(x-1, y, this);
    }
  }
  
}
    
void Board::removeFromList(int x, int y) {
  for (unsigned int i = 0; i < bulletList->size(); i++) {
    GamePiece* bullet = bulletList->at(i);
    if (bullet->getX() == x && bullet->getY() == y) {
      bulletList->erase(bulletList->begin() + i);
    }
  }
  for (unsigned int i = 0; i < monsterList->size(); i++) {
    GamePiece* monster = monsterList->at(i);
    if (monster->getX() == x && monster->getY() == y) {
      monsterList->erase(monsterList->begin() + i);
    }
  }
  for (unsigned int i = 0; i < goldList->size(); i++) {
    GamePiece* gold = goldList->at(i);
    if (gold->getX() == x && gold->getY() == y) {
      goldList->erase(goldList->begin() + i);
    }
  }
  for (unsigned int i = 0; i < dynamiteList->size(); i++) {
    GamePiece* dynamite = dynamiteList->at(i);
    if (dynamite->getX() == x && dynamite->getY() == y) {
      dynamiteList->erase(dynamiteList->begin() + i);
    }
  }
  for (unsigned int i = 0; i < candyList->size(); i++) {
    GamePiece* candy = candyList->at(i);
    if (candy->getX() == x && candy->getY() == y) {
      candyList->erase(candyList->begin() + i);
    }
  }
}

void Board::moveGold() {
   for (unsigned int i = 0; i < goldList->size(); i++) {
     GamePiece* gold = goldList->at(i);
     int x = gold->getX();
     int y = gold->getY();
     if(gold->canMoveDown(board)) {
        if (x + 1 == px && y == py) {
          board->at(x)[y] = new GamePiece(x, y, this);
          removeFromList(x, y);
          score += 500;
        } else {
          moveDown(gold->getX(), gold->getY());
        }
     } else {
       board->at(gold->getX())[gold->getY()] = new GamePiece(gold->getX(), gold->getY(), this);
       removeFromList(x, y);
     }
  }
}  

void Board::moveDynamite() {
   for (unsigned int i = 0; i < dynamiteList->size(); i++) {
      GamePiece* dynamite = dynamiteList->at(i);
      if (dynamite->canMoveDown(board)) {
         moveDown(dynamite->getX(), dynamite->getY());
      } else {
         for (int i = dynamite->getX(); i < dynamite->getX() + 2; i++) {
           for (int j = dynamite->getY(); j < dynamite->getY() + 2; j++) {
             if (j < dim && i < dim) {
               if (i == px && j == py) {
                  lives = 0;
                }
               board->at(i)[j] = new GamePiece(i, j, this);
             }
           }
         }
         removeFromList(dynamite->getX(), dynamite->getY());
      }
   }
}

void Board::addGold() {
  int y = rand() % (dim-1);
  GamePiece* gold = new Gold(0, y, this);
  board->at(0)[y] = gold;
  goldList->push_back(gold);  
}

void Board::addDynamite() {
  int y = rand() % (dim-1);
  GamePiece* dynamite = new Dynamite(0, y, this);
  board->at(0)[y] = dynamite;
  dynamiteList->push_back(dynamite);  
}

void Board::addCandy() {
  int y = rand() % (dim-1);
  GamePiece* candy = new Candy(0, y, this);
  board->at(0)[y] = candy;
  candyList->push_back(candy);
}
  
void Board::addMonster() {
  int y = rand() % (dim-1);
  GamePiece* monster = new Monster(0, y, this);
  board->at(0)[y] = monster;
  monsterList->push_back(monster);
}

void Board::shoot() {
  cout << board->at(dim-1)[0]->display() << endl;
  if (!board->at(px-1)[py]->isBullet()) {
    GamePiece* bullet = new Bullet(px-1, py, this);
    board->at(px-1)[py] = bullet;
    bulletList->push_back(bullet);
  }
}
 
void Board::movePlayerLeft() {
   GamePiece* player = board->at(px)[py];
   if (player->canMoveLeft(board)) {
     moveLeft(px, py);
     py--;
   }
}

void Board::movePlayerRight() {
   GamePiece* player = board->at(px)[py];
   if (player->canMoveRight(board)) {
     moveRight(px, py);
     py++;
   }
}  

void Board::display() {  
  for (int i = 0; i < dim; i++) {
    for (int j = 0; j < dim; j++) {
       QString x = board->at(i)[j]->display().c_str();
       QLabel* label = new QLabel();
       QImage image(board->at(i)[j]->display().c_str());
       label->setPixmap(QPixmap::fromImage(image));
       label->setGeometry(QRect(40*j,40 * i, 40,40));
       scene->addWidget(label);
       //cout << board->at(i)[j]->display();
     //  cout << " ";
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

void Board::moveDown(int x, int y) {
  GamePiece* gp = board->at(x)[y];
  GamePiece* blank = new GamePiece(x, y, this);
  board->at(x)[y] = blank;
  board->at(x+1)[y] = gp;
  board->at(x+1)[y]->moveDown();
}

void Board::moveUp(int x, int y) {
  GamePiece* gp = board->at(x)[y];
  GamePiece* blank = new GamePiece(x, y, this);
  board->at(x)[y] = blank;
  board->at(x-1)[y] = gp;
  board->at(x-1)[y]->moveUp();
}

void Board::moveDiagonalRight(int x, int y) {
  GamePiece* gp = board->at(x)[y];
  GamePiece* blank = new GamePiece(x, y, this);
  board->at(x)[y] = blank;
  board->at(x+1)[y+1] = gp;
  board->at(x+1)[y+1]->moveDiagonalRight();
}

void Board::moveDiagonalLeft(int x, int y) {
  GamePiece* gp = board->at(x)[y];
  GamePiece* blank = new GamePiece(x, y, this);
  board->at(x)[y] = blank;
  board->at(x+1)[y-1] = gp;
  board->at(x+1)[y-1]->moveDiagonalLeft();
}

bool Board::checkLife() {
  if (!board->at(px)[py]->isPlayer()) {
     board->at(px)[py] = new GamePiece(px, py, this);
     if (lives == 0) {
       return true;
     }
     lives--;
     px = dim - 1;
     py = 5;
     board->at(px)[py] = new Player(px, py, this);
     return false;
  }
  return false;
}
  
int Board::getNumMonsters() {
  return monsterList->size();
}
     
int Board::getDim() {
  return dim;
}

int Board::getScore() {
  return score;
}

int Board::getLives() {
  return lives;
}
   
