#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QPushButton>
#include <QTimer>
#include "board.h"

class MainWindow : public QWidget {
   Q_OBJECT

public:
   MainWindow();
   ~MainWindow();
   void addPushButtons();
   void addBottomButtons();
   
public slots:
   void quit();
   void handleHowTo();
   void handlePause();
   void handleTimer();

private:
   QHBoxLayout *startLayout;
   QVBoxLayout *mainLayout;
   QHBoxLayout *bottomLayout;
   QWidget *window;
   QGraphicsScene *scene;
   QGraphicsView *view;
   Board* board;
   QTimer *timer;
};

#endif
