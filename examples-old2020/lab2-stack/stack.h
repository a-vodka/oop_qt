#ifndef STACK_H
#define STACK_H

#include <QTableWidget>

const int stacksize = 10;
const int EMPTY = -1;
class Stack
{
    int arr[stacksize]; // Массив для хранения данных
    int top; // Вершина стека
    QTableWidget *qtable; // Указатель на StringGrid
public:
    Stack();    // Конструктор
    void push(int c);   // Добавление элемента
    int pop();   // Выталкивание элемента
    void clear();    // Очистка стека
    bool isEmpty(); // Проверка на наличие элементов в стеке
    bool isFull();  // Проверка на заполнение всего стека
    int getCount(); // Количество элементов в стеке
    void setQTable(QTableWidget *qtable);
};
#endif // STACK_H
