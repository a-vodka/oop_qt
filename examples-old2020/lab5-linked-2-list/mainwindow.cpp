#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "linked2list.h"
#include <QInputDialog>

Linked2list list2;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Наші налаштування
    list2.setQTable(ui->tableWidget);
    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Дані"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    list2.AddHead(ui->lineEdit->text().toInt());
}

void MainWindow::on_pushButton_2_clicked()
{
    list2.Del();
}

void MainWindow::on_tableWidget_cellDoubleClicked(int row, int column)
{
    QString value = ui->tableWidget->item(row, column)->text();
    bool ok;

    QString text = QInputDialog::getText(this, "Значення", "Введіть нове значення", QLineEdit::Normal, value, &ok);

    if (ok && !text.isEmpty())
        list2.SetValue(row, text.toInt());
}
