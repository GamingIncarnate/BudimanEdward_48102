/* 
   File:   main
   Author: Edward Budiman
   Created on December 2, 2016, 11:11 AM
   Purpose: Show different sorts
 */

//System Libraries
#include <iostream>   //Input/Output objects
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
void slctSrt(int [], int);
void bubSrt(int[], int);
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    const short SIZE=8;
    int bubArr[SIZE]={5,3,6,4,7,2,1,8};
    int slctArr[SIZE]={5,3,6,4,7,2,1,8};
    
    //Input values
  
    //Process values -> Map inputs to Outputs
    slctSrt(slctArr,SIZE);
    bubSrt(bubArr,SIZE);
    //Exit Program
    return 0;
}

//Selection Sort
void slctSrt(int a[],int n){
    //initialize variables
    int minPos, filler;
    
    //Loop until sorted
    for (int i=0; i < n-1; i++){
        minPos=i;
        for (int j=i+1; j<n; j++){
            if (a[j]<a[minPos]){
                minPos=j;
            }
        }
        if (minPos !=i){
            filler=a[i];
            a[i]=a[minPos];
            a[minPos]=filler;
        }
        for (short j=0; j<n; j++){
            cout<<a[j];
        }
        cout<<endl;
    }
}

//Bubble Sort
void bubSrt(int a[],int n){
    bool swap;
    int temp;
    
    do{
        swap=false;
        for(int i=0; i<n-1; i++){
            if (a[i]>a[i+1]){
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                swap=true;
            }
            for (short j=0; j<n; j++){
                cout<<a[j];
            }
            cout<<endl;
        }
    }while (swap); //I'm copying the Gaddis book. I'm not sure what this means so IDK what to change it to.
}