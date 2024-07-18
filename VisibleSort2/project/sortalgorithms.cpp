#include "SortAlgorithms.h"
#include <QThread>
#include <QTimer>

SortAlgorithms::SortAlgorithms(ArrayToSort &arr, QObject *parent)
    : QObject(parent), array(arr), currentStep(0), i(0), j(0), key(0) {
}

void SortAlgorithms::startInsertSort() {
    array.sortstats.reset();
    array.sortstats.startTiming();
    currentStep = 1;
    QTimer::singleShot(0, this, &SortAlgorithms::runInsertSort);
}

void SortAlgorithms::runInsertSort() {
    int n = array.GetSize();
    if (currentStep >= n) {
        array.sortstats.stopTiming();
        emit finished();
        return;
    }

    if (j >= 0 && array.get(j) > key) {
        array.set(array.get(j), j + 1);
        j--;
    } else {
        array.set(key, j + 1);
        currentStep++;
        if (currentStep < n) {
            key = array.get(currentStep);
            j = currentStep - 1;
        }
    }

    emit stepCompleted();

    // 不自动调用下一步，让外部控制
    // QTimer::singleShot(0, this, &SortAlgorithms::runInsertSort);
}

 void SortAlgorithms::startBinarySort() {
     array.sortstats.reset();
     array.sortstats.startTiming();
     currentStep = 1;
     QTimer::singleShot(0, this, &SortAlgorithms::runBinarySort);
}

 void SortAlgorithms::runBinarySort() {
     int n = array.GetSize();
if (currentStep >= n) {
    array.sortstats.stopTiming();
    emit finished();
    return;
}

if (j >= 0 && array.get(j) > key) {
    array.set(array.get(j), j + 1);
    j--;
} else {
    array.set(key, j + 1);
    currentStep++;
    if (currentStep < n) {
        key = array.get(currentStep);
        j = currentStep - 1;
    }
}

emit stepCompleted();
}

void SortAlgorithms::startShellSort() {
        array.sortstats.reset();
array.sortstats.startTiming();
currentStep = 1;
QTimer::singleShot(0, this, &SortAlgorithms::runShellSort);
 }

void SortAlgorithms::runShellSort() {
    int n = array.GetSize();
    if (currentStep >= n) {
        array.sortstats.stopTiming();
        emit finished();
        return;
    }

    if (j >= 0 && array.get(j) > key) {
        array.set(array.get(j), j + 1);
        j--;
    } else {
        array.set(key, j + 1);
        currentStep++;
        if (currentStep < n) {
            key = array.get(currentStep);
            j = currentStep - 1;
        }
    }

    emit stepCompleted();
    }


 void SortAlgorithms::startBubbleSort() {
     array.sortstats.reset();
     array.sortstats.startTiming();
     currentStep = 1;
     QTimer::singleShot(0, this, &SortAlgorithms::runBubbleSort);
}

void SortAlgorithms::runBubbleSort() {
    int n = array.GetSize();
    if (currentStep >= n) {
        array.sortstats.stopTiming();
        emit finished();
        return;
    }

    if (j >= 0 && array.get(j) > key) {
        array.set(array.get(j), j + 1);
        j--;
    } else {
        array.set(key, j + 1);
        currentStep++;
        if (currentStep < n) {
            key = array.get(currentStep);
            j = currentStep - 1;
        }
    }

    emit stepCompleted();
}

 void SortAlgorithms::startQuickSort() {
     array.sortstats.reset();
     array.sortstats.startTiming();
     currentStep = 1;
     QTimer::singleShot(0, this, &SortAlgorithms::runQuickSort);
 }

void SortAlgorithms::runQuickSort() {
    int n = array.GetSize();
    if (currentStep >= n) {
        array.sortstats.stopTiming();
        emit finished();
        return;
    }

    if (j >= 0 && array.get(j) > key) {
        array.set(array.get(j), j + 1);
        j--;
    } else {
        array.set(key, j + 1);
        currentStep++;
        if (currentStep < n) {
            key = array.get(currentStep);
            j = currentStep - 1;
        }
    }

    emit stepCompleted();
 }



void SortAlgorithms::startSelectionSort() {
    array.sortstats.reset();
    array.sortstats.startTiming();
    currentStep = 1;
    QTimer::singleShot(0, this, &SortAlgorithms::runSelectionSort);
 }

 void SortAlgorithms::runSelectionSort() {
     int n = array.GetSize();
     if (currentStep >= n) {
         array.sortstats.stopTiming();
         emit finished();
         return;
     }

     if (j >= 0 && array.get(j) > key) {
         array.set(array.get(j), j + 1);
         j--;
     } else {
         array.set(key, j + 1);
         currentStep++;
         if (currentStep < n) {
             key = array.get(currentStep);
             j = currentStep - 1;
         }
     }

     emit stepCompleted();
   }



 void SortAlgorithms::startHeapSort() {
 array.sortstats.reset();
 array.sortstats.startTiming();
 currentStep = 1;
 QTimer::singleShot(0, this, &SortAlgorithms::runHeapSort);
}

 void SortAlgorithms::runHeapSort() {
     int n = array.GetSize();
     if (currentStep >= n) {
         array.sortstats.stopTiming();
         emit finished();
         return;
     }

     if (j >= 0 && array.get(j) > key) {
         array.set(array.get(j), j + 1);
         j--;
     } else {
         array.set(key, j + 1);
         currentStep++;
         if (currentStep < n) {
             key = array.get(currentStep);
             j = currentStep - 1;
         }
     }

     emit stepCompleted();
    }



 void SortAlgorithms::startMergeSort() {
     array.sortstats.reset();
     array.sortstats.startTiming();
     currentStep = 1;
     QTimer::singleShot(0, this, &SortAlgorithms::runMergeSort);
}

void SortAlgorithms::runMergeSort() {
    int n = array.GetSize();
    if (currentStep >= n) {
        array.sortstats.stopTiming();
        emit finished();
        return;
    }

    if (j >= 0 && array.get(j) > key) {
        array.set(array.get(j), j + 1);
        j--;
    } else {
        array.set(key, j + 1);
        currentStep++;
        if (currentStep < n) {
            key = array.get(currentStep);
            j = currentStep - 1;
        }
    }

    emit stepCompleted();
}



void SortAlgorithms::startRadixSort() {
array.sortstats.reset();
array.sortstats.startTiming();
currentStep = 1;
QTimer::singleShot(0, this, &SortAlgorithms::runRadixSort);
 }

 void SortAlgorithms::runRadixSort() {
     int n = array.GetSize();
     if (currentStep >= n) {
         array.sortstats.stopTiming();
         emit finished();
         return;
     }

     if (j >= 0 && array.get(j) > key) {
         array.set(array.get(j), j + 1);
         j--;
     } else {
         array.set(key, j + 1);
         currentStep++;
         if (currentStep < n) {
             key = array.get(currentStep);
             j = currentStep - 1;
         }
     }

     emit stepCompleted();
}


