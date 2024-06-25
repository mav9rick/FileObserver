#ifndef FILETYPESTRATEGY_H
#define FILETYPESTRATEGY_H
#include <Strategy.h>
#include <QDir>
#include <QMap>
#include <QFileInfo>
class FileTypeStrategy : public Strategy
{
public:
    int Calculate(const QDir& dir, QMap<QString, int>& fileSizesByType) override;
};

#endif // FILETYPESTRATEGY_H
