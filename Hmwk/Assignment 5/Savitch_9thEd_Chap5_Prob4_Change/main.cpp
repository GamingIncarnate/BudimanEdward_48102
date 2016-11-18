/* 
   File:   main
   Author: Jason Emerson
   Created on Nov 2nd, 2016, 12:00 PM
   Purpose:  Calculate Change
 */

//System Libraries
#include <iostream>   //Input/Output objects
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
void dollars(int,int &,int &,int &,int &,int &);
void cents(int,int &,int &,int &,int &);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    int n50s,n20s,n10s,n5s,n1s;       //Dollar quantities
    int quarter,dimes,nickles,pennies;//Coin quantities
    float tender,price;               //Price and Tendered amounts
    int tDolr,tCent,pDolr,pCent;      //Price and Tendered dollars and cents
    
    //Input values
    do{
        cout<<"This program calculates the exact change"<<endl;
        cout<<"What is the price of the purchase = $"<<endl;
        cin>>price;
        cout<<"What is the tendered amount = $ > Price"<<endl;
        cin>>tender;
    }while(tender-price<0);
    
    //First step calculate dollars and cents
    pDolr=price+0.005f;           //Partial penny
    pCent=(price-pDolr)*100+0.005;//Number of cents with partial penny   
    tDolr=tender+0.005f;           //Partial penny
    tCent=(tender-tDolr)*100+0.005;//Number of cents with partial penny
    
    //Display the amounts
    cout<<"The price input     = $"<<pDolr<<"."<<pCent<<endl;
    cout<<"The tendered amount = $"<<tDolr<<"."<<tCent<<endl;
    if(tCent-pCent<0){
        tDolr--;
        tCent+=100;
    }
    cout<<"The change amount   = $"<<tDolr-pDolr<<"."<<tCent-pCent<<endl;
    
    //Calculate the Change
    dollars(tDolr-pDolr,n50s,n20s,n10s,n5s,n1s);
    cout<<n50s<<" number of 50's"<<endl;
    cout<<n20s<<" number of 20's"<<endl;
    cout<<n10s<<" number of 10's"<<endl;
    cout<<n5s<<" number of 5's"<<endl;
    cout<<n1s<<" number of 1's"<<endl;
    
    //Calculate the Change
    cents(tCent-pCent,quarter,dimes,nickles,pennies);
    cout<<quarter<<" number of quarter's"<<endl;
    cout<<dimes<<" number of dimes's"<<endl;
    cout<<nickles<<" number of nickle's"<<endl;
    cout<<pennies<<" number of penny's"<<endl;

    //Exit Program
    return 0;
}

void cents(int d,int &n25s,int &n10s,int &n5s,int &n1s){
    //Calculate the change
    n25s=d/25;  //How many 25's
    d-=25*n25s;
    n10s=d/10;  //How many 10's
    d-=10*n10s;
    n5s=d/5;    //How many 5's
    d-=5*n5s;
    n1s=d;
}

void dollars(int d,int &n50s,int &n20s,int &n10s,int &n5s,int &n1s){
    //Calculate the change
    n50s=d/50;  //How many 50's
    d-=50*n50s;
    n20s=d/20;  //How many 20's
    d-=20*n20s;
    n10s=d/10;  //How many 10's
    d-=10*n10s;
    n5s=d/5;    //How many 5's
    d-=5*n5s;
    n1s=d;
}