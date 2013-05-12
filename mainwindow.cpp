#include <iostream>
#include <QGraphicsPixmapItem>
#include <QMessageBox>
#include <QKeyEvent>
#include <QtGui>
#include <QLabel>
#include <sstream>
#include "mainmenu.h"
#include "mainwindow.h"

using namespace std;

/** Constructor for MainWindow that sets the timer, creates the window, scene, and view, as well
*   as adds the layouts and pushbuttons to the screen
*/
MainWindow::MainWindow() 
{  
   interval = 250;
   counter = 0;
   isPaused = true;
   timer = new QTimer(this);
   timer->setInterval(interval);
   connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
   
   window = new QWidget();
   scene = new QGraphicsScene();
   view = new QGraphicsView( scene );
   this->setFocusPolicy(Qt::StrongFocus);
   board = new Board(scene);
   view->setFixedSize(402, 402);
   startLayout = new QHBoxLayout();
   bottomLayout = new QHBoxLayout();
   moveLayout = new QHBoxLayout();
   textLayout = new QHBoxLayout();
   mainLayout = new QVBoxLayout();
   mainLayout->addLayout(startLayout, 0);
   mainLayout->addLayout(textLayout, 1);
   mainLayout->addWidget(view);
   mainLayout->addLayout(moveLayout, 2);
   mainLayout->addLayout(bottomLayout, 3);
   window->setLayout(mainLayout);
   window->show();
   board->display();  
}

/** MainWindow destructor */
MainWindow::~MainWindow() {
}

/** When the timer goes off at each interval, this slot is called
*   It moves each object every time the counter hits a certain integer
*   Counter is incremented every time this function is called
*/
void MainWindow::handleTimer() {
   int moveAll = 2;
   int goldA = 15;
   int candyA = 20;
   int dynamiteA = 25;
   int monsterA = 5;
   
   counter++;
   if (counter % 60 == 0) {
      cout << "HERE" << endl;
      timer->setInterval(interval * (.65));
   }
   if (counter % moveAll == 0) {
     board->moveGold();
     board->moveDynamite();
     board->moveCandy();
   }
   if (counter % goldA == 0) {
     board->addGold();
   }
   if (counter % candyA == 0) {
     board->addCandy();
   }
   if (counter % dynamiteA == 0) {
     board->addDynamite();
   }
   if (counter % 1 == 0) {
     board->moveBullet();
   }
   if (counter % monsterA == 0) {
     board->addMonster();
   }
   if (counter % moveAll == 0) {
      board->moveMonsterDown();
   }
   qDeleteAll(scene->items());
   board->display();
   if (board->getLives() == 0) {
     timer->stop();
     gameOver();
   }
   stringstream ss;
   ss << board->getLives();
   QString lives = "Lives: ";
   lives.append(ss.str().c_str());
   livesBox->setText(lives);
   
   stringstream s1;
   s1 << board->getScore();
   QString score = "Score: ";
   score.append(s1.str().c_str());
   scoreBox->setText(score);
}

/** When player has lost all his lives, this function is called, which instantiates a message box
*   stating the player's score and giving him options to continue
*/
void MainWindow::gameOver() {
   QMessageBox *game = new QMessageBox();
   QString msg = ("GAME OVER\n\nYour score was: ");
   stringstream ss;
   ss << board->getScore();
   msg.append(ss.str().c_str());
   msg.append(" ");
   msg.append("\nPress Restart to begin a new game or Quit to close all windows.");
   game->setText(msg);
   game->show();
}

/** This function creates the main pushbuttons, including start game, pause, and restart */
void MainWindow::addPushButtons() {
   QPushButton *start = new QPushButton("Start Game");
   startLayout->addWidget(start);
   connect(start, SIGNAL(clicked()), this, SLOT(handleStart()));
   QPushButton *pause = new QPushButton("Pause");
   startLayout->addWidget(pause);
   connect(pause, SIGNAL(clicked()), this, SLOT(handlePause()));
   QPushButton *restart = new QPushButton("Restart");
   startLayout->addWidget(restart);
   connect(restart, SIGNAL(clicked()), this, SLOT(handleRestart()));
}

/** This function adds the howTo button and the quit button */
void MainWindow::addBottomButtons() {
   QPushButton *howTo = new QPushButton("How to Play");
   bottomLayout->addWidget(howTo);
   connect(howTo, SIGNAL(clicked()), this, SLOT(handleHowTo()));
   QPushButton *quit = new QPushButton("Quit");
   bottomLayout->addWidget(quit);
   connect(quit, SIGNAL(clicked()), this, SLOT(quit()));
}

