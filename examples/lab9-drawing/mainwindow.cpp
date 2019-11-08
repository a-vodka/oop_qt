#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::_x(double x)
{
    return int(a*x + b);
}
int MainWindow::_y(double y)
{
    return int(c*y + d);
}


bool MainWindow::eventFilter(QObject* watched, QEvent* event)
{
    if (watched == ui->widget && event->type() == QEvent::Paint)
    {
        QPainter p(ui->widget);

        int w = p.device()->width();
        int h = p.device()->height();

        int xc_min = 10;
        int xc_max = w - 10;
        int yc_min = 10;
        int yc_max = h - 10;
        a = (xc_max - xc_min) / (xm_max - xm_min);
        b =  xc_min - a * xm_min;
        c = (yc_min - yc_max) / (ym_max - ym_min);
        d =  yc_min - c * ym_max;

        QPen pen(Qt::GlobalColor::blue);
        pen.setWidth(2);
        p.setPen(pen);

        QBrush brush(Qt::GlobalColor::red, Qt::DiagCrossPattern);

        QPainterPath path;
        path.moveTo(_x(0), _y(0));
        path.lineTo(_x(0.5),_y(1));
        path.lineTo(_x(1),_y(0));
        path.lineTo(_x(0),_y(0));

        p.drawPath(path);
        p.fillPath(path, brush);

        return true; // return true if you do not want to have the child widget paint on its own afterwards, otherwise, return false.
    }
    return false;
}


