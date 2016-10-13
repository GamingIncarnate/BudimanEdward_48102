/* 
 * File:   main.cpp
 * Author: Edward Budiman
 * Created on October 11, 2016, 12:21 PM
 * Purpose:  Display sea level rise in a table
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
    float rise=1.5e0f;
    float level;
    short years;
    
    //Process/Calculations Here
    for (years=0; years<=25; years++)
    {
        level+=rise;
        cout<<"The level of the sea after "<<years<<" years is "<<level<<endl;
    }
    
    //Exit
    return 0;
}



