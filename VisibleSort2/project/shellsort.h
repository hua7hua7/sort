#ifndef SHELLSORT_H
#define SHELLSORT_H

#include <QObject>
#include "arraytosort.h"
#include <QThread>
#include <QTimer>

class ShellSort : public QObject
{
    Q_OBJECT

public:
    explicit ShellSort(ArrayToSort &arr);

    void startSort();

signals:
    void finished();

private slots:
    void runSort();

private:
    ArrayToSort &array;
};

#endif // SHELLSORT_H
