/* 
   File:   main
   Author: Edward Budiman
   Created on September 29, 2016, 11:11 AM
   Purpose: Give a percentage of males and females
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <iomanip>    //Manipulating decimal places
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
const char PERCENT=100;
//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    unsigned short nFem, nMal;  //Number of males and females
    float nPpl, perFem, perMal; //Amount of people and their percentages
    
    //Input values
    cout<<"How many males are in the class?"<<endl;
    cin>>nMal; //Amount of males
    
    cout<<"How many females are in the class?"<<endl;
    cin>>nFem; //Amount of females
    
    //Process values -> Map inputs to Outputs
    nPpl=nMal+nFem;
    perFem=nFem/nPpl*PERCENT;
    perMal=nMal/nPpl*PERCENT;
    
    //Display Output
    cout<<"The number of people in the class is "<<nPpl<<endl;
    cout<<"The percentage of females in the class is "<<setprecision(2)<<perFem<<"%"<<endl;
    cout<<"The percentage of males in the class is "<<setprecision(2)<<perMal<<"%"<<endl;
    
    //Exit Program
    return 0;
}
