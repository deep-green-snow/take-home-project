#ifndef ATMCONTROLLER_H
#define ATMCONTROLLER_H

#include <iostream>
#include <string>

using namespace std;

enum class ATM_STATE : int {
    IDLE,
    CARD_INSERTED,
    PIN_CHECKED,
    ACCOUNT_SELECTED,
};

class ATMController{
    private:
        ATM_STATE _state;
        int _cash;
        int _user;
        int _account;
    
    public:
        ATMController() : _state(ATM_STATE::IDLE), _user(0), _account(0), _cash(0) {}

        // ATM UI
        void resetState();
        void setCash(int cash);
        int getCash();
        int getUser();
        int getAccount();

        int insertCard(int card_number);
        int setPIN(int pin);
        int selectAccount(int account);
        int seeBalance();
        int deposit(int cash);
        int withdraw(int cash);
};

#endif