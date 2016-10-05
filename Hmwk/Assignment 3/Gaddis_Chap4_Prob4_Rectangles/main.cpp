/* 
   File:   main
   Author: Edward Budiman
   Created on October 4, 2016, 4:15 PM
   Purpose: Compare the area of rectangles
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
    short len1, wid1, len2, wid2; //The measurements of the rectangles
    int area1, area2;             //Area of the rectangles
  
    //Input values
    cout<<"What is the length of the first rectangle?"<<endl;
    cin>>len1;
    
    cout<<"What is the width of the first rectangle?"<<endl;
    cin>>wid1;
    
    cout<<"What is the length of the second rectangle?"<<endl;
    cin>>len2;
    
    cout<<"What is the width of the second rectangle?"<<endl;
    cin>>wid2;
    
    //Process values -> Map inputs to Outputs
    area1=len1*wid1;
    area2=len2*wid2;
    
    //Compare the rectangles
    if (area1>area2)
        cout<<"Rectangle 1 is larger with an area of "<<area1<<endl;
    else 
        cout<<"rectangle 2 is larger with an area of "<<area2<<endl;
    //Exit Program
    return 0;
}