#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <QTreeWidget>

struct Elem
{
    int data;
    Elem *left, *right;
};


class binary_tree
{
    Elem * root; 	// корінь
    QTreeWidget* tv;
    void PrintTree(Elem * Node, QTreeWidgetItem* trNode);
    void AddElem(Elem** node, Elem *data);
public:
    binary_tree();           // Конструктор
    void Print();           // друк дерева
    void Insert(int data); // вставка  елементу
    void SetQTree(QTreeWidget *tv); // Установка посилання на QTreeWidget
};

#endif // BINARY_TREE_H
