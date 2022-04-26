#include "tictack.h"

tictack::tictack(QWidget *parent)
  : QWidget(parent)
{
  setWindowTitle("Tic tac toe v.0");
//  QRect winc = geometry();
//  qInfo() << winc;
  makeLayout();
  startGame();
}

tictack::~tictack() {}

void tictack::makeLayout()
{
//  QVBoxLayout *vlayout = new QVBoxLayout();
  lbl = new QLabel(this);
  lbl->setAlignment(Qt::AlignCenter);
  //  vlayout->addWidget(lbl);
  QGridLayout *buttons = new QGridLayout;
//  buttons->setSizeConstraint(QLayout::SetFixedSize);
  buttons->addWidget(lbl,0,0,1,3);
//  QHBoxLayout *buttons = new QHBoxLayout();
  for (int n = 0; n < NumButtons; ++n) {
      btn[n] = new QPushButton(this);
      btn[n]->setText(QString::number(n));
      btn[n]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
      btn[n]->setCheckable(true);
      connect(btn[n], SIGNAL(clicked(bool)), this, SLOT(turn()));
  }
  for (int n = 0; n < qSqrt(NumButtons); ++n) {
      for (int m = 0; m < qSqrt(NumButtons); ++m) {
          int s =  n*qSqrt(NumButtons)+m;
          buttons->addWidget(btn[s], n+1, m);
//              qInfo() << "n: "<< n << "m: " << m << "N: " << s;
      }
  }
//  btn1 = new QPushButton(this);
//  btn1->setText("1");
//  btn2 = new QPushButton(this);
//  btn2->setText("2");
//  buttons->addWidget(btn1);
//  buttons->addWidget(btn2);
//  vlayout->addLayout(buttons);
//  setLayout(vlayout);
  setLayout(buttons);
  resize(300,330);
}

void tictack::startGame()
{
//    qsrand(42);
//  int x = QRandomGenerator::global()->bounded(2);
//    for (int n = 0; n < 10; n++) {
  int x = qrand() % 2 ;
  player = getPlayer(x);
//  qInfo() << "X = " << x << "Player" << player;
//}
  // MAYBE better make a function
  if (player == playerO) {
//      btn1->setText("O");
      lbl->setText("O");
    }
  else {
      lbl->setText("X"); }

//  for (int n = 0; n < 10; n++ ) {
//      x = QRandomGenerator::global()->bounded(2);
//      player = getPlayer(x);
//      qInfo() << "Run: " << (n+1) << "X = " << x << "Player" << player;
//    }
}
players tictack::getPlayer(int x)
{
  if (x == 0)
    return playerO;
  else
    return playerX;
}

void tictack::turn()
{
    QPushButton *currentbtn = qobject_cast<QPushButton *>(sender());
    // TO-DO: change color of button text
    if (player == playerO) {
        currentbtn->setText("O");
//        currentbtn->setFont(redFont);
//        currentbtn->setEnabled(false);
//        currentbtn->setChecked(false);
//        currentbtn->setDown(true);
        lbl->setText("Now X turn");
        player = playerX;
    } else {
        currentbtn->setText("X");
//        currentbtn->setChecked(false);
//        currentbtn->setEnabled(false);
        lbl->setText("Now O turn");
        player = playerO;
    }
}
