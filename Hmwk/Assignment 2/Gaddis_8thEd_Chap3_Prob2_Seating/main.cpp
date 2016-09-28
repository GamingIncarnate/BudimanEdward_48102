/* 
   File:   main
   Author: Edward Budiman
   Created on September 22, 2016, 11:30 AM
   Purpose: Find the amount of each ticket sold and then calculate the total income with a fixed decimal notation of 2
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <iomanip>    //Formating

using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    short numA,numB,numC; //Number of each ticket sold
    float costA,costB,costC; //Cost of Seats A,B and C for tickets
    float tot; //Total income of all the tickets
   
    
    //Input values
    cout<<"How many Class A tickets were sold?"<<endl;
    cin>>numA;
    cout<<"How many Class B tickets were sold?"<<endl;
    cin>>numB;
    cout<<"How many Class C tickets were sold?"<<endl;
    cin>>numC;
    
    //Process values -> Map inputs to Outputs
    costA=15*numA; //$15 multiplied by the number of Class A tickets sold
    costB=12*numB; //$12 multiplied by the number of Class B tickets sold
    costC=9*numC; //$9 multiplied by the number of Class C tickets sold
    tot=costA+costB+costC; //Total income of all the tickets
           
    //Display Output
    cout<<"The total income from all ticket sales is $"<<setprecision(2)<<fixed<<tot<<endl;

    //Exit Program
    return 0;
}