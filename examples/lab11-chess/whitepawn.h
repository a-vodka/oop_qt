#ifndef WHITEPAWN_H
#define WHITEPAWN_H
#include "chesspiece.h"

class WhitePawn : public ChessPiece
{
public:
    WhitePawn(int fx, int fy);
    bool canMove(int x, int y);
};

#endif // WHITEPAWN_H
