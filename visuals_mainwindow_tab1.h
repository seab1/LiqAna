#ifndef VISUALS_MAINWINDOW_TAB1_H
#define VISUALS_MAINWINDOW_TAB1_H

#include <QString>

class Visuals_MainWindow_tab1 //Klasa zawierająca opcje wizualne i mechaniczne zakładki 1 okna głównego
{
private:
    //Atrybuty:
    int MSFMethodChoice, rdMethodChoice, KsigmaMethodChoice, volumStrainMethodChoice;
    QString MSF, Kalfa, M, g, aMax, pa;

public:
    //Konstruktor:
    explicit Visuals_MainWindow_tab1(int MSFMethodChoice = 0, int rdMethodChoice = 0, int KsigmaMethodChoice = 0, int volumStrainMethodChoice = 0,
                                     QString MSF = "1,00", QString Kalfa = "1,00", QString M = "7,50", QString g = "9,81", QString aMax = "0,90",
                                     QString pa = "101,33");

    //Gettery i settery:
    int getMSFMethodChoice();
    void setMSFMethodChoice(int MSFMethodChoice);

    int getrdMethodChoice();
    void setrdMethodChoice(int rdMethodChoice);

    int getKsigmaMethodChoice();
    void setKsigmaMethodChoice(int KsigmaMethodChoice);

    int getVolumStrainMethodChoice();
    void setVolumStrainMethodChoice(int volumStrainMethodChoice);

    QString getMSF();
    void setMSF(QString MSF);

    QString getKalfa();
    void setKalfa(QString Kalfa);

    QString getM();
    void setM(QString M);

    QString getg();
    void setg(QString g);

    QString getaMax();
    void setaMax(QString aMax);

    QString getpa();
    void setpa(QString pa);
};

#endif // VISUALS_MAINWINDOW_TAB1_H