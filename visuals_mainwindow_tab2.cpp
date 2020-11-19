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

//Metody:
void Visuals_MainWindow_tab2::initiate(QLineEdit *valField_assumedDepth, QLineEdit *valField_waterTableDepth, QLineEdit *valField_readingsInterval)
{
    valField_assumedDepth -> setValidator(this -> getDouble2Decimals());
    valField_assumedDepth -> setText(this -> assumedDepth);

    valField_waterTableDepth -> setValidator(this -> getDouble2Decimals());
    valField_waterTableDepth -> setText(this -> waterTableDepth);

    valField_readingsInterval -> setValidator(this -> getDouble2Decimals());
    valField_readingsInterval -> setText(this -> readingsInterval);
}
