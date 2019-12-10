#ifndef BLACKPAWN_H
#define BLACKPAWN_H
#include "chesspiece.h"

class BlackPawn : public ChessPiece
{
public:
    BlackPawn(int fx, int fy);
    bool canMove(int x, int y);
};

#endif // BLACKPAWN_H
