/* 
   File:   main
   Author: Edward Budiman
   Created on September 19, 2016, 12:45 PM
   Purpose: To calculate total sales tax on a purchase
 */

//System Libraries
#include <iostream>   //Input/Output objects
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
const char PERCENT=100;
//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    int item=95;      //Item purchased
    int statetx=4;    //State tax
    float countx=2;  //Sales tax
    float tottx;      //Total amount paid in taxes
    
    //Process values -> Calculate total amount of taxes
    tottx=((item*statetx)+(item*countx))/PERCENT;  //Equation for amount paid in taxes
    
    //Display Output
    cout<<"Price of item = "<<item<<endl;
    cout<<"State sales tax = "<<statetx<<endl;
    cout<<"County sales tax = "<<countx<<endl;
    cout<<"The total amount of money paid in taxes = $"<<tottx<<endl;
           
    //Exit Program
    return 0;
}
