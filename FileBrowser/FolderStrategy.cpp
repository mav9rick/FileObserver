#include "FolderStrategy.h"


int FolderStrategy::Calculate(const QDir& dir)
{
    int totalSize = 0;
    QFileInfoList list = dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
    for (const QFileInfo &fileInfo : list)
    {
        if (fileInfo.isDir())
        {
            QDir subDir(fileInfo.absoluteFilePath());
            totalSize += Calculate(subDir); // Рекурсивный вызов для поддиректорий
        }
        else
        {
            totalSize += fileInfo.size(); // Добавляем размер файла
        }
    }
    return totalSize;
}
