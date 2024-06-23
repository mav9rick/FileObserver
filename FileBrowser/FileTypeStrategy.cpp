#include "FileTypeStrategy.h"

// Функция для подсчета размера файлов по их типам (расширениям) в директории и её поддиректориях
void getDirectorySizeByType(const QString &dirPath, QMap<QString, quint64> &sizeMap)
{
    QDir dir(dirPath);
    QVector<QFileInfo> list = dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot | QDir::Hidden | QDir::System).toVector();
    for (const QFileInfo &fileInfo : list)
    {
        if (fileInfo.isDir())
        {
            getDirectorySizeByType(fileInfo.absoluteFilePath(), sizeMap);
        }
        else
        {
            QString extension = fileInfo.suffix().toLower();
            sizeMap[extension] += fileInfo.size();
        }
    }
}
QVector<QVector<QString>> FileTypeStrategy::Calculate(QString dir) const
{
    QMap<QString, quint64> sizeMap;
    getDirectorySizeByType(dir, sizeMap);

    QVector<QVector<QString>> result;
    for (auto it = sizeMap.begin(); it != sizeMap.end(); ++it)
    {
        result.append({it.key(), QString::number(it.value())});
    }
    return result;
}

