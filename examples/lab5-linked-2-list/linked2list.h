#ifndef LINKED2LIST_H
#define LINKED2LIST_H

#include <QTableWidget>

struct Elem // Елемент даних
{
    int data; // Дані
    Elem * next, * prev; // Адреса наступного та попередього елементу у списку
};
class Linked2list
{
    Elem *Head, *Tail;// Голова, хвіст
    int Count;		// Кількість елементів списку
    QTableWidget *qtable; // QTableWidget для відображення
public:
    Linked2list();	// Конструктор
    ~Linked2list();	// Деструктор
    int GetCount(); 	// Кількість елементів у списку
    void DelAll();		// Видалення всього списку
    void Del(int pos = 0); 	// Видалення елементу з списку
    void AddHead(int n);	// Дадавання елементу в початок списоку
    void setQTable(QTableWidget *qtable);// Для встановлення посилання на QTableWidget
    void PrintToQTable();// Вивід списку у QTableWidget
    void SetValue(int index, int data); // Завдання значення i-го елементу
};


#endif // LINKED2LIST_H
