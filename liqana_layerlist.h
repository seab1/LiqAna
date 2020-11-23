#ifndef LIQANA_LAYERLIST_H
#define LIQANA_LAYERLIST_H

#include "liqana_common.h"

class LiqAna_layerList : public LiqAna_common //Klasa odpowiedzialna za przeprowadzanie operacji na liście warstw oraz parametrach warstw
{
private:
    //Atrybuty:
    QStringList layerNames, layerThicknesses, layerFCs;

public:
    //Konstruktor:
    LiqAna_layerList();

    //Gettery i settery:
    QStringList getLayerNames();
    void setLayerNames(QStringList layerNames);

    QStringList getLayerThicknesses();
    void setLayerThicknesses(QStringList layerThicknesses);

    QStringList getLayerFCs();
    void setLayerFCs(QStringList layerFCs);

    //Metody:
    void initiate(QTreeWidget *list_layers);
};

#endif // LIQANA_LAYERLIST_H
