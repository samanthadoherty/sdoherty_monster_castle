#include <iostream>
#include <QGraphicsPixmapItem>
#include <QMessageBox>
#include <QLabel>
#include "mainwindow.h"

using namespace std;

MainWindow::MainWindow() 
{
   timer = new QTimer(this);
   timer->setInterval(1000);
   timer->start();
   connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
   window = new QWidget();
   scene = new QGraphicsScene();
   view = new QGraphicsView( scene );
   board = new Board(scene);
   view->setFixedSize(402, 402);
   
   QLabel* myImage = new QLabel();
   QImage image("images/00911-Stone-Wall-Backdrop.jpg");
   myImage->setPixmap(QPixmap::fromImage(image));
   scene->addWidget(myImage);

   startLayout = new QHBoxLayout();
   bottomLayout = new QHBoxLayout();
   mainLayout = new QVBoxLayout();
   mainLayout->addLayout(startLayout, 0);
   mainLayout->addWidget(view);
   mainLayout->addLayout(bottomLayout, 1);
   window->setLayout(mainLayout);
   window->show();
   board->display();
  // board->moveMonster();
  // cout << "DISPLAY" << endl;
   //board->display();
}

MainWindow::~MainWindow() {
   delete scene;
   delete view;
}

void MainWindow::handleTimer() {
   cout << "Handle Timer" << endl;
   qDeleteAll(scene->items());
   board->moveMonster();
   board->display();
}

void MainWindow::addPushButtons() {
   QPushButton *start = new QPushButton("Start Game");
   startLayout->addWidget(start);
   QPushButton *pause = new QPushButton("Pause");
   startLayout->addWidget(pause);
   connect(pause, SIGNAL(clicked()), this, SLOT(handlePause()));
   QPushButton *restart = new QPushButton("Restart");
   startLayout->addWidget(restart);
   
}

void MainWindow::addBottomButtons() {
   QPushButton *howTo = new QPushButton("How to Play");
   bottomLayout->addWidget(howTo);
   connect(howTo, SIGNAL(clicked()), this, SLOT(handleHowTo()));
   QPushButton *quit = new QPushButton("Quit");
   bottomLayout->addWidget(quit);
   connect(quit, SIGNAL(clicked()), this, SLOT(quit()));
}

void MainWindow::handlePause() {
   QMessageBox *pauseMsg = new QMessageBox();
   pauseMsg->setText("Your quest has been paused.\n\nPress ok when you're ready to continue:");
   pauseMsg->show();
}

void MainWindow::handleHowTo() {
   QMessageBox *msgBox = new QMessageBox();
   msgBox->setText("How to Play the Game:\n\n1. Use the left and right arrow keys to move player.\n\n2. Goal is to get as many points as by possible by moving your player back and forth to collect candy (worth 100 points) and/or pots of gold (worth 500 points) as they move across the screen.\n\n3. Be careful though! You only get 3 lives to start with and if you run into any of the monsters that will also be moving across the board, you die. The game will end when you have zero lives left.\n\n4. Also, if you run into a stick of dynamite, the game automatically ends regardless of how many lives you have left.\n\n5. The game will start to speed up after a while, so collect points while you can!\n\n6. You may pause, restart, or quit the game at any time.\n\nReady?");
   msgBox->show();
}

void MainWindow::quit() {
   exit (EXIT_FAILURE);
}
