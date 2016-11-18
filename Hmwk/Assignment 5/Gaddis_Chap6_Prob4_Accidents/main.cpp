/* 
 * File:   main.cpp
 * Author: Edward Budiman
 * Created on November 17, 2016, 10:01 AM
 * Purpose: Calculate which part of the city is safest for driving
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int getAxidnts();
void findLow(int,int,int,int,int);
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int north, south, east, west, central;
    int axidnts=0;
    
    //Input or initialize values Here
    cout<<"This is the north part of town."<<endl;
    north=getAxidnts();
    
    cout<<"This is the south part of town."<<endl;
    south=getAxidnts();
    
    cout<<"This is the east part of town."<<endl;
    east=getAxidnts();
    
    cout<<"This is the west part of town."<<endl;
    west=getAxidnts();
    
    cout<<"This is the central part of town."<<endl;
    central=getAxidnts();
    
    //Process/Calculations Here
    
    //Output Located Here
    findLow(north, south, east, west, central);
    //Exit
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   Problem 1 ****************************************
//Purpose:  Ask for number of accidents and determine if over 0
//Inputs:   Number of accidents
//Output:  Number of accidents
//******************************************************************************
int getAxidnts(){
    int axidnts;
    cout<<"Enter the number of accidents for this area of the city."<<endl;
    cin>>axidnts;
    while (axidnts<0){
        cout<<"The number of accidents can't be less than 0."<<endl<<endl;
        cin>>axidnts;
    }
    return axidnts;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   Problem 1 ****************************************
//Purpose:  Determine which part of town is the most dangerous
//Inputs:   The number of accidents for each part of town
//Output:  A display of which city is the most dangerous and how many accidents
//******************************************************************************
void findLow(int north, int south, int east, int west, int central){
    if (north>south&&north>east&&north>west&&north>central){
        cout<<"The north part of town is the most dangerous with "<<north<<" accidents."<<endl;
    }else if (south>north&&south>east&&south>west&&south>central){
        cout<<"The south part of town is the most dangerous with "<<south<<" accidents."<<endl;
    }else if (east>north&&east>south&&east>west&&east>central){
        cout<<"The east part of town is the most dangerous with "<<east<<" accidents."<<endl;
    }else if (west>north&&west>south&&west>east&&west>central){
        cout<<"The west part of town is the most dangerous with "<<west<<" accidents."<<endl;
    }else{
        cout<<"The central part of town is the most dangerous with "<<central<<" accidents."<<endl;
    }
}