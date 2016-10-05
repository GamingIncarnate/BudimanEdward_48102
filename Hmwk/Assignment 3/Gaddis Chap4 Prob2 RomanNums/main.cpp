/* 
   File:   main
   Author: Edward Budiman
   Created on October 4, 2016, 3:25 PM
   Purpose: Convert a number between 1 and 10 to Roman numerals
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
    short num; //Number between 1 and 10
   
    //Input values
    cout<<"Enter a number between 1 and 10"<<endl;
    cin>>num;
  
    //Process values -> Translate into Roman Numerals
    switch(num)
    {
        case 1 :cout<<"I\n";
        break;
        case 2 :cout<<"II\n";
        break;
        case 3 :cout<<"III\n";
        break;
        case 4 :cout<<"IV\n";
        break;
        case 5 :cout<<"V\n";
        break;
        case 6 :cout<<"VI\n";
        break;
        case 7 :cout<<"VII\n";
        break;
        case 8 :cout<<"VIII\n";
        break;
        case 9 :cout<<"IX\n";
        break;
        case 10 :cout<<"X\n";
        break;
        default :cout<<"Invalid Number\n";
    }
    //Exit Program
    return 0;
}
