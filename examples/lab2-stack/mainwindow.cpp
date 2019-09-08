#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stack.h"

Stack stack;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Наші налаштування
    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Stack data"));
    stack.setQTable(ui->tableWidget);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{   // Кнопка push
    stack.push(ui->lineEdit->text().toInt());
}

void MainWindow::on_pushButton_2_clicked()
{   // Кнопка pop
    if(!stack.isEmpty())
    {
        int val = stack.pop();
        ui->lineEdit->setText(QString::number(val));
    }
    else
    {
        QMessageBox::information(this, "stack ", "Stack is empty!!");
    }
}
