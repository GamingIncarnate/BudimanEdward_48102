/* 
   File:   main
   Author: Jason Emerson
   Created on October 15th, 2016, 10:10 AM
   Purpose: List an items wholesale cost and markup percentage.
 */

//System Libraries
#include <iostream>   //Input/Output objects
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
const unsigned char PERCENT=100;

//Function prototypes
void calculateRetail(float,float, float &);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    float price;
    float percent;
    float tMarkup;
    float total = 0;
    
    //Input values
    do{
        cout<<"Please input the wholesale price of the item"<<endl;
        cin>>price;
    }while(price<0);
    do{
        cout<<"Please input the markup percent of the item"<<endl;
        cin>>percent;
    }while(percent<0);
    
    //Process values -> Map inputs to Outputs
    calculateRetail(price,percent,total);
    
    //Display Output
    cout<<"The total price of the item is: $"<<total<<endl;

    //Exit Program
    return 0;
}

void calculateRetail(float price,float percent, float & total){
    //Retail Price Calculations
    total=((price*percent)/PERCENT+price);
}