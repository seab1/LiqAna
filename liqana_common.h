#ifndef LIQANA_COMMON_H
#define LIQANA_COMMON_H

#include <QString>


class LiqAna_common //Klasa zawierająca globalne parametry wizualizacji i walidacji
{
private:
    bool saveNeeded;

public:
    //Konstruktor:
    LiqAna_common(bool saveNeeded = false);

    //Gettery i settery:
    bool getSaveNeeded();
    void setSaveNeeded(bool saveNeeded);

    //Metody:
    QString pointerTranslate(QString toTranslate);
    QString setExactRange(QString valFieldText, double bottomVal, double topVal);
    QString properValidator(QString valFieldText);
};

#endif // LIQANA_COMMON_H
