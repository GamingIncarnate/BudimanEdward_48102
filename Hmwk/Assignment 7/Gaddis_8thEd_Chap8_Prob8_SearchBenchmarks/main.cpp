/* 
 * File: main.cpp
 * Author: Edward Budiman
 * Created on December 2nd, 2016, 1:32 PM
 * Purpose: Find the time it takes to find a number using a Linear and Binary search 
 */

#include <iostream>   //Input/Output objects
#include <cstdlib>   //Random Number

using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
int binSrch(int[],int,int); //Binary Search

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    const int SIZE = 20;
    int num[SIZE]={12,78,136,457,785,986,1035,
                    2566,5487,7854,9658,105487,305478,
                    987456,10547896,3457986,5123987,8354985,10548796,20548796,};
    int number;
    int linear = 1;
    int binary = 0;
    bool found = false;

    //Input values
    cout << "Please input a number.";
    cin >> number;

    //Linear search
    for (int i = 0; i < SIZE; i++){
        if (num[i] == number) {
            found = true;
            break;
        }
        linear++;
    }
    
    //Display Outputs
    cout<<"The linear search took "<<linear<<" attempts."<<endl;
    cout<<"The binary search took "<<binSrch(num,SIZE,number)<<" attempts."<<endl;
    
    //Exit Program
    return 0;
}
int binSrch(int arr[],int size,int num){
    //Declaration of Variables
    int first=0;
    int mid;
    int last=size-1;
    bool found=false;
    int count=0;
    
    //Process Values
    do{
        mid=(first+last)/2; //Calculate the mid point
        if(arr[mid]== num){
            found=true;
        }else if(arr[mid]>num)last= mid-1;
        else first=mid+1;
        count++;
    }while(!found&&first<=last);
    
    //Return to main
    return count;
}