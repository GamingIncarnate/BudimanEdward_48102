/* 
 * File:   main.cpp
 * Author: Edward Budiman
 * Created on December 8, 2016, 9:43 AM
 * Purpose: Create an awesome text based adventure that will impress Dr. Lehr
 */

//System Libraries Here
#include <iostream> //Input/Output
#include <fstream>  //File Manipulation
#include <string>   //String Elements
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void userInput(char);
//Program Execution
int main(int argc, char** argv) {
    //Declare all Variables Here
    char input;
    
    //Input or initialize values Here
    cout<<"Enter M"<<endl;
    cin>>input;
    
    userInput(input);
    
    //Process/Calculations Here
    
    //Output Located Here

    //Exit
    return 0;
}

void userInput(char input){
//Declare variables
    ifstream in;
    ofstream out;
    int rows,cols;
    string line;
    
    if(input=='M'||input=='m'){
        in.open("map.dat");
        in>>rows>>cols;
        
        //Display map
        for (int row=1;row<=rows+1;row++){
            getline(in,line);
            cout<<line<<endl;
        }
    }
}