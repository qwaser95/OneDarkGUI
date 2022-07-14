#ifndef ONEDARKMAIN_H
#define ONEDARKMAIN_H

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
  class OneDarkMain;
}

class CustomButton : public QPushButton
{
  Q_OBJECT
public:
  explicit CustomButton(QWidget *parent = 0);

private slots:
  //void checkStateChange();
};

class OneDarkMain : public QMainWindow
{
  Q_OBJECT

public:
  explicit OneDarkMain(QWidget *parent = 0);
  ~OneDarkMain();

private slots:
  void on_pushButton_hideMenu_toggled(bool checked);

  void on_pushButton_minmaxWindow_toggled(bool checked);

  void on_pushButton_closeApp_clicked();

  void on_pushButton_hidden_clicked();

  void on_pushButton_titleSettings_toggled(bool checked);

  void on_pushButton_changeRightMenu_toggled(bool checked);

  void on_pushButton_information_toggled(bool checked);

  void on_pushButton_setting_toggled(bool checked);

  void on_pushButton_closeMenu_Settings_clicked();

  void on_pushButton_closeMenu_Info_clicked();

  void on_pushButton_home_toggled(bool checked);

  void on_pushButton_showCustomWidgets_toggled(bool checked);

  void on_pushButton_addUsers_toggled(bool checked);

  void on_pushButton_newFile_toggled(bool checked);

  void on_pushButton_openFile_toggled(bool checked);

  void on_pushButton_saveFile_toggled(bool checked);

private:
  Ui::OneDarkMain *ui;
  void animationFrame(QWidget *widget, int toState, QString property);
  void animationButton(QPushButton *button, bool checked, int tabIndex);
};

#endif // ONEDARKMAIN_H
