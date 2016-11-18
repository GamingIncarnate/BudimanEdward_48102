/* 
   File:   main
   Author: Jason Emerson
   Created on September 29th, 2016, 12:00 PM
   Purpose: Enter the sales for regional teams and displays
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <iomanip>
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
float getSales();
void findHighest(float,float,float,float);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    float nEast,sEast,nWest,sWest;
    
    //Input values
    
    //Process values -> Map inputs to Outputs
    
    //Display Output
    cout<<setw(90)<<"Regional Sales:"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Northeast Sales:"<<endl;
    nEast=getSales();
    cout<<endl;
    cout<<"Northwest Sales:"<<endl;
    nWest=getSales();
    cout<<endl;
    cout<<"Southeast Sales:"<<endl;
    sEast=getSales();
    cout<<endl;
    cout<<"Southwest Sales:"<<endl;
    sWest=getSales();
    
    //Output the highest
    findHighest(nWest,sWest,nEast,nWest);

    //Exit Program
    return 0;
}

float getSales(){
    //Declaration of Variables
    float sales;
    
    //Input the sales number for the region
    cout<<"Please input the sales for this region"<<endl;
    cin>>sales;
    
    if(sales<0){
        cout<<"Please input a number greater than 0"<<endl;
    }
    return sales;
}

void findHighest(float nWest,float sWest,float nEast,float sEast){
    if(nWest>nEast&&nWest>sEast){
        if(nWest>sWest)
        {
            cout<<"The Northwest division had the greatest number of sales: $";
            cout<<nWest<<endl;
        }
}
    if(nEast>sEast&&nEast>nWest){
        if(nEast>sWest)
        {
            cout<<"The Northeast division had the greatest number of sales: $";
            cout<<nEast<<endl;
        }
    if(sEast>nEast&&sEast>nWest)
        if(sEast>sWest)
        {
                cout<<"The Southeast division had the greatest number of sales: $";
                cout<<sEast<<endl;
        }
}
    if(sWest>nEast&&sWest>sEast)
    {
        if(sWest>nWest)
        {
            cout<<"The Southwest division had the greatest number of sales: $";
            cout<<sWest<<endl;
        }
}
}