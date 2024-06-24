#ifndef FOLDERSTRATEGY_H
#define FOLDERSTRATEGY_H
#include <Strategy.h>
#include <QDir>
class FolderStrategy : public Strategy
{
public:
    int Calculate(const QDir& dir, QMap<QString, int>& fileSizesByType) override;
    int CalculateFolderSize(const QDir& dir);
};

#endif // FOLDERSTRATEGY_H
