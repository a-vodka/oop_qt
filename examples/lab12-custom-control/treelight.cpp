#include "treelight.h"

TreeLight::TreeLight(int x, int y, int r)
{
    this->x = x;
    this->y = y;
    this->r = r;
    inc = 2;
}

void TreeLight::Draw(QPainter *p)
{
    p->drawEllipse(x-r/2, y-r/2, r, r);
}

void TreeLight::Next()
{
     r += inc;
     if (r > 20 || r < 0)
         inc = - inc;
}
