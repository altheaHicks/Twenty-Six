/*
    Name: Althea Leigh Hicks
    Description: Header file twentySix.h for Twenty Six Dice Game

*/
#ifndef CLASS_H
#define CLASS_H
#include <iostream>
using namespace std;


/*
 *class twentySix: class declaring variables and functions for game of Twenty-Six
 *constructors: twentySix(int=10)
 *public functions: twentySix(int=10);
                    void readInitialBankAmount();
                    void setInitialBankAmount(int);
                    int getInitialBankAmount() const;
                    int getBankAmount() const;
                    void setDisplayMode(bool);
                    void readDisplayMode();
                    bool playOn() const;
                    void playRound();
 *static members:   static constexpr int MIN_BANK = 10;
                    static constexpr int MAX_BANK = 200;
 * 
 */

class twentySix{
    
        int initialBank;
        int currentBank;
        bool displayGame;
        int pointValue;
        int currentScore;
        int currentPayout;
        int diceRolls[13][10];
        static constexpr int MIN_BANK = 10;
        static constexpr int MAX_BANK = 200;
        bool yesOrNo(string) const;
        void showGame() const;

    public:
        twentySix(int=10);
        void readInitialBankAmount();
        void setInitialBankAmount(int);
        int getInitialBankAmount() const;
        int getBankAmount() const;
        void setDisplayMode(bool);
        void readDisplayMode();
        bool playOn() const;
        void playRound();



};

#endif