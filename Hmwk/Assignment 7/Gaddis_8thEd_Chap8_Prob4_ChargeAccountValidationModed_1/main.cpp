/* 
 * File:   main.cpp
 * Author: Edward Budiman
 * Created on December 2, 2016 10:40 AM
 * Purpose: User inputs a charge number and checks it to see if it is valid with the current charge numbers in an array
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int binSrch(int a[],int n,int val);
int slctSrt(int a[],int n);
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=18;
    
        //Account Numbers Below
    int accounts[SIZE]={5658845,4520125,7895122,8777541,8451277,1302850,8080152,
                     4562555,5552012,5050552,7825877,1250255,1005231,6545231,
                     3852085,7576651,7881200,4581002};
    int accNum; //Account Number Being Input
    int found; //Where the number was found
    
    //Input or initialize values Here
    cout<<"Please input the Account Number:"<<endl;
    cin>>accNum;
    
    //Sort then Binary Search
    slctSrt(accounts,SIZE);
    found=binSrch(accounts,SIZE,accNum);
    
    //Output Located Here
    if(found==-1)cout<<"Number is invalid"<<endl;
    else{
        cout<<"Number is valid"<<endl;
    }

    //Exit
    return 0;
}

//Binary Search
int  binSrch(int a[],int n,int val){
    //Declare and setup
    int begRng=0,endRng=n;
    //Loop until found
    do{
        int midPnt=(endRng+begRng)/2;
        if(a[midPnt]==val)return midPnt;
        else if(a[midPnt]<val){
            begRng=midPnt+1;
        }else{
            endRng=midPnt-1;
        }
    }while(endRng>begRng);
    return -1;
}

//Selection Sort
int slctSrt(int a[],int n){
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
    }
}
        

