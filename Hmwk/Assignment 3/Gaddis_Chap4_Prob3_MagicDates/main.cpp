/* 
   File:   main
   Author: Edward Budiman
   Created on October 4, 2016, 4:06 PM
   Purpose: Determine if the date is magical
 */

//System Libraries
#include <iostream>   //Input/Output objects
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    short month, day, year; //values of th dates
    
    //Input values
    cout<<"Enter in the month by number"<<endl;
    cin>>month;
    
    cout<<"Enter the day of the month"<<endl;
    cin>>day;
    
    cout<<"Enter the last 2 digits of the year"<<endl;
    cin>>year;
    //Process values -> Map inputs to Outputs
    if(year==month*day) //Activate when the year equals the month*day
        cout<<"The date is magical"<<endl;
    else //If the previous requirement is not met
        cout<<"The date is not magical"<<endl;
    //Exit Program
    return 0;
}