void MainWindow::keyPressEvent(QKeyEvent *keyEvent) {
   cout << "here" << endl;
   if (keyEvent->key() == Qt::Key_Left) {
      cout << "key";
   }
} 
 
/** This button implements the left and right pushbuttons that allow the player to move back and forth
*   It also creates the shoot button so the user can shoot monsters with the bullet
*/
void MainWindow::addMoveButtons() {
   QPushButton *left = new QPushButton("Left");
   moveLayout->addWidget(left);
   connect(left, SIGNAL(clicked()), this, SLOT(handleLeft()));
   QPushButton *right = new QPushButton("Right");
   moveLayout->addWidget(right);
   connect(right, SIGNAL(clicked()), this, SLOT(handleRight()));
   QPushButton* shoot = new QPushButton("Shoot");
   moveLayout->addWidget(shoot);
   connect(shoot, SIGNAL(clicked()), this, SLOT(handleShoot()));
}

/** This function adds the boxes that display the player's name, score and number of lives left */
void MainWindow::addTextBoxes(QString name) {
    nameBox = new QTextEdit(name);
    textLayout->addWidget(nameBox);
    scoreBox = new QTextEdit("Score: 0");
    textLayout->addWidget(scoreBox);
    livesBox = new QTextEdit("Lives: 3");
    textLayout->addWidget(livesBox);
}

/** When restart is pushed, this slot is called, which deletes all the items in the scene as a way 
*   of refreshing the board, stops the timer, creates a new board, and restarts the timer
*/
void MainWindow::handleRestart() {
  // isPaused = true;
   timer->stop();
   qDeleteAll(scene->items());
   Board* temp = board;
   board = new Board(scene);
   delete temp;
   interval = 250;
   timer->setInterval(interval);
   timer->start();
   board->display();
}

/** If the user hits the left pushbutton, this slot is called, which allows the player to move left */
void MainWindow::handleLeft() {
   if (!isPaused) {
     board->movePlayerLeft();
     board->display();
   }
}

/** If the start button is pushed, this function is called, which starts the timer and adds the first
*   monster to get the game started
*/
void MainWindow::handleStart() {
   if (isPaused) {
     isPaused = false;
     timer->start();
     board->addMonster();
   }
}

/** If the user hits the right pushbutton, this slot is called, which allows the player to move right */
void MainWindow::handleRight() {
   if (!isPaused) {
     board->movePlayerRight();
     board->display();
   }
}

/** If the user presses the shoot button, this function is called, which causes a bullet to appear */
void MainWindow::handleShoot() {
  if (!isPaused) {
    board->shoot();
    board->display();
  }
}

/** If the user hits the pause buttons, this slot is called that creates a message box stating that the
*   game is paused and tells the player what they can do to start it again
*   Also stops the timer
*/
void MainWindow::handlePause() {
   QMessageBox *pauseMsg = new QMessageBox();
   pauseMsg->setText("Your game has been paused. Press 'Start Game' on the main window to continue");
   if (isPaused) {
   } else {
     isPaused = true;     
     pauseMsg->show();
     timer->stop();
   }
}

/** If the player hits the how to button, this slot makes a message box appear detailing all the things
*   the user needs to know to play the game
*/
void MainWindow::handleHowTo() {
   QMessageBox *msgBox = new QMessageBox();
   msgBox->setText("How to Play the Game:\n\n1. Use the left and right buttons to move player.\n\n2. Goal is to get as many points as by possible by moving your player back and forth to collect pots of gold (worth 100 points) as they move across the screen.\n\n3. Be careful though! You only get 3 lives to start with and if you run into any of the monsters that will also be moving across the board, you die. If you collect a piece of candy though, you gain one life. The game will end when you have zero lives left.\n\n4. If you press the 'Shoot' button and hit a monster with your bullet, you gain 500 points and the monster dies! \n\n5. Also, if you run into a stick of dynamite, the game automatically ends regardless of how many lives you have left.\n\n6. The game will start to speed up after a while, so collect points while you can!\n\n7. You may pause, restart, or quit the game at any time.\n\nReady?");
   msgBox->show();
}

/** If the user hits the quit button, this slot causes the game to exit immediately */
void MainWindow::quit() {
   exit (EXIT_FAILURE);
}
