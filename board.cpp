#include "board.h"

using namespace std;

/** Default constructor */
Board::Board() {}

/** Constructor to initialize graphics scene, dim, lives, score, and coordinates
*   of player
*   @param QGraphicScene* scene_, what the user will see
*/
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

/** Resets each vector by clearing it, which removes all items from the board
*/
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

/** Uses candyList vector to find position of candy and move it down, if
*   candy is able to move down (nothing is in it's way)
*   Accounts for when candy runs into player and increases lives by 1
*/
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

/** Uses goldList vector to find position of gold and move it down, if
*   gold is able to move down (nothing is in it's way)
*   Accounts for when gold runs into player and increases score by 100
*/
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

/** Uses monsterList vector to find position of monster and move it horizontal
*   Accounts for when monster runs into other objects, which causes those
*   objects to disappear and be removed
*/
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

/** Uses monsterList vector to find position of monster and move it down
*   If object is below monster, function accounts for collisions into each
*   type of object, including player (subtract a life)
*/
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

/** Uses bulletList vector to find position of bullet and move it up
*   If bullet runs into something, that object and the bullet will disappear
*   If the object is a monster, player gains 500 points
*/
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

/** Uses dynamiteList vector to find position of dynamite and move it down, if
*   dynamite is able to move down (nothing is in it's way)
*   Accounts for when dynamite reaches bottom of screen and explodes,
*   causing everything around it to disappear and the game to end
*   if player is nearby
*/
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

/** Removes current candy object from its vector, needed when it runs into
*   another object or reaches bottom of screen
*   @param int x, the x coordinate of candy object
*   @param int y, the y coordinate of candy object
*/
void Board::removeCandy(int x, int y) {
  for (unsigned int i = 0; i < candyList->size(); i++) {
    GamePiece* candy = candyList->at(i);
    if (candy->getX() == x && candy->getY() == y) {
      candyList->erase(candyList->begin() + i);
    }
  }
}
 
/** Removes current gold object from its vector, needed when it runs into
*   another object or reaches bottom of screen
*   @param int x, the x coordinate of gold object
*   @param int y, the y coordinate of gold object
*/
void Board::removeGold(int x, int y) {
  for (unsigned int i = 0; i < goldList->size(); i++) {
    GamePiece* gold = goldList->at(i);
    if (gold->getX() == x && gold->getY() == y) {
      goldList->erase(goldList->begin() + i);
    }
  }
} 

/** Removes current bullet object from its vector, needed when it runs into
*   another object or reaches top of screen
*   @param int x, the x coordinate of bullet object
*   @param int y, the y coordinate of bullet object
*/
void Board::removeBullet(int x, int y) {
  for (unsigned int i = 0; i < bulletList->size(); i++) {
    GamePiece* bullet = bulletList->at(i);
    if (bullet->getX() == x && bullet->getY() == y) {
      bulletList->erase(bulletList->begin() + i);
    }
  }
}

/** Removes current monster object from its vector, needed when it reaches bottom of screen
*   @param int x, the x coordinate of monster object
*   @param int y, the y coordinate of monster object
*/
void Board::removeMonster(int x, int y) {
  for (unsigned int i = 0; i < monsterList->size(); i++) {
    GamePiece* monster = monsterList->at(i);
    if (monster->getX() == x && monster->getY() == y) {
      monsterList->erase(monsterList->begin() + i);
    }
  }
}

/** Removes current dynamite object from its vector, needed when it runs into
*   another object or reaches bottom of screen
*   @param int x, the x coordinate of dynamite object
*   @param int y, the y coordinate of dynamite object
*/
void Board::removeDynamite(int x, int y) {
  for (unsigned int i = 0; i < dynamiteList->size(); i++) {
    GamePiece* dynamite = dynamiteList->at(i);
    if (dynamite->getX() == x && dynamite->getY() == y) {
      dynamiteList->erase(dynamiteList->begin() + i);
    }
  }
}

/** Used when timer reaches certain interval, adds gold object to a random
*   location at top of screen
*/
void Board::addGold() {
  int y = rand() % (dim-1);
  GamePiece* gold = new Gold(0, y, this);
  board->at(0)[y] = gold;
  goldList->push_back(gold);  
}

/** Used when timer reaches certain interval, adds dynamite object to a random
*   location at top of screen
*/
void Board::addDynamite() {
  int y = rand() % (dim-1);
  GamePiece* dynamite = new Dynamite(0, y, this);
  board->at(0)[y] = dynamite;
  dynamiteList->push_back(dynamite); 
}

