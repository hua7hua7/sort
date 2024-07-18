#ifndef VISIBLE_H
#define VISIBLE_H

#include "arraytosort.h"
#include "binarysort.h"
#include "bubblesort.h"
#include "heapsort.h"
#include "insertsort.h"
#include "mergesort.h"
#include "quicksort.h"
#include "radixsort.h"
#include "selectionsort.h"
#include "shellsort.h"

#include <QObject>

class Visible: public QObject
{
    Q_OBJECT

public:
    // 构造和析构函数
    Visible();
    //Visible(QWidget *parent);

    ~Visible();

    // 排序函数的接口
    enum SortType{INSERT, BINARY, SHELL, BUBBLE,
                    QUICK, SELECTION, HEAP, MERGE, RADIX};
    void DoSort(SortType type);

    // 返回这个数组
    ArrayToSort& getArray();

    // 可用于访问的排序用ArrayToSort
    ArrayToSort array;

signals:
    void sortStarted();
    void sortFinished();

private:
    // 各个排序算法指针的存放处

    InsertSort    *insertSort       = NULL;
    BinarySort    *binarySort       = NULL;
    ShellSort     *shellSort        = NULL;
    BubbleSort    *bubbleSort       = NULL;
    QuickSort     *quickSort        = NULL;
    SelectionSort *selectionSort    = NULL;
    HeapSort      *heapSort         = NULL;
    MergeSort     *mergeSort        = NULL;
    RadixSort     *radixSort        = NULL;
};

#endif // VISIBLE_H
