#ifndef CIRCULARSPLASH_H
#define CIRCULARSPLASH_H

#include <QWidget>

namespace Ui {
  class CircularSplash;
}

class CircularSplash : public QWidget
{
  Q_OBJECT

public:
  explicit CircularSplash(QWidget *parent = 0);
  ~CircularSplash();

private:
  Ui::CircularSplash *ui;
};

#endif // CIRCULARSPLASH_H
