/* 
 * File:   main.cpp
 * Author: Edward Budiman
 * Created on September 20, 2016, 11:25 AM
 * Purpose:  
 */

//System Libraries Here
#include <iostream> //
#include <iomanip>  //Format Library
#include <cstdlib> //Random Number Seed
#include <cmath>  //Square Root Function
#include <ctime> //Time to set random numbers
using namespace std; //Name-space used in the System Library

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
const float MAXRAND=pow(2,31)-1;//Max signed positive value for int
//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declaration of Variables
    float n,guess,r;
    float scale=90,shift=10;
    short counter=0;
    
    //Input or initialize values Here - float random number (10,100) vs.
    //                                  integer random number rand()%scale+shift[10,100]]
    n=rand()/MAXRAND*scale+shift;
    guess=n/2;
            
    //Process/Calculations Here
        cout<<"The number to find the square root of = "<<n<<endl;
        cout<<"The initial guess = "<<guess<<endl;
        
    //First Pass
        r=n/guess;
        guess=(guess+r)/2;
        counter+=1;
    //Output Located Here
        cout<<fixed<<showpoint<<setprecision(4);
        cout<<"Pass "<<counter<<" [r,guess]=["<<setw(7)<<r
                <<","<<setw(7)<<guess<<"]"<<endl;
    //Second Pass
        r=n/guess;
        guess=(guess+r)/2;
        counter+=1;
    //Output Located Here
        cout<<"Pass "<<counter<<" [r,guess]=["<<setw(7)<<r
                <<","<<setw(7)<<guess<<"]"<<endl;
    //Next Pass    
        r=n/guess;
        guess=(guess+r)/2;
        counter+=1;
    //Output Located Here
        cout<<"Pass "<<counter<<" [r,guess]=["<<setw(7)<<r
                <<","<<setw(7)<<guess<<"]"<<endl;
    //Next Pass
        r=n/guess;
        guess=(guess+r)/2;
        counter+=1;
    //Output Located Here
        cout<<"Pass "<<counter<<" [r,guess]=["<<setw(7)<<r
                <<","<<setw(7)<<guess<<"]"<<endl;
    //Next Pass
        r=n/guess;
        guess=(guess+r)/2;
        counter+=1;
    //Output Located Here
        cout<<"Pass "<<counter<<" [r,guess]=["<<setw(7)<<r
                <<","<<setw(7)<<guess<<"]"<<endl;
    //Next Pass
        r=n/guess;
        guess=(guess+r)/2;
        counter+=1;
    //Output Located Here
        cout<<"Pass "<<counter<<" [r,guess]=["<<setw(7)<<r
                <<","<<setw(7)<<guess<<"]"<<endl;
        
        cout<<"The sqrt("<<n<<")= "<<sqrt(n)<<endl;
    //Exit
    return 0;
}
