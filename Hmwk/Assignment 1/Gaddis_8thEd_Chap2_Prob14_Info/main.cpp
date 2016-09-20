/* 
   File:   main
   Author: Edward Budiman
   Created on September 19, 2016, 11:46 AM
   Purpose: To view personal identification on one cout line
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
    
    //Input values
    short cargas=15; //Gallons the car holds
    short milestrv=375; //Miles the car can travel on a full tank
    int MPG; //Miles per gallon the car receives
    
    //Process values -> Map inputs to Outputs
    MPG=milestrv/cargas;
    
    //Display Output
    cout<<"The car gets a total of "<<MPG<<" MPG"<<endl;
    
    //Exit Program
    return 0;
}