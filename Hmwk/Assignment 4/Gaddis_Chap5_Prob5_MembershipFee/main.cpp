/* 
 * File:   main.cpp
 * Author: Edward Budiman
 * Created on October 18, 2016, 11:00 AM
 * Purpose:  Calculate the money a club will charge a year for 6 years
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
    short numyers=6;    //Amount of years ahead
    float ppyear=2500;  //Dollars paid per year
    float prcrise=0.04; //Increase in price every year
    
    //Input or initialize values Here
    cout<<"Your initial price is "<<ppyear<<endl; //Display starting Price
    
    //Process/Calculations and Output
    for (short i=1; i<=numyers; i++) //Loop adding 4 percent to price per year
    {
        ppyear+=ppyear*prcrise;
        cout<<"The amount you pay for year "<<i<<" will be "<<ppyear<<endl; 
        
    }
    //Exit
    return 0;
}

