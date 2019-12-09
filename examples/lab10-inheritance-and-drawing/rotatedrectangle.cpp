#include "rotatedrectangle.h"
#include <math.h>
RotatedRectangle::RotatedRectangle(int cx, int cy, int w, int h): BaseShape(cx, cy)
{
    width = w;
    height = h;
}

void RotatedRectangle::Draw(QPainter *p)
{
    CalculateVertices();
    p->drawPolygon(vertices, N);
}

void RotatedRectangle::CalculateVertices()
{
    vertices[0] = QPoint( width / 2, -height / 2);
    vertices[1] = QPoint(-width / 2, -height / 2);
    vertices[2] = QPoint(-width / 2,  height / 2);
    vertices[3] = QPoint( width / 2,  height / 2);

    for(int i = 0; i < N ; i++)
    {
        int x = vertices[i].x();
        int y = vertices[i].y();
        vertices[i].setX(int(x * cos(alpha) - y * sin(alpha) + centerX));
        vertices[i].setY(int(x * sin(alpha) + y * cos(alpha) + centerY));
    }
}
