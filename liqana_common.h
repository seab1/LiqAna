#ifndef LIQANA_COMMON_H
#define LIQANA_COMMON_H

#include <cmath>
#include <QDebug>
#include <QString>
#include <QStringList>
#include <QList>
#include <QDoubleValidator>
#include <QLineEdit>
#include <QComboBox>
#include <QCheckBox>
#include <QLabel>
#include <QHeaderView>
#include <QTreeWidget>
#include <QTableView>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QMainWindow>
#include <QStatusBar>

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

    //Walidatory:
    void validateValue(QLineEdit *valField, double bottomVal, double topVal);
    void validateSelection(int oldPos, int newPos, QLineEdit *valField);

    //Metody:
    QString pointerTranslate(QString toTranslate);
    QString setExactRange(QString valFieldText, double bottomVal, double topVal);
    QString properValidator(QString valFieldText);
};

#endif // LIQANA_COMMON_H
