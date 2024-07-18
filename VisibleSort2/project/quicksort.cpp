#include "QuickSort.h"
#include <QThread>
#include <QTimer>

QuickSort::QuickSort(ArrayToSort &arr) :array(arr)
{
}

void QuickSort::startSort()
{
    // QThread *thread = new QThread;
    // this->moveToThread(thread);

    // connect(thread, &QThread::started, this, &QuickSort::runSort);
    // connect(this, &QuickSort::finished, thread, &QThread::quit);
    // connect(thread, &QThread::finished, thread, &QThread::deleteLater);

    // thread->start();
    array.sortstats.reset();
    array.sortstats.startTiming();
    runSort();
    array.sortstats.stopTiming();
    emit finished();
}

void QuickSort::runSort()
{


    int n = array.GetSize();
    _Qsort(0, n - 1);

    emit finished();
}

int QuickSort::Partition(int s, int t)
{
    int i = s, j = t;
    int base = array.get(s);
    while (i < j) {
        while (j > i && array.get(j) > base)
            j--;
        if (j > i) {
            array.set(array.get(j), i);
            i++;
        }

        while (i < j && array.get(i) <= base)
            i++;
        if (i < j) {
            array.set(array.get(i), j);
            j--;
        }

    }
    array.set(base, i);

    return i;
}

void QuickSort::_Qsort(int s, int t)
{
    if (s < t) {
        int i = Partition(s, t);
        _Qsort(s, i - 1);
        _Qsort(i + 1, t);
    }
}
