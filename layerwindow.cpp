#include "layerwindow.h"
#include "ui_layerwindow.h"

//Działanie po przyciśnięciu przycisku ESC na klawiaturze:
void LayerWindow::keyPressEvent(QKeyEvent *event)
{
    if(event -> key() == Qt::Key_Escape) event -> accept();
    else event -> ignore();
}

//Konstruktor i destruktor:
LayerWindow::LayerWindow(QWidget *parent, int layerNumber, int openMode, int closeMode) :
    QDialog(parent),
    LiqAna_common(),
    ui(new Ui::LayerWindow)
{
    ui -> setupUi(this);

    //Działanie konstruktora:
    this -> initiate();

    this -> layerNumber = layerNumber;
    this -> openMode = openMode;
    this -> closeMode = closeMode;
}

LayerWindow::~LayerWindow()
{
    delete ui;
}

//Gettery i settery:
int LayerWindow::getLayerNumber() {return this -> layerNumber;}
void LayerWindow::setLayerNumber(int layerNumber) {this -> layerNumber = layerNumber;}

int LayerWindow::getOpenMode() {return this -> openMode;}
void LayerWindow::setOpenMode(int openMode) {this -> openMode = openMode;}

int LayerWindow::getCloseMode() {return this -> closeMode;}
void LayerWindow::setCloseMode(int closeMode) {this -> closeMode = closeMode;}

//Metody:
void LayerWindow::initiate()
{
    ui -> valField_layerThickness -> setValidator(this -> getDouble2Decimals());
    ui -> valField_FC -> setValidator(this -> getDouble2Decimals());
}

//Metody pól silnika:
//Walidacja pól wartości:
void LayerWindow::on_valField_layerName_cursorPositionChanged(int oldPos, int newPos) {this -> validateSelection(oldPos, newPos, ui -> valField_layerName);}

void LayerWindow::on_valField_layerThickness_editingFinished() {this -> validateValue(ui -> valField_layerThickness, 0.01, 100.00);}
void LayerWindow::on_valField_layerThickness_cursorPositionChanged(int oldPos, int newPos) {this -> validateSelection(oldPos, newPos, ui -> valField_layerThickness);}

void LayerWindow::on_valField_FC_editingFinished() {this -> validateValue(ui -> valField_FC, 0.01, 100.00);}
void LayerWindow::on_valField_FC_cursorPositionChanged(int oldPos, int newPos) {this -> validateSelection(oldPos, newPos, ui -> valField_FC);}

//Działanie przycisków:
void LayerWindow::on_LayerWindow_button_OK_clicked()
{

}

void LayerWindow::on_LayerWindow_button_cancel_clicked()
{

}
