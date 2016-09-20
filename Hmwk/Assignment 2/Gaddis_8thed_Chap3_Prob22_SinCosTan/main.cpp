/* 
 * File:   main.cpp
 * Author: Edward Budiman
 * Created on September 20, 2016, 12:13 PM
 * Purpose:  Hello World Template
 */

//System Libraries Here
#include <iostream>  //Input/Output objects
#include <iomanip>   //Formatting
#include <cmath>     //Sin Cos Tan
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
const float PI=4*atan(1.0);//PI
const float CNVDEGR=PI/180;//Conversion form degrees to radians
//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    float deg,radians;
    //Input or initialize values Here
    deg+=5;
    radians=deg*CNVDEGR;
    
    //Output
    cout<<"[Degrees, Radians,     Sine,  Cosine, Tangent]"<<endl;
    cout<<fixed<<showpoint<<setprecision(5);
    cout<<"{"<<setw(8)<<deg<<","<<setw(8)<<radians
            <<","<<setw(8)<<sin(radians)<<","<<setw(8)<<cos(radians)
            <<","<<setw(8)<<tan(radians)<<"]"<<endl;
        //Input or initialize values Here
    deg+=5;
    radians=deg*CNVDEGR;
    
    //Output
    cout<<fixed<<showpoint<<setprecision(5);
    cout<<"{"<<setw(8)<<deg<<","<<setw(8)<<radians
            <<","<<setw(8)<<sin(radians)<<","<<setw(8)<<cos(radians)
            <<","<<setw(8)<<tan(radians)<<"]"<<endl;
        //Input or initialize values Here
    deg+=5;
    radians=deg*CNVDEGR;
    
    //Output
    cout<<fixed<<showpoint<<setprecision(5);
    cout<<"{"<<setw(8)<<deg<<","<<setw(8)<<radians
            <<","<<setw(8)<<sin(radians)<<","<<setw(8)<<cos(radians)
            <<","<<setw(8)<<tan(radians)<<"]"<<endl;
        //Input or initialize values Here
    deg+=5;
    radians=deg*CNVDEGR;
    
    //Output
    cout<<fixed<<showpoint<<setprecision(5);
    cout<<"{"<<setw(8)<<deg<<","<<setw(8)<<radians
            <<","<<setw(8)<<sin(radians)<<","<<setw(8)<<cos(radians)
            <<","<<setw(8)<<tan(radians)<<"]"<<endl;
        //Input or initialize values Here
    deg+=5;
    radians=deg*CNVDEGR;
    
    //Output
    cout<<fixed<<showpoint<<setprecision(5);
    cout<<"{"<<setw(8)<<deg<<","<<setw(8)<<radians
            <<","<<setw(8)<<sin(radians)<<","<<setw(8)<<cos(radians)
            <<","<<setw(8)<<tan(radians)<<"]"<<endl;
        //Input or initialize values Here
    deg+=5;
    radians=deg*CNVDEGR;
    
    //Output
    cout<<fixed<<showpoint<<setprecision(5);
    cout<<"{"<<setw(8)<<deg<<","<<setw(8)<<radians
            <<","<<setw(8)<<sin(radians)<<","<<setw(8)<<cos(radians)
            <<","<<setw(8)<<tan(radians)<<"]"<<endl;
        //Input or initialize values Here
    deg+=5;
    radians=deg*CNVDEGR;
    
    //Output
    cout<<fixed<<showpoint<<setprecision(5);
    cout<<"{"<<setw(8)<<deg<<","<<setw(8)<<radians
            <<","<<setw(8)<<sin(radians)<<","<<setw(8)<<cos(radians)
            <<","<<setw(8)<<tan(radians)<<"]"<<endl;
    //Exit
    return 0;
}

