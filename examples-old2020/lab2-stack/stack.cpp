#include "stack.h"
#include <QString>

Stack::Stack()
{
    top = EMPTY; // Изначально стек пуст
    qtable = nullptr;
}
void Stack::clear()
{
    top = EMPTY;
}
bool Stack::isEmpty()
{
    return top == EMPTY;
}
bool Stack::isFull()
{
    return top == stacksize - 1;
}
int Stack::getCount()
{
    return top + 1; // Количество элементов в стеке
}
void Stack::push(int c)
{
    if(!isFull())
    {
        top++;
        arr[top] = c;
        if(qtable)
        {
            qtable->insertRow(0);
            qtable->setItem(0, 0, new QTableWidgetItem(QString::number(c)));
        }
    }
}
int Stack::pop()
{
    if(!isEmpty())
    {
        top--;
        if(qtable) qtable->removeRow(0);
        return arr[top + 1];
    }
    else // Нечего извлекать
        return 0;
}
void Stack::setQTable(QTableWidget *qtable)
{
    this->qtable = qtable;
}

