#include "blackpawn.h"

BlackPawn::BlackPawn(int fx, int fy): ChessPiece(fx, fy)
{
    imagename = "./chess_images/Chess_pdt60.png";
}

bool BlackPawn::canMove(int x, int y)
{
    if(x != fx)
        return false;
    if(fy == 6)
        if(y == 5 || y == 4)
            return true;
        else
            return false;
    else if(y == fy - 1)
        return true;
    else return false;
}
