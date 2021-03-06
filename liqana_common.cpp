#include "liqana_common.h"

//Konstruktor:
LiqAna_common::LiqAna_common(bool saveNeeded)
{
    this -> saveNeeded = saveNeeded;

    double2Decimals = new QDoubleValidator();
    this -> double2Decimals -> setNotation(QDoubleValidator::StandardNotation);
    this -> double2Decimals -> setDecimals(2);
}

//Gettery i settery:
bool LiqAna_common::getSaveNeeded() {return this -> saveNeeded;}
void LiqAna_common::setSaveNeeded(bool saveNeeded) {this -> saveNeeded = saveNeeded;}

QDoubleValidator *LiqAna_common::getDouble2Decimals() {return this -> double2Decimals;}

//Walidatory:
void LiqAna_common::validateValue(QLineEdit *valField, double bottomVal, double topVal)
{
   QString value = valField -> text();
   valField -> setText(this -> pointerTranslate(this -> setExactRange(value, bottomVal, topVal)));
   if(value == valField -> text()) valField -> setText(this -> properValidator(valField -> text()));
   valField -> deselect();
}

void LiqAna_common::validateSelection(int oldPos, int newPos, QLineEdit *valField)
{
    int valueLength = valField -> text().length();
    if(oldPos == valueLength) valField -> setSelection(valueLength, valueLength);
    if(newPos < valueLength) valField -> setSelection(0, valueLength);
}

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
    valFieldText = this -> pointerTranslate(valFieldText);

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
