/*
    Althea Leigh Hicks
    A Game of Twenty-Six Implementation file
*/
#include <iostream>

#include "twentySix.h"

using namespace std;

/*
 * twentySix: constructor for twentySix class
 * parameters: int
 */
twentySix::twentySix(int passedInitialBank){
    initialBank = passedInitialBank;
    currentBank = initialBank;
    displayGame = 0;
    pointValue = 0;
    currentScore = 0;
    currentPayout = 0;
    for( int i=0; i<13;i++ ){
        for( int j=0; j<10;j++ ){
            diceRolls[i][j] = 0;
        }
    }
    //diceRolls[13][10] = {0};
    cout << "testing" << endl;
    cout << "extra line" << endl;
}


/*
 * readInitialBankAmount: reads initialBank amount
 * parameters: none
 * return value: void
 */
void twentySix::readInitialBankAmount(){

    cout << "Initial Bank amount must be between 10 and 200" << endl;
    cout << "Enter Initial bank Amount: ";
    cin >> initialBank;
    while(initialBank < MIN_BANK || initialBank > MAX_BANK){
        cout << "Error, invalid bank amount, please re-enter.\n";
        cout << "Initial Bank amount must be between 10 and 200" << endl;
        cout << "Enter Initial bank Amount: ";
        cin >> initialBank;
    }
    currentBank = initialBank;
    
}

/*
 * setInitialBankAmount: sets initial bank amount
 * parameters: int
 * return value: void
 */
void twentySix::setInitialBankAmount(int passedAmount){
    if( !(passedAmount >= MIN_BANK && passedAmount <= MAX_BANK) ){
        cout << "Error, invalid bank amount.\nError, invalid initial bank amount value.\nNo changes made." << endl;
    }    
    initialBank = passedAmount;
    currentBank = initialBank;
}

/*
 * getInitialBankAmount: gets initial bank amount
 * parameters: none
 * return value: int
 */
int twentySix::getInitialBankAmount() const {
    return initialBank;
}

/*
 * getBankAmount: gets bank amount
 * parameters: none
 * return value: int
 */
int twentySix::getBankAmount() const {
    return currentBank;
}

/*
 * setDisplayMode: assigns value to displayGame variable
 * parameters: bool
 * return value: void
 */
void twentySix::setDisplayMode(bool a){
    displayGame = a;
}

/*
 * yesOrNo: prompts user for yes or no response
 * parameters: string
 * return value: bool
 */
bool twentySix::yesOrNo(string userAnswer) const{
    bool yesNoReturn;
    char yesNoAnswer;
    cout << userAnswer << endl;
    cin >> yesNoAnswer;

    //error testing for invalid responses
    while (!(yesNoAnswer == 'Y' || yesNoAnswer == 'y' || yesNoAnswer == 'N' || yesNoAnswer == 'n')){
        cout << "Error, must respond 'Y', 'y', 'N', or 'n'. " << endl;
        cout << "Please try again." << endl;
        cout << userAnswer << endl;
        cin >> yesNoAnswer;

    }

    //Return values based on response
    if( yesNoAnswer == 'Y' || yesNoAnswer == 'y'){
        yesNoReturn = true;
    }
    else if( yesNoAnswer == 'N' || yesNoAnswer == 'n'){
        yesNoReturn = false;
    }
    return yesNoReturn;

}

/*
 * readDisplayMode: asks user if they want to display game details
 * parameters: none
 * return value: void
 */
void twentySix::readDisplayMode(){
    string askDisplay;
    bool displayResponse;
    askDisplay = "Display Game Details? (Y/y/N/n): "; 
    displayResponse = yesOrNo(askDisplay);
    if( displayResponse == true ){
        displayGame = true;
    }
    else if( displayResponse == false ){
        displayGame = false;
    }
}

/*
 * playOn: asks user if they want to play another round
 * parameters: none
 * return value: bool
 */
bool twentySix::playOn() const {
    string askPlayOn;
    bool playOnResponse;
    askPlayOn = "Play Another Round? (Y/y/N/n): ";
    playOnResponse = yesOrNo(askPlayOn);
    if(playOnResponse == true){
        return true;
    }
    else{
        return false;
    }


}

/*
 * playRound: plays one round of twenty-six
 * parameters: none
 * return value: void
 */
void twentySix::playRound(){

    if (currentBank <= 0){
        return;
    }
    else{
        currentBank = currentBank-1;
        pointValue = rand()%6+1;
        for(int i=0;i<13;i++){
            for(int j=0;j<10;j++){
                diceRolls[i][j]= rand()%6+1;
                if (diceRolls[i][j] == pointValue){
                    currentScore++;
                }
            }
        }
        //testing for payout amounts. Adds payout to current bank amount.
        if (currentScore <= 10){
            currentPayout = 10;
            currentBank = currentBank+10;
        }
        else if (currentScore == 13){
            currentPayout = 5;
            currentBank = currentBank+5;
        }
        else if (currentScore == 26){
            currentPayout = 4;
            currentBank = currentBank+4;
        }
        else if (currentScore == 27){
            currentPayout = 5;
            currentBank = currentBank+5;
        }
        else if (currentScore == 28){
            currentPayout = 6;
            currentBank = currentBank+6;
        }
        else if (currentScore == 29){
            currentPayout = 8;
            currentBank = currentBank+8;
        }
        else if (currentScore == 30){
            currentPayout = 10;
            currentBank = currentBank+10;
        }
        else 
            currentPayout = 0;
        
        if(displayGame == true){
            showGame();
        }
    }
    currentScore = 0;

}

/*
 * showGame: displays game results
 * parameters: none
 * return value: void
 */
void twentySix::showGame() const{
    cout << endl << "*********************************" << endl;
    cout << "Twenty-Six Game - Round Results: " << endl;
    cout << "Dice Rolls: " << endl;
    for (int i=0; i<13; i++) {
    for (int j=0; j<10; j++)
    cout << "   " << diceRolls[i][j];
    cout << endl;
    }
    cout << endl;
    cout << "Initial Bank: " << initialBank << endl;
    cout << "Point Value: " << pointValue << endl;
    cout << "Score: " << currentScore << endl;
    cout << "Payout Amount: " << currentPayout;
    if (currentPayout > 0)
    cout << " You won! :-)" << endl;
    else
    cout << " You lost. :-(" << endl;
    cout << "Current Bank: " << currentBank << endl;
    cout << endl;
}
