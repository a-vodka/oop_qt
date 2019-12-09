#ifndef BASESHAPE_H
#define BASESHAPE_H

#include <QPainter>

class BaseShape
{
protected:
    double alpha;
    int centerX, centerY;
public:
    BaseShape(int cx, int cy);
    virtual ~BaseShape();
    void Rotate(double dAlpha);
    virtual void Draw(QPainter *p) = 0;
    void setScale(double scale);
    void MoveLeft();
    void MoveRight();
    void MoveUp();
    void MoveDown();
};

#endif // BASESHAPE_H
