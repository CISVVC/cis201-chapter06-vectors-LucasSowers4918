#include "transaction.h"
#include "transactionlog.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

Transaction_log::Transaction_log()
{
}

void Transaction_log::add_entry(Transaction t)
{
    m_entries.push_back(t);
}

vector<double> Transaction_log::daily_balances()
{
    vector<double> balances;
    double total = 0;

    for(int day=0; (day+1) <= max_day(); day++)
    {
        total += get_total_for_day(day+1);  
        balances.push_back(total);  

    }

    return balances;
}

double Transaction_log::get_total_for_day(int day)
{
    double total = 0;

    for(int i=0; i<m_entries.size(); i++)
    {
        if(m_entries[i].get_day() == day)
            total = total + m_entries[i].get_amount();
    }
    
    return total;
}

int Transaction_log::max_day()
{
    int max = 0; 


    for(int i=0; i<m_entries.size(); i++)
    {
        if(max < m_entries[i].get_day())
            max = m_entries[i].get_day();
    }

    return max;
}

double Transaction_log::average_balance(const vector<double>& balances)
{
    double total = balances[0];

    for(int i=1; i<balances.size(); i++)
        total += balances[i];

    return (static_cast<double>(total/balances.size()) );
}

double Transaction_log::minimum(const vector<double>& balances)
{
    double minimum = balances[0];

    for(int i=1; i<balances.size(); i++)
    {
        if(minimum > balances[i])
            minimum = balances[i];
    }

    return minimum;
}

double Transaction_log::interest(double balance, int periods)
{
    double rate = 0.5;
    rate = rate/100.0;

    return balance*rate*periods;
}

void Transaction_log::print_transactions_for_day(int day)
{
    for(int i=0; i < m_entries.size(); i++)
    {
        if(m_entries[i].get_day() == day)
            m_entries[i].print();
    }
}

void Transaction_log::print_daily_report()
{
    const int INT_PERIOD = 30; 

    vector<double> balances = daily_balances();

    for(int day=0; day < max_day(); day++)
    {
        print_transactions_for_day(day+1);
        if(balances[day] != balances[day-1])   
            cout << "Day" << day+1 << " balance:" << "\t" << balances[day] << endl << endl;
    }

    
    if(balances.size() >= INT_PERIOD)
        print_interest(balances.size()/INT_PERIOD, balances);
}

void Transaction_log::print_interest(int periods, const vector<double>& balances)
{ 
    double bal = average_balance(balances);

    double interest_accrued = interest(bal, periods);  

    double end_balance = balances[balances.size()-1];

    cout << "Average daily balance: " << bal << endl;

    cout << "Interest earned: \t" << setprecision(2) << fixed << interest_accrued << endl;  

    cout << "Final average balance with interest: \t" << interest_accrued + end_balance << endl << endl;

    bal = minimum(balances);
    interest_accrued = interest(bal, periods);   

    cout << "Minimum daily balance: " << bal << endl;

    cout << "Interest earned: \t" << setprecision(2) << fixed << interest_accrued << endl;  
 
    cout << "Final minimul balance with interest: \t" << interest_accrued + end_balance << endl << endl;    
}

