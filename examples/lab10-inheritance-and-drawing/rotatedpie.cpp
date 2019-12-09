#include "rotatedpie.h"
#include <math.h>
#include <qdebug.h>

RotatedPie::RotatedPie(int cx, int cy, int r):BaseShape(cx, cy)
{
    this->r = r;
}

 void RotatedPie::Draw(QPainter *p)
 {
 /* startAngle та spanAngle повинні бути вказані як 1/16 градуса,
  * тобто повне коло дорівнює 5760 одиниць (16 * 360). Додатні
  * значення кутів означають напрям проти годинникової стрілки,
  * а від'ємні - за годинниковою стрілкою. Нульовий градус
  * знаходиться в положенні годинної стрілки на 3 години. */
     int startAngle = int( 30 + alpha*180./M_PI)*16 ;
     int spanAngle =  300*16;

     p->drawPie(centerX, centerY, 2*r, 2*r, startAngle, spanAngle);
 }
