#include <QInputDialog>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "linkedlist.h"

LinkedList list;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Наші налаштування
    list.setQTable(ui->tableWidget);
    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Дані"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    list.Add(ui->lineEdit->text().toInt());
}

void MainWindow::on_pushButton_2_clicked()
{
    list.Del();
}

void MainWindow::on_tableWidget_cellDoubleClicked(int row, int column)
{
    QString value = ui->tableWidget->item(row, column)->text();
    bool ok;

    QString text = QInputDialog::getText(this, "Значення", "Введіть нове значення", QLineEdit::Normal, value, &ok);

    if (ok && !text.isEmpty())
            list.SetValue(row, text.toInt());

}
