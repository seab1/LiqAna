#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    //Start aplikacji:
    QApplication a(argc, argv);

    //Inicjalizacja i wyświetlenie okna głównego:
    MainWindow w;
    w.show();

    return a.exec();
}
