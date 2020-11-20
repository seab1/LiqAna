#ifndef VISUALS_MAINWINDOW_TAB2_H
#define VISUALS_MAINWINDOW_TAB2_H

#include "liqana_common.h"

class Visuals_MainWindow_tab2 : public LiqAna_common //Klasa zawierająca opcje wizualne i mechaniczne zakładki 2 okna głównego
{
private:
    //Atrybuty:
    QString assumedDepth, waterTableDepth, readingsInterval;

public:
    //Konstruktor:
    Visuals_MainWindow_tab2(QString assumedDepth = "1,20", QString waterTableDepth = "1,00", QString readingsInterval = "0,30");

    //Gettery i settery:
    QString getAssumedDepth();
    void setAssumedDepth(QString assumedDepth);

    QString getWaterTableDepth();
    void setWaterTableDepth(QString waterTableDepth);

    QString getReadingsInterval();
    void setReadingsInterval(QString readingsInterval);

    //Wizualizatory pól wartości i opisów:
    void depthsFixer(QLineEdit *valField_assumedDepth, QLineEdit *valField_readingsInterval);
    void requiredReadingsNumberCalculator(QLineEdit *valField_assumedDepth, QLineEdit *valField_readingsInterval, QLabel *label_requiredReadingsNumber);

    //Metody:
    void initiate(QLineEdit *valField_assumedDepth, QLineEdit *valField_waterTableDepth, QLineEdit *valField_readingsInterval,
                  QLabel *label_requiredReadingsNumber);
};

#endif // VISUALS_MAINWINDOW_TAB2_H
