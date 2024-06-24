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
    QMap<QString, int> map;
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
    int totalSize = strategy->Calculate(dirPath, map);
    output << "Total size calculated: " << totalSize << " bytes" << "\n";
    for (auto it = map.constBegin(); it != map.constEnd(); ++it)
    {
        output << it.key() << ": " << it.value() << " bytes" << "\n";
        output.flush();
    }
    delete strategy; // Освобождаем выделенную память
    return 0;
}
