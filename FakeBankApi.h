constexpr int USER_NUMBER = 2;
constexpr int MAX_ACCOUNT_NUMBER = 3;

static int FAKE_USER_INFO[USER_NUMBER][3] = {{1234, 0000, 2}, // {Card number, Pin number, Number of account} 
                                             {5678, 7777, 1}};
static int FAKE_ACCOUNT_MAP[USER_NUMBER][MAX_ACCOUNT_NUMBER] = {{50'000, 100'000, -1},
                                                                {200'000, -1, -1}};

class FakeBankApi{
    public:
        static int isValidCard(int card_number){
            for(int i = 0 ; i < USER_NUMBER ; i++){
                if(FAKE_USER_INFO[i][0] == card_number) return i;
            }
            return -1;
        }

        static int isValidPin(int user, int pin_number){
            if(FAKE_USER_INFO[user][1] == pin_number) return 1;
            else return -1;
        }

        static int isValidAccount(int user, int account_idx){
            if(account_idx < FAKE_USER_INFO[user][2]) return 1;
            else return -1;
        }
};