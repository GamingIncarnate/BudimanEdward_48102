/* 
   File:   main
   Author: Edward Budiman
   Created on September 29, 2016, 12:02 PM
   Purpose: Calculate the profits of a movie theater
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <iomanip>    //Manipulating decimal places
#include <string>     //Custon names
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    string namMovi;
    int nAdTix, nKidTix;
    float gboprof, nboprof, distrib;  //Gross and Net Box Office Profit + Distributor Profit
    
    //Input values
    cout<<"Enter name of movie:"<<endl;
    getline(cin, namMovi);
    
    cout<<"Enter number of adult tickets sold."<<endl;
    cin>>nAdTix;
    
    cout<<"Enter number of child tickets sold."<<endl;
    cin>>nKidTix;
  
    //Process values -> Map inputs to Outputs
    gboprof=nAdTix*10+nKidTix*6;
    nboprof=gboprof*0.2;
    distrib=gboprof-nboprof;
    
    //Display Outputs
    cout<<"Movie Name:                  "<<namMovi<<endl;
    cout<<"Adult Tickets Sold:          "<<nAdTix<<endl;
    cout<<"Child Tickets Sold:          "<<nKidTix<<endl;
    cout<<"Gross Profits =              $"<<setprecision(2)<<fixed<<gboprof<<endl;
    cout<<"Net Profits =                $"<<setprecision(2)<<fixed<<nboprof<<endl;
    cout<<"Amount Paid to Distributor = $"<<setprecision(2)<<fixed<<distrib<<endl;
    
    //Exit Program
    return 0;
}