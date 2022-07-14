#include "onedarkmain.h"
#include "ui_onedarkmain.h"
#include <QPropertyAnimation>
#include <QDebug>
#include <qframe.h>
#include <QTabBar>

OneDarkMain::OneDarkMain(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::OneDarkMain)
{
  ui->setupUi(this);
  ui->tabWidget_mainBody->tabBar()->setVisible(false);
  ui->tabWidget_rightMenu->tabBar()->setVisible(false);
  ui->tabWidget_leftMenu->tabBar()->setVisible(false);
  setWindowFlag(Qt::FramelessWindowHint);
}

OneDarkMain::~OneDarkMain()
{
  delete ui;
}

void OneDarkMain::animationFrame(QWidget *widget, int toState, QString property)
{
  QPropertyAnimation *animation = new QPropertyAnimation(widget, property.toUtf8());
  animation->setDuration(200);
  animation->setStartValue(widget->maximumWidth());
  animation->setEndValue(toState);
  animation->start();
}

void OneDarkMain::animationButton(QPushButton *button, bool checked, int tabIndex)
{
  if (checked)
    {
      ui->tabWidget_mainBody->setCurrentIndex(tabIndex);
      button->setMinimumWidth(200);
    }
  else
    {
      button->setMinimumWidth(0);
    }
}

void OneDarkMain::on_pushButton_hideMenu_toggled(bool checked)
{
    if (checked)
      {
        animationFrame(ui->frame_mainMenu, 40, "maximumWidth");
        ui->pushButton_hideMenu->setIcon(QIcon("://hamburger.ico"));
      }
    else
      {
        animationFrame(ui->frame_mainMenu, 200, "maximumWidth");
        ui->pushButton_hideMenu->setIcon(QIcon("://arrowdefault.ico"));
      }
}

void OneDarkMain::on_pushButton_minmaxWindow_toggled(bool checked)
{
    if (checked)
      {
        ui->pushButton_minmaxWindow->setIcon(QIcon("://minimize.ico"));
        setWindowState(Qt::WindowMaximized);
      }
    else
      {
        ui->pushButton_minmaxWindow->setIcon(QIcon("://maximize.ico"));
        setWindowState(Qt::WindowNoState);
      }
}

void OneDarkMain::on_pushButton_closeApp_clicked()
{
    close();
}

void OneDarkMain::on_pushButton_hidden_clicked()
{
    showMinimized();
}

void OneDarkMain::on_pushButton_titleSettings_toggled(bool checked)
{
    if (checked)
      {
        animationFrame(ui->frame_rightMenu, 180, "maximumWidth");
      }
    else
      {
        animationFrame(ui->frame_rightMenu, 0, "maximumWidth");
      }
}

void OneDarkMain::on_pushButton_changeRightMenu_toggled(bool checked)
{
    if (checked)
      {
        ui->pushButton_changeRightMenu->setIcon(QIcon("://arrowdefault.ico"));
        ui->pushButton_changeRightMenu->setText("Show Menu 1");
        ui->tabWidget_rightMenu->setCurrentIndex(1);
      }
    else
      {
        ui->pushButton_changeRightMenu->setIcon(QIcon("://arrowright.ico"));
        ui->pushButton_changeRightMenu->setText("Show Menu 2");
        ui->tabWidget_rightMenu->setCurrentIndex(0);
      }
}

void OneDarkMain::on_pushButton_information_toggled(bool checked)
{
    if (checked)
      {
        animationFrame(ui->tabWidget_leftMenu, 180, "maximumWidth");
        animationFrame(ui->pushButton_information, 200, "minimumWidth");
        ui->tabWidget_leftMenu->setCurrentIndex(0);
        ui->pushButton_setting->setChecked(false);
      }
    else
      {
        animationFrame(ui->pushButton_information, 0, "minimumWidth");
      }
}

void OneDarkMain::on_pushButton_setting_toggled(bool checked)
{
  if (checked)
    {
      animationFrame(ui->tabWidget_leftMenu, 180, "maximumWidth");
      animationFrame(ui->pushButton_setting, 200, "minimumWidth");
      ui->tabWidget_leftMenu->setCurrentIndex(1);
      ui->pushButton_information->setChecked(false);
    }
  else
    {
      animationFrame(ui->pushButton_setting, 0, "minimumWidth");
    }
}

void OneDarkMain::on_pushButton_closeMenu_Settings_clicked()
{
    animationFrame(ui->tabWidget_leftMenu, 0, "maximumWidth");
    ui->pushButton_setting->setChecked(false);
}

void OneDarkMain::on_pushButton_closeMenu_Info_clicked()
{
    animationFrame(ui->tabWidget_leftMenu, 0, "maximumWidth");
    ui->pushButton_information->setChecked(false);
}

void OneDarkMain::on_pushButton_home_toggled(bool checked)
{
    animationButton(ui->pushButton_home, checked, 0);
}

void OneDarkMain::on_pushButton_showCustomWidgets_toggled(bool checked)
{
    animationButton(ui->pushButton_showCustomWidgets, checked, 1);
}

void OneDarkMain::on_pushButton_addUsers_toggled(bool checked)
{
    animationButton(ui->pushButton_addUsers, checked, 2);
}

void OneDarkMain::on_pushButton_newFile_toggled(bool checked)
{
    animationButton(ui->pushButton_newFile, checked, 3);
}

void OneDarkMain::on_pushButton_openFile_toggled(bool checked)
{
    animationButton(ui->pushButton_openFile, checked, 4);
}

void OneDarkMain::on_pushButton_saveFile_toggled(bool checked)
{
    animationButton(ui->pushButton_saveFile, checked, 5);
}
