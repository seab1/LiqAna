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

void LayerWindow::putValues(int valueRow, QString value)
{
    switch(valueRow)
    {
        case 1:
        ui -> valField_layerName -> setText(value);
        break;

        case 2:
        ui -> valField_layerThickness -> setText(value);
        break;

        case 3:
        ui -> valField_FC -> setText(value);
        break;
    }
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
    if((ui -> valField_layerName -> text().isEmpty() || (ui -> valField_layerName -> text() == ","))
     || ((ui -> valField_layerThickness -> text().isEmpty()) || (ui -> valField_layerThickness -> text() == ","))
     || ((ui -> valField_FC -> text().isEmpty()) || (ui -> valField_FC -> text() == ","))) QMessageBox::warning(this, "Błąd!", "Nie wszystkie parametry mają poprawnie przypisane wartości!");
    else
    {
        this -> closeMode = 1;
        this -> close();
    }
}

void LayerWindow::on_LayerWindow_button_cancel_clicked()
{
    ui -> valField_layerName -> clear();
    ui -> valField_layerThickness -> clear();
    ui -> valField_FC -> clear();

    this -> closeMode = 2;
    this -> close();
}
