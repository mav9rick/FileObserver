#ifndef FOLDERSTRATEGY_H
#define FOLDERSTRATEGY_H
#include <Strategy.h>
#include <QDir>
class FolderStrategy : public Strategy
{
public:
    //using Dirs = QVector<QString>;
    QVector<QVector<QString>> Calculate(QString dir);
    int getDirectorySize(const QString &dirPath);
};

#endif // FOLDERSTRATEGY_H
