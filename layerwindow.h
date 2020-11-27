#ifndef LAYERWINDOW_H
#define LAYERWINDOW_H

#include "liqana_common.h"

namespace Ui {class LayerWindow;}

class LayerWindow : public QDialog, public LiqAna_common
{
    Q_OBJECT

private:
    //Atrybuty:
    int closeMode;
    //openMode - tryb otwarcia okna; 1 - dodawanie nowej warstwy, 2 - edycja wybranej warstwy
    //closeMode - tryb zamknięcia warstwy; 1 - zatwierdzenie zmian, 2 - anulowanie zmian
    QString currentLayerName, currentLayerThickness, currentFC;

public:
    //Działanie po przyciśnięciu przycisku ESC na klawiaturze:
    virtual void keyPressEvent(QKeyEvent *event);

    //Konstruktor i destruktor:
    explicit LayerWindow(QWidget *parent = 0, int closeMode = 1);
    ~LayerWindow();

    //Gettery i settery:
    int getCloseMode();
    void setCloseMode(int closeMode);

    QString getCurrentLayerName();
    void setCurrentLayerName(QString currentLayerName);

    QString getCurrentLayerThickness();
    void setCurrentLayerThickness(QString currentLayerName);

    QString getCurrentFC();
    void setCurrentFC(QString currentLayerName);

    //Metody:
    void initiate();
    void putValues(int valFieldNumber, QString value);
    void clearCurrents();
    void clearFields();

private slots:
    //Metody silnika:
    //Walidacja pól wartości:
    void on_valField_layerName_cursorPositionChanged(int oldPos, int newPos);

    void on_valField_layerThickness_editingFinished();
    void on_valField_layerThickness_cursorPositionChanged(int oldPos, int newPos);

    void on_valField_FC_editingFinished();
    void on_valField_FC_cursorPositionChanged(int oldPos, int newPos);

    //Działanie przycisków:
    void on_LayerWindow_button_OK_clicked();
    void on_LayerWindow_button_cancel_clicked();

private:
    Ui::LayerWindow *ui;
};

#endif // LAYERWINDOW_H
