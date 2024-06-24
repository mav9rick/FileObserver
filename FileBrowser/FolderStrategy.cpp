#include "FolderStrategy.h"

int FolderStrategy::CalculateFolderSize(const QDir& dir)
{
    int totalSize = 0;
    // Получаем список всех элементов в текущей директории
    QFileInfoList list = dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
    for (const QFileInfo &fileInfo : list)
    {
        if (fileInfo.isDir())
        {
            // Рекурсивный вызов для поддиректории
            QDir subDir(fileInfo.absoluteFilePath());
            totalSize += CalculateFolderSize(subDir);
        }
        else
        {
            // Это файл, добавляем его размер к общему размеру и к размеру по типу
            totalSize += fileInfo.size();
        }
    }
    return totalSize;
}
int FolderStrategy::Calculate(const QDir& dir, QMap<QString, int> &fileSizesByType)
{
    int totalSize = 0;
    int dirSize = 0;
    // Получаем список всех элементов в текущей директории
    QFileInfoList list = dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
    for (const QFileInfo &fileInfo : list)
    {
        if (fileInfo.isDir())
        {
            // Рекурсивный вызов для поддиректории
            QDir subDir(fileInfo.absoluteFilePath());
            dirSize = CalculateFolderSize(subDir);
            totalSize += dirSize;
            QString fileName = fileInfo.fileName();
            fileSizesByType[fileName] += dirSize;
        }
        else
        {
            // Это файл, добавляем его размер к общему размеру и к размеру по типу
            totalSize += fileInfo.size();
        }
    }
    return totalSize;
}

