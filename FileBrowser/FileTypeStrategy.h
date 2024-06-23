#ifndef FILETYPESTRATEGY_H
#define FILETYPESTRATEGY_H
#include <Strategy.h>
#include <QDir>
#include <QMap>
#include <QFileInfo>
class FileTypeStrategy : public Strategy
{
public:
    //using Dirs = QVector<QString>;
    int Calculate(const QDir& dir, QMap<QString, int>& fileSizesByType) override;
    static void getDirectorySizeByType(const QString &dirPath, QMap<QString, quint64> &sizeMap);
};

#endif // FILETYPESTRATEGY_H
