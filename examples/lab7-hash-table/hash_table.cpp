#include "hash_table.h"
#include <QTableWidget>

hash_table::hash_table()
{
   qtable = nullptr;
   t = new hash_table_entry * [T_S];
   for (unsigned int i = 0; i < T_S; i++)
   {
      t[i] = nullptr;
   }
}

hash_table::~hash_table()
{
   for (unsigned int i = 0; i < T_S; i++)
   {
      if (t[i] != nullptr)
         delete t[i];
         delete[] t;
   }
}

int hash_table::HashFunc(QString k)
{
   unsigned int s = 0;
   for (int i =0; i< k.length(); i++)
       s += uint(k[i].digitValue());

   return int(s % T_S);
}

void hash_table::Insert(QString k, int v)
{
   int h = HashFunc(k);
   while (t[h] != nullptr && t[h]->k != k)
   {
      h = HashFunc(k + " ");
   }
   if (t[h] != nullptr)
      delete t[h];
   t[h] = new hash_table_entry(k, v);
   PrintToQTable();
}

int hash_table::SearchKey(QString k)
{
   int h = HashFunc(k);
   while (t[h] != nullptr && t[h]->k != k)
   {
        h = HashFunc(k + " ");
   }
   if (t[h] == nullptr)
      return -1;
   else
      return t[h]->v;
}

void hash_table::Remove(QString k)
{
   int h = HashFunc(k);
   while (t[h] != nullptr) {
      if (t[h]->k == k)
         break;
      h = HashFunc(k + " ");
   }
   if (t[h] == nullptr) {
      // cout<<"No Element found at key "<<k<<endl;
      return;
   } else {
      delete t[h];
   }
   PrintToQTable();
}

void hash_table::setQTable(QTableWidget* qtable)
{
    this->qtable = qtable;
}

void hash_table::PrintToQTable()
{
    qtable->setRowCount(int(T_S));
    for (int i = 0; i < int(T_S); i++)
    {
        if (t[i])
        {
            qtable->setItem(i, 0, new QTableWidgetItem(t[i]->k));
            qtable->setItem(i, 1, new QTableWidgetItem(QString::number(t[i]->v)));
        }
    }
}
