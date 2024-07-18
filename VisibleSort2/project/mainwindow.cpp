#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "page1.h"
#include "page2.h"
#include "page3.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 实例化页面
    this->p1 = new Page1;
    this->p2 = new Page2;
    this->p3 = new Page3;

    connect(this->p1, &Page1::back, this, &MainWindow::BackToMainpage);
    connect(this->p2, &Page2::back, this, &MainWindow::BackToMainpage);
    connect(this->p3, &Page3::back, this, &MainWindow::BackToMainpage);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_Visible_clicked()
{
    p1->show();
    this->hide();
}


void MainWindow::on_pushButton_input_clicked()
{
    p2->show();
    this->hide();
}

void MainWindow::on_pushButton_tutor_clicked()
{
    p3->show();
    this->hide();
}

void MainWindow::BackToMainpage(){
    this->show();
}


void MainWindow::on_ExitButton_clicked()
{
    exit(0);
}
