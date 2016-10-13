/* 
 * File:   main.cpp
 * Author: Edward Budiman
 * Created on October 11, 2016, 12:04 PM
 * Purpose: Add all the numbers in a number
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
    short num, counter; //Enter variable for number inputted and the how many times the loop should repeat
    int sum;            //The end sum of all the numbers
    
    //Input or initialize values Here
    cout<<"Enter a positive number"<<endl; //Ask for a number
    cin>>num;
    
    while (num<0) //Check if positive number
    {
        cout<<"Enter a POSITIVE number"<<endl;
        cin>>num;
    }
    
    //Process/Calculations Here
    for (short counter; counter<=num; counter++) //Utilize for loop
    {
        sum+=counter;
    }
    //Output Located Here
    cout<<"The sum of all numbers within that number is"<<endl;
    cout<<sum<<endl;

    //Exit
    return 0;
}

