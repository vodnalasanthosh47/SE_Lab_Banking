#include "Bank.h"

void Bank::enrollCustomer(Customer* customer) {
    if (customersByPAN.find(customer->getPANNumber()) != customersByPAN.end()) {
        cout << "(Bank) enrollCustomer failed: PAN exists\n";
        return;
    }
    customersByPAN[customer->getPANNumber()] = customer;
    cout << "(Bank) enrollCustomer: " << customer->getName()
         << " enrolled (PAN=" << customer->getPANNumber() << ")\n";
}

bool Bank::loginAsCustomer(const string& pan) {
    if (customersByPAN.find(pan) == customersByPAN.end()) {
        cout << "(Bank) loginAsCustomer failed: no customer with PAN " << pan << "\n";
        return false;
    }
    currentCustomer = customersByPAN[pan];
    cout << "(Bank) loginAsCustomer: currentCustomer=" << currentCustomer->getName() << "\n";
    return true;
}

void Bank::registerAccount(Account* acc, Customer* owner) {
    accountsByNumber[acc->getAccountNumber()] = acc;
    cout << "(Bank) registerAccount: acc=" << acc->getAccountNumber()
         << " registered to " << owner->getName() << "\n";
}

Account* Bank::findAccountByNumber(const string& accNum) {
    if (accountsByNumber.find(accNum) == accountsByNumber.end()) return nullptr;
    return accountsByNumber[accNum];
}

void Bank::addTransaction(const Transaction& t) {
    transactions.push_back(t);
    cout << "(Bank) addTransaction: " << t.toString() << "\n";
}

void Bank::showAllCustomers() {
    cout << "=== Bank Customers ===\n";
    for (auto& kv : customersByPAN)
        cout << "- " << kv.second->getName() << " (PAN=" << kv.first << ")\n";
    cout << "======================\n";
}

void Bank::showAllAccounts() {
    cout << "=== Bank Accounts ===\n";
    for (auto& kv : accountsByNumber)
        cout << "- account=" << kv.first << " balance=" << kv.second->getBalance() << "\n";
    cout << "======================\n";
}

void Bank::showAllTransactions() {
    cout << "=== Bank Transactions ===\n";
    if (transactions.empty()) cout << "No transactions yet.\n";
    for (auto& t : transactions) cout << t.toString() << "\n";
    cout << "========================\n";
}
