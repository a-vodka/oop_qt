#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "polynomial.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    static double coef[] = {-5, 1};
    static Polynomial p(2, coef);

    static double coef1[] = {-1, -3, 1};
    static Polynomial p1(3, coef1);

    QChart *chart = new QChart();

    chart->addSeries(p.plot());
    chart->addSeries(p1.plot());

    chart->createDefaultAxes();

    ui->chart->setChart(chart);


    ui->chart->setRenderHint(QPainter::Antialiasing);


}

