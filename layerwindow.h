#ifndef LAYERWINDOW_H
#define LAYERWINDOW_H

#include "liqana_common.h"

namespace Ui {
class LayerWindow;
}

class LayerWindow : public QDialog, public LiqAna_common
{
    Q_OBJECT

private:
    //Atrybuty:
    int layerNumber, openMode, closeMode;
    //openMode - tryb otwarcia okna; 1 - dodawanie nowej warstwy, 2 - edycja wybranej warstwy
    //closeMode - tryb zamknięcia warstwy; 1 - zatwierdzenie zmian, 2 - anulowanie zmian

public:
    //Działanie po przyciśnięciu przycisku ESC na klawiaturze:
    virtual void keyPressEvent(QKeyEvent *event);

    //Konstruktor i destruktor:
    explicit LayerWindow(QWidget *parent = 0, int layerNumber = 1, int openMode = 1, int closeMode = 1);
    ~LayerWindow();

    //Gettery i settery:
    int getLayerNumber();
    void setLayerNumber(int layerNumber);

    int getOpenMode();
    void setOpenMode(int openMode);

    int getCloseMode();
    void setCloseMode(int closeMode);

    //Metody:
    void initiate();

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
