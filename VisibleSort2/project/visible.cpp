#include "visible.h"
#include <iostream>
#include "QThread"
#include "arraytosort.h"

Visible::Visible(){
    QThread* sub = new QThread;
    this->moveToThread(sub);
    sub->start();

    insertSort = new InsertSort(array);
    binarySort = new BinarySort(array);
    shellSort = new ShellSort(array);
    bubbleSort = new BubbleSort(array);
    quickSort = new QuickSort(array);
    selectionSort = new SelectionSort(array);
    heapSort = new HeapSort(array);
    mergeSort = new MergeSort(array);
    radixSort = new RadixSort(array);
}

Visible::~Visible() {

    delete insertSort;
    delete binarySort;
    delete shellSort;
    delete bubbleSort;
    delete quickSort;
    delete selectionSort;
    delete heapSort;
    delete mergeSort;
    delete radixSort;

}

ArrayToSort& Visible::getArray() {
    return array;
}

void Visible::DoSort(SortType type) {

    emit sortStarted();
    // 测试是否做到了多线程
    //qDebug() << "Current thread" << QThread::currentThread();

    switch (type) {
    case INSERT:
        insertSort->startSort();
        break;
    case BINARY:
        binarySort->startSort();
        break;
    case SHELL:
        shellSort->startSort();
        break;
    case BUBBLE:
        bubbleSort->startSort();
        break;
    case QUICK:
        quickSort->startSort();
        break;
    case SELECTION:
        selectionSort->startSort();
        break;
    case HEAP:
        heapSort->startSort();
        break;
    case MERGE:
        mergeSort->startSort();
        break;
    case RADIX:
        radixSort->startSort();
        break;
    default:
        std::cerr << "Error Occurred at DoSort...\\n";
    }

    emit sortFinished();
}
