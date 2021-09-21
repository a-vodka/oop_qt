#include "queue.h"

Queue::Queue(int MaxLength)
{
    qEnd = 0;
    maxQLength = MaxLength;
    q = new int[maxQLength];
    qtable = nullptr;
}
Queue::~Queue()
{
    delete []q;
}
bool Queue::isEmpty()
{
    return qEnd == 0;
}
bool Queue::isFull()
{
    return qEnd == maxQLength;
}
bool Queue::push(int elem)
{
    if(isFull())
        return false;
    q[qEnd] = elem; // Записуємо новий елемент
    qEnd++;
    if(qtable)
    {
        qtable->insertRow(0);
        qtable->setItem(0, 0, new QTableWidgetItem(QString::number(elem)));
    }
    return true;
}
bool Queue::pop(int &elem)
{
    if(isEmpty())
        return false;
    elem = q[0];    // Записуємо в еlem вилучаємий елемент
    for(int i = 0; i < qEnd - 1; i++) // Зсув елементів, що залишилися
        q[i] = q[i + 1];
    qEnd--;     // Зменшуємо довжину черги
    if(qtable)
        qtable->removeRow(qEnd);
    return true;
}
void Queue::setQTable(QTableWidget* qtable)
{
    this->qtable = qtable;
}
