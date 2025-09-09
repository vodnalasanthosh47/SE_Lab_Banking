#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <bits/stdc++.h>
using namespace std;

#include "Transaction.h"

class Account {
    static long nextAccNum;    // using static variable to generate unique account numbers
    string accountNumber;
    double balance;
    vector<Transaction> transactions;

public:
    Account(double initialDeposit);
    Account();

    string getAccountNumber() const;
    double getBalance() const;

    bool sendMoney(double amount);
    void receiveMoney(double amount);

    void addTransaction(const Transaction& t);
    void viewTransactions() const;
};

#endif
