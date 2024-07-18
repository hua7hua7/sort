#include "BubbleSort.h"
#include <QThread>
#include <QTimer>

BubbleSort::BubbleSort(ArrayToSort& arr) : array(arr)
{
}

void BubbleSort::startSort()
{
    //QThread *thread = new QThread;
    //this->moveToThread(thread);

    //connect(thread, &QThread::started, this, &BubbleSort::runSort);
    //connect(this, &BubbleSort::finished, thread, &QThread::quit);
    //connect(thread, &QThread::finished, thread, &QThread::deleteLater);

    //thread->start();

    array.sortstats.reset();
    array.sortstats.startTiming();
    runSort();
    array.sortstats.stopTiming();
    emit finished();
}

void BubbleSort::runSort()
{

    int n = array.GetSize();
    for (int i = 0; i < n - 1; i++) {
        bool exchange = false;
        for (int j = n - 1; j > i; j--) {
            if (array.compare(j, j-1)) {
                // 交换元素
                array.swap(j-1, j);
                exchange = true;
            }

        }
        if (!exchange) break;
    }
    emit finished();
}
