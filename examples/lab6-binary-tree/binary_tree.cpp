#include "binary_tree.h"
#include <QTreeView>

binary_tree::binary_tree()
{
    root = nullptr;
}
void binary_tree::Print()
{
    if (tv == nullptr)
        return;

    tv->clear(); // Очищумо TreeWidget
    QTreeWidgetItem *treeItem = new QTreeWidgetItem(tv);
    treeItem->setText(0,"root");

    PrintTree(root, treeItem);  // Викликаємо рекурсивний друк
    tv->expandAll();
}
void binary_tree::PrintTree(Elem * Node, QTreeWidgetItem* trNode)
{
    if (Node == nullptr)
        return;
    QTreeWidgetItem* trNode1 = new QTreeWidgetItem(trNode);
    trNode1->setText(0, QString::number(Node->data));
    trNode->addChild(trNode1);

    PrintTree(Node->left,  trNode1);
    PrintTree(Node->right, trNode1);

}
void binary_tree::AddElem(Elem** node, Elem *data)
{
    if(*node == nullptr)  // Якщо лист -- вставляємо елемент
        *node = data;
    else
    {
        if ((*node)->data > data->data) // В яку гілку?
            AddElem(&((*node)->left), data);
        else
            AddElem(&((*node)->right), data);
   }
}
void binary_tree::Insert(int data)
{
    Elem * z = new Elem;
    z->left = nullptr;
    z->right = nullptr;
    z->data = data;
    AddElem(&root, z);  // викликаємо метод вствки елементу
}

void binary_tree::SetQTree(QTreeWidget *tv)
{
    this->tv = tv;
}
