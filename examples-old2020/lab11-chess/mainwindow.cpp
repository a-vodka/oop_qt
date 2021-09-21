#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QDebug>
#include <QKeyEvent>
#include "chesspiece.h"
#include "whitepawn.h"
#include "blackpawn.h"
#include <QMessageBox>

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
    for(auto piece = pieces.begin(); piece < pieces.end(); piece++)
        delete *piece;
}

bool MainWindow::eventFilter(QObject* watched, QEvent* event)
{
    if(watched == ui->widget && event->type() == QEvent::Paint)
    {
        QPainter p(ui->widget);
        DrawChessField(&p);
        for(auto piece = pieces.begin(); piece < pieces.end(); piece++)
        {
            (*piece)->Draw(&p);
            if((*piece)->getPosition() ==  this->cellcoord)
                for(int i = 0; i < 8; i++)
                    for(int j = 0; j < 8; j++)
                        if((*piece)->canMove(i, j))
                            (*piece)->DrawShadow(&p, i, j);
        }

        return true;
    }

    if(watched == ui->widget && event->type() == QEvent::MouseButtonPress)
    {
        QPoint clickpos = reinterpret_cast<QMouseEvent *>(event)->pos();
        QPoint coord = ChessPiece::GetCellByMouseClick(clickpos);
        this->cellcoord = coord;
        ui->widget->update();
    }

    return false;
}



void MainWindow::DrawChessField(QPainter *p)
{
    QBrush b1(QColor(0xEEEE00));
    QBrush b2(QColor(0x666600));

    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
        {
            if((i + j) % 2 == 0)
                p->fillRect(ChessPiece::GetCellRect(i, j), b1);
            else
                p->fillRect(ChessPiece::GetCellRect(i, j), b2);

        }
    for(int i = 0; i < 8; i++)
    {
        QChar text = QChar('A' + i);

        QRect textrect1 = p->fontMetrics().boundingRect(QString(text));
        QRect textrect2 = p->fontMetrics().boundingRect(QString::number(8 - i));

        p->drawText(DeskBorder + i * DeskCell + DeskCell / 2 - textrect1.width() / 2, 2 * DeskBorder + 8 * DeskCell, QString(text));
        p->drawText(DeskBorder / 2, DeskBorder + i * DeskCell + DeskCell / 2 + textrect2.height() / 2, QString::number(8 - i));
    }
}



bool MainWindow::StrToChessPos(QString s,  int &i, int &j)
{
    if(s.length() != 2)
        return false;
    QByteArray sc = s.toUpper().toLocal8Bit();
    i = sc[0] - 'A';
    j = sc[1] - '1';
    return true;
}

void MainWindow::on_pushButton_clicked()
{
    int x = 0, y = 0;
    if(!StrToChessPos(ui->lineEdit->text(), x, y))
        return;
    for(auto piece = pieces.begin(); piece < pieces.end(); piece++)
    {
        if((*piece)->getPosition() == QPoint(x, y))
        {
            QMessageBox::warning(this, "", "Клітинка зайнята");
            return;
        }
    }


    if(ui->radioButton->isChecked())
        pieces.push_back(new BlackPawn(x, y));

    if(ui->radioButton_2->isChecked())
        pieces.push_back(new WhitePawn(x, y));
    ui->widget->update();
}
