/* 
 * File:   main.cpp
 * Author: Edward Budiman
 * Created on September 19, 2016, 11:33 AM
 * Purpose: Calculate Cost of Stock Purchase
 */

#include <iostream> //Input/Output Libraries
using namespace std; //Libraries compiled under standard namespace

//User Libraries

//Global Constants
const char PERCENT=100;

//Functional Prototypes

//Program Execution Begins Here!
int main(int argc, char** argv) {
    //Declare and Initialize Variables
    unsigned short nShares=750; //Number of Shares
    float ppShare=3.5e1f;       // Price Per Share in $'s
    unsigned char comish=2;     //Commission percentage
    float pricePd, comshPd, totPaid; //Price, Commission, Total Paid $'s
    
    //Calculate the amount paid in $'s
    pricePd=nShares*ppShare;
    comshPd=pricePd*comish/PERCENT;
    totPaid=pricePd+comshPd;
    
    //Output the results
    cout<<"Price of Stock Purchase Problem"<<endl;
    cout<<"Number of Shares Purchased = "<<nShares<<endl;
    cout<<"Price Per share = $"<<ppShare<<endl;
    cout<<"Commission = "<<static_cast<int> (comish)<<"%"<<endl;
    cout<<"Price Paid For the Shares = $"<<pricePd<<endl;
    cout<<"Price Paid in Commission = $"<<comshPd<<endl;
    cout<<"Total Paid               = $"<<totPaid<<endl;
    
    return 0;
}

