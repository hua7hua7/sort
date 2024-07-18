#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "page1.h"
#include "page2.h"
#include "page3.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Visible_clicked();

    void on_pushButton_input_clicked();

    void on_pushButton_tutor_clicked();

    void BackToMainpage();

    void on_ExitButton_clicked();

private:
    Ui::MainWindow *ui;
    Page1 *p1 = NULL;
    Page2 *p2 = NULL;
    Page3 *p3 = NULL;
};
#endif // MAINWINDOW_H


// MainWindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "SortStats.h"
#include "ChartWidget.h"
#include "QuickSort.h"
// Include other sort headers

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_startButton_clicked();

private:
    Ui::MainWindow *ui;
    ChartWidget *chartWidget;
    ArrayToSort array;
    std::vector<SortStats> stats;
    QuickSort *quickSort;
    // Other sort objects

    void setupStats();
    void startSorts();
};

#endif // MAINWINDOW_H
