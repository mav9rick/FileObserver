#include "FileTypeStrategy.h"

int FileTypeStrategy::Calculate(const QDir &dir, QMap<QString, int>& fileSizesByType)
{
    int totalSize = 0;
    QFileInfoList list = dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
    for (const QFileInfo &fileInfo : list)
    {
        if (fileInfo.isDir())
        {
            QDir subDir(fileInfo.absoluteFilePath());
            totalSize += Calculate(subDir, fileSizesByType); // Рекурсивный вызов для поддиректорий
        }
        else
        {
            QString fileType = fileInfo.suffix(); // Получаем расширение файла
            if (fileType.isEmpty())
            {
                fileType = "no_extension"; // Если файл не имеет расширения
            }
            totalSize += fileInfo.size();
            fileSizesByType[fileType] += fileInfo.size(); // Добавляем размер файла к соответствующему типу
        }
    }
    return totalSize;
}

