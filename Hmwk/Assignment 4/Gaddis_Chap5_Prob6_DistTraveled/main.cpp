/* 
 * File:   main.cpp
 * Author: Edward Budiman
 * Created on October 18, 2016, 11:48 AM
 * Purpose: Calculate distance based on speed and time
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
    float speed, distance;
    short time;
    short incrTime=1;
     
    //Input or initialize values Here
    cout<<"This program calculates distance based on speed and time."<<endl;
    cout<<"Enter the speed of the car in miles per hour."<<endl;
    cin>>speed;
    cout<<"Enter the amount of time it has traveled in hours."<<endl;
    cin>>time;
    
    while (speed<0){
        cout<<"Enter a positive speed"<<endl;
        cin>>speed;
    }
    while (time<1){
        cout<<"Enter a time longer than 1 hour"<<endl;
        cin>>time;
    }
    //Process/Calculations Here
    cout<<"Hour  Distance Traveled"<<endl;
    cout<<"----------------------------"<<endl;
    
    for (short i=1; i<=time; i++){
        distance=speed*incrTime;
        cout<<incrTime<<"             "<<distance<<" miles"<<endl;
        incrTime++;
    }
    //Output Located Here
    

    //Exit
    return 0;
}

