#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "chesspiece.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    void DrawChessField(QPainter *p);
    bool eventFilter(QObject* watched, QEvent* event);
    bool StrToChessPos(QString s,  int &i,int &j);
    QVector<ChessPiece*> pieces;
    QPoint cellcoord;

};

#endif // MAINWINDOW_H
