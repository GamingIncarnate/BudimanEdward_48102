/* 
   File:   main
   Author: Edward Budiman
   Created on September 26, 2016, 1:32 PM
   Purpose: Number of calories for cookies ate
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
   short bagCook=30; //30 cookies in a bag
   short calCook=300; //300 calories per serving
   short serving=10; //10 servings per bag
   short cookAte; //number of cookies ate
   short calorie; //total calories ate per number of cookies
   
   //10 servings * 300 calories per serving = 3000 calories per bag of cookies
   //100 calories per cookie
        
    //Input values
   cout<<"How many cookies did you eat?"<<endl;
   cin>>cookAte;
    
    //Process values -> Map inputs to Outputs
   calorie=cookAte*100;
   
    //Display Output
   cout<<"You ate "<<calorie<<" calories."<<endl;

    //Exit Program
    return 0;
}