#include<iostream>
#include<vector>
#include"creditcard.h"
using namespace std;

int main()
{
 vector<CreditCard*>wallet(10); // vector of 10 credit card pointers
 
 //allocating three cards
 wallet[0] = new CreditCard("530 432 423","John Doe",2500);
 wallet[1] = new CreditCard("530 564 545","Steven",5000);
 wallet[2] = new CreditCard("584 544 445","Demartini",3500);
 
 for(int j=1;j<=16;j++)
 {
  wallet[0]->chargeIt(double(j));  //Explicitly cast to double
  wallet[1]->chargeIt(2*j);        //Implicitly cast to double
  wallet[2]->chargeIt(double(3*j));
 }
 
 cout << "Card Payments:\n";
 for(int i=0;i<3;i++)
 {
  cout << *wallet[i];
  while(wallet[i]->getBalance() > 100.0)
  {
   wallet[i]->makePayment(100.0);
   cout << "New Payment = " << wallet[i]->getBalance() << "\n";
  }
  cout << "\n";
  delete wallet[i];
 }

system("pause");    
return 0;
}
