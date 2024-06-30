#include "ATMController.h"

int main()
{
    // #1 Wrong card number
    cout << "-- Test case 1 --" << endl;
    try{
        ATMController atm = ATMController();
        atm.insertCard(0);
    } catch(int msg) {}
        
    // #2 Wrong PIN number
    cout << "-- Test case 2 --" << endl;
    try{
        ATMController atm = ATMController();
        atm.insertCard(1234); 
        atm.setPIN(0001);
    } catch(string msg) {}

    // #3 Wrong account number
    cout << "-- Test case 3 --" << endl;
    try{
        ATMController atm = ATMController();
        atm.insertCard(1234);
        atm.setPIN(0000);
        atm.selectAccount(2);
    } catch(string msg) {}

    // #4 General case (balance/deposit/withdraw)
    cout << "-- Test case 4 --" << endl;
    try{
        ATMController atm = ATMController();
        atm.setCash(500'000);

        atm.insertCard(1234);
        atm.setPIN(0000);
        atm.selectAccount(1);
        
        int balance = atm.seeBalance();
        cout << "current balance : " << balance << endl;
        
        cout << "deposit : 10,000" << endl;
        balance = atm.deposit(10'000);
        cout << "current balance : " << balance << endl;
        
        atm.insertCard(1234);
        atm.setPIN(0000);
        atm.selectAccount(1);

        cout << "withdraw : 30,000" << endl;
        balance = atm.withdraw(30'000);
        cout << "current balance : " << balance << endl;

    } catch(string msg) {}

    return 0;
}