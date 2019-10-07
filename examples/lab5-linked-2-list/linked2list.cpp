#include "linked2list.h"

Linked2list::Linked2list()
{
   // спочатку список порожній
    Head = Tail = nullptr;
    Count = 0;
}

Linked2list::~Linked2list()
{
    qtable = nullptr;
    DelAll(); 	// Видалення всіх елементів списку
}
void Linked2list::AddHead(int n)
{
    Elem * temp = new Elem; // Створення нового елементу
    temp->prev = nullptr;  // Попередього немає
    temp->data = n;     // Заповнюємо дані
    temp->next = Head;  // Наступний - голова у минулому
    if (Head != nullptr) 	// Чи є елементи
        Head->prev = temp;
    // Якщо елемент перший, то він одночасно голова та хвіст
    if (Count == 0)
        Head = Tail = temp;
    else
        Head = temp;    // інакше новий елемент - голова
    Count++;
    PrintToQTable();
}
void Linked2list::Del(int pos)
{
    pos++;
    if(pos < 1 || pos > Count)
        return;
    int i = 1; 	// Лічильник
    Elem * Del = Head;
    while(i < pos)
    {
        Del = Del->next; // Знаходимо елемент, що видаляється
        i++;
    }
    // Знаходимо елемент,
    // попередній до видаляємого
    Elem * PrevDel = Del->prev;
    // Елемент, наступний за видаляємим
    Elem * AfterDel = Del->next;
    if (PrevDel != nullptr && Count != 1) // Якщо видаляємо не голову
        PrevDel->next = AfterDel;
     if(AfterDel != nullptr && Count != 1) // Якщо видаляємо не хвіст
        AfterDel->prev = PrevDel;
    if(pos == 1) 	// Удаляются крайние?
        Head = AfterDel;
    if(pos == Count)
        Tail = PrevDel;
    delete Del; 	// Освобождение памяти
    Count--;
    PrintToQTable();
}
void Linked2list::DelAll()
{
    // Поки є елементи - видаляємо по одному з головы
    while(Count != 0)
        Del();
}
int Linked2list::GetCount()
{
    return Count;
}
void Linked2list::SetValue(int index, int data)
{
    if (index > GetCount())
        return;
    Elem * temp = Head;
    int i = 0;
    while (temp != nullptr && i < index)
    {
        i++;
        temp = temp->next;
    }
    temp->data = data;
    PrintToQTable();
}
void Linked2list::setQTable(QTableWidget* qtable)
{
    this->qtable = qtable;
}
void Linked2list::PrintToQTable()
{
    if (qtable == nullptr)
        return;
    Elem * temp = Head; 	// Запам'ятовуємо адресу головного ел-ту
    qtable->setRowCount(Count);
    int i = 0;
    while(temp != nullptr)     // Поки є елементи
    {
        qtable->setItem(i, 0, new QTableWidgetItem(QString::number(temp->data)));
        temp = temp->next; 	// Переходимо до наступного ел-ту списку
        i++;
    }
}
