#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <bits/stdc++.h>
using namespace std;

#include "Account.h"

class Bank; // forward declaration

class Customer {
    string name;
    string phoneNumber;
    string emailId;
    string address;
    string PANNumber;
    vector<Account*> accounts;

public:
    Customer(string n, string ph, string email, string addr, string pan);

    string getName() const;
    string getPANNumber() const;
    const vector<Account*>& getAccounts() const;

    Account* openAccount(Bank& bank, double initialDeposit);
    void sendMoney(Account* fromAccount, const string& receiverAccountNumber,
                   double amount, Bank& bank);

    void viewTransactions(Account* account) const;
    void viewBalance(Account* account) const;
};

#endif
