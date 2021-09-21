#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QDir>
#include <QMouseEvent>
#include <QMenu>
#include <QTimer>
#include "treelight.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    setParent(nullptr); // Create TopLevel-Widget
    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);
    setAttribute(Qt::WA_PaintOnScreen); // not needed in Qt 5.2 and up

    ui->widget->installEventFilter(this);

    paintTimer = new QTimer(this);
    paintTimer->start(10);
    connect(paintTimer, SIGNAL(timeout()), this, SLOT(updatePixmap()));
    l1 = new TreeLight(125, 150, 1);

}

MainWindow::~MainWindow()
{
    delete ui;
}


bool MainWindow::eventFilter(QObject* watched, QEvent* event)
{
    if(watched == ui->widget && event->type() == QEvent::Paint)
    {
        QPainter p(ui->widget);
        QBrush b(Qt::red);
        QPen pn(Qt::red);
        p.setPen(pn);
        p.setBrush(b);


        QImage img(QDir::currentPath() + "/tree.png");
        p.drawImage(ui->widget->rect(), img, img.rect());

        l1->Draw(&p);
    }

    if(watched == ui->widget && event->type() == QEvent::MouseMove)
    {
        QMouseEvent *me = reinterpret_cast<QMouseEvent *>(event);
        move(me->globalPos() - clickpos );
    }
    if(watched == ui->widget && event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *me = reinterpret_cast<QMouseEvent *>(event);
        if (me->button() == Qt::MouseButton::LeftButton)
        {
            clickpos = reinterpret_cast<QMouseEvent *>(event)->pos();
        }
        if (me->button() == Qt::MouseButton::RightButton)
        {
            QMenu myMenu;
            myMenu.addAction("Вийти", this, SLOT(on_action_1()));
            myMenu.exec(me->globalPos());
        }
    }

    return false;
}

void MainWindow::on_action_1()
{
   this->close();
}

void MainWindow::updatePixmap()
{
    l1->Next();
    repaint();
}
