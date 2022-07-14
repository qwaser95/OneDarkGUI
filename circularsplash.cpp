#include "circularsplash.h"
#include "ui_circularsplash.h"

CircularSplash::CircularSplash(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::CircularSplash)
{
  ui->setupUi(this);
}

CircularSplash::~CircularSplash()
{
  delete ui;
}
