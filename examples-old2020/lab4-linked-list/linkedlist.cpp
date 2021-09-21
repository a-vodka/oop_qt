#include "linkedlist.h"

LinkedList::LinkedList()
{
    Head = nullptr;	// спочатку список порожній
    Count = 0;
}
LinkedList::~LinkedList()
{
    qtable = nullptr;
    DelAll();		// Видалення всіх елементів списку
}
int LinkedList::GetCount()
{
    return Count; // Кількість елементів у списку
}
void LinkedList::Add(int data)
{
    Element * temp = new Element; // Створення нового елементу
    temp->data = data; // заповнення даними
    temp->Next = Head; // наступний елемент - це теперешня голова
    Head = temp; // новий елемент стає головним елементом
    Count++; // Збільшуємо кількість ел-тів
    PrintToQTable();
}
void LinkedList::Del()
{
    if (Head == nullptr)
        return;
    Element * temp = Head; 	// запам'ятовуємо адресу головного ел-та
    Head = Head->Next;	// перекидаємо голову на наступний ел-т
    delete temp;		// видаляжмо минулий головний ел-т
    Count--;			// зменшуємо кількість на 1
    PrintToQTable(); 		// друкуємо список
}
void LinkedList::DelAll()
{
    while (Head != nullptr) // Пока еще есть элементы
        Del(); 		// Удаляем элементы по одному
}
void LinkedList::setQTable(QTableWidget* qtable)
{
    this->qtable = qtable;
}
void LinkedList::PrintToQTable()
{
    if (qtable == nullptr)
        return;
    Element * temp = Head; 	// Запам'ятовуємо адресу головного ел-ту
    qtable->setRowCount(Count);
    int i = 0;
    while(temp != nullptr)     // Поки є ел-ти
    {
        qtable->setItem(i, 0, new QTableWidgetItem(QString::number(temp->data)));
        temp = temp->Next; 	// Переходимо до наступного ел-ту списку
        i++;
    }
}
void LinkedList::SetValue(int index, int data)
{
    if (index > GetCount())
        return;
    Element * temp = Head;
    int i = 0;
    while (temp != nullptr && i < index)
    {
        i++;
        temp = temp->Next;
    }
    temp->data = data;
    PrintToQTable();
}
