
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

using namespace std;

class Transaction
{
public:
   Transaction(int day, double amount, string description); 
   int get_day() const;   
   double get_amount() const;   
   void print() const;      // prints data

private:
   int m_day;  
   double m_amount;   
   string m_description;   
};

#endif
