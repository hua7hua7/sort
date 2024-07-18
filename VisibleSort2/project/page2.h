#ifndef PAGE2_H
#define PAGE2_H
//#include "visible.h"
#include "ChartWidget.h"
#include "visible2.h"
#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class Page2;
}

class Page2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Page2(QWidget *parent = nullptr);
  //  void resizeEvent(QResizeEvent *event) override;
    ~Page2();

signals:
    void back();

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
private:
    Ui::Page2 *ui;
    Visible2 *visible_2 = NULL;
    ChartWidget *chartwidget = NULL;
};

#endif // PAGE2_H
