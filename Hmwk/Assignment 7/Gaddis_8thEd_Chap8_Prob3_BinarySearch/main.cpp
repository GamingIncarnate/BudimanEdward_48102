/* 
 * File:   main.cpp
 * Author: Edward Budiman
 * Created on December 1st, 2016, 8:25 PM
 * Purpose: Determine if a number is a winning number using a Binary Search
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
    int first=0; //First Element
    int last=11-1; //Last Element
    int middle; //Middle
    bool found=false; //Set to false while not found
    
    //Input or initialize values 
    cout<<"What is this week's 5 digit winning lottery number?"<<endl;
    cin>>tick;
    
    //Process/Calculations Here
    do{
        middle=(first+last)/2; //Calculate the mid point
        if(tickets[middle]==tick){
            found=true;
            pos=middle;
            cout<<"Congratulations! Ticket number "<<pos<<" won with number "<<tick<<endl;
        }
        else if(tickets[middle]>tick)last=middle-1;
        else first=middle+1;
    }while(found==false&&first<=last);
    
    if(found==false){
        cout<<"Sorry, none of your tickets were the winning ticket."<<endl;
    }

    //Exit
    return 0;
}

