#include "Transaction.h"

long Transaction::nextId = 1;

Transaction::Transaction(double amt, const string& sender, const string& receiver) 
    : transactionID(nextId++), 
      amount(amt),
      senderAccountNumber(sender), 
      receiverAccountNumber(receiver) {}

long Transaction::getTransactionID() const {
    return transactionID;
}
double Transaction::getAmount() const {
    return amount;
}
string Transaction::getSenderAccountNumber() const {
    return senderAccountNumber;
}
string Transaction::getReceiverAccountNumber() const {
    return receiverAccountNumber;
}

string Transaction::toString() const {
    ostringstream oss;
    oss << "Transaction(id= " << transactionID << "): "
        << "\n    amount= " << amount
        << "\n    from= " << senderAccountNumber
        << "\n    to= " << receiverAccountNumber;
    return oss.str();
}
