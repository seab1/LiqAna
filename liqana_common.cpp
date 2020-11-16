#include "liqana_common.h"

//Konstruktor:
LiqAna_common::LiqAna_common(bool saveNeeded) {LiqAna_common::saveNeeded = saveNeeded;}

//Gettery i settery:
bool LiqAna_common::getSaveNeeded() {return LiqAna_common::saveNeeded;}
void LiqAna_common::setSaveNeeded(bool saveNeeded) {LiqAna_common::saveNeeded = saveNeeded;}

//Metody:
QString LiqAna_common::pointerTranslate(QString toTranslate)
{
    if(toTranslate.contains(","))
    {
        int pointerIndex = toTranslate.indexOf(",");
        return toTranslate.replace(pointerIndex, 1, ".");
    }
    else if(toTranslate.contains("."))
    {
        int pointerIndex = toTranslate.indexOf(".");
        return toTranslate.replace(pointerIndex, 1, ",");
    }

    return toTranslate;
}

QString LiqAna_common::setExactRange(QString valFieldText, double bottomVal, double topVal)
{
    valFieldText = LiqAna_common::pointerTranslate(valFieldText);

    if(valFieldText.toDouble() >= topVal)
    {
        return QString::number(topVal, 'f', 2);
    }
    else if(valFieldText.toDouble() < bottomVal)
    {
        return QString::number(bottomVal, 'f', 2);
    }

    return QString::number(valFieldText.toDouble(), 'f', 2);
}

QString LiqAna_common::properValidator(QString valFieldText)
{
    if(valFieldText.front() == ",") valFieldText.prepend("0");
    if(valFieldText.right(2).contains(",") && !valFieldText.endsWith(",")) valFieldText.append("0");
    if(!valFieldText.contains(",")) valFieldText.append(",00");
    if(valFieldText.endsWith(",")) valFieldText.append("00");

    while(valFieldText.front() == "0")
    {
        if(valFieldText.indexOf(",") == 1) break;
        valFieldText.remove(0, 1);
    }

    return valFieldText;
}
