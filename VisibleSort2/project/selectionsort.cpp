#include "SelectionSort.h"
#include <QThread>
#include <QTimer>

SelectionSort::SelectionSort(ArrayToSort &arr) :array(arr)
{
}

void SelectionSort::startSort()
{
    //QThread *thread = new QThread;
    //this->moveToThread(thread);

    //connect(thread, &QThread::started, this, &SelectionSort::runSort);
    //connect(this, &SelectionSort::finished, thread, &QThread::quit);
    //connect(thread, &QThread::finished, thread, &QThread::deleteLater);

    //thread->start();

    array.sortstats.reset();
    array.sortstats.startTiming();
    runSort();
    array.sortstats.stopTiming();
    emit finished();
}

void SelectionSort::runSort()
{
    int n = array.GetSize();
    for (int i = 0; i < n - 1; i++) {
        int minj = i;
        for (int j = i + 1; j < n; j++) {
            if (array.compare(j, minj))
                minj = j;
        }
        if (minj != i)
            array.swap(i, minj);
    }


    emit finished();
}
