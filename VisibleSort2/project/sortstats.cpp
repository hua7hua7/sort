#include "sortstats.h"
#include "qdebug.h"
#include <chrono>

SortStats::SortStats()
{
    reset();
}

void SortStats::reset()
{
    this->elapsedTime = 0;
    this->getTimes = 0;
    this->setTimes = 0;
    this->swapTimes = 0;
    this->compareTimes = 0;
}

void SortStats::startTiming() {
    startTime = std::chrono::duration_cast<std::chrono::microseconds>(
                    std::chrono::high_resolution_clock::now().time_since_epoch()
                    ).count();
}

void SortStats::stopTiming() {
    double endTime = std::chrono::duration_cast<std::chrono::microseconds>(
                         std::chrono::high_resolution_clock::now().time_since_epoch()
                         ).count();
    elapsedTime += (endTime - startTime) / 1000.0; // Convert to milliseconds
}

void SortStats::incrementGets()
{
    getTimes++;
}

void SortStats::incrementSets()
{
    setTimes++;
}

void SortStats::incrementComparisons()
{
    compareTimes++;
    getTimes += 2;
}

void SortStats::incrementSwaps()
{
    swapTimes++;
    getTimes += 2;
    setTimes += 2;
}

int SortStats::getGetTimes() const
{
    return getTimes;
}

int SortStats::getSetTimes() const
{
    return setTimes;
}

int SortStats::getCompTimes() const
{
    return compareTimes;
}

int SortStats::getSwapTimes() const
{
    return swapTimes;
}

double SortStats::getElapsedTime() const {
    return elapsedTime;
}

void SortStats::Print()
{
    qDebug() << "Current State:";
    qDebug() << "Gets: " << getTimes;
    qDebug() << "Sets: " << setTimes;
    qDebug() << "Compares: " << compareTimes;
    qDebug() << "Swaps: " << swapTimes;
    qDebug() << "Time recorded" << elapsedTime;
    qDebug() << "";
}
