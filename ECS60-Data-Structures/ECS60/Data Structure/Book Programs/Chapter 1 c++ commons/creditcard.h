#ifndef CREDITCARD_H
#define CREDITCARD_H
#include<string>
#include<iostream>
using namespace std;

class CreditCard
{
 private:
   string number;
   string name;
   int limit;
   double balance;
 public:
   CreditCard(string no,string nm,int lim,double bal = 0)
   {
    number = no;
    name = nm;
    limit = lim;
    balance = bal;
   }
   
   string getNumber()
   { return number; }
   
   string getName()
   { return name; }
   
   int getLimit()
   { return limit; }
    
   double getBalance()
   { return balance; }
   
   bool chargeIt(double price);
   void makePayment(double payment);
   
};
ostream &operator<<(ostream &out,CreditCard &c);
#endif  

/*CreditCard::CreditCard(string no,string nm,int lim,double bal=0)
{
 number = no;
 name = nm;
 limit = lim;
 balance = bal;
}*/

bool CreditCard::chargeIt(double price)
{
 if(price + balance > double(limit))
  return false;
 balance += price;
  return true;
}

void CreditCard::makePayment(double payment)
{
 balance -= payment;
}

ostream &operator<<(ostream &out,CreditCard &c)
{
 out << "Number = " << c.getNumber() << "\n"
     << "Name = " << c.getName() << "\n"
     << "Balance = " << c.getBalance() << "\n"
     << "Limit = " << c.getLimit() << "\n";
 return out;
}
