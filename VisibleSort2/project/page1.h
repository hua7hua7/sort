#ifndef PAGE1_H
#define PAGE1_H

#include <QMainWindow>
#include "painter.h"
#include "visible.h"
#include <QMessageBox>
namespace Ui {
class Page1;
}

class Page1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Page1(QWidget *parent = nullptr);
    void resizeEvent(QResizeEvent *event) override;
    ~Page1();

signals:
    void sortRequested(Visible::SortType type);
    void back();

private slots:
    void on_BackButton_clicked();

    void on_SetSizeButton_clicked();

    void on_SetDelayButton_clicked();

    void on_ButtonShuffle_clicked();

    void on_Button1_Insert_clicked();

    void on_Button2_Binary_clicked();

    void on_Button3_Shell_clicked();

    void on_Button4_Bubble_clicked();

    void on_Button5_Quick_clicked();

    void on_Button6_Selection_clicked();

    void on_Button7_Heap_clicked();

    void on_Button8_Merge_clicked();

    void on_Button9_Radix_clicked();

    void UpdatePainter();

    void color(int i);

    void color(int i, int j);

    // 激活按钮状态，表示可以调整
    void activateButtons();

    // 使按钮失效，表示不可调整
    void disableButtons();

private:
    Ui::Page1 *ui;
    Visible *visible = NULL;
    Painter *painter = NULL;
};

#endif // PAGE1_H
