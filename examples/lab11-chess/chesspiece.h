#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <QString>
#include <QPainter>

const int DeskBorder = 15;
const int DeskCell = 50;

class ChessPiece
{
protected:
    int fx, fy;
    QString imagename;

public:
    //ChessPiece();
    ChessPiece(int fx, int fy);
    virtual ~ChessPiece();
    void setPosition(int x, int y);
    QPoint getPosition();
    void Draw(QPainter *p);
    void DrawShadow(QPainter *p, int i, int j);
    virtual bool canMove(int x, int y) = 0;
    static QRect GetCellRect(int i, int j);
    static QPoint GetCellByMouseClick(QPoint p);
};

#endif // CHESSPIECE_H
