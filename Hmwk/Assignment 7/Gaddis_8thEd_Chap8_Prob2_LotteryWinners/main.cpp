/* 
 * File:   main.cpp
 * Author: Edward Budiman
 * Created on December 2nd, 2016, 8:25 PM
 * Purpose: Determine if a number is a winning number using a Linear Search
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const short SIZE=10;
    short pos=-1;
    int tickets[SIZE]={13579,26791,26792,55555,62483,77777,79422,85647,93121};
    int tick; //User's ticket
    bool found=false; //Set to false while not found
    
    //Input or initialize values 
    cout<<"What is this week's 5 digit winning lottery number?"<<endl;
    cin>>tick;
    
    //Process/Calculations Here
    for (short i=0; i<=SIZE&&!found; i++){
        if (tickets[i]==tick){
            found=true;
            pos=i+1;
        }
    }
    
    //Output Located Here
    if (pos==-1){
        cout<<"Sorry, none of your tickets were the winning ticket."<<endl;
    }else{
        cout<<"Congratulations! Ticket number "<<pos<<" won with number "<<tick<<endl;
    }

    //Exit
    return 0;
}

