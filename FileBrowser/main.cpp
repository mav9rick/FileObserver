
#include "FileTypeStrategy.h"
#include "FolderStrategy.h"
#include "Strategy.h"
#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QVector>
#include <QDebug>
#include <iostream>
using namespace std;
int main()
{
    QTextStream input(stdin);
    QTextStream output(stdout);
    output << "Select Strategy (1 for Folder Strategy, 2 for File Type Strategy): ";
    output.flush();
    QString choice;
    input >> choice;
    output << "Enter directory path: ";
    output.flush();
    QString dirPath;
    input >> dirPath;
    Strategy *strategy = nullptr;
    if (choice == "1")
    {
        strategy = new FolderStrategy();
    }
    else if (choice == "2")
    {
        strategy = new FileTypeStrategy();
    }
    else
    {
        output << "Invalid choice" << "\n";
        return -1;
    }
    QVector<QVector<QString>> result = strategy->Calculate(dirPath);
    for (const QVector<QString> &entry : result)
    {
        output << entry[0] << ": " << entry[1] << " bytes" << "\n";
    }
    delete strategy;
    return 0;
}
