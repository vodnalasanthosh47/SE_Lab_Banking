#include "Account.h"

long Account::nextAccNum = 1001; // starting account numbers from 1001 (to reduce confusion with transaction IDs)

Account::Account(double initialDeposit)
    : balance(initialDeposit) {
    accountNumber = to_string(nextAccNum++);
    cout << "[Account created]\n" 
         << " ------------------------------------------------\n"
         << "  accountNumber= " << accountNumber << "\n"
         << "  initialDeposit= " << initialDeposit << "\n"
         << "  currentBalance= " << balance << "\n"
         << " ------------------------------------------------\n";
}
Account::Account() {
    Account(0.0);
}

string Account::getAccountNumber() const { 
    return accountNumber; 
}
double Account::getBalance() const { 
    return balance; 
}

bool Account::sendMoney(double amount) {
    if (amount <= 0) {
        cout << "(Account " << accountNumber << ") ERROR: amount to send must be positive\n";
        return false;
    }
    if (balance < amount) {
        cout << "(Account " << accountNumber << ") ERROR: insufficient balance\n";
        return false;
    }
    balance -= amount;
    cout << "(Account " << accountNumber << ") Money sent: " << amount
         << ", newBalance=" << balance << "\n";
    return true;
}

void Account::receiveMoney(double amount) {
    if (amount <= 0) {
        cout << "(Account " << accountNumber << ") ERROR: amount must be positive\n";
        return;
    }
    balance += amount;
    cout << "(Account " << accountNumber << ") Money received: " << amount
         << ", newBalance=" << balance << "\n";
}

void Account::addTransaction(const Transaction& t) {
    transactions.push_back(t);
}

void Account::viewTransactions() const {
    cout << "---- Transactions for Account " << accountNumber << " ----\n";
    if (transactions.empty()) {
        cout << "No transactions yet.\n";
    } else {
        for (const auto& t : transactions) {
            cout << t.toString() << "\n";
        }
    }
    cout << "----------------------------------------------------\n";
}
