#include "mainwindow.h"

#include <QApplication>
#include <fstream>

void CreateFiles();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // Create necessary files if they don't already exist.
    CreateFiles();

    return a.exec();
}

void CreateFiles()
{
    std::fstream login("login.csv");

    // Check if login.csv exists, if not then create it.
    if (!login.good())
    {
        login.open("login.csv");
        login.close();
    }
}
