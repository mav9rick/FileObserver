#include "FolderStrategy.h"

int FolderStrategy::CalculateFolderSize(const QDir& dir, QMap<QString, int> &fileSizesByType)
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
            totalSize += Calculate(subDir, fileSizesByType);
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
    // Получаем список всех элементов в текущей директории
    QFileInfoList list = dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
    for (const QFileInfo &fileInfo : list)
    {
        if (fileInfo.isDir())
        {
            // Рекурсивный вызов для поддиректории
            fileSizesByType
            QDir subDir(fileInfo.absoluteFilePath());
            totalSize += Calculate(subDir, fileSizesByType);
        }
        else
        {
            // Это файл, добавляем его размер к общему размеру и к размеру по типу
            totalSize += fileInfo.size();
        }
    }
    return totalSize;
}

