#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;

    const int xm_min=0, xm_max=1, ym_min=0, ym_max=1;

    double a,b,c,d;

    int _x(double x);
    int _y(double y);
    bool eventFilter(QObject* watched, QEvent* event);

};

#endif // MAINWINDOW_H
