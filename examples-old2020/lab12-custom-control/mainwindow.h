#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "treelight.h"
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
    bool eventFilter(QObject* watched, QEvent* event);
    QPoint clickpos;
    QTimer *paintTimer;
    TreeLight *l1;
private slots:
    void on_action_1();
    void updatePixmap();
};

#endif // MAINWINDOW_H
