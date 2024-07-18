#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <QObject>
#include "arraytosort.h"
#include <QThread>
#include <QTimer>

class HeapSort : public QObject
{
    Q_OBJECT

public:
    explicit HeapSort(ArrayToSort &arr);

    void startSort();

signals:
    void finished();

private slots:
    void runSort();

private:
    void shiftDown(int low, int high);

    ArrayToSort &array;
};

#endif // HEAPSORT_H
