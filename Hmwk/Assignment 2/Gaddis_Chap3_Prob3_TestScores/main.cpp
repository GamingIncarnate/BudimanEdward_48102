/* 
 * File:   main.cpp
 * Author: Edward Budiman
 * Created on September 22, 2016, 12:06 PM
 * Purpose: Calculate miles per gallon
 */

//System Libraries Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    float a, b, c, d, e; //Test scores
    float tot, avg;      //Total and average
    
    //Input or initialize values Here
    cout<<"Input 5 test scores"<<endl; //Asking for scores
    cin>>a; //Score 1
    cin>>b; //Score 2
    cin>>c; //Score 3
    cin>>d; //Score 4
    cin>>e; //Score 5
    
    //Process/Calculations Here
    tot=a+b+c+d+e; //Adding all scores together to get total value
    avg=tot/5; //Divide by number of scores for average
    
    //Output Located Here
    cout<<"The average test score is "<<setprecision(1)<<fixed<<avg<<" points."<<endl; //Displaying the result
    //Exit
    return 0;
}
