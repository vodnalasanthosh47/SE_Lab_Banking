#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <bits/stdc++.h>
using namespace std;

class Transaction {
    static long nextId;    // using static variable to make unique IDs
    long transactionID;
    double amount;
    string senderAccountNumber;
    string receiverAccountNumber;

public:
    Transaction(double amt, const string& sender, const string& receiver);

    long getTransactionID() const;
    double getAmount() const;
    string getSenderAccountNumber() const;
    string getReceiverAccountNumber() const;

    string toString() const;
};

#endif
