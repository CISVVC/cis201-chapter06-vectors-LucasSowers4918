/*
File: Main.cpp
Description: This program shows a bank statment it shows some of the days it was accessed how much the balance was how much was taken or added and the total intrest that was added to the account
Author: Lucas Sowers
Email: lucass4918@student.vvc.edu
Date:11/17/18
*/
#include "transaction.h"
#include "transactionlog.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// The transactions that were happening to the account
void fill_log(Transaction_log &log)
{
   log.add_entry(Transaction(1, 1143.24, "Initial balance"));
   log.add_entry(Transaction(1, -440.56, "Check"));
   log.add_entry(Transaction(1, 215.05, "Deposit"));
   log.add_entry(Transaction(2, 68.50, "Deposit"));
   log.add_entry(Transaction(3, -100.0, "Check"));
   log.add_entry(Transaction(4, -42.98, "Check"));
   log.add_entry(Transaction(5, 220.0, "Deposit"));
   log.add_entry(Transaction(6, -20.04, "Check"));
   log.add_entry(Transaction(6, 15.0, "Deposit"));

   log.add_entry(Transaction(17, 120.05, "Deposit"));
   log.add_entry(Transaction(20, 60.0, "Deposit"));
   log.add_entry(Transaction(25, -110.0, "Check"));
   log.add_entry(Transaction(30, -240.56, "Check"));
}

int main()
{
    Transaction_log log;
    fill_log(log);
    log.print_daily_report();

   return 0;
}
