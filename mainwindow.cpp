#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    LiqAna_common(false),
    ui(new Ui::MainWindow)
{
    ui -> setupUi(this);

    //Działanie konstruktora:

}

MainWindow::~MainWindow()
{
    delete ui;
}
