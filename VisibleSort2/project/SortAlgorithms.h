#ifndef SORTALGORITHMS_H
#define SORTALGORITHMS_H

#include "arraytosort.h"

class SortAlgorithms : public QObject {
    Q_OBJECT

public:
    explicit SortAlgorithms(ArrayToSort &array, QObject *parent = nullptr);

    void startInsertSort();
     void startBinarySort();
     void startShellSort();
     void startBubbleSort();
     void startQuickSort();
     void startSelectionSort();
     void startHeapSort();
     void startMergeSort();
    void startRadixSort();

signals:
    void finished();
    void stepCompleted();

private:
    ArrayToSort &array;
    int currentStep;//当前步骤的存储
    int i, j, key;//用于逐步排序的变量
public slots:
    void runInsertSort();
     void runBinarySort();
     void runShellSort();
     void runBubbleSort();
     void runQuickSort();
     void runSelectionSort();
     void runHeapSort();
     void runMergeSort();
     void runRadixSort();
};

#endif // SORTALGORITHMS_H
