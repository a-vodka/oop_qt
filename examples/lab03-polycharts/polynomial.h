#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <QString>
#include <QLineSeries>

class Polynomial
{
    //Q_OBJECT

    int n;
    double *coef;
    double lb, rb, plot_step;

    QT_CHARTS_NAMESPACE::QLineSeries *series;

public:
    Polynomial(int n, double coef[]);
    ~Polynomial();
    double eval(double x);
    QT_CHARTS_NAMESPACE::QLineSeries * plot();
    QString getName();
};

#endif // POLYNOMIAL_H
