#ifndef STRATEGY_H
#define STRATEGY_H
#include <QVector>
#include <QString>
class Strategy
{
public:
    //using Dirs = QVector<QString>;
    virtual QVector<QVector<QString>> Calculate(QString dir) const = 0;
};

#endif // STRATEGY_H
