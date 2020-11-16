#include "visuals_mainwindow_tab1.h"

//Konstruktor:
Visuals_MainWindow_tab1::Visuals_MainWindow_tab1(int MSFMethodChoice, int rdMethodChoice, int KsigmaMethodChoice, int volumStrainMethodChoice,
                                                 QString MSF, QString Kalfa, QString M, QString g, QString aMax, QString pa) : LiqAna_common()
{
    this -> MSFMethodChoice = MSFMethodChoice;
    this -> rdMethodChoice = rdMethodChoice;
    this -> KsigmaMethodChoice = KsigmaMethodChoice;
    this -> volumStrainMethodChoice = volumStrainMethodChoice;
    this -> MSF = MSF;
    this -> Kalfa = Kalfa;
    this -> M = M;
    this -> g = g;
    this -> aMax = aMax;
    this -> pa = pa;
}

//Gettery i settery:
int Visuals_MainWindow_tab1::getMSFMethodChoice() {return this -> getMSFMethodChoice();}
void Visuals_MainWindow_tab1::setMSFMethodChoice(int MSFMethodChoice) {this -> MSFMethodChoice = MSFMethodChoice;}

int Visuals_MainWindow_tab1::getrdMethodChoice() {return this -> rdMethodChoice;}
void Visuals_MainWindow_tab1::setrdMethodChoice(int rdMethodChoice) {this -> rdMethodChoice = rdMethodChoice;}

int Visuals_MainWindow_tab1::getKsigmaMethodChoice() {return this -> KsigmaMethodChoice;}
void Visuals_MainWindow_tab1::setKsigmaMethodChoice(int KsigmaMethodChoice) {this -> KsigmaMethodChoice = KsigmaMethodChoice;}

int Visuals_MainWindow_tab1::getVolumStrainMethodChoice() {return this -> volumStrainMethodChoice;}
void Visuals_MainWindow_tab1::setVolumStrainMethodChoice(int volumStrainMethodChoice) {this -> volumStrainMethodChoice = volumStrainMethodChoice;}

QString Visuals_MainWindow_tab1::getMSF() {return this -> MSF;}
void Visuals_MainWindow_tab1::setMSF(QString MSF) {this -> MSF = MSF;}

QString Visuals_MainWindow_tab1::getKalfa() {return this -> Kalfa;}
void Visuals_MainWindow_tab1::setKalfa(QString Kalfa) {this -> Kalfa = Kalfa;}

QString Visuals_MainWindow_tab1::getM() {return this -> M;}
void Visuals_MainWindow_tab1::setM(QString M) {this -> M = M;}

QString Visuals_MainWindow_tab1::getg() {return this -> g;}
void Visuals_MainWindow_tab1::setg(QString g) {this -> g = g;}

QString Visuals_MainWindow_tab1::getaMax() {return this -> aMax;}
void Visuals_MainWindow_tab1::setaMax(QString aMax) {this -> aMax = aMax;}

QString Visuals_MainWindow_tab1::getpa() {return this -> pa;}
void Visuals_MainWindow_tab1::setpa(QString pa) {this -> pa = pa;}

//Walidatory:
void Visuals_MainWindow_tab1::validateValue(QLineEdit *valField, double bottomVal, double topVal)
{
   QString value = valField -> text();
   valField -> setText(this -> pointerTranslate(this -> setExactRange(value, bottomVal, topVal)));
   if(value == valField -> text()) valField -> setText(this -> properValidator(valField -> text()));
   valField -> deselect();
}

void Visuals_MainWindow_tab1::validateSelection(int oldPos, int newPos, QLineEdit *valField)
{
    int valueLength = valField -> text().length();
    if(oldPos == valueLength) valField -> setSelection(valueLength, valueLength);
    if(newPos < valueLength) valField -> setSelection(0, valueLength);
}

//Metody:
void Visuals_MainWindow_tab1::backToDefault(QComboBox *drawer_MSF, QComboBox *drawer_rd, QComboBox *drawer_Ksigma, QComboBox *drawer_volumStrainMethod,
                                            QLineEdit *valField_MSF, QLineEdit *valField_Kalfa, QLineEdit *valField_M, QLineEdit *valField_g,
                                            QLineEdit *valField_aMax, QLineEdit *valField_pa)
{
    drawer_MSF -> setCurrentIndex(0);
    drawer_rd -> setCurrentIndex(0);
    drawer_Ksigma -> setCurrentIndex(0);
    drawer_volumStrainMethod -> setCurrentIndex(0);
    valField_MSF -> setText("1,00");
    valField_Kalfa -> setText("1,00");
    valField_M -> setText("7,50");
    valField_g -> setText("9,81");
    valField_aMax -> setText("0,90");
    valField_pa -> setText("101,33");
}
