#include "painter.h"
#include "qpainter.h"
#include <QDebug>
#include <QVBoxLayout>

Painter::Painter(ArrayToSort &arr, QWidget *parent)
    : QWidget(parent), array(arr.getarray())
{
    setAttribute(Qt::WA_TranslucentBackground);
}

Painter::~Painter()
{
}

void Painter::SetArray(std::vector<int> arr)
{
    this->array = arr;
}

void Painter::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    // 使用你的绘图函数
    PaintArray(painter);

    // 测试计数

    /*static int times = 0;
    times++;
    qDebug() << "Paint Event started"
             << " Event times:" << times;*/
}

void Painter::PushColored(int i)
{
    colored.push(i);
}

void Painter::PaintArray(QPainter &painter)
{
    // 绘制白色背景
    painter.setBrush(Qt::white);
    painter.setPen(Qt::NoPen);
    painter.drawRect(0, 0, this->width(), this->height());

    // 计算画布的有效显示区域
    int effectiveHeight = this->height() - 40; // 上下各留20像素边距
    int effectiveWidth = this->width() - 40;   // 两侧各留20像素边距

    // 获取数组的长度
    int n = array.size(); // 使用getArray()来获取数组长度
    int totalWidthOfBlocks = n * 10 + (n - 1) * 1;
    // 计算每个矩形的宽度和高度比例
    int maxElementValue = n; // 找到数组中的最大值
    int maxHeight = maxElementValue * (this->height() / 185); // 原始最大高度，基于数组最大值乘以按照窗口的最大值计算出的比例
    int scaleFactor = std::min(
        (effectiveHeight - 20) / maxHeight, // 垂直方向的缩放，保持底部对齐
        (effectiveWidth - 100) / (n * 10) // 水平方向的缩放，基于矩形数量和每两个矩形之间的间隔
    );

    // 计算矩形框的左半边位置，使它们居中
    int left_border = (effectiveWidth - totalWidthOfBlocks) / 2;
    // 绘制黑色的矩形框

    painter.setPen(Qt::NoPen);
    for (int i = 0; i < n; i++)
    {
        // 根据队列里的数据决定柱子的颜色
        if(!colored.empty() && i==colored.front()){
            painter.setBrush(Qt::red);
            colored.pop();
        }
        else{
            painter.setBrush(Qt::black);
        }

        // 根据数组元素值和缩放因子计算矩形的高度
        int originalHeight = array[i] * (this->height() / 185);
        int scaledHeight = std::min(originalHeight * scaleFactor, effectiveHeight - 20);

        // 计算每个矩形的位置并绘制
        painter.drawRect(
            left_border + i * (10 + 1), // 宽度为10，间隔为1
            effectiveHeight - scaledHeight - 85, // 保持底部在同一水平线
            10,
            scaledHeight
        );
    }
}
//用于修改标记
void Painter::markSorted()
{
    allSorted = true; // 标记排序完成
    update(); // 更新界面显示
}
