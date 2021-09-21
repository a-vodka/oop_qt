#include <math.h>
#include <QString>
#include <QLineSeries>

#include "polynomial.h"

Polynomial::Polynomial(int n, double coef[])
{
    lb = -5;
    rb = 5;
    plot_step = (rb - lb)/100;

    this->n = n;
    this->coef = new double[n];

    for (int i = 0; i < n; i++)
        this->coef[i] = coef[i];

    series = new QT_CHARTS_NAMESPACE::QLineSeries();

}

Polynomial::~Polynomial()
{
    if ( coef != nullptr)
        delete []coef;
    delete series;
}

double Polynomial::eval(double x)
{
    double value = 0;
    for (int i = 0;i < n;i++)
    {
        value += coef[i] * pow(x, i);
    }
    return value;
}

QT_CHARTS_NAMESPACE::QLineSeries * Polynomial::plot()
{
    series->clear();

    double x = this->lb;
    while (x < this->rb)
    {
         series->append(x, this->eval(x));
         x += plot_step;
    }
    series->setName(this->getName());

    return series;
}

QString Polynomial::getName()
{
    QString name;

    for (int i = 0;i < n;i++)
    {
        if (coef[i] > 0 and i!=0)
            name += " + ";
        name += QString::number(coef[i], 'f', 1);

        if ( i != 0)
                name += "x^"+QString::number(i);
    }
    return name;
}
