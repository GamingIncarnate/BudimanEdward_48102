/* 
   File:   main
   Author: Edward Budiman
   Created on October 4, 2016, 4:33 PM
   Purpose: Determine whether or not a person is overweight, underweight, or optimal
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
    float weight, height;
    float bmi;
    
    //Input values
    cout<<"Enter person's weight"<<endl;
    cin>>weight;
    
    cout<<"Enter person's height in inches"<<endl;
    cin>>height;
   
    //Process values -> Map inputs to Outputs
    bmi=(weight*703)/(height*height);

    //Determine BMI category
    if(bmi<18.5)
        cout<<"This person is underweight"<<endl;
    else if(bmi>25)
        cout<<"This person is overweight"<<endl;
    else
        cout<<"This person is optimal"<<endl;
    
    cout<<"their BMI is "<<bmi<<endl;
    //Exit Program
    return 0;
}