#include "liqana_layerlist.h"

//Konstruktor:
LiqAna_layerList::LiqAna_layerList() : LiqAna_common() {}

//Gettery i settery:
QStringList LiqAna_layerList::getLayerNames() {return this -> layerNames;}
void LiqAna_layerList::setLayerNames(QStringList layerNames) {this -> layerNames = layerNames;}

QStringList LiqAna_layerList::getLayerThicknesses() {return this -> layerThicknesses;}
void LiqAna_layerList::setLayerThicknesses(QStringList layerThicknesses) {this -> layerThicknesses = layerThicknesses;}

QStringList LiqAna_layerList::getLayerFCs() {return this -> layerFCs;}
void LiqAna_layerList::setLayerFCs(QStringList layerFCs) {this -> layerFCs = layerFCs;}

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
