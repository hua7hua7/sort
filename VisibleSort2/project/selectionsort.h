#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <QObject>
#include "arraytosort.h"
#include <QThread>
#include <QTimer>

class SelectionSort : public QObject
{
    Q_OBJECT

public:
    explicit SelectionSort(ArrayToSort &arr);

    void startSort();

signals:
    void finished();

private slots:
    void runSort();

private:
    ArrayToSort &array;
};

#endif // SELECTIONSORT_H
