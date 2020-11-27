#include "layerwindow.h"
#include "ui_layerwindow.h"

//Działanie po przyciśnięciu przycisku ESC na klawiaturze:
void LayerWindow::keyPressEvent(QKeyEvent *event)
{
    if(event -> key() == Qt::Key_Escape) event -> accept();
    else event -> ignore();
}

//Konstruktor i destruktor:
LayerWindow::LayerWindow(QWidget *parent, int closeMode) :
    QDialog(parent),
    LiqAna_common(),
    ui(new Ui::LayerWindow)
{
    ui -> setupUi(this);

    //Zablokowanie możliwości zmiany rozmiaru i wyłączenie bazowej możliwości zamknięcia okna:
    this -> setWindowFlags(Qt::MSWindowsFixedSizeDialogHint | Qt::WindowTitleHint | Qt::CustomizeWindowHint);

    //Działanie konstruktora:
    this -> initiate();

    this -> closeMode = closeMode;
}

LayerWindow::~LayerWindow()
{
    delete ui;
}

//Gettery i settery:
int LayerWindow::getCloseMode() {return this -> closeMode;}
void LayerWindow::setCloseMode(int closeMode) {this -> closeMode = closeMode;}

QString LayerWindow::getCurrentLayerName() {return this -> currentLayerName;}
void LayerWindow::setCurrentLayerName(QString currentLayerName) {this -> currentLayerName = currentLayerName;}

QString LayerWindow::getCurrentLayerThickness() {return this -> currentLayerThickness;}
void LayerWindow::setCurrentLayerThickness(QString currentLayerThickness) {this -> currentLayerThickness = currentLayerThickness;}

QString LayerWindow::getCurrentFC() {return this -> currentFC;}
void LayerWindow::setCurrentFC(QString currentFC) {this -> currentFC = currentFC;}

//Metody:
void LayerWindow::initiate()
{
    ui -> valField_layerName -> setMaxLength(30);
    ui -> valField_layerThickness -> setValidator(this -> getDouble2Decimals());
    ui -> valField_FC -> setValidator(this -> getDouble2Decimals());
}

void LayerWindow::putValues(int valFieldNumber, QString value)
{
    switch(valFieldNumber)
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

void LayerWindow::clearCurrents()
{
    this -> currentLayerName.clear();
    this -> currentLayerThickness.clear();
    this -> currentFC.clear();
}

void LayerWindow::clearFields()
{
    ui -> valField_layerName -> clear();
    ui -> valField_layerThickness -> clear();
    ui -> valField_FC -> clear();
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
        this -> currentLayerName = ui -> valField_layerName -> text();
        this -> currentLayerThickness = ui -> valField_layerThickness -> text();
        this -> currentFC = ui -> valField_FC -> text();

        this -> closeMode = 1;
        this -> close();
    }
}

void LayerWindow::on_LayerWindow_button_cancel_clicked()
{
    this -> clearFields();

    this -> closeMode = 2;
    this -> close();
}
