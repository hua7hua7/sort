#include "visible3.h"

Visible3::Visible3()
    : sortAlgorithms(new SortAlgorithms(array, this)) {
    connect(sortAlgorithms, &SortAlgorithms::finished, this, &Visible3::sortFinished);
    connect(sortAlgorithms, &SortAlgorithms::stepCompleted, this, &Visible3::stepCompleted);
}

Visible3::~Visible3() {
    delete sortAlgorithms;

}

void Visible3::DoSort(SortType type) {
    emit sortStarted();
    currentSortType = type;

    switch (type) {
    case INSERT:
        sortAlgorithms->startInsertSort();
        break;
    case BINARY:
        sortAlgorithms->startBinarySort();
        break;
    case SHELL:
        sortAlgorithms->startShellSort();
        break;
    case BUBBLE:
        sortAlgorithms->startBubbleSort();
        break;
    case QUICK:
        sortAlgorithms->startQuickSort();
        break;
    case SELECTION:
        sortAlgorithms->startSelectionSort();
        break;
    case HEAP:
        sortAlgorithms->startHeapSort();
        break;
    case MERGE:
        sortAlgorithms->startMergeSort();
        break;
    case RADIX:
        sortAlgorithms->startRadixSort();
        break;
    default:
        break;
    }
}

void Visible3::stepSort() {
    switch (currentSortType) {
    case INSERT:
        sortAlgorithms->runInsertSort();
        break;
    case BINARY:
        sortAlgorithms->runBinarySort();
        break;
    case SHELL:
        sortAlgorithms->runShellSort();
        break;
    case BUBBLE:
        sortAlgorithms->runBubbleSort();
        break;
    case QUICK:
        sortAlgorithms->runQuickSort();
        break;
    case SELECTION:
        sortAlgorithms->runSelectionSort();
        break;
    case HEAP:
        sortAlgorithms->runHeapSort();
        break;
    case MERGE:
        sortAlgorithms->runMergeSort();
        break;
    case RADIX:
        sortAlgorithms->runRadixSort();
        break;
    default:
        break;
    }
}
ArrayToSort& Visible3::getArray() {
    return array;
}

