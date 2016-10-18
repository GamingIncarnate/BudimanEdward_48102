/* 
 * File:   main.cpp
 * Author: Edward Budiman
 * Created on October 18, 2016, 12:19 PM
 * Purpose: Calculate amount of money earned if you earned a penny a day doubled for x amount of days
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
    float earned;
    int pennies=1;
    float totpen=0;
    short days;
    //Input or initialize values Here
    cout<<"This program calculates how much money you would make if you earned a penny and doubled it each day"<<endl;
    cout<<"Enter an amount of days to work"<<endl;
    cin>>days;
    
    while (days<1){
        cout<<"Pretend you work for more than a day. Enter a number of days greater than 1"<<endl;
        cin>>days;
    }
    
    //Process/Calculations Here
    cout<<"Days  Pennies Earned"<<endl;
    cout<<"--------------------"<<endl;
    
    for (short i=1; i<=days; i++){
        cout<<i<<"          "<<pennies<<endl;
        totpen+=pennies;
        pennies=pennies*2;
    }
    
    //Output Located Here
    cout<<"You made "<<totpen<<" pennies, or "<<totpen/100<<" dollars"<<endl;
    //Exit
    return 0;
}

