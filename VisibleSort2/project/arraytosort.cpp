#include "ArrayToSort.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <ctime>
#include <QThread>
#include <Qpainter>
#include <QDebug>

ArrayToSort::ArrayToSort()
{
    this->n = 100;
    this->arr.resize(100);
    InitArray();

    this->setFixedSize(1200, 580);
}

ArrayToSort::ArrayToSort(int num) : n(num)
{
    this->arr.resize(num);
}

void ArrayToSort::InitArray()
{
    for (int i = 0; i < n; i++) {
        this->arr[i] = i + 1;
    }
}

void ArrayToSort::SetArray(){
    // 待更新
}

int ArrayToSort::GetSize(){
    return n;
}

void ArrayToSort::SetSize(int num)
{
    this->arr.resize(num);
    this->n = num;
    InitArray();
    Update();
}

void ArrayToSort::ShuffleArray()
{
    std::shuffle(this->arr.begin(), this->arr.end(), std::default_random_engine(static_cast<unsigned>(time(nullptr))));
    Update();
}

std::vector<int> & ArrayToSort::getarray()
{
    return arr;
}

int ArrayToSort::get(int i)
{
    //qDebug() << "get";
    if (i < 0 || i >= n) {
        std::cerr << "Got Error when using function 'get':\n";
        std::cerr << "Index out of range...\n";
        return 0;
    } else {
        sortstats.incrementGets();
        emit color(i);
        Update();
        return this->arr[i];
    }
}

void ArrayToSort::set(int temp, int i)
{
    //qDebug() << "set";
    if (i < 0 || i >= n) {
        std::cerr << "Got Error when using function 'set':\n";
        std::cerr << "Index out of range...\n";
    } else {
        this->arr[i] = temp;
        sortstats.incrementSets();
        emit color(i);
        Update();
    }
}

bool ArrayToSort::compare(int i, int j)
{
    sortstats.incrementComparisons();
    emit color(i, j);
    Update();
    return arr[i] < arr[j];
}

void ArrayToSort::swap(int i, int j)
{
    //qDebug() << "swap";
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    sortstats.incrementSwaps();
    emit color(i, j);
    Update();
}

void ArrayToSort::Print()
{
    qDebug() << "The size N: " << this->n << "  ";
    qDebug() << "The actual Size: " << arr.size() << "\n";
    qDebug() << "The elements of array:";
    for(auto &a: arr){
        qDebug() << a << " ";
    }
    qDebug() << "\n";
}

void ArrayToSort::setDelay(int num)
{
    delay = num;
}

void ArrayToSort::Update()
{
    // 下两行为新增的，试图一边sort一边更新
    QThread::usleep(delay);
    emit ArrayToSort::UpdatePainter();
}
