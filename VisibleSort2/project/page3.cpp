#include "page3.h"
#include "ui_page3.h"
#include <painter.h>

Page3::Page3(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Page3) {

    ui->setupUi(this);
    this->setMinimumSize(1200, 900);
    this->visible_3 = new Visible3;
    this->painter = new Painter(visible_3->getArray(), this);
    this->painter->setGeometry(0, 0, this->width(), this->height() - 150);
    painter->update();

    connect(&visible_3->getArray(), &ArrayToSort::UpdatePainter, this, &Page3::updatePainter);
    connect(visible_3, &Visible3::stepCompleted, this, &Page3::updatePainter);

    connect(this, &Page3::sortRequested, visible_3, &Visible3::DoSort);
    connect(visible_3, &Visible3::sortStarted, this, &Page3::disableButtons);
    connect(visible_3, &Visible3::sortFinished, this, &Page3::activateButtons);

    connect(ui->nextStep, &QPushButton::clicked, this, &Page3::executeSortStep);  // 连接信号到槽 // 假设有一个按钮用于执行下一步排序
}

void Page3::resizeEvent(QResizeEvent *event) {
    QMainWindow::resizeEvent(event); // 调用基类的 resizeEvent
    if (this->painter) {
        this->painter->setGeometry(0, 0, this->width(), this->height() - 150);
    }
    // 获取窗口的新尺寸
    int width = this->width();
    int height = this->height();
    QPushButton *buttonShuffle = findChild<QPushButton*>("ButtonShuffle");
    buttonShuffle->move(300, this->height() - buttonShuffle->height() - 60);
    QPushButton *BackButton = findChild<QPushButton*>("BackButton");
    BackButton->move(this->width()-BackButton->width()-40, this->height() - BackButton->height() - 60);
    QPushButton *Button9_Radix = findChild<QPushButton*>("Button9_Radix");
    Button9_Radix->move(width-Button9_Radix->width()-131, height- Button9_Radix->height() - 60);
    QPushButton *Button8_Merge = findChild<QPushButton*>("Button8_Merge");
    Button8_Merge->move(width-Button8_Merge->width()-222, height- Button8_Merge->height() - 60);
    QPushButton *Button7_Heap = findChild<QPushButton*>("Button7_Heap");
    Button7_Heap->move(width-Button7_Heap->width()-313, height- Button7_Heap->height() - 60);
    QPushButton *Button6_Selection = findChild<QPushButton*>("Button6_Selection");
    Button6_Selection->move(width-Button6_Selection->width()-404, height- Button6_Selection->height() - 60);
    QPushButton *Button5_Quick = findChild<QPushButton*>("Button5_Quick");
    Button5_Quick->move(width-Button5_Quick->width()-40, height- Button5_Quick->height() - 111);
    QPushButton *Button4_Bubble = findChild<QPushButton*>("Button4_Bubble");
    Button4_Bubble->move(width-Button5_Quick->width()-131, height- Button5_Quick->height() - 111);
    QPushButton *Button3_Shell = findChild<QPushButton*>("Button3_Shell");
    Button3_Shell->move(width-Button5_Quick->width()-222, height- Button5_Quick->height() - 111);
    QPushButton *Button2_Binary = findChild<QPushButton*>("Button2_Binary");
    Button2_Binary->move(width-Button5_Quick->width()-313, height- Button5_Quick->height() - 111);
    QPushButton *Button1_Insert = findChild<QPushButton*>("Button1_Insert");
    Button1_Insert->move(width-Button1_Insert->width()-404, height- Button1_Insert->height() - 111);
    QPushButton *nextStep = findChild<QPushButton*>("nextStep");
    nextStep->move(300, this->height() - buttonShuffle->height() - 100);
}


Page3::~Page3()
{
    delete ui;
    delete visible_3;
    delete painter;
}

void Page3::on_BackButton_clicked()
{
    this->hide();
    emit back();
}
void Page3::on_ButtonShuffle_clicked()
{
    visible_3->getArray().ShuffleArray();
}


void Page3::on_Button1_Insert_clicked() {
    emit sortRequested(Visible3::INSERT);
}

void Page3::on_Button2_Binary_clicked() {
    emit sortRequested(Visible3::BINARY);
}

void Page3::on_Button3_Shell_clicked() {
    emit sortRequested(Visible3::SHELL);
}

void Page3::on_Button4_Bubble_clicked() {
    emit sortRequested(Visible3::BUBBLE);
}

void Page3::on_Button5_Quick_clicked() {
    emit sortRequested(Visible3::QUICK);
}

void Page3::on_Button6_Selection_clicked() {
    emit sortRequested(Visible3::SELECTION);
}

void Page3::on_Button7_Heap_clicked() {
    emit sortRequested(Visible3::HEAP);
}

void Page3::on_Button8_Merge_clicked() {
    emit sortRequested(Visible3::MERGE);
}

void Page3::on_Button9_Radix_clicked() {
    emit sortRequested(Visible3::RADIX);
}

void Page3::executeSortStep() {
    visible_3->stepSort();
    painter->update();
}

 void Page3::color(int i) {
     painter->PushColored(i);
}

 void Page3::color(int i, int j) {
     if (i > j) std::swap(i, j);
    painter->PushColored(i);
     painter->PushColored(j);
 }

void Page3::updatePainter() {
    painter->update();
}

void Page3::activateButtons() {
    ui->Button1_Insert->setEnabled(true);
    ui->Button2_Binary->setEnabled(true);
    ui->Button3_Shell->setEnabled(true);
    ui->Button4_Bubble->setEnabled(true);
    ui->Button5_Quick->setEnabled(true);
    ui->Button6_Selection->setEnabled(true);
    ui->Button7_Heap->setEnabled(true);
    ui->Button8_Merge->setEnabled(true);
    ui->Button9_Radix->setEnabled(true);
}

void Page3::startSort(int type) {
    emit sortRequested(static_cast<Visible3::SortType>(type));
}
void Page3::disableButtons() {


    ui->Button1_Insert->setEnabled(false);
    ui->Button2_Binary->setEnabled(false);
    ui->Button3_Shell->setEnabled(false);
    ui->Button4_Bubble->setEnabled(false);
    ui->Button5_Quick->setEnabled(false);
    ui->Button6_Selection->setEnabled(false);
    ui->Button7_Heap->setEnabled(false);
    ui->Button8_Merge->setEnabled(false);
    ui->Button9_Radix->setEnabled(false);
}

