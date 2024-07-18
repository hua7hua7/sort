#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <QObject>
#include "arraytosort.h"

class BubbleSort : public QObject
{
    Q_OBJECT

public:
    BubbleSort(ArrayToSort& arr);
    void startSort();

signals:
    void finished();

private:
    ArrayToSort &array;

private slots:
    void runSort();
};

#endif // BUBBLESORT_H
