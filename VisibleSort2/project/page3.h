#ifndef PAGE3_H
#define PAGE3_H

#include <QWidget>
#include "ChartWidget.h"
#include "visible3.h"
#include <QMainWindow>
#include <QMessageBox>
#include<QPushButton>
#include <QTimer>
#include "painter.h"
#include "arraytosort.h"

namespace Ui {
class Page3;
}

class Page3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Page3(QWidget *parent = nullptr);
    void resizeEvent(QResizeEvent *event) override;
    ~Page3();

signals:
    void back();
    void sortRequested(Visible3::SortType type);
private slots:
    void on_BackButton_clicked();
    void on_Button1_Insert_clicked();
    void on_Button2_Binary_clicked();
    void on_Button3_Shell_clicked();
    void on_Button4_Bubble_clicked();
    void on_Button5_Quick_clicked();
    void on_Button6_Selection_clicked();
    void on_Button7_Heap_clicked();
    void on_Button8_Merge_clicked();
    void on_Button9_Radix_clicked();
     void on_ButtonShuffle_clicked();
    void startSort(int type);
    void executeSortStep();
    void updatePainter();
    void disableButtons();
    void activateButtons();
private:
    Ui::Page3 *ui;
    Visible3 *visible_3 = NULL;
    ChartWidget *chartwidget = NULL;
    ArrayToSort array;
    QTimer *timer;
    int currentStep;
    int sortType;
    void color(int i);
    void color(int i, int j);
    Painter *painter = NULL;
};


#endif // PAGE3_H
