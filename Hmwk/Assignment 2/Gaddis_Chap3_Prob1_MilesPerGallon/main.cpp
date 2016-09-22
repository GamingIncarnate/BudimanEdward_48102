/* 
 * File:   main.cpp
 * Author: Edward Budiman
 * Created on September 22, 2016, 11:30 AM
 * Purpose: Calculate miles per gallon
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
    short galhld, mlsdrv;
    float mpg;
    
    //Input or initialize values Here
    cout<<"How many gallons in your car?"<<endl;
    cin>>galhld;
    
    cout<<"How many miles from a full tank?"<<endl;
    cin>>mlsdrv;
    
    //Process/Calculations Here
    mpg=mlsdrv/galhld;
    
    //Output Located Here
    cout<<"Your MPG is "<<mpg<<endl;

    //Exit
    return 0;
}

