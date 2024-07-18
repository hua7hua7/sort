// ChartWidget.h
#ifndef CHARTWIDGET_H
#define CHARTWIDGET_H

#include <QWidget>
#include <vector>
#include "sortstats.h"

class ChartWidget : public QWidget
{
    Q_OBJECT

public:
    ChartWidget(QWidget *parent = nullptr);
    void updateStats(const std::vector<SortStats>& stats);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    std::vector<SortStats> stats;
};

#endif // CHARTWIDGET_H
