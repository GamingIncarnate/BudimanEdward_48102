/* 
 * File:   main.cpp
 * Author: Edward Budiman
 * Created on October 13, 2016, 12:26 PM
 * Purpose: Guessing game
 */

//System Libraries Here
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    int range, nGuess;
    int number, answer;
    
    //Input or initialize values Here
    cout<<"This is the guessing game"<<endl;
    cout<<"Choose a range for the number to guess"<<endl;
    cin>>range;
    
    //Process/Calculations Here
    nGuess=log(range)/log(2);
    cout<<"You have "<<nGuess<<" guesses to find the random number"<<endl;
    number=rand()%(range+1); //[0, range]
    
    //Display the results of each guess
    for(int guess=1;guess<=nGuess;guess++){
        cout<<"Input your guess"<<endl;
        cin>>answer;
        if(answer>number)cout<<"Guess too high"<<endl;
        else if(answer<number)cout<<"Guess too low"<<endl;
        else{
            cout<<"  "<<endl;
            cout<<"You guessed the number"<<endl;
            exit(0);
        }
    }
    cout<<"  "<<endl;
    cout<<"Sorry too many guesses"<<endl;

    //Exit
    return 0;
}
