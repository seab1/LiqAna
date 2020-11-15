#include "visuals_mainwindow_tab1.h"

//Konstruktor:
Visuals_MainWindow_tab1::Visuals_MainWindow_tab1(int MSFMethodChoice, int rdMethodChoice, int KsigmaMethodChoice, int volumStrainMethodChoice,
                                                 QString MSF, QString Kalfa, QString M, QString g, QString aMax, QString pa)
{
    Visuals_MainWindow_tab1::MSFMethodChoice = MSFMethodChoice;
    Visuals_MainWindow_tab1::rdMethodChoice = rdMethodChoice;
    Visuals_MainWindow_tab1::KsigmaMethodChoice = KsigmaMethodChoice;
    Visuals_MainWindow_tab1::volumStrainMethodChoice = volumStrainMethodChoice;
    Visuals_MainWindow_tab1::MSF = MSF;
    Visuals_MainWindow_tab1::Kalfa = Kalfa;
    Visuals_MainWindow_tab1::M = M;
    Visuals_MainWindow_tab1::g = g;
    Visuals_MainWindow_tab1::aMax = aMax;
    Visuals_MainWindow_tab1::pa = pa;
}

//Gettery i settery:
int Visuals_MainWindow_tab1::getMSFMethodChoice() {return Visuals_MainWindow_tab1::getMSFMethodChoice();}
void Visuals_MainWindow_tab1::setMSFMethodChoice(int MSFMethodChoice) {Visuals_MainWindow_tab1::MSFMethodChoice = MSFMethodChoice;}

int Visuals_MainWindow_tab1::getrdMethodChoice() {return Visuals_MainWindow_tab1::rdMethodChoice;}
void Visuals_MainWindow_tab1::setrdMethodChoice(int rdMethodChoice) {Visuals_MainWindow_tab1::rdMethodChoice = rdMethodChoice;}

int Visuals_MainWindow_tab1::getKsigmaMethodChoice() {return Visuals_MainWindow_tab1::KsigmaMethodChoice;}
void Visuals_MainWindow_tab1::setKsigmaMethodChoice(int KsigmaMethodChoice) {Visuals_MainWindow_tab1::KsigmaMethodChoice = KsigmaMethodChoice;}

int Visuals_MainWindow_tab1::getVolumStrainMethodChoice() {return Visuals_MainWindow_tab1::volumStrainMethodChoice;}
void Visuals_MainWindow_tab1::setVolumStrainMethodChoice(int volumStrainMethodChoice) {Visuals_MainWindow_tab1::volumStrainMethodChoice = volumStrainMethodChoice;}

QString Visuals_MainWindow_tab1::getMSF() {return Visuals_MainWindow_tab1::MSF;}
void Visuals_MainWindow_tab1::setMSF(QString MSF) {Visuals_MainWindow_tab1::MSF = MSF;}

QString Visuals_MainWindow_tab1::getKalfa() {return Visuals_MainWindow_tab1::Kalfa;}
void Visuals_MainWindow_tab1::setKalfa(QString Kalfa) {Visuals_MainWindow_tab1::Kalfa = Kalfa;}

QString Visuals_MainWindow_tab1::getM() {return Visuals_MainWindow_tab1::M;}
void Visuals_MainWindow_tab1::setM(QString M) {Visuals_MainWindow_tab1::M = M;}

QString Visuals_MainWindow_tab1::getg() {return Visuals_MainWindow_tab1::g;}
void Visuals_MainWindow_tab1::setg(QString g) {Visuals_MainWindow_tab1::g = g;}

QString Visuals_MainWindow_tab1::getaMax() {return Visuals_MainWindow_tab1::aMax;}
void Visuals_MainWindow_tab1::setaMax(QString aMax) {Visuals_MainWindow_tab1::aMax = aMax;}

QString Visuals_MainWindow_tab1::getpa() {return Visuals_MainWindow_tab1::pa;}
void Visuals_MainWindow_tab1::setpa(QString pa) {Visuals_MainWindow_tab1::pa = pa;}
