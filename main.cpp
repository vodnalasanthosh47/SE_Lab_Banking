#include <bits/stdc++.h>
using namespace std;

#include "Bank.h"
#include "Customer.h"

int main() {
    cout << "=============== Bank Demo Starting ===============\n";

    Bank bank;

    // Created customers outside the bank class to simplify stuff
    Customer Ramesh("Alice", "1234567890", "Ramesh@example.com", "Bhaskara B812", "PAN_RAMESH_01");
    cout << "\n";
    Customer Vishish("Bob", "0987654321", "Vishish@example.com", "Visvesvaraya V547", "PAN_VISHISH_02");
    cout << "\n";

    bank.enrollCustomer(&Ramesh);
    cout << "\n";
    bank.enrollCustomer(&Vishish);
    cout << "\n";

    Account* RameshAcc1 = Ramesh.openAccount(bank, 1000.0);
    cout << "\n";
    Account* RameshAcc2 = Ramesh.openAccount(bank, 500.0);
    cout << "\n";
    Account* VidhishAcc1   = Vishish.openAccount(bank, 300.0);
    cout << "\n";

    bank.showAllCustomers();
    cout << "\n";
    bank.showAllAccounts();
    cout << "\n";

    bank.loginAsCustomer(Ramesh.getPANNumber());
    cout << "\n";
    Ramesh.sendMoney(RameshAcc1, VidhishAcc1->getAccountNumber(), 200.0, bank);
    cout << "\n";

    Ramesh.viewBalance(RameshAcc1);
    cout << "\n";
    Ramesh.viewBalance(RameshAcc2);
    cout << "\n";
    Vishish.viewBalance(VidhishAcc1);
    cout << "\n";

    Ramesh.viewTransactions(RameshAcc1);
    cout << "\n";
    Vishish.viewTransactions(VidhishAcc1);
    cout << "\n";

    Ramesh.sendMoney(RameshAcc2, VidhishAcc1->getAccountNumber(), 50.0, bank);
    cout << "\n";

    bank.showAllTransactions();
    cout << "\n";

    Ramesh.viewTransactions(RameshAcc1);
    cout << "\n";
    Ramesh.viewTransactions(RameshAcc2);
    cout << "\n";
    Vishish.viewTransactions(VidhishAcc1);
    cout << "\n";

    cout << "=============== Bank Demo Completed ===============\n";
    return 0;
}
