#include "whitepawn.h"

WhitePawn::WhitePawn(int fx, int fy): ChessPiece(fx, fy)
{
    imagename = "./chess_images/Chess_plt60.png";
}

bool WhitePawn::canMove(int x, int y)
{
    if(x != fx)
        return false;
    if(fy == 1)
        if(y == 3 || y == 2)
            return true;
        else
            return false;
    else if(y == fy + 1)
        return true;
    else
        return false;
}
