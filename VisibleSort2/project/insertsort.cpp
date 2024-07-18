#include "InsertSort.h"
#include <QThread>
#include <QTimer>

InsertSort::InsertSort(ArrayToSort &arr) : array(arr)
{
}

void InsertSort::startSort()
{
    // QThread *thread = new QThread;
    // this->moveToThread(thread);

    // connect(thread, &QThread::started, this, &InsertSort::runSort);
    // connect(this, &InsertSort::finished, thread, &QThread::quit);
    // connect(thread, &QThread::finished, thread, &QThread::deleteLater);

    // thread->start();
    array.sortstats.reset();
    array.sortstats.startTiming();
    runSort();
    array.sortstats.stopTiming();
    emit finished();
}

void InsertSort::runSort()
{


    int n = array.GetSize();
    for (int i = 1; i < n; i++) {
        int key = array.get(i);
        int j = i - 1;
        while (j >= 0 && array.get(j) > key) {
            array.set(array.get(j), j + 1);
            j--;

        }
        array.set(key, j + 1);


    }

    emit finished();
}
