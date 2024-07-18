#ifndef ARRAYTOSORT_H
#define ARRAYTOSORT_H

#include "qwidget.h"
#include "sortstats.h"
#include <vector>
#include <QObject>

class ArrayToSort : public QWidget
{
    Q_OBJECT

public:
    ArrayToSort();
    ArrayToSort(int num);

    // 数组的初始化和准备操作
    void InitArray();       // 随机初始化数组（针对有可视化）
    void SetArray();        // 设置数组（针对文件输入）
    int GetSize();
    void SetSize(int num);
    void ShuffleArray();
    std::vector<int> &getarray();

    // 数组的排序操作和基本变量
    int get(int i);
    void set(int temp, int i);
    bool compare(int i, int j);
    void swap(int i, int j);

    // 数组的输出操作
    void Update();  // 提醒系统更新内容
    void Print();   // 测试用输出

    // 用于统计用的计数器
    SortStats sortstats;

    // 用于调整delay，从而调整排序速度
    void setDelay(int num);

signals:
    void color(int i);
    void color(int i, int j);
    void UpdatePainter();

private:
    std::vector<int> arr;   // 存放数组
    int n;  // 数组大小
    int delay = 0;
};

#endif // ARRAYTOSORT_H
