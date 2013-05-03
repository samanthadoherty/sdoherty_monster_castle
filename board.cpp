#include "board.h"

using namespace std;

Board::Board() {}

Board::Board(QGraphicsScene* scene_) {
   px = 9; py = 5;
   dim = 10;
   lives = 3;
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
      for (int j = 0; j < dim; j++) {
        GamePiece* gp = new GamePiece(i, j, this);
        col.push_back(gp);
      }
      board->push_back(col);
   }
   
   GamePiece* player = new Player(px, py, this);
   board->at(px)[py] = player;
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
     if(candy->canMoveDown(board)) {
        if (x + 1 == px && y == py) {
          board->at(x)[y] = new GamePiece(x, y, this);
          removeCandy(x, y);
          lives++;
        } else {
          moveDown(candy->getX(), candy->getY());
        }
     } else {
       board->at(candy->getX())[candy->getY()] = new GamePiece(candy->getX(), candy->getY(), this);
       removeCandy(x, y);
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
          removeGold(x, y);
          score += 100;
        } 
        else {
           moveDown(gold->getX(), gold->getY());
        }
     } else {
       board->at(gold->getX())[gold->getY()] = new GamePiece(gold->getX(), gold->getY(), this);
       removeGold(x, y);
     }
  }
} 

void Board::moveMonster() {
   for (unsigned int i = 0; i < monsterList->size(); i++) {
     GamePiece* monster = monsterList->at(i);
     if (monster->canMoveRight(board)) {
        if (monster->getX() + 1 == px && monster->getY() == py) {
           lives--;
           px = dim - 1;
           py = 5;
           board->at(px)[py] = new Player(px, py, this);
           board->at(monster->getX())[monster->getY() + 1] = new GamePiece(monster->getX(), monster->getY() + 1, this);
           GamePiece* gp = new GamePiece(monster->getX(), monster->getY(), this);
           board->at(monster->getX())[monster->getY()] = gp;
           removeMonster(monster->getX(), monster->getY());
        }
        else if (board->at(monster->getX())[monster->getY() + 1]->isCandy()) {
            board->at(monster->getX())[monster->getY() + 1] = new GamePiece(monster->getX(), monster->getY() + 1, this);
            removeCandy(monster->getX(), monster->getY()+1);
            moveRight(monster->getX(), monster->getY());
        }
        else if (board->at(monster->getX())[monster->getY() + 1]->isGold()) {
            board->at(monster->getX())[monster->getY() + 1] = new GamePiece(monster->getX(), monster->getY() + 1, this);
            removeGold(monster->getX(), monster->getY()+1);
            moveRight(monster->getX(), monster->getY());
        }
        else if (board->at(monster->getX())[monster->getY() + 1]->isDynamite()) {
            board->at(monster->getX())[monster->getY() + 1] = new GamePiece(monster->getX(), monster->getY() + 1, this);
            removeDynamite(monster->getX(), monster->getY()+1);
            moveRight(monster->getX(), monster->getY());
        }
        else {
           moveRight(monster->getX(), monster->getY());
        }
     } else if (monster->canMoveLeft(board)) {
        if (monster->getY() - 1 == py && monster->getX() == px) {
           lives--;
           px = dim - 1;
           py = 5;
           board->at(px)[py] = new Player(px, py, this);
           board->at(monster->getX())[monster->getY() - 1] = new GamePiece(monster->getX(), monster->getY() - 1, this);
           GamePiece* gp = new GamePiece(monster->getX(), monster->getY(), this);
           board->at(monster->getX())[monster->getY()] = gp;
           removeMonster(monster->getX(), monster->getY());
        }
        else if (board->at(monster->getX())[monster->getY() - 1]->isCandy()) {
           board->at(monster->getX())[monster->getY() - 1] = new GamePiece(monster->getX(), monster->getY() - 1, this);
           removeCandy(monster->getX(), monster->getY()-1);
           moveRight(monster->getX(), monster->getY());
           
        }
        else if (board->at(monster->getX())[monster->getY() - 1]->isGold()) {
           board->at(monster->getX())[monster->getY() - 1] = new GamePiece(monster->getX(), monster->getY() - 1, this);
           removeGold(monster->getX(), monster->getY()-1);
           moveRight(monster->getX(), monster->getY());
        }
        else if (board->at(monster->getX())[monster->getY() - 1]->isDynamite()) {
           board->at(monster->getX())[monster->getY() - 1] = new GamePiece(monster->getX(), monster->getY() - 1, this);
           removeDynamite(monster->getX(), monster->getY()-1);
           moveLeft(monster->getX(), monster->getY());     
        }
        else {
           moveLeft(monster->getX(), monster->getY());
        }
     }
   }
}

