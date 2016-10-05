/* 
   File:   main
   Author: Edward Budiman
   Created on October 4, 2016, 11:11 PM
   Purpose: Give weight in newtons from an object's mass
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
    int mass, weight;
    //Input values
    cout<<"What is the object's mass?"<<endl;
    cin>>mass;
    //Process values -> Map inputs to Outputs
    weight=mass*9.8;
    
    //Determine if too light or too heavy and output result
    if (weight>1000)
        cout<<"This object is too large"<<endl;
    else if (weight<10)
        cout<<"This object is too light"<<endl;
    else
        cout<<"This object is "<<weight<<" newtons"<<endl;
    //Exit Program
    return 0;
}