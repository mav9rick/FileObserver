#ifndef FOLDERSTRATEGY_H
#define FOLDERSTRATEGY_H
#include <Strategy.h>
#include <QDir>
class FolderStrategy : public Strategy
{
public:
    //using Dirs = QVector<QString>;
    int Calculate(const QDir& dir, QMap<QString, int>& fileSizesByType) override;
    static int getDirectorySize(const QString &dirPath);
};

#endif // FOLDERSTRATEGY_H
