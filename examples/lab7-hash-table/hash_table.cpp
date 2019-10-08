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
   int s = 0;
   for (int i =0; i< k.length(); i++)
       s += k[i].digitValue();

   return s % T_S;
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
   //cout<<"Element Deleted"<<endl;
}

void hash_table::setQTable(QTableWidget* qtable)
{
    this->qtable = qtable;
}

void hash_table::PrintToQTable()
{
    qtable->setRowCount(T_S);
    for (int i = 0; i < (int)T_S; i++)
    {
        if (t[i])
        {
            qtable->setItem(i, 0, new QTableWidgetItem(t[i]->k));
            qtable->setItem(i, 1, new QTableWidgetItem(QString::number(t[i]->v)));
        }
    }
}




/*
int main() {
   hash_table hash;
   int k, v;
   int c;
   while (1) {
      cout<<"1.Insert element into the table"<<endl;
      cout<<"2.Search element from the key"<<endl;
      cout<<"3.Delete element at a key"<<endl;
      cout<<"4.Exit"<<endl;
      cout<<"Enter your choice: ";
      cin>>c;
      switch(c) {
         case 1:
            cout<<"Enter element to be inserted: ";
            cin>>v;
            cout<<"Enter key at which element to be inserted: ";
            cin>>k;
            hash.Insert(k, v);
         break;
         case 2:
            cout<<"Enter key of the element to be searched: ";
            cin>>k;
            if (hash.SearchKey(k) == -1) {
               cout<<"No element found at key "<<k<<endl;
               continue;
            } else {
               cout<<"Element at key "<<k<<" : ";
               cout<<hash.SearchKey(k)<<endl;
            }
         break;
         case 3:
            cout<<"Enter key of the element to be deleted: ";
            cin>>k;
            hash.Remove(k);
         break;
         case 4:
            exit(1);
         default:
            cout<<"\nEnter correct option\n";
      }
   }
   return 0;
}
*/
