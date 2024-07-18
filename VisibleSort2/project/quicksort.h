#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <QObject>
#include "arraytosort.h"
#include <QThread>
#include <QTimer>

class QuickSort : public QObject
{
    Q_OBJECT

public:
    explicit QuickSort(ArrayToSort &arr);

    void startSort();

signals:
    void finished();

private slots:
    void runSort();

private:
    int Partition(int s, int t);
    void _Qsort(int s, int t);

    ArrayToSort &array;
};

#endif // QUICKSORT_H
