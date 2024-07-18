#ifndef INSERTSORT_H
#define INSERTSORT_H

#include <QObject>
#include "arraytosort.h"

class InsertSort : public QObject
{
    Q_OBJECT

public:
    InsertSort(ArrayToSort &arr);
    void startSort();

signals:
    void finished();

private:

    ArrayToSort &array;

private slots:
    void runSort();
};

#endif // INSERTSORT_H
