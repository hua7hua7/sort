#ifndef SORTSTATS_H
#define SORTSTATS_H

#include <QString>

class SortStats
{
public:
    SortStats();
    void reset();

    // 计时相关函数
    void startTiming();
    void stopTiming();

    // 计次相关函数
    void incrementGets();
    void incrementSets();
    void incrementComparisons();
    void incrementSwaps();

    // 获取相关函数的信息
    int getGetTimes() const;
    int getSetTimes() const;
    int getCompTimes() const;
    int getSwapTimes() const;
    double getElapsedTime() const;
    void Print();
    QString getStats();

private:
    double startTime;
    double elapsedTime;

    int getTimes;
    int setTimes;
    int compareTimes;
    int swapTimes;
};

#endif // SORTSTATS_H
