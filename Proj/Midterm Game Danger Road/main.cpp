/* 
 * File:   main.cpp
 * Author: Edward Budiman
 * Created on October 27, 2016, 9:59 AM
 * Purpose: Make a game that will impress the professor
 */

//System Libraries Here
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed
     srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
     short obsticle;
     
    //Input or initialize values Here
     obsticle=rand()%4+1;
     
    //Process/Calculations Here
     switch (obsticle){
         case 1:cout<<"]x| | | ["<<endl; break;
         case 2:cout<<"] |x| | ["<<endl; break;
         case 3:cout<<"] | |x| ["<<endl; break;
         case 4:cout<<"] | | |x["<<endl; break;
    }
            
    //Output Located Here
     cout<<obsticle<<endl;
    //Exit
    return 0;
}

