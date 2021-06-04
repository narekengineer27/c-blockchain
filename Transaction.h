#ifndef Transaction_H
#define Transaction_H
#include <iostream>

using namespace std;

class Transaction
{
private:
    string SenderKey;
    string ReceivierKey;
    double Amount;
    string Timestamp;
public:
    Transaction();
    Transaction(string, string, size_t = 0.0);
    string TimeStamp();
    string get_Timestamp();
    string get_SenderKey();
    string get_ReceiverKey();
    int get_Amount();
    string AllToString();
};
#endif

Transaction::Transaction(){};

Transaction::Transaction(string Senderkey, string ReceiverKey, size_t Amount)
{
    this->SenderKey = Senderkey;
    this->ReceivierKey = ReceiverKey;
    this->Amount = Amount;
    Timestamp = TimeStamp();

}

string Transaction::TimeStamp()
{
    time_t tt; 
  
    struct tm * ti; 
  
    time (&tt); 
  
    ti = localtime(&tt); 
  
    return asctime(ti); 
}

string Transaction::get_Timestamp()
{
    return Timestamp;
}

string Transaction::get_SenderKey()
{
    return SenderKey;
}

string Transaction::get_ReceiverKey()
{
    return ReceivierKey;
}

int Transaction::get_Amount()
{
    return Amount;
}

string Transaction::AllToString()
{
    string All;
    All = SenderKey + ReceivierKey + to_string(Amount) + Timestamp;
    return All;
}

