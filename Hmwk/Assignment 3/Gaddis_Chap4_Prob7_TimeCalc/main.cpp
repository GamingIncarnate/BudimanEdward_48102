/* 
   File:   main
   Author: Edward Budiman
   Created on October 4, 2016, 11:16 PM
   Purpose: calculate length of time from seconds inputed
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
    float sec, mins, hours, days; //Precise amount of minutes, hours, and days
    
    //Input values
    cout<<"How many seconds?"<<endl;
    cin>>sec;
    
    //Calculate minutes, hours, and days from seconds
    mins=sec/60;
    hours=sec/3600;
    days=sec/86400;
    
    //Display time
    if (sec>=86400)                                            //Displays in days
        cout<<sec<<" seconds equals "<<days<<" days"<<endl;
    else if (sec>=3600)                                        //Displays in hours
        cout<<sec<<" seconds equals "<<hours<<" hours"<<endl;
    else if (sec>=60)                                          //Displays in minutes
        cout<<sec<<" seconds equals "<<mins<<" minutes"<<endl;
    else if (sec>=0)                                           //Displays in seconds
        cout<<sec<<" seconds equals "<<sec<<" seconds"<<endl;
           
    //Exit Program
    return 0;
}