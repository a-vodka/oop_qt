#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "binary_tree.h"

binary_tree tree;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // налаштування
    ui->treeWidget->setColumnCount(1);
    ui->treeWidget->setHeaderHidden(true);
    tree.SetQTree(ui->treeWidget);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    tree.Insert(rand()%100);
    tree.Print();
}