/** Used when timer reaches certain interval, adds candy object to a random
*   location at top of screen
*/
void Board::addCandy() {
  int y = rand() % (dim-1);
  GamePiece* candy = new Candy(0, y, this);
  board->at(0)[y] = candy;
  candyList->push_back(candy);
}

/** Used when timer reaches certain interval, adds monster object to a random
*   location at top of screen
*/  
void Board::addMonster() {
  int y = rand() % (dim-1);
  GamePiece* monster = new Monster(0, y, this);
  board->at(0)[y] = monster;
  monsterList->push_back(monster);
}

/** This keeps generating a new bullet as it moves and deallocating the old
*   one
*/
void Board::shoot() {
  if (!board->at(px-1)[py]->isBullet()) {
    GamePiece* bullet = new Bullet(px-1, py, this);
    board->at(px-1)[py] = bullet;
    bulletList->push_back(bullet);
  }
}
 
/** This keeps track of when the user presses the left pushbutton, and
*   moves the player one space to the left accordingly
*/
void Board::movePlayerLeft() {
   GamePiece* player = board->at(px)[py];
   if (player->canMoveLeft(board)) {
     moveLeft(px, py);
     py--;
   }
}

/** This keeps track of when the user presses the right pushbutton, and
*   moves the player one space to the right accordingly
*/
void Board::movePlayerRight() {
   GamePiece* player = board->at(px)[py];
   if (player->canMoveRight(board)) {
     moveRight(px, py);
     py++;
   }
}  

/** This displays the current board and all the objects present on it by
*   iterating through all parts of the board
*/
void Board::display() {  
  for (int i = 0; i < dim; i++) {
    for (int j = 0; j < dim; j++) {
       QString x = board->at(i)[j]->display().c_str();
       QLabel* label = new QLabel();
       QImage image(board->at(i)[j]->display().c_str());
       label->setPixmap(QPixmap::fromImage(image));
       label->setGeometry(QRect(40*j,40 * i, 40,40));
       scene->addWidget(label);
    }
    cout << endl;
  }
}

/** This function is called to move a piece to the right on the board
*   @param int x, the current x coordinate of the object
*   @param int y, the current y coordinate of the object
*/
void Board::moveRight(int x, int y) {
  GamePiece* gp = board->at(x)[y];
  GamePiece* blank = new GamePiece(x, y, this);
  board->at(x)[y] = blank;
  board->at(x)[y+1] = gp;
  board->at(x)[y+1]->moveRight();
}

/** This function is called to move a piece to the left on the board
*   @param int x, the current x coordinate of the object
*   @param int y, the current y coordinate of the object
*/
void Board::moveLeft(int x, int y) {
  GamePiece* gp = board->at(x)[y];
  GamePiece* blank = new GamePiece(x, y, this);
  board->at(x)[y] = blank;
  board->at(x)[y-1] = gp;
  board->at(x)[y-1]->moveLeft();
}

/** This function is called to move a piece down the board
*   @param int x, the current x coordinate of the object
*   @param int y, the current y coordinate of the object
*/
void Board::moveDown(int x, int y) {
  GamePiece* gp = board->at(x)[y];
  GamePiece* blank = new GamePiece(x, y, this);
  board->at(x)[y] = blank;
  board->at(x+1)[y] = gp;
  board->at(x+1)[y]->moveDown();
}

/** This function is called to move a piece up the board
*   @param int x, the current x coordinate of the object
*   @param int y, the current y coordinate of the object
*/
void Board::moveUp(int x, int y) {
  GamePiece* gp = board->at(x)[y];
  GamePiece* blank = new GamePiece(x, y, this);
  board->at(x)[y] = blank;
  board->at(x-1)[y] = gp;
  board->at(x-1)[y]->moveUp();
}

/** This is called when a life is lost to subtract the life and
*   reset the player at its starting location
*   @returns true if lives are at 0 to indicate that the game should end
*   @returns false if the player still has more lives left
*/
bool Board::checkLife() {
  if (!board->at(px)[py]->isPlayer()) {
     lives--;
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
 
/** @returns monsterList->size(), the number of monsters on the board */ 
int Board::getNumMonsters() {
  return monsterList->size();
}

/** @returns dim, the dimensions of the board */     
int Board::getDim() {
  return dim;
}

/** @returns score, the score the player currently has */
int Board::getScore() {
  return score;
}

/** @returns lives, the number of lives the player currently has */
int Board::getLives() {
  return lives;
}
