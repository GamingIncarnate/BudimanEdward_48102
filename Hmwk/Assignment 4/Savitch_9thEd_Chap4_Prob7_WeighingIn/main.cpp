/* 
 * File:   main.cpp
 * Author: Edward Budiman
 * Created on October 6, 2016, 11:54 AM
 * Purpose:  Calculate your weight
 */

//System Libraries Here
#include <iostream>  //Input/Output Objects
using namespace std; //Name-Space used in the System Library

//User Libraries Here

//Global Constants Only, No Global Variables
float GRAVITY=6.673e-8f;  //Universal Gravity Constant cm^3/g/sec^2
float CNKGGRM=1000;       //Conversion from KG to Grams
float CNSGGRM=14593.9;    //Conversion from Slugs to Grams
float CNKMMET=1000;       //Conversion from Km to Meters
float CNMETCM=100;        //Conversion from Meters to Centimeters
float CNDYNLB=2.24809e-6f;//Conversion from Dynes to Pounds
float CNSGLBS=32.174f;    //Conversion from slugs to pounds which oddly enough is the acceleration of gravity in ft/sec^2
//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    float msEarth=5.972e24; //Google lookup -> Kilograms
    float msMark=6.0f;      //Mass of Mark in slugs
    float rdEarth=6371.0f;  //Google radius of the Earth
    float weight;           //Force of attraction from physics
    
    //Conversion of Inputs
    msEarth*=CNKGGRM;       //Convert mass of the earth to grams
    msMark*=CNSGGRM;        //Convert mass of mark to grams
    rdEarth*=CNKMMET*CNMETCM;//Convert the radius of the Earth to centimeters
   
    //Process/Calculations Here
   weight=GRAVITY*msMark*msEarth/rdEarth/rdEarth; //Weak force attraction due to gravity
    weight*=CNDYNLB; //Convert Dynes to Pounds
    
    //Output Located Here
    cout<<"According to the weak force of gravity, Mark weighs = "<<weight<<" lbs"<<endl;
    cout<<"As a check, Mark weighs = "<<6*CNSGLBS<<" lbs"<<endl;
    cout<<"The percentage error in the Radius of Earth = +-"<<100.0f*18/6371<<"%"<<endl;
    cout<<"The margin of error for the weight = "<<(weight-6*CNSGLBS)/weight*100.0f<<"%"<<endl;
    //Exit
    return 0;
}

