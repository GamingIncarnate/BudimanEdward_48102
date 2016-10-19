/* 
   File:   main
   Author: Edward Budiman
   Created on October 18th, 2016, 10:00 PM
   Purpose: Display number of rooms occupied, unoccupied on each floor
 */

//System Libraries
#include <iostream>   //Input/Output objects
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declaration of Variables
    unsigned short numFlrs; //Number of floors
    unsigned short numRoom; //Number of rooms on each floor
    unsigned short numOpd; //Number of occupied rooms
    unsigned short totRoom=0; //Total number of rooms
    unsigned short totOpd=0; //Total number of occupied rooms
    float roomOcc; //Number of rooms occupied
    
    //Input Rooms
    cout<<"How many floors are in the hotel?";
    cin>>numFlrs;
    
    while (numFlrs < 1)
    {
        cout<<"Number of floors must be 1 or above. Please enter again";
        cin>>numFlrs;
    }
    
    //Process values -> Map inputs to Outputs
    for (int i = 1; i <=numFlrs; i++) {
        if (i==13){
            i++;
        }
        cout<<"Floor "<<i<<endl;
        cout<<"Please enter the number of rooms:"<<endl;
        cin>>numRoom;
        
        cout<<"Please enter the number of rooms occupied:"<<endl;
        cin>>numOpd;
        
        while (numOpd<10){
            cout<<"The number of rooms must be 10 or above. Please enter again";
            cin>>numOpd;
        }
        
        totRoom+=numRoom;
        totOpd+=numOpd;
    }
    
    roomOcc=static_cast<float>(totOpd)/totRoom*100;
    
    //Display Output
    cout<<"Total number of floors          : "<<numFlrs<<endl;
    cout<<"Total number of rooms           : "<<totRoom<<endl;
    cout<<"Total number of occupied rooms  : "<<totOpd<<endl;
    cout<<"The percentage of rooms occupied: "<<roomOcc<<"%"<<endl;

    //Exit Program
    return 0;
}