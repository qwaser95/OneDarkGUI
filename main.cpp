#include "onedarkmain.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  OneDarkMain w;
  w.show();

  return a.exec();
}
