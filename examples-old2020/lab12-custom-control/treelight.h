#ifndef TREELIGHT_H
#define TREELIGHT_H

#include <QPainter>

class TreeLight
{
    int x, y;
    int r;
    int inc;
public:
    TreeLight(int x, int y, int r);
    void Draw(QPainter *p);
    void Next();
};

#endif // TREELIGHT_H
