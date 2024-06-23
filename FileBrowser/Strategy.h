#ifndef STRATEGY_H
#define STRATEGY_H
#include "qdir.h"
#include <QVector>
#include <QString>
class Strategy
{
public:
    //using Dirs = QVector<QString>;
    virtual int Calculate(const QDir& dir, QMap<QString, int>& fileSizesByType) = 0;
};

#endif // STRATEGY_H
