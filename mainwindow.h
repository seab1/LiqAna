#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "liqana_common.h"
#include "visuals_mainwindow_tab1.h"

#include <QDebug>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public LiqAna_common
{
    Q_OBJECT

private:
    //Klasy pomniejsze:
    Visuals_MainWindow_tab1 visuals_MainWindow_tab1_1;
    Visuals_MainWindow_tab1 visuals_MainWindow_tab1_2;

public:
    //Konstruktor i destruktor:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
