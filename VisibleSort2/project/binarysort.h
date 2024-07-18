#ifndef BINARYSORT_H
#define BINARYSORT_H

#include <QObject>
#include "arraytosort.h"

class BinarySort : public QObject
{
    Q_OBJECT

public:
    explicit BinarySort(ArrayToSort &arr);

    void startSort();

signals:
    void finished();

private:
    ArrayToSort &array;

private slots:
    void runSort();
};

#endif // BINARYSORT_H
