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
void dispMap();
void dispInv(int[],string[],int);

//Program Execution
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=100;
    int utilize=50;
    char input;
    int inventory[SIZE]={};
    string invntry[SIZE]={};
    
    //Input or initialize values Here
    cout<<"Enter M"<<endl;
    cin>>input;
    
    
    for (int i=0;i<=utilize;i++){
        string test="a";
        invntry[i]=test;
    }
    dispMap();
    dispInv(inventory,invntry,utilize);
    
    //Process/Calculations Here
    
    //Output Located Here

    //Exit
    return 0;
}

void dispInv(int a[],string b[],int n){
//Output inventory array
    for(int i=1; i<=n; i++){
        cout<<a[i];
        cout<<b[i];
        if (i%10==0)cout<<endl;
    }
}

void dispMap(){
//Declare variables
    ifstream in;
    int rows;
    string line;
    
//Open the file
    in.open("map.dat");
    in>>rows;

//Display map
    for (int row=0;row<=rows;row++){
        getline(in,line);
        cout<<line<<endl;
    }
    
//Close and clear the file    
    in.close();
    in.clear();           
}