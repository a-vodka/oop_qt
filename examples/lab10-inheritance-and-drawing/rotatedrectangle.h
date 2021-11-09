#ifndef ROTATEDRECTANGLE_H
#define ROTATEDRECTANGLE_H

#include "baseshape.h"


class RotatedRectangle : public BaseShape
{
private:
    const static int N = 4;
    int width, height;
    QPoint vertices[N];
    void CalculateVertices();
public:
    void Draw(QPainter *p);
    RotatedRectangle(int cx, int cy, int w, int h);
};

#endif // ROTATEDRECTANGLE_H
