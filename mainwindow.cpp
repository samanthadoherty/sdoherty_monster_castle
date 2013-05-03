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

MainWindow::MainWindow() 
{  
   interval = 10;
   counter = 0;
   isPaused = true;
   timer = new QTimer(this);
   timer->setInterval(250);
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

MainWindow::~MainWindow() {
}

void MainWindow::handleTimer() {
   int moveAll = 2;
   int goldA = 15;
   int candyA = 20;
   int dynamiteA = 25;
   int monsterA = 7;

   if (counter % 50 == 0) {
      cout << "HERE" << endl;
      candyA = candyA/2;
      moveAll = moveAll/2;
      goldA = goldA/2;
      dynamiteA = dynamiteA/2;
      monsterA = monsterA/2;
   }
   counter++;
   if (counter % moveAll == 0) {
     //board->moveMonster();
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

/*bool MainWindow::eventFilter(QObject *obj, QEvent *event) {
   QKeyEvent *keyEvent = NULL;
   bool result = false;
   if (event->type() == QEvent::KeyPress) {
      keyEvent = dynamic_cast<QKeyEvent*>(event);
      this->keyPressEvent(keyEvent);
      result = true;
   }
   else if (event->type() == QEvent::KeyRelease) {
      keyEvent = dynamic_cast<QKeyEvent*>(event);
      this->keyReleaseEvent(keyEvent);
      result = true;
   }
   else
      result = QObject::eventFilter(obj, event);
   return result;
} */  
  
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

void MainWindow::addTextBoxes(QString name) {
    nameBox = new QTextEdit(name);
    textLayout->addWidget(nameBox);
    scoreBox = new QTextEdit("Score: 0");
    textLayout->addWidget(scoreBox);
    livesBox = new QTextEdit("Lives: 3");
    textLayout->addWidget(livesBox);
}

void MainWindow::handleRestart() {
  // isPaused = true;
   timer->stop();
   qDeleteAll(scene->items());
   Board* temp = board;
   board = new Board(scene);
   delete temp;
   timer->start();
   board->display();
}

void MainWindow::handleLeft() {
   if (!isPaused) {
     board->movePlayerLeft();
     board->display();
   }
}


void MainWindow::handleStart() {
   if (isPaused) {
     isPaused = false;
     timer->start();
     board->addMonster();
   }
}

void MainWindow::handleRight() {
   if (!isPaused) {
     board->movePlayerRight();
     board->display();
   }
}

void MainWindow::handleShoot() {
  if (!isPaused) {
    board->shoot();
    board->display();
  }
}

void MainWindow::handlePause() {
   QMessageBox *pauseMsg = new QMessageBox();
   pauseMsg->setText("Your game has been paused. Press 'Start Game' on the main window to continue");
   if (isPaused) {
    // isPaused = false;
    // timer->start();
   } else {
     isPaused = true;     
     pauseMsg->show();
     timer->stop();
   }
}

void MainWindow::handleHowTo() {
   QMessageBox *msgBox = new QMessageBox();
   msgBox->setText("How to Play the Game:\n\n1. Use the left and right arrow keys to move player.\n\n2. Goal is to get as many points as by possible by moving your player back and forth to collect pots of gold (worth 100 points) as they move across the screen.\n\n3. Be careful though! You only get 3 lives to start with and if you run into any of the monsters that will also be moving across the board, you die. If you collect a piece of candy though, you gain one life. The game will end when you have zero lives left.\n\n4. If you press the 'Shoot' button and hit a monster with your bullet, you gain 500 points and the monster dies! 5. Also, if you run into a stick of dynamite, the game automatically ends regardless of how many lives you have left.\n\n6. The game will start to speed up after a while, so collect points while you can!\n\n7. You may pause, restart, or quit the game at any time.\n\nReady?");
   msgBox->show();
}

void MainWindow::quit() {
   exit (EXIT_FAILURE);
}
