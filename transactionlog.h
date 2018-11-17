#ifndef TRANSACTIONLOG_H
#define TRANSACTIONLOG_H

#include <string>
#include <vector>

using namespace std;

class Transaction_log
{
    public:
        Transaction_log();
        void add_entry(Transaction t); 
        
        // adds up total balance for each day
        vector<double> daily_balances();            
        double get_total_for_day(int day);  
        int max_day();   
       
       //calculates average
        double average_balance(const vector<double>& balances);

       //calculates smallest balance
        double minimum(const vector<double>& balances);
       //calculates interest
        double interest(double balance, int periods);


        // Prints Transactions with the given day
        void print_transactions_for_day(int day);

        // Prints all Transactions
        void print_daily_report();

        void print_interest(int periods, const vector<double>& balances);

    private:
        vector<Transaction> m_entries; 
};

#endif
