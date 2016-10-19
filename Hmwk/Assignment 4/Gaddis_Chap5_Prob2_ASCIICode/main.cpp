/* 
   File:   main
   Author: Edward Budiman
   Created on October 11th, 2016, 12:12 PM
   Purpose: Display ASCII codes from 0 to 127 with 16 digits per line  
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
    char letter;
    
    //Input values
    cout<<" I will display the characters for ASCII codes 0 through 127"<<endl;
    
    //Process values -> Map inputs to Outputs
    for (int count = 0; count <= 127; count++)
    {
        if (count%16==0)cout<<endl;
        
        cout<<letter<<" ";
        letter++;
    }
        
    
    //Display Output

    //Exit Program
    return 0;
}