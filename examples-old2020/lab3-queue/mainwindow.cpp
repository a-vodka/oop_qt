#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "queue.h"
#include <QMessageBox>
Queue *q;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Наші налаштування
    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Дані"));

    q = new Queue(10);
    q->setQTable(ui->tableWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete q;
}

void MainWindow::on_pushButton_clicked()
{
    int elem = ui->lineEdit->text().toInt();
    if(!q->push(elem))
        QMessageBox::information(this, "Черга", "Переповнення");
}

void MainWindow::on_pushButton_2_clicked()
{
    int elem;
    if(q->pop(elem))
        ui->lineEdit->setText(QString::number(elem));
    else
        QMessageBox::information(this, "Черга", "Черга пуста");
}
