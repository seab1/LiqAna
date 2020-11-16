#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    LiqAna_common(),
    ui(new Ui::MainWindow)
{
    ui -> setupUi(this);

    //Działanie konstruktora:
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Metody silnika:
//Zakładka 1:
//Walidacja pól wartości:
void MainWindow::on_valField_MSF_editingFinished() {visuals_MainWindow_tab1.validateValue(ui -> valField_MSF, 0.01, 10.00);}
void MainWindow::on_valField_MSF_cursorPositionChanged(int oldPos, int newPos) {visuals_MainWindow_tab1.validateSelection(oldPos, newPos, ui -> valField_MSF);}
void MainWindow::on_valField_MSF_textChanged() {this -> setSaveNeeded(true);}

void MainWindow::on_valField_Kalfa_editingFinished() {visuals_MainWindow_tab1.validateValue(ui -> valField_Kalfa, 0.01, 1.00);}
void MainWindow::on_valField_Kalfa_cursorPositionChanged(int oldPos, int newPos) {visuals_MainWindow_tab1.validateSelection(oldPos, newPos, ui -> valField_Kalfa);}
void MainWindow::on_valField_Kalfa_textChanged() {this -> setSaveNeeded(true);}

void MainWindow::on_valField_M_editingFinished() {visuals_MainWindow_tab1.validateValue(ui -> valField_M, 0.01, 10.00);}
void MainWindow::on_valField_M_cursorPositionChanged(int oldPos, int newPos) {visuals_MainWindow_tab1.validateSelection(oldPos, newPos, ui -> valField_M);}
void MainWindow::on_valField_M_textChanged() {this -> setSaveNeeded(true);}

void MainWindow::on_valField_g_editingFinished() {visuals_MainWindow_tab1.validateValue(ui -> valField_g, 9.00, 10.00);}
void MainWindow::on_valField_g_cursorPositionChanged(int oldPos, int newPos) {visuals_MainWindow_tab1.validateSelection(oldPos, newPos, ui -> valField_g);}
void MainWindow::on_valField_g_textChanged() {this -> setSaveNeeded(true);}

void MainWindow::on_valField_aMax_editingFinished() {visuals_MainWindow_tab1.validateValue(ui -> valField_aMax, 0.01, 1.00);}
void MainWindow::on_valField_aMax_cursorPositionChanged(int oldPos, int newPos) {visuals_MainWindow_tab1.validateSelection(oldPos, newPos, ui -> valField_aMax);}
void MainWindow::on_valField_aMax_textChanged() {this -> setSaveNeeded(true);}

void MainWindow::on_valField_pa_editingFinished() {visuals_MainWindow_tab1.validateValue(ui -> valField_pa, 0.01, 1000.00);}
void MainWindow::on_valField_pa_cursorPositionChanged(int oldPos, int newPos) {visuals_MainWindow_tab1.validateSelection(oldPos, newPos, ui -> valField_pa);}
void MainWindow::on_valField_pa_textChanged() {this -> setSaveNeeded(true);}
