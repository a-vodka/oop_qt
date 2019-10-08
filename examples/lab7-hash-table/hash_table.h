#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <QTableWidget>

struct hash_table_entry
{
      QString k;
      int v;
      hash_table_entry(QString k, int v)
      {
         this->k = k;
         this->v = v;
      }
};

class hash_table
{
   private:
      const unsigned int T_S = 13;
      hash_table_entry **t;
      QTableWidget *qtable; // QTableWidget для відображення
   public:
      hash_table();
      ~hash_table();
      int HashFunc(QString k);
      void Insert(QString k, int v);
      int SearchKey(QString k);
      void Remove(QString k);
      void setQTable(QTableWidget* qtable);
      void PrintToQTable();


};



#endif // HASH_TABLE_H
