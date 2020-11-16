#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "liqana_common.h"
#include "visuals_mainwindow_tab1.h"

#include <QDebug>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public LiqAna_common
{
    Q_OBJECT

private:
    //Klasy pomniejsze:
    Visuals_MainWindow_tab1 visuals_MainWindow_tab1;

public:
    //Konstruktor i destruktor:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    //Zakładka 1:
    //Walidacja pól wartości:
    void on_valField_MSF_editingFinished();
    void on_valField_MSF_cursorPositionChanged(int oldPos, int newPos);
    void on_valField_MSF_textChanged();

    void on_valField_Kalfa_editingFinished();
    void on_valField_Kalfa_cursorPositionChanged(int oldPos, int newPos);
    void on_valField_Kalfa_textChanged();

    void on_valField_M_editingFinished();
    void on_valField_M_cursorPositionChanged(int oldPos, int newPos);
    void on_valField_M_textChanged();

    void on_valField_g_editingFinished();
    void on_valField_g_cursorPositionChanged(int oldPos, int newPos);
    void on_valField_g_textChanged();

    void on_valField_aMax_editingFinished();
    void on_valField_aMax_cursorPositionChanged(int oldPos, int newPos);
    void on_valField_aMax_textChanged();

    void on_valField_pa_editingFinished();
    void on_valField_pa_cursorPositionChanged(int oldPos, int newPos);
    void on_valField_pa_textChanged();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
