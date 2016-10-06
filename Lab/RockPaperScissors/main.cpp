/* 
 * File:   main.cpp
 * Author: Edward Budiman
 * Created on JOctober 6, 2016, 12:26 PM
 * Purpose:  Play Rock Paper Scissors
 */

//System Libraries Here
#include <iostream>  //Input.Output objects
#include <cstdlib>   //Random number generator
#include <ctime>     //Time
using namespace std; //Name-space used in the system library

//User Libraries Here

//Global Constants Only, No Global Variables

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    char computr;  //Computers choice
    char rPlay;     //Our rock/paper/scissors choice
    
    //Input computer values
    computr=rand()%4+80;
    while(computr=='Q'){
        computr=rand()%4+80;
    }
    
    //Input our rock, paper, scissors
    cout<<"Input your choice R-Rock, P-Paper, S-Scissors"<<endl;
    cin>>rPlay;
    switch(rPlay){
        case 'r':
        case 'R':rPlay='R';break;
        case 's':
        case 'S':rPlay='S';break;
        default :rPlay='P';break;
    }
    
    //Output Located Here
    cout<<"The computer generates a "<<computr<<endl;
    cout<<"The player type in a     "<<rPlay<<endl;
    
    //Determine the winner and display
    if(computr==rPlay){
        cout<<"You both tied each other"<<endl;
    }else if(computr=='P'{
        if(rPlay=='S')cout<<"The player wins"<<endl;
        else cout<<"The computer wins"<<endl;
    }else if(computr=='S'){
        if(rPlay=='S')cout<<"The player wins"<<endl;
        else cout<<"The computer wins"<<endl;
    }else{
        if(rPlay=='P')cout<<"The player wins"<<endl;
        else cout<<"The computer wins"<<endl;
    )

    //Exit
    return 0;
}

