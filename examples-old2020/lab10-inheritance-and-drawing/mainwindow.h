#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <baseshape.h>
#include <QVector>

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

    void on_pushButton_6_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    bool eventFilter(QObject* watched, QEvent* event);
    QVector<BaseShape*> shapes;
};

#endif // MAINWINDOW_H
