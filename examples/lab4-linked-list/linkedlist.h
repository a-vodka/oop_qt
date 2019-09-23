#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <QTableWidget>

struct Element   // Елемент даних
{
    int data; 	 // Дані
    Element * Next; // Адреса наступного елементу у списку
};

class LinkedList
{
    Element * Head;	// Вказівник на голову списка
    int Count;		// Кількість елементів списку
    QTableWidget *qtable; // QTableWidget для відображення
public:
    LinkedList();	// Конструктор
    ~LinkedList();	// Деструктор
    void Add(int data);// Дадавання елементу в список
    void Del();// Видалення елементу з списку
    void DelAll();	// Видалення всього списку
    void setQTable(QTableWidget *qtable);// Для встановлення посилання на QTableWidget
    void PrintToQTable();// Вивід списку у QTableWidget
    void SetValue(int index, int data); // Завдання значення i-го елементу
    int GetCount(); // Кількість елементів у списку
public:

};

#endif // LINKEDLIST_H
