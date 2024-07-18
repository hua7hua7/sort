#ifndef PAINTER_H
#define PAINTER_H

#include <QWidget>
#include "arraytosort.h"
#include "qpainter.h"
#include <vector>
#include <queue>

namespace Ui {
class Painter;
}

class Painter : public QWidget
{
    Q_OBJECT

public:
    explicit Painter(ArrayToSort &arr, QWidget *parent = nullptr);
    ~Painter();

    void SetArray(std::vector<int> arr);

    void PushColored(int i);
    void markSorted();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::Painter *ui;

    std::vector<int> &array;

    int delay = 5;

    void PaintArray(QPainter &painter);

    std::queue<int> colored;
    //新增标记指示所有数组是否排序完成。
    bool allSorted= false;
};

#endif // PAINTER_H
