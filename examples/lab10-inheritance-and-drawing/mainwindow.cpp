#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include "rotatedrectangle.h"
#include "rotatedpie.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget->installEventFilter(this);
    shapes.push_back(new RotatedRectangle(100, 100, 60, 40));
    shapes.push_back(new RotatedRectangle(50, 30, 60, 40));
    shapes.push_back(new RotatedPie(70, 130, 40));

    for (int i = 0; i < shapes.size(); i++)
        ui->comboBox->addItem(QString::number(i));
}

MainWindow::~MainWindow()
{
    delete ui;
    for(auto i = shapes.begin(); i < shapes.end(); i++)
    {
        delete *i;
    }
    shapes.clear();
}

bool MainWindow::eventFilter(QObject* watched, QEvent* event)
{
    if(watched == ui->widget && event->type() == QEvent::Paint)
    {
        QPainter p(ui->widget);
        for(auto i = shapes.begin(); i < shapes.end(); i++)
        {
            (*i)->Draw(&p);
        }
        return true;
    }
    return false;
}

void MainWindow::on_pushButton_clicked()
{
    int i = ui->comboBox->currentIndex();
    shapes[i]->Rotate(M_PI/10.0);
    ui->widget->update();
}

void MainWindow::on_pushButton_6_clicked()
{
    int i = ui->comboBox->currentIndex();
    shapes[i]->Rotate(-M_PI/10.0);
    ui->widget->update();
}

void MainWindow::on_pushButton_3_clicked()
{
    int i = ui->comboBox->currentIndex();
    shapes[i]->MoveUp();
    ui->widget->update();
}

void MainWindow::on_pushButton_4_clicked()
{
    int i = ui->comboBox->currentIndex();
    shapes[i]->MoveDown();
    ui->widget->update();
}

void MainWindow::on_pushButton_2_clicked()
{
    int i = ui->comboBox->currentIndex();
    shapes[i]->MoveLeft();
    ui->widget->update();
}

void MainWindow::on_pushButton_5_clicked()
{
    int i = ui->comboBox->currentIndex();
    shapes[i]->MoveRight();
    ui->widget->update();
}
