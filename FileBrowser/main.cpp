#include "FileTypeStrategy.h"
#include "FolderStrategy.h"
#include "Strategy.h"
#include <Context.h>
#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QVector>
#include <QDebug>
#include <iostream>
using namespace std;

QString percent(int finalSize, int size)
{
    if (finalSize != 0 && size != 0)
    {
        double percent = 100.0 * size / finalSize;
        if (percent < 0.1)
        {
            return "< 0.1 %";
        }
        else
        {
            return QString::number(percent, 'f', 2) + " %";
        }
    }
    else
    {
        return "0.00 %";
    }
}

int main()
{
    QString command;
    while (command != "exit")
    {
        unique_ptr<Context> context;
        QMap<QString, int> map;
        QTextStream in(stdin);
        QTextStream out(stdout);
        out << "Select Strategy (1 for Folder Strategy, 2 for File Type Strategy): ";
        out.flush();
        QString choice;
        in >> choice;
        if (choice == "1")
        {
            context = make_unique<Context>(make_unique<FolderStrategy>());
        }
        else if (choice == "2")
        {
            context = make_unique<Context>(make_unique<FileTypeStrategy>());
        }
        else
        {
            out << "Invalid choice" << "\n";
            return -1;
        }
        out << "Enter directory path: ";
        out.flush();
        QString dirPath;
        in >> dirPath;
        QFileInfo dircheck(dirPath);
        if (!dircheck.isDir())
        {
            out << "Invalid directory.";
            return -1;
        }
        int dirSize = context->calculate(dirPath, map);
        double finalSize = dirSize / 1024.0;
        QString mainDirName = dircheck.fileName();
        out << "/" << mainDirName << " : " << QString::number(finalSize, 'f', 2) << " KB " << "\n";
        out.flush();
        if (finalSize == 0)
        {
            cout << "Directory is empty." << "\n";
            continue;
        }
        for (auto m = map.constBegin(); m != map.constEnd(); ++m)
        {
            double size = m.value() / 1024.0;
            QString procent = percent(finalSize, size);
            QString sizeS = QString::number(size, 'f', 2);
            out << "  |" << "- " << m.key() << ": " << sizeS << " KB " << procent << "\n";
            out.flush();
        }
        command = dirPath;
    }

    return 0;
}
