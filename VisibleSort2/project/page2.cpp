#include "page2.h"
#include "ui_page2.h"
//#include "ChartWidget.h"
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

Page2::Page2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Page2)
{
    ui->setupUi(this);
    this->visible_2 = new Visible2(this);
    this->chartwidget = new ChartWidget();
    this->setMinimumSize(1200, 900);

    // 使用布局管理器
    QVBoxLayout *mainLayout = new QVBoxLayout();
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    buttonLayout->addWidget(ui->Button1_Insert);
    buttonLayout->addWidget(ui->Button2_Binary);
    buttonLayout->addWidget(ui->Button3_Shell);
    buttonLayout->addWidget(ui->Button4_Bubble);
    buttonLayout->addWidget(ui->Button5_Quick);
    buttonLayout->addWidget(ui->Button6_Selection);
    buttonLayout->addWidget(ui->Button7_Heap);
    buttonLayout->addWidget(ui->Button8_Merge);
    buttonLayout->addWidget(ui->Button9_Radix);
    buttonLayout->addWidget(ui->BackButton);

    QHBoxLayout *graphLayout = new QHBoxLayout();

    graphLayout->addWidget(chartwidget);

    mainLayout->addLayout(graphLayout);
    mainLayout->addLayout(buttonLayout);
    //mainLayout->addWidget(this->visible_2->painter);

    ui->centralwidget->setLayout(mainLayout);
}

Page2::~Page2()
{
    delete ui;
}

void Page2::on_BackButton_clicked()
{
    this->hide();
    emit back();
}


void Page2::on_Button1_Insert_clicked()
{
    //visible_2->DoSort(visible_2->SortType::INSERT);
}


void Page2::on_Button2_Binary_clicked()
{
    //visible_2->DoSort(visible_2->SortType::BINARY);
}


void Page2::on_Button3_Shell_clicked()
{
    //visible_2->DoSort(visible_2->SortType::SHELL);
}


void Page2::on_Button4_Bubble_clicked()
{
    //visible_2->DoSort(visible_2->SortType::BUBBLE);
}


void Page2::on_Button5_Quick_clicked()
{
    //visible_2->DoSort(visible_2->SortType::QUICK);
}


void Page2::on_Button6_Selection_clicked()
{
    //visible_2->DoSort(visible_2->SortType::SELECTION);
}


void Page2::on_Button7_Heap_clicked()
{
    //visible_2->DoSort(visible_2->SortType::HEAP);
}


void Page2::on_Button8_Merge_clicked()
{
    //visible_2->DoSort(visible_2->SortType::MERGE);
}


void Page2::on_Button9_Radix_clicked()
{
    //visible_2->DoSort(visible_2->SortType::RADIX);
}

