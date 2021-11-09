#include "baseshape.h"

BaseShape::BaseShape(int cx, int cy)
{
    alpha = 0;
    centerX = cx;
    centerY = cy;
}

BaseShape::~BaseShape()
{

}

void BaseShape::Rotate(double dAlpha)
{
    alpha += dAlpha;
}

void BaseShape::MoveLeft()
{
    centerX -= 10;
}

void BaseShape::MoveRight()
{
    centerX += 10;
}

void BaseShape::MoveUp()
{
    centerY -= 10;
}

void BaseShape::MoveDown()
{
    centerY += 10;
}
