#include "HeapSort.h"
#include <QThread>
#include <QTimer>

HeapSort::HeapSort(ArrayToSort &arr) :array(arr)
{
}

void HeapSort::startSort()
{
    // QThread *thread = new QThread;
    // this->moveToThread(thread);

    // connect(thread, &QThread::started, this, &HeapSort::runSort);
    // connect(this, &HeapSort::finished, thread, &QThread::quit);
    // connect(thread, &QThread::finished, thread, &QThread::deleteLater);

    // thread->start();
    array.sortstats.reset();
    array.sortstats.startTiming();
    runSort();
    array.sortstats.stopTiming();
    emit finished();
}

void HeapSort::runSort()
{

    int n = array.GetSize();
    for (int i = n / 2 - 1; i >= 0; i--) {
        shiftDown(i, n - 1);
    }
    for (int i = n - 1; i > 0; i--) {
        array.swap(0, i);
        shiftDown(0, i - 1);
    }

    emit finished();
}

void HeapSort::shiftDown(int low, int high)
{
    int i = low;
    int j = 2 * i + 1;
    int temp = array.get(i);
    while (j <= high) {
        if (j < high && array.compare(j, j+1)) {
            j++;
        }
        if (temp < array.get(j)) {
            array.set(array.get(j), i);

            i = j;
            j = 2 * i + 1;
        } else {
            break;
        }
    }
    array.set(temp, i);
}
