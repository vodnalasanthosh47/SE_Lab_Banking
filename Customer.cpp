#include "Customer.h"
#include "Bank.h"

Customer::Customer(string n, string ph, string email, string addr, string pan)
    : name(n), 
      phoneNumber(ph), 
      emailId(email), 
      address(addr), 
      PANNumber(pan) {
    cout << "(New Customer created) name=" << name
         << ", PAN=" << PANNumber << "\n";
}

string Customer::getName() const {
    return name;
}
string Customer::getPANNumber() const {
    return PANNumber;
}
const vector<Account*>& Customer::getAccounts() const {
    return accounts;
}

Account* Customer::openAccount(Bank& bank, double initialDeposit) {
    Account* acc = new Account(initialDeposit);
    accounts.push_back(acc);
    bank.registerAccount(acc, this);
    cout << "(Customer " << name << ") created Account: " << acc->getAccountNumber() << "\n";
    return acc;
}

void Customer::sendMoney(Account* fromAccount, const string& receiverAccountNumber,
                         double amount, Bank& bank) {
    cout << "(Customer " << name << ") Attempting sendMoney from "
         << fromAccount->getAccountNumber() << " to " << receiverAccountNumber
         << " amount=" << amount << "\n";

    bool isFromAccountCustomers = false;    // check if the customer owns the fromAccount
    for (auto* acc : accounts) if (acc == fromAccount) isFromAccountCustomers = true;
    if (!isFromAccountCustomers) {
        cout << "ERROR: account does not belong to this customer.\n";
        return;
    }

    Account* receiver = bank.findAccountByNumber(receiverAccountNumber);
    if (!receiver) {
        cout << "ERROR: receiver account not found.\n";
        return;
    }

    if (!fromAccount->sendMoney(amount)) return;
    receiver->receiveMoney(amount);

    Transaction t(amount, fromAccount->getAccountNumber(), receiverAccountNumber);
    fromAccount->addTransaction(t);
    receiver->addTransaction(t);
    bank.addTransaction(t);

    cout << "(Customer " << name << ") sendMoney successful. Transaction ID: "
         << t.getTransactionID() << "\n";
}

void Customer::viewTransactions(Account* account) const {
    cout << "(Customer " << name << ") viewTransactions for account "
         << account->getAccountNumber() << "\n";
    account->viewTransactions();
}

void Customer::viewBalance(Account* account) const {
    cout << "(Customer " << name << ") viewBalance: account="
         << account->getAccountNumber() << " balance="
         << account->getBalance() << "\n";
}
