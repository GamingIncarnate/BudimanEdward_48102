/* 
 * File:   main.cpp
 * Author: Edward Budiman
 * Created on November 15, 2016, 11:47 AM
 * Purpose:  Calculate the area of a rectangle
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
float getLength (); //Function asks user for length
float getWidth ();  //Function asks user for width
float getArea (float,float);   //Function calculates area
void dispData (float,float,float);  //Function displays data
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    float length=getLength(); //Calls function and assigns length value
    float width=getWidth(); //Calls function and assigns width value

    //Input or initialize values Here
    
    //Process/Calculations Here
    float area=getArea(length,width); //Calls function and assigns area value
    
    //Output Located Here
    dispData(area,length,width); //Calls function and displays data
    //Exit
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   Problem 1 ****************************************
//Purpose:  Obtains a value for length
//Inputs:   The User inputs a float value
//Output:  The function outputs the float value
//******************************************************************************
float getLength(){
    float length;
    cout<<"Enter the length of the rectangle."<<endl;
    cin>>length;
    return length;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   Problem 1 ****************************************
//Purpose:  Obtains a value for width
//Inputs:   The User inputs a float value
//Output:  The function outputs the float value
//******************************************************************************
float getWidth(){
    float width;
    cout<<"Enter the width of the rectangle."<<endl;
    cin>>width;
    return width;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   Problem 1 ****************************************
//Purpose:  Calculate the area of the rectangle
//Inputs:   The values returned from getLength and getWidth
//Output:  A float value of the rectangle's area
//******************************************************************************
float getArea(float length,float width){
    float area;
    area=length*width;
    return area;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   Problem 1 ****************************************
//Purpose:  Display the measurements of the rectangle
//Inputs:   The values of the rectangle
//Output:  A display of the rectangle's parameters
//******************************************************************************
void dispData(float area, float length, float width){
    cout<<"The length of the rectangle is "<<length<<endl;
    cout<<"The width of the rectangle is "<<width<<endl;
    cout<<"The area of the rectangle is "<<area<<endl;
}