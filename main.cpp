
#undef NDEBUG

#include <cassert> 
#include <iostream>
#include <cmath>
#include "random.h"
bool guessLogic(int correctNumber, int guess){
    if(correctNumber==guess){
        std::cout << "Correct! You win!\n";
        return true;
    }
    std::cout <<"Your guess is too "<< (guess>correctNumber ? "high\n":"low\n");
    return false;
}
bool guessAttempt(int correctNumber, int attemptNumber, int minGuess, int maxGuess){
    std::cout << "Guess #"<<attemptNumber<<": ";
    int guess{};
    while(true){
    	std::cin >> guess;
    	bool success{std::cin};
    	std::cin.clear();
    	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    	if(!success||guess<minGuess|| guess>maxGuess){
    	    continue;
    	}
    return guessLogic(correctNumber,guess);
    }
}
bool playGame(int minGuess, int maxGuess){
    int numberToGuess {Random::get(minGuess,maxGuess)};
    for(int i{1}; i<=7; i++){
        if(guessAttempt(numberToGuess,i,minGuess,maxGuess)){
            return true;
        }
    }
    std::cout << "Sorry, you lose. The correct number was "<<numberToGuess<<".\n";
    return false;
}
void gameplayLoop(int minGuess, int maxGuess){
    bool boolIsValidInput{true};
    do{
        if(boolIsValidInput){playGame(minGuess,maxGuess);}
        std::cout <<"Would you like to play again?(Y/n)";
        char input {};
        std::cin >> input;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if(input=='Y'){
            boolIsValidInput=true;
            continue;
        }
        if(input=='n'){
            std::cout << "Thank you for playing.";
            return;
        }
        boolIsValidInput=false;
    }while(true);
}
int main()
{
    std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is.\n";
    gameplayLoop(1,100);
    return 0;
}