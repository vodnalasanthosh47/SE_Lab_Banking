#ifndef BANK_H
#define BANK_H

#include <bits/stdc++.h>
using namespace std;

#include "Account.h"
#include "Customer.h"
#include "Transaction.h"

class Bank {
    map<string, Customer*> customersByPAN;    // storing customers indexed by PAN number
    map<string, Account*> accountsByNumber;    // storing accounts indexed by account number
    vector<Transaction> transactions;
    Customer* currentCustomer = nullptr;

public:
    void enrollCustomer(Customer* customer);
    bool loginAsCustomer(const string& pan);
    void registerAccount(Account* acc, Customer* owner);
    Account* findAccountByNumber(const string& accNum);
    void addTransaction(const Transaction& t);

    void showAllCustomers();
    void showAllAccounts();
    void showAllTransactions();
};

#endif
