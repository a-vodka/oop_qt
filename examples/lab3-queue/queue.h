#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include <QTableWidget>
class Queue
{
    int *q;         // Черга
    int qEnd;       // Поточний розмір черги
    int maxQLength; // Максимальний розмір черги
    QTableWidget *qtable;       // QTableWidget для відображення
public:
    Queue(int MaxLength);// Конструктор
    ~Queue();            // Деструктор
    bool push(int elem); // Дадавання елементу в чергу
    bool pop(int & elem);// Вилучення елементу з черги
    bool isEmpty();  // Черга порожня?
    bool isFull();       // Черга заповнена?
    void setQTable(QTableWidget *qtable);// Для встановлення посилання на QTableWidget
};
#endif // QUEUE_H_INCLUDED
