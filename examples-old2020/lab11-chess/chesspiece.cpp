#include "chesspiece.h"
#include <qdebug.h>
#include <qdir.h>

ChessPiece::ChessPiece(int fx, int fy)
{
    imagename =  QDir::currentPath() + "/" + imagename;
    setPosition(fx, fy);
}

ChessPiece::~ChessPiece()
{

}

QRect ChessPiece::GetCellRect(int i, int j)
{
    QRect result;
    int nj = 7 - j;
    result.setLeft(i * DeskCell + DeskBorder);
    result.setTop(nj * DeskCell + DeskBorder);
    result.setRight((i + 1)*DeskCell + DeskBorder);
    result.setBottom((nj + 1)*DeskCell + DeskBorder);
    return result;
}

QPoint ChessPiece::getPosition()
{
    return QPoint(fx, fy);
}

QPoint ChessPiece::GetCellByMouseClick(QPoint p)
{
    int x = p.x();
    int y = p.y();
    x -= DeskBorder;
    y -= DeskBorder;
    if(x < 0 || y < 0 || x > 8 * DeskCell || y > 8 * DeskCell)
        return QPoint(-1, -1);
    return QPoint(x / DeskCell, 7 - y / DeskCell);
}

void ChessPiece::Draw(QPainter *p)
{
    QImage img(imagename);
    p->drawImage(GetCellRect(fx, fy), img, img.rect());
}

void ChessPiece::DrawShadow(QPainter *p, int i, int j)
{

    QImage img(imagename);
    p->setCompositionMode(QPainter::CompositionMode_Overlay);
    p->drawImage(GetCellRect(i, j), img, img.rect());
    p->setCompositionMode(QPainter::CompositionMode_SourceOver);
}

void ChessPiece::setPosition(int x, int y)
{
    fx = x;
    fy = y;
}
