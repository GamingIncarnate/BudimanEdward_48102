/* 
 * File:   main.cpp
 * Author: Edward Budiman
 * Created on December 1st, 2016, 10:00 PM
 * Purpose: Sort an array of strings
 */

//System Libraries Here
#include <iostream>
#include <string>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void selectionSort(string[],int);
void printArray(string[],int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=20; //Size of array (20 names))
    string names[SIZE]={"Collins,Bill","Smith,Bart","Allen,Jim",
                             "Griffin,Jim","Stamey,Marty","Rose,Geri",
                             "Taylor,Terri","Johnson,Jill",
                             "Allison,Jeff","Looney,Joe","Wolfe,Bill",
                             "James,Jean","Weaver,Jim","Pore,Bob",
                             "Rutherford,Greg","Javens,Renee",
                             "Harrison,Rose","Setzer,Cathy",
                             "Pike,Gordon","Holland,Beth"};
    
    //Selection Sort
    selectionSort(names,SIZE);
    //Output Array
    printArray(names,SIZE);
    //Exit
    return 0;
}

void selectionSort(string names[],int j){
    //Declaration of Variables
    int minInd;
    string name;
    
    //Process Values
    for(int i=0;i<(j-1);i++){
        minInd=i;
        name=names[i];
        for(int k=i+1;k<j;k++){
            if(names[k]<name){
                name=names[k];
                minInd=k;
            }
        }
        names[minInd]=names[i];
        names[i]=name;
    }
    
}

void printArray(string names[],int j){
    //Process Values
    for(int t=0;t<j;t++){
        cout<<t<<": "<<names[t]<<endl;
    }
}