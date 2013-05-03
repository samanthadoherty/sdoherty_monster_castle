#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QTimer>
#include "board.h"

class MainWindow : public QWidget {
   Q_OBJECT

public:
   MainWindow();
   ~MainWindow();
   void addPushButtons();
   void addBottomButtons();
   void addMoveButtons();
   void addTextBoxes(QString);
   void gameOver();

protected:
   void keyPressEvent(QKeyEvent *);
  // bool eventFilter(QObject *obj, QEvent *event);
  // void keyReleaseEvent(QKeyEvent *keyEvent);
   
public slots:
   void quit();
   void handleHowTo();
   void handlePause();
   void handleTimer();
   void handleLeft();
   void handleRight();
   void handleShoot();
   void handleRestart();
   void handleStart();
private:
   QHBoxLayout *startLayout;
   QHBoxLayout *moveLayout;
   QVBoxLayout *mainLayout;
   QHBoxLayout *bottomLayout;
   QTextEdit *nameBox;
   QTextEdit *scoreBox;
   QTextEdit *livesBox;
   QHBoxLayout *textLayout;
   QWidget *window;
   QGraphicsScene *scene;
   QGraphicsView *view;
   Board* board;
   QTimer *timer;
   int counter;
   bool isPaused;
   int interval;
};

#endif
