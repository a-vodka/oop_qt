#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hash_table.h"

hash_table ht;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Налаштування
    ht.setQTable(ui->tableWidget);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Ключ"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Значення"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ht.Insert(ui->lineEdit->text(),ui->lineEdit_2->text().toInt());
}
