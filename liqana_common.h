#ifndef LIQANA_COMMON_H
#define LIQANA_COMMON_H

#include <QString>
#include <QDoubleValidator>


class LiqAna_common //Klasa zawierająca globalne parametry wizualizacji i walidacji
{
private:
    //Atrybuty:
    bool saveNeeded;
    QDoubleValidator *double2Decimals;

public:
    //Konstruktor:
    LiqAna_common(bool saveNeeded = false);

    //Gettery i settery:
    bool getSaveNeeded();
    void setSaveNeeded(bool saveNeeded);

    QDoubleValidator *getDouble2Decimals();

    //Metody:
    QString pointerTranslate(QString toTranslate);
    QString setExactRange(QString valFieldText, double bottomVal, double topVal);
    QString properValidator(QString valFieldText);
};

#endif // LIQANA_COMMON_H
