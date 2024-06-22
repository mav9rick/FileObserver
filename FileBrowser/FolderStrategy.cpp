#include "FolderStrategy.h"

int getDirectorySize(const QString &dirPath)
{
    int size = 0;
    QDir dir(dirPath);
    // Получение списка всех файлов и директорий
    QVector<QFileInfo> list = dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot | QDir::Hidden | QDir::System).toVector();
    // Итерация по всем элементам
    for (const QFileInfo &fileInfo : list)
    {
        if (fileInfo.isDir())
        {
            // Рекурсивный вызов для поддиректорий
            size += getDirectorySize(fileInfo.absoluteFilePath());
        }
        else
        {
            // Добавление размера файла
            size += fileInfo.size();
        }
    }
    return size;
}
QVector<QVector<QString>> FolderStrategy::Calculate(QString directory)
{

}
