/*/* 
 * File:   main.cpp
 * Author: Edward Budiman
 * Created on September 29, 2016, 12:05 PM
 * Purpose:  Determine type of wave through length
 */

//System Libraries Here
#include <iostream>
#include <string>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    float waveLen;
    string waveTyp;
    
    //Input or initialize values Here
    cout<<"Input wave length in Meters"<<endl;
    cout<<"This program determines the band of radiation"<<endl;
    cin>>waveLen;
    
    //Process/Calculations Here
    waveTyp=(waveLen>=1e-2f)?"RadioBand":
            (waveLen>=1e-3f)?"MicroWaveBand":
            (waveLen>=7e-7f)?"Infra-RedBand":
            (waveLen>=4e-7f)?"VisibleBand":
            (waveLen>=1e-8f)?"Ultra-VioletBand":
            (waveLen>=1e-11f)?"X-rayBand":
            "GammaRayBand";

    //Output Located Here
    cout<<"This wave is a(n) "<<waveTyp<<endl;
    
    //Exit
    return 0;
}

