#include "BinarySort.h"
#include <QThread>
#include <QTimer>

BinarySort::BinarySort(ArrayToSort &arr) : array(arr)
{
}

void BinarySort::startSort()
{
    // QThread *thread = new QThread;
    // this->moveToThread(thread);

    // connect(thread, &QThread::started, this, &BinarySort::runSort);
    // connect(this, &BinarySort::finished, thread, &QThread::quit);
    // connect(thread, &QThread::finished, thread, &QThread::deleteLater);

    // thread->start();

    array.sortstats.reset();
    array.sortstats.startTiming();
    runSort();
    array.sortstats.stopTiming();
    emit finished();
}

void BinarySort::runSort()
{
    int n = array.GetSize();
    for (int i = 1; i < n; i++) {
        if (array.compare(i, i-1)) {
            int temp = array.get(i);
            int low = 0, high = i - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (array.compare(i, mid))
                    high = mid - 1;
                else
                    low = mid + 1;
            }

            for (int j = i - 1; j >= high + 1; j--) {
                array.set(array.get(j), j + 1);


            }
            array.set(temp, high + 1);
        }
    }
}
