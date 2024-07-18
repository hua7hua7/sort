// ChartWidget.cpp
#include "ChartWidget.h"
#include <QPainter>
#include <algorithm>

ChartWidget::ChartWidget(QWidget *parent) : QWidget(parent)
{
    //    // 初始化 ChartWidget 并添加到布局中
    //    chartWidget = new ChartWidget(this);
    //    QVBoxLayout *layout = new QVBoxLayout(this);
    //    layout->addWidget(chartWidget);
    //    layout->setMargin(0);
    //    setLayout(layout);
}

void ChartWidget::updateStats(const std::vector<SortStats>& newStats) {
    stats = newStats;
    update();
}

void ChartWidget::paintEvent(QPaintEvent *event) {
    /*
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setBrush(Qt::white);
    painter.drawRect(0, 0, this->width(), this->height());

    if (stats.empty()) return;

    int n = stats.size();
    int maxTime = std::max_element(stats.begin(), stats.end(), [](const SortStats& a, const SortStats& b) {
        return a.getElapsedTime() < b.getElapsedTime();
    })->getElapsedTime();

    int maxComparisons = std::max_element(stats.begin(), stats.end(), [](const SortStats& a, const SortStats& b) {
        return a.getComparisons() < b.getComparisons();
    })->getComparisons();

    int maxMoves = std::max_element(stats.begin(), stats.end(), [](const SortStats& a, const SortStats& b) {
        return a.getMoves() < b.getMoves();
    })->getMoves();

    int barWidth = this->width() / (3 * n);

    for (int i = 0; i < n; ++i) {
        int heightTime = stats[i].getElapsedTime() / maxTime * this->height() * 0.8;
        int heightComparisons = stats[i].getComparisons() / maxComparisons * this->height() * 0.8;
        int heightMoves = stats[i].getMoves() / maxMoves * this->height() * 0.8;

        painter.setBrush(Qt::blue);
        painter.drawRect(i * 3 * barWidth, this->height() - heightTime, barWidth, heightTime);
        painter.setBrush(Qt::red);
        painter.drawRect(i * 3 * barWidth + barWidth, this->height() - heightComparisons, barWidth, heightComparisons);
        painter.setBrush(Qt::green);
        painter.drawRect(i * 3 * barWidth + 2 * barWidth, this->height() - heightMoves, barWidth, heightMoves);

        painter.setPen(Qt::black);
        painter.drawText(i * 3 * barWidth, this->height() - heightTime - 10, stats[i].getName());
    }*/
}
