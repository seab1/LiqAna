#ifndef LIQANA_LAYERLIST_H
#define LIQANA_LAYERLIST_H

#include "liqana_common.h"

class LiqAna_layerList : public LiqAna_common //Klasa odpowiedzialna za przeprowadzanie operacji na liście warstw oraz parametrach warstw
{
private:
    //Atrybuty:
    QStringList layerNames, layerThicknesses, layerFCs;
    int numberOfLayers;

public:
    //Konstruktor:
    LiqAna_layerList(int numberOfLayers = 0);

    //Gettery i settery:
    QStringList getLayerNames();
    void setLayerNames(QStringList layerNames);

    QStringList getLayerThicknesses();
    void setLayerThicknesses(QStringList layerThicknesses);

    QStringList getLayerFCs();
    void setLayerFCs(QStringList layerFCs);

    int getNumberOfLayers();
    void setNumberOfLayers(int numberOfLayers);

    //Metody:
    void initiate(QTreeWidget *list_layers);
    void sortLayers(QTreeWidget *list_layers);
    void addLayer(QTreeWidget *list_layers, QString currentLayerName, QString currentLayerThickness, QString currentFC);
    void editLayer(QTreeWidgetItem *currentLayerPosition, QString currentLayerName, QString currentLayerThickness, QString currentFC);
    void deleteLayer(QTreeWidget *list_layers, QTreeWidgetItem *currentLayerPosition);
    void moveLayerUp(QTreeWidget *list_layers, QTreeWidgetItem *currentLayerPosition);
    void moveLayerDown(QTreeWidget *list_layers, QTreeWidgetItem *currentLayerPosition);
};

#endif // LIQANA_LAYERLIST_H
