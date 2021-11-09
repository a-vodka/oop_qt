#ifndef ROTATEDPIE_H
#define ROTATEDPIE_H

#include <QPainter>
#include <baseshape.h>

class RotatedPie : public BaseShape
{
    int r;
    void CalculateVertices();
public:
    void Draw(QPainter *p);
    RotatedPie(int cx, int cy, int r);
};

#endif // ROTATEDPIE_H
