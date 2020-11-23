#include "visuals_mainwindow_tab2.h"

//Konstruktor:
Visuals_MainWindow_tab2::Visuals_MainWindow_tab2(QString assumedDepth, QString waterTableDepth, QString readingsInterval) : LiqAna_common()
{
    this -> assumedDepth = assumedDepth;
    this -> waterTableDepth = waterTableDepth;
    this -> readingsInterval = readingsInterval;
}

//Gettery i settery:
QString Visuals_MainWindow_tab2::getAssumedDepth() {return this -> assumedDepth;}
void Visuals_MainWindow_tab2::setAssumedDepth(QString assumedDepth) {this -> assumedDepth = assumedDepth;}

QString Visuals_MainWindow_tab2::getWaterTableDepth() {return this -> waterTableDepth;}
void Visuals_MainWindow_tab2::setWaterTableDepth(QString waterTableDepth) {this -> waterTableDepth = waterTableDepth;}

QString Visuals_MainWindow_tab2::getReadingsInterval() {return this -> readingsInterval;}
void Visuals_MainWindow_tab2::setReadingsInterval(QString readingsInterval) {this -> readingsInterval = readingsInterval;}

LiqAna_layerList Visuals_MainWindow_tab2::getLayerList() {return this -> layerList;}
void Visuals_MainWindow_tab2::setLayerList(LiqAna_layerList layerList) {this -> layerList = layerList;}

//Wizualizatory pól wartości i opisów:
void Visuals_MainWindow_tab2::depthsFixer(QLineEdit *valField_assumedDepth, QLineEdit *valField_readingsInterval)
{
    double currentAssumedDepth = this -> pointerTranslate(valField_assumedDepth -> text()).toDouble();
    double currentReadingsInterval = this -> pointerTranslate(valField_readingsInterval -> text()).toDouble();

    if(currentAssumedDepth < currentReadingsInterval) valField_readingsInterval -> setText(this -> pointerTranslate(QString::number(currentAssumedDepth, 'f', 2)));
}

void Visuals_MainWindow_tab2::requiredReadingsNumberCalculator(QLineEdit *valField_assumedDepth, QLineEdit *valField_readingsInterval,
                                                               QLabel *label_requiredReadingsNumber)
{
    double currentAssumedDepth = this -> pointerTranslate(valField_assumedDepth -> text()).toDouble();
    double currentReadingsInterval = this -> pointerTranslate(valField_readingsInterval -> text()).toDouble();
    double requiredReadingsNumber = trunc(currentAssumedDepth/currentReadingsInterval + 0.001);
    int fixingAddition = 0;

    if(requiredReadingsNumber * currentReadingsInterval < currentAssumedDepth) fixingAddition = 1;

    label_requiredReadingsNumber -> setText(this -> pointerTranslate(QString::number(requiredReadingsNumber + fixingAddition)));
}

//Metody:
void Visuals_MainWindow_tab2::initiate(QLineEdit *valField_assumedDepth, QLineEdit *valField_waterTableDepth,QLineEdit *valField_readingsInterval,
                                       QLabel *label_requiredReadingsNumber)
{
    valField_assumedDepth -> setValidator(this -> getDouble2Decimals());
    valField_assumedDepth -> setText(this -> assumedDepth);

    valField_waterTableDepth -> setValidator(this -> getDouble2Decimals());
    valField_waterTableDepth -> setText(this -> waterTableDepth);

    valField_readingsInterval -> setValidator(this -> getDouble2Decimals());
    valField_readingsInterval -> setText(this -> readingsInterval);

    this -> requiredReadingsNumberCalculator(valField_assumedDepth, valField_readingsInterval, label_requiredReadingsNumber);
}
