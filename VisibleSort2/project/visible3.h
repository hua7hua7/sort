#ifndef VISIBLE3_H
#define VISIBLE3_H

#include <QObject>
#include "arraytosort.h"
#include"sortalgorithms.h"
class Visible3 : public QObject

{
    Q_OBJECT
public:
public:
    Visible3();
    ~Visible3();

    enum SortType { INSERT
                     , BINARY, SHELL, BUBBLE, QUICK
                     , SELECTION, HEAP, MERGE, RADIX };
    void DoSort(SortType type);
    void stepSort();

    ArrayToSort& getArray();
    ArrayToSort array;

signals:
    void sortStarted();
    void sortFinished();
    void stepCompleted();

private:
SortAlgorithms *sortAlgorithms;
    SortType currentSortType;
    bool sorting;
};

#endif // VISIBLE3_H
