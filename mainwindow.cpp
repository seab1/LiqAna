#include "mainwindow.h"
#include "ui_mainwindow.h"

//Konstruktor i destruktor:
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    LiqAna_common(),
    ui(new Ui::MainWindow)
{
    ui -> setupUi(this);

    //Działanie konstruktora:
    this -> initiate();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Metody:
void MainWindow::initiate()
{
    visuals_MainWindow_tab1.initiate(ui -> drawer_MSF, ui -> drawer_rd, ui -> drawer_Ksigma, ui -> drawer_volumStrainMethod, ui -> valField_MSF,
                                     ui -> valField_Kalfa, ui -> valField_M, ui -> valField_g, ui -> valField_aMax, ui -> valField_pa);
    visuals_MainWindow_tab2.initiate(ui -> valField_assumedDepth, ui -> valField_waterTableDepth, ui -> valField_readingsInterval, ui -> label_requiredReadingsNumber);
    visuals_MainWindow_tab2.getLayerList().initiate(ui -> list_layers);
}

//Metody silnika:
//Zakładka 1:
//Walidacja pól wartości:
void MainWindow::on_valField_MSF_editingFinished() {this -> validateValue(ui -> valField_MSF, 0.01, 10.00);}
void MainWindow::on_valField_MSF_cursorPositionChanged(int oldPos, int newPos) {this -> validateSelection(oldPos, newPos, ui -> valField_MSF);}
void MainWindow::on_valField_MSF_textChanged() {this -> setSaveNeeded(true);}

void MainWindow::on_valField_Kalfa_editingFinished() {this -> validateValue(ui -> valField_Kalfa, 0.01, 1.00);}
void MainWindow::on_valField_Kalfa_cursorPositionChanged(int oldPos, int newPos) {this -> validateSelection(oldPos, newPos, ui -> valField_Kalfa);}
void MainWindow::on_valField_Kalfa_textChanged() {this -> setSaveNeeded(true);}

void MainWindow::on_valField_M_editingFinished() {this -> validateValue(ui -> valField_M, 0.01, 10.00);}
void MainWindow::on_valField_M_cursorPositionChanged(int oldPos, int newPos) {this -> validateSelection(oldPos, newPos, ui -> valField_M);}
void MainWindow::on_valField_M_textChanged() {this -> setSaveNeeded(true);}

void MainWindow::on_valField_g_editingFinished() {this -> validateValue(ui -> valField_g, 9.00, 10.00);}
void MainWindow::on_valField_g_cursorPositionChanged(int oldPos, int newPos) {this -> validateSelection(oldPos, newPos, ui -> valField_g);}
void MainWindow::on_valField_g_textChanged() {this -> setSaveNeeded(true);}

void MainWindow::on_valField_aMax_editingFinished() {this -> validateValue(ui -> valField_aMax, 0.01, 1.00);}
void MainWindow::on_valField_aMax_cursorPositionChanged(int oldPos, int newPos) {this -> validateSelection(oldPos, newPos, ui -> valField_aMax);}
void MainWindow::on_valField_aMax_textChanged() {this -> setSaveNeeded(true);}

void MainWindow::on_valField_pa_editingFinished() {this -> validateValue(ui -> valField_pa, 0.01, 1000.00);}
void MainWindow::on_valField_pa_cursorPositionChanged(int oldPos, int newPos) {this -> validateSelection(oldPos, newPos, ui -> valField_pa);}
void MainWindow::on_valField_pa_textChanged() {this -> setSaveNeeded(true);}

//Opcje aktywacji pola wartości MSF:
void MainWindow::on_drawer_MSF_currentIndexChanged(int index) {visuals_MainWindow_tab1.ifEnableUserMSF(index, ui -> valField_MSF);}

//Powrót parametrów do wartości domyślnych:
void MainWindow::on_button_backToDefault_clicked() {visuals_MainWindow_tab1.backToDefault(ui -> valField_Kalfa, ui -> valField_M, ui -> valField_g,
                                                                                          ui -> valField_aMax, ui ->valField_pa);}

//Zakładka 2:
//Walidacja pól wartości:
void MainWindow::on_valField_assumedDepth_editingFinished()
{
    this -> validateValue(ui -> valField_assumedDepth, 0.01, 100.00);
    visuals_MainWindow_tab2.depthsFixer(ui -> valField_assumedDepth, ui -> valField_readingsInterval);
    visuals_MainWindow_tab2.requiredReadingsNumberCalculator(ui -> valField_assumedDepth, ui -> valField_readingsInterval, ui -> label_requiredReadingsNumber);
}

void MainWindow::on_valField_assumedDepth_cursorPositionChanged(int oldPos, int newPos) {this -> validateSelection(oldPos, newPos, ui -> valField_assumedDepth);}
void MainWindow::on_valField_assumedDepth_textChanged() {this -> setSaveNeeded(true);}

void MainWindow::on_valField_waterTableDepth_editingFinished() {this -> validateValue(ui -> valField_waterTableDepth, 0.00, 100.00);}
void MainWindow::on_valField_waterTableDepth_cursorPositionChanged(int oldPos, int newPos) {this -> validateSelection(oldPos, newPos, ui -> valField_waterTableDepth);}
void MainWindow::on_valField_waterTableDepth_textChanged(){this -> setSaveNeeded(true);}

void MainWindow::on_valField_readingsInterval_editingFinished()
{
    this -> validateValue(ui -> valField_readingsInterval, 0.01, 0.50);
    visuals_MainWindow_tab2.depthsFixer(ui -> valField_assumedDepth, ui -> valField_readingsInterval);
    visuals_MainWindow_tab2.requiredReadingsNumberCalculator(ui -> valField_assumedDepth, ui -> valField_readingsInterval, ui -> label_requiredReadingsNumber);
}

void MainWindow::on_valField_readingsInterval_cursorPositionChanged(int oldPos, int newPos) {this -> validateSelection(oldPos, newPos, ui -> valField_readingsInterval);}
void MainWindow::on_valField_readingsInterval_textChanged() {this -> setSaveNeeded(true);}
