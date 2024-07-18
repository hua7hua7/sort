#include "ShellSort.h"
#include <QThread>
#include <QTimer>

ShellSort::ShellSort(ArrayToSort &arr) :array(arr)
{
}

void ShellSort::startSort()
{
    //QThread *thread = new QThread;
    //this->moveToThread(thread);

    //connect(thread, &QThread::started, this, &ShellSort::runSort);
    //connect(this, &ShellSort::finished, thread, &QThread::quit);
    //connect(thread, &QThread::finished, thread, &QThread::deleteLater);

    //thread->start();

    array.sortstats.reset();
    array.sortstats.startTiming();
    runSort();
    array.sortstats.stopTiming();
    emit finished();
}

void ShellSort::runSort()
{


    int n = array.GetSize();
    int d = n / 2;
    while (d > 0) {
        for (int i = d; i < n; i++) {
            if (array.compare(i, i-d)) {
                int temp = array.get(i);
                int j = i - d;
                do {
                    array.set(array.get(j), j + d);
                    j -= d;



                } while (j >= 0 && array.get(j) > temp);
                array.set(temp, j + d);
            }

        }
        d = d / 2;
    }


    emit finished();
}
