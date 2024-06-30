#include "ATMController.h"
#include "FakeBankApi.h"

void ATMController::resetState()
{
    _state = ATM_STATE::IDLE;
}

void ATMController::setCash(int cash)
{
    _cash = cash;
}

int ATMController::getCash()
{
    return _cash;
}

int ATMController::getUser()
{
    return _user;
}

int ATMController::getAccount()
{
    return _account;
}

int ATMController::insertCard(int card_number)
{
    int res = 0;
    switch(_state) {
        case(ATM_STATE::IDLE):
            if( FakeBankApi::isValidCard(card_number) >= 0) {
                _user = FakeBankApi::isValidCard(card_number);
                _state = ATM_STATE::CARD_INSERTED;
                res = 1;
            } else {
                cout << "Card number does not exist!" << endl;
            }
            break;
        case(ATM_STATE::CARD_INSERTED):
            cout  << "Card is already inserted!" << endl;
            break;
        case(ATM_STATE::PIN_CHECKED):
            cout  << "Card is already inserted!" << endl;
            break;
        case(ATM_STATE::ACCOUNT_SELECTED):
            cout  << "Card is already inserted!" << endl;
            break;
        default:
            cout  << "default";
            break;
    }

    return res;
}


int ATMController::setPIN(int pin_number)
{
    int res = 0;
    switch(_state) {
        case(ATM_STATE::IDLE):
            cout  << "Insert card first." << endl;
            break;
        case(ATM_STATE::CARD_INSERTED):
            if(FakeBankApi::isValidPin(_user, pin_number) > 0){
                _state = ATM_STATE::PIN_CHECKED;
                res = 1;
            } else {
                cout  << "Wrong PIN number!" << endl;
            }
            break;
        case(ATM_STATE::PIN_CHECKED):
            cout  << "PIN is already checked!" << endl;
            break;
        case(ATM_STATE::ACCOUNT_SELECTED):
            cout  << "PIN is already checked!" << endl;
            break;
        default:
            cout  << "default";
            break;
    }

    return res;
}

int ATMController::selectAccount(int account)
{
    int res = 0;
    switch(_state) {
        case(ATM_STATE::IDLE):
            cout  << "Insert card first." << endl;
            break;
        case(ATM_STATE::CARD_INSERTED):
            cout  << "Insert card first." << endl;
            break;
        case(ATM_STATE::PIN_CHECKED):
            if(FakeBankApi::isValidAccount(_user, account) > 0){
                _account = account;
                _state = ATM_STATE::ACCOUNT_SELECTED;
                res = 1;
            } else {
                cout  << "Wrong account!" << endl;
            }
            break;
        case(ATM_STATE::ACCOUNT_SELECTED):
            cout  << "Account is already selected!" << endl;
            break;
        default:
            cout  << "default" << endl;
            break;
    }

    return res;
}

int ATMController::seeBalance()
{
    if(_state != ATM_STATE::ACCOUNT_SELECTED) return -1;
    return FAKE_ACCOUNT_MAP[_user][_account];
}

int ATMController::deposit(int cash)
{
    if(_state != ATM_STATE::ACCOUNT_SELECTED) return -1;

    int balance = 0;
    if(cash > 0) {
        FAKE_ACCOUNT_MAP[_user][_account] += cash;
        balance = FAKE_ACCOUNT_MAP[_user][_account];
    } else balance = -2;

    _state = ATM_STATE::IDLE;
    resetState();
    
    return balance;
}

int ATMController::withdraw(int cash)
{
    if(_state != ATM_STATE::ACCOUNT_SELECTED) return -1;

    int balance = 0;
    if(FAKE_ACCOUNT_MAP[_user][_account] - cash >= 0){
        FAKE_ACCOUNT_MAP[_user][_account] -= cash;
        balance = FAKE_ACCOUNT_MAP[_user][_account];
    } else balance = -2;
    
    _state = ATM_STATE::IDLE;
    resetState();

    return balance;
}