#include "page1.h"
#include "ui_page1.h"
#include <painter.h>

Page1::Page1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Page1)
{
    ui->setupUi(this);
    this->setMinimumSize(1200, 900);

    // 本窗口专属的Visible类
    this->visible = new Visible;

    // 调好本窗口Painter及其大小
    this->painter = new Painter(visible->getArray(), this);
    this->painter->setGeometry(0,0,this->width(), this->height()-150);
    this->painter->update();

    // 更新窗口绘制信号的连接
    connect(&this->visible->getArray(), &ArrayToSort::UpdatePainter, this, &Page1::UpdatePainter);
    connect(&this->visible->getArray(), SIGNAL(color(int)), this, SLOT(color(int)));
    connect(&this->visible->getArray(), SIGNAL(color(int, int)), this, SLOT(color(int, int)));

    // 按钮对应的信号槽连接（直接连接）（多线程测试）
    //qDebug() << "Current thread" << QThread::currentThread();
    connect(this, &Page1::sortRequested, visible, &Visible::DoSort);

    // 防止误触的信号连接
    connect(visible, &Visible::sortStarted, this, &Page1::disableButtons);
    connect(visible, &Visible::sortFinished, this, &Page1::activateButtons);

}

void Page1::resizeEvent(QResizeEvent *event) {
    QMainWindow::resizeEvent(event); // 调用基类的 resizeEvent
    if (this->painter) {
        this->painter->setGeometry(0, 0, this->width(), this->height() - 150);
    }
    // 获取窗口的新尺寸
    int width = this->width();
    int height = this->height();
    //所有按钮的位置更新
    QPushButton *SetSizeButton = findChild<QPushButton*>("SetSizeButton");
    SetSizeButton->move(220, this->height() - SetSizeButton->height() - 110);
    QPushButton *buttonShuffle = findChild<QPushButton*>("ButtonShuffle");
    buttonShuffle->move(300, this->height() - buttonShuffle->height() - 80);
    QPushButton *SetDelayButton = findChild<QPushButton*>("SetDelayButton");
    SetDelayButton->move(220, this->height() - SetDelayButton->height() - 80);
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
    Button1_Insert->move(width-Button5_Quick->width()-404, height- Button5_Quick->height() - 111);

    //输入文字框
    QLineEdit *SizeEdit = findChild<QLineEdit*>("SizeEdit");
    SizeEdit->move(155, height - SizeEdit->height() - 110);
    QLineEdit *DelayEdit = findChild<QLineEdit*>("DelayEdit");
    DelayEdit->move(155, height - DelayEdit->height() - 81);
    //文本标签
    QLabel *label_1 = findChild<QLabel*>("label");
    label_1->move(60, height - label_1->height() - 110);
    QLabel *label_2 = findChild<QLabel*>("label_2");
    label_2->move(60, height - label_2->height() - 81);
}
Page1::~Page1()
{
    delete ui;
}

void Page1::on_BackButton_clicked()
{
    this->hide();
    emit back();
}


void Page1::on_SetSizeButton_clicked()
{
    int newSize = ui->SizeEdit->text().toInt();
    if (newSize >= 1 && newSize <= 100) {
        visible->getArray().SetSize(newSize);
    } else {
        QMessageBox::warning(this, "输入错误", "输入值必须在1到100之间！");
    }
}

void Page1::on_SetDelayButton_clicked()
{
    int ndelay = ui->DelayEdit->text().toInt();
    if (ndelay >= 0 && ndelay <= 100) {
        visible->getArray().setDelay(ndelay);
    } else {
        QMessageBox::warning(this, "输入错误", "输入值必须在0到100之间！");
    }
}


void Page1::on_ButtonShuffle_clicked()
{
    visible->getArray().ShuffleArray();
}

void Page1::on_Button1_Insert_clicked()
{
    emit sortRequested(Visible::INSERT);
}

void Page1::on_Button2_Binary_clicked()
{
    emit sortRequested(Visible::BINARY);
}

void Page1::on_Button3_Shell_clicked()
{
    emit sortRequested(Visible::SHELL);
}

void Page1::on_Button4_Bubble_clicked()
{
    emit sortRequested(Visible::BUBBLE);
}

void Page1::on_Button5_Quick_clicked()
{
    emit sortRequested(Visible::QUICK);
}

void Page1::on_Button6_Selection_clicked()
{
    emit sortRequested(Visible::SELECTION);
}

void Page1::on_Button7_Heap_clicked()
{
    emit sortRequested(Visible::HEAP);
}

void Page1::on_Button8_Merge_clicked()
{
    emit sortRequested(Visible::MERGE);
}

void Page1::on_Button9_Radix_clicked()
{
    emit sortRequested(Visible::RADIX);
}

void Page1::color(int i){
    painter->PushColored(i);
}

void Page1::color(int i, int j){
    if(i > j) std::swap(i, j);
    painter->PushColored(i);
    painter->PushColored(j);
}

void Page1::UpdatePainter()
{
    painter->update();
}

void Page1::activateButtons()
{
    ui->ButtonShuffle->setEnabled(true);
    ui->SetSizeButton->setEnabled(true);
    ui->SetDelayButton->setEnabled(true);
    ui->DelayEdit->setEnabled(true);
    ui->SizeEdit->setEnabled(true);

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

void Page1::disableButtons()
{
    ui->ButtonShuffle->setEnabled(false);
    ui->SetSizeButton->setEnabled(false);
    ui->SetDelayButton->setEnabled(false);
    ui->DelayEdit->setEnabled(false);
    ui->SizeEdit->setEnabled(false);

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
