#include "FolderStrategy.h"


int FolderStrategy::Calculate(const QDir& dir, QMap<QString, int> &fileSizesByType)
{
    int totalSize = 0;
    QFileInfoList list = dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
    if (!list.isEmpty())
    {
        for (const QFileInfo &fileInfo : list)
        {
            if (fileInfo.isDir())
            {
                QDir subDir(fileInfo.absoluteFilePath());
                totalSize += Calculate(subDir,fileSizesByType); // Рекурсивный вызов для поддиректорий
            }
            else
            {
                QString folderName = dir.dirName();
                totalSize += fileInfo.size(); // Добавляем размер файла
                fileSizesByType[folderName] += fileInfo.size();
            }
        }
    }
    else
    {
        totalSize = 0;
    }
    return totalSize;
}
