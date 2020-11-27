#include "liqana_layerlist.h"

//Konstruktor:
LiqAna_layerList::LiqAna_layerList(int numberOfLayers) : LiqAna_common() {this -> numberOfLayers = numberOfLayers;}

//Gettery i settery:
QStringList LiqAna_layerList::getLayerNames() {return this -> layerNames;}
void LiqAna_layerList::setLayerNames(QStringList layerNames) {this -> layerNames = layerNames;}

QStringList LiqAna_layerList::getLayerThicknesses() {return this -> layerThicknesses;}
void LiqAna_layerList::setLayerThicknesses(QStringList layerThicknesses) {this -> layerThicknesses = layerThicknesses;}

QStringList LiqAna_layerList::getLayerFCs() {return this -> layerFCs;}
void LiqAna_layerList::setLayerFCs(QStringList layerFCs) {this -> layerFCs = layerFCs;}

int LiqAna_layerList::getNumberOfLayers() {return this -> numberOfLayers;}
void LiqAna_layerList::setNumberOfLayers(int numberOfLayers) {this -> numberOfLayers = numberOfLayers;}

//Metody:
void LiqAna_layerList::initiate(QTreeWidget *list_layers)
{
    list_layers -> setColumnWidth(0, 59);
    list_layers -> setColumnWidth(1, 250);
    list_layers -> setColumnWidth(2, 170);
    list_layers -> setColumnWidth(3, 150);
    list_layers -> header() -> setMinimumWidth(59);
    list_layers -> header() -> setSectionResizeMode(QHeaderView::Fixed);
    list_layers -> header() -> setSectionsMovable(false);
}

void LiqAna_layerList::sortLayers(QTreeWidget *list_layers)
{
    for(int i = 0; i < list_layers -> topLevelItemCount(); i++)
    {
        list_layers -> topLevelItem(i) -> setText(0, QString::number(i + 1));
    }
}

void LiqAna_layerList::addLayer(QTreeWidget *list_layers, QString currentLayerName, QString currentLayerThickness, QString currentFC)
{
    this -> numberOfLayers++;

    QTreeWidgetItem *layerPosition = new QTreeWidgetItem(list_layers);
    layerPosition -> setText(0, QString::number(this -> numberOfLayers));
    layerPosition -> setText(1, currentLayerName);
    layerPosition -> setText(2, currentLayerThickness);
    layerPosition -> setText(3, currentFC);
    list_layers -> addTopLevelItem(layerPosition);
}

void LiqAna_layerList::editLayer(QTreeWidgetItem *currentLayerPosition, QString currentLayerName, QString currentLayerThickness, QString currentFC)
{
    currentLayerPosition -> setText(1, currentLayerName);
    currentLayerPosition -> setText(2, currentLayerThickness);
    currentLayerPosition -> setText(3, currentFC);
}

void LiqAna_layerList::deleteLayer(QTreeWidget *list_layers, QTreeWidgetItem *currentLayerPosition)
{
    this -> numberOfLayers--;

    list_layers -> takeTopLevelItem(list_layers -> indexOfTopLevelItem(currentLayerPosition));
    this -> sortLayers(list_layers);
}

void LiqAna_layerList::moveLayerUp(QTreeWidget *list_layers, QTreeWidgetItem *currentLayerPosition)
{
    QTreeWidgetItem *layerPositionAbove = list_layers -> topLevelItem(list_layers -> indexOfTopLevelItem(currentLayerPosition) - 1);
    QString columnValueAbove, currentColumnValue;

    for(int i = 1; i < 4; i++)
    {
        columnValueAbove = layerPositionAbove -> text(i);
        currentColumnValue = currentLayerPosition -> text(i);
        currentLayerPosition -> setText(i, columnValueAbove);
        layerPositionAbove -> setText(i, currentColumnValue);
    }

    this -> sortLayers(list_layers);
    list_layers -> setCurrentItem(layerPositionAbove);
}

void LiqAna_layerList::moveLayerDown(QTreeWidget *list_layers, QTreeWidgetItem *currentLayerPosition)
{
    QTreeWidgetItem *layerPositionBelow = list_layers -> topLevelItem(list_layers -> indexOfTopLevelItem(currentLayerPosition) + 1);
    QString columnValueBelow, currentColumnValue;

    for(int i = 1; i < 4; i++)
    {
        columnValueBelow = layerPositionBelow -> text(i);
        currentColumnValue = currentLayerPosition -> text(i);
        currentLayerPosition -> setText(i, columnValueBelow);
        layerPositionBelow -> setText(i, currentColumnValue);
    }

    this -> sortLayers(list_layers);
    list_layers -> setCurrentItem(layerPositionBelow);
}
