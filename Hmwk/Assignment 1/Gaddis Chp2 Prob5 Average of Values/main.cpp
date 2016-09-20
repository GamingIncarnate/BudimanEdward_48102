/* 
   File:   main
   Author: Edward Budiman
   Created on September 19, 2016, 1:23 PM
   Purpose: Calculate the average value of 5 variables
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
    short a=28;  //Variable 1
    short b=32;  //Variable 2
    short c=37;  //Variable 3
    short d=24;  //Variable 4
    short e=33;  //Variable 5
    short sum, avg;  //Further variable and end result 
    
    //Process values -> Map inputs to Outputs
    //Figure out the average value
    sum=a+b+c+d+e;
    avg=sum/5;
    //Display Output
    cout<<"The average value of "<<a<<", "<<b<<", "<<c<<", "<<d<<", and "<<e<<" is "<<avg<<endl;
    
    //Exit Program
    return 0;
}

