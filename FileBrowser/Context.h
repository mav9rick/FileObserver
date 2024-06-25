#ifndef CONTEXT_H
#define CONTEXT_H
#include <QString>
#include <QMap>
#include <QPair>
#include "Strategy.h"
#include <windows.h>
#include <memory>
using namespace std;
class Context
{
public:
    Context(unique_ptr<Strategy> st) : strategy(move(st)) {};
    void set(unique_ptr<Strategy> str)
    {
        this->strategy = move(str);
    }
    int calculate(const QDir& dir, QMap<QString, int>& fileSizesByType)
    {
        return strategy->Calculate(dir,fileSizesByType);
    }
private:
    unique_ptr<Strategy> strategy;
};

#endif // CONTEXT_H