void Board:: moveMonsterDown() {
   for (unsigned int i = 0 ; i < monsterList->size(); i++) {
     GamePiece* monster = monsterList->at(i);
     int y = monster->getY();
     if (monster->getX() != dim-1) {
       if (monster->getY() == py && monster->getX() + 1 == px) {
           lives--;
           px = dim - 1;
           py = 5;          
           board->at(monster->getX() + 1)[monster->getY()] = new GamePiece(monster->getX() + 1, monster->getY(), this);
           board->at(px)[py] = new Player(px, py, this);
           removeMonster(monster->getX(), monster->getY());
           GamePiece* gp = new GamePiece(monster->getX(), monster->getY(), this);
           board->at(monster->getX())[monster->getY()] = gp;

        }
        else if (board->at(monster->getX() + 1)[monster->getY()]->isCandy()) {
           board->at(monster->getX() + 1)[monster->getY()] = new GamePiece(monster->getX() + 1, monster->getY(), this);
           removeCandy(monster->getX() + 1, monster->getY());
           moveRight(monster->getX(), monster->getY());
        }
        else if (board->at(monster->getX() + 1)[monster->getY()]->isGold()) {
           board->at(monster->getX() + 1)[monster->getY()] = new GamePiece(monster->getX() + 1, monster->getY(), this);
           removeGold(monster->getX() + 1, monster->getY()); 
           moveRight(monster->getX(), monster->getY());
        }
        else if (board->at(monster->getX() + 1)[monster->getY()]->isDynamite()) {
           board->at(monster->getX() + 1)[monster->getY()] = new GamePiece(monster->getX() + 1, monster->getY(), this);
           removeDynamite(monster->getX() + 1, monster->getY());
           moveLeft(monster->getX(), monster->getY());
        }
        else {
           moveDown(monster->getX(), monster->getY());
        }
     } 
     else {
       board->at(dim-1)[monster->getY()] = new GamePiece(dim-1, monster->getY(), this);
       removeMonster(dim-1, y);
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
       removeBullet(x, y);
    } 
    else if (board->at(x-1)[y]->isMonster()) {
       board->at(x)[y] = new GamePiece(x, y, this);
       board->at(x-1)[y] = new GamePiece(x - 1, y, this); 
       removeBullet(x, y);
       removeMonster(x-1, y);
       score += 500;
    }
    else if (board->at(x-1)[y]->isCandy()) {
       board->at(x)[y] = new GamePiece(x, y, this);
       board->at(x-1)[y] = new GamePiece(x - 1, y, this); 
       removeBullet(x, y);
       removeCandy(x-1, y);
    }
    else if (board->at(x-1)[y]->isGold()) {
       board->at(x)[y] = new GamePiece(x, y, this);
       board->at(x-1)[y] = new GamePiece(x - 1, y, this); 
       removeBullet(x, y);
       removeGold(x-1, y);
    }
    else if (board->at(x-1)[y]->isDynamite()) {
       board->at(x)[y] = new GamePiece(x, y, this);
       board->at(x-1)[y] = new GamePiece(x - 1, y, this); 
       removeBullet(x, y);
       removeDynamite(x-1, y);
    } 
    else
        moveUp(x, y);
  }
  
}

void Board::moveDynamite() {
   for (unsigned int i = 0; i < dynamiteList->size(); i++) {
      GamePiece* dynamite = dynamiteList->at(i);
      if (dynamite->canMoveDown(board)) {
         moveDown(dynamite->getX(), dynamite->getY());         
      } 
      else {
         if (dynamite->getX() + 1 == dim && dynamite->getY() != 0) {        
            for (int i = dynamite->getX() - 1; i <= dynamite->getX(); i++) {
               for (int j = dynamite->getY() - 1; j <= dynamite->getY() + 1; j++) {
                  if (j < dim && i < dim) {
                     if (i == px && j == py) {
                        lives = 0;
                     }
                     board->at(i)[j] = new GamePiece(i, j, this);
                  }
               }
            }
            board->at(dynamite->getX())[dynamite->getY()] = new GamePiece(dynamite->getX(), dynamite->getY(), this);
            removeDynamite(dynamite->getX(), dynamite->getY());
         }
         else {
            board->at(dynamite->getX())[dynamite->getY()] = new GamePiece(dynamite->getX(), dynamite->getY(), this);
            removeDynamite(dynamite->getX(), dynamite->getY());
            board->at(dynamite->getX())[dynamite->getY() + 1] = new GamePiece(dynamite->getX(), dynamite->getY() + 1, this);
         }
      }
   }
}

void Board::removeCandy(int x, int y) {
  for (unsigned int i = 0; i < candyList->size(); i++) {
    GamePiece* candy = candyList->at(i);
    if (candy->getX() == x && candy->getY() == y) {
      candyList->erase(candyList->begin() + i);
    }
  }
}
 
void Board::removeGold(int x, int y) {
  for (unsigned int i = 0; i < goldList->size(); i++) {
    GamePiece* gold = goldList->at(i);
    if (gold->getX() == x && gold->getY() == y) {
      goldList->erase(goldList->begin() + i);
    }
  }
} 

void Board::removeBullet(int x, int y) {
  for (unsigned int i = 0; i < bulletList->size(); i++) {
    GamePiece* bullet = bulletList->at(i);
    if (bullet->getX() == x && bullet->getY() == y) {
      bulletList->erase(bulletList->begin() + i);
    }
  }
}

void Board::removeMonster(int x, int y) {
  for (unsigned int i = 0; i < monsterList->size(); i++) {
    GamePiece* monster = monsterList->at(i);
    if (monster->getX() == x && monster->getY() == y) {
      monsterList->erase(monsterList->begin() + i);
    }
  }
}

void Board::removeDynamite(int x, int y) {
  for (unsigned int i = 0; i < dynamiteList->size(); i++) {
    GamePiece* dynamite = dynamiteList->at(i);
    if (dynamite->getX() == x && dynamite->getY() == y) {
      dynamiteList->erase(dynamiteList->begin() + i);
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

bool Board::checkLife() {
  if (!board->at(px)[py]->isPlayer()) {
     lives--;
    // board->at(px)[py] = new GamePiece(px, py, this);
     if (lives < 0) {
       return true;
     }
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
   
