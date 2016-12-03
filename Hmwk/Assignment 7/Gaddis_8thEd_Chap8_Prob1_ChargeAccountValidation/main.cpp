/* 
 * File:   main.cpp
 * Author: Edward Budiman
 * Created on November 29th, 2016, 12:10 PM
 * Purpose: User inputs a charge number and checks it to see if it is valid with the current charge numbers in an array
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
    const int SIZE=18;
        //Account Numbers Below
    int accounts[SIZE]={5658845,4520125,7895122,8777541,8451277,1302850,8080152,
                     4562555,5552012,5050552,7825877,1250255,1005231,6545231,
                     3852085,7576651,7881200,4581002};
    int accNum; //Account Number Being Input
    bool found=false; //Exit Loop
    
    //Input or initialize values Here
    cout<<"Please input the Account Number:"<<endl;
    cin>>accNum;
    
    //Simple Linear Search
    for(int i=1;i<18&&found==false;i++){
        if(accNum==accounts[i])found=true;
    }
    
    //Output Located Here
    if(found==true)cout<<"Number is valid"<<endl;
    else{
        cout<<"Number is invalid"<<endl;
    }

    //Exit
    return 0;
}

