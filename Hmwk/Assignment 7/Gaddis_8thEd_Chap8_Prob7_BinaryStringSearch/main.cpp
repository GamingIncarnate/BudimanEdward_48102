/* 
 * File:   main.cpp
 * Author: Edward Budiman
 * Created on December 2nd, 2016, 12:32 PM
 * Purpose: Sort an array of strings and use a Binary Search
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
int binarySearch(string[],string);

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
    string name;
    
    //Selection Sort
    selectionSort(names,SIZE);
    
    //Name to Search
    cout<<"What is the name you are attempting to search for?"<<endl;
    cout<<"Please enter in the format of Last,First"<<endl;
    cin>>name;
    
    //Search for name and Display if Found or Not
    int nameF=binarySearch(names,name);
    
    if(nameF==-1){
        cout<<"Sorry, we are unable to locate the name you listed in our list."<<endl;
    }
    else{
        cout<<"Name Found: "<<names[nameF]<<endl;
    }
    
    //Exit
    return 0;
}

void selectionSort(string names[],int j){
    //Declaration of Variables
    int minInd;
    string name;
    
    //Process Values
    for(int i=0;i<(j-1);i++){
        minInd=i; //Minimum
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

int binarySearch(string names[],string j){
    //Declaration of Variables
    short pos=-1; //Position
    int first=0; //First Element
    int last=21-1; //Last Element
    int middle; //Middle
    bool found=false; //Set to false while not found
    
    //Process Values
    do{
        middle=(first+last)/2; //Calculate the mid point
        if(names[middle]==j){
            //found=true;
            pos=middle;
            return pos;
        }
        else if(names[middle]>j)last=middle-1;
        else first=middle+1;
    }while(found==false&&first<=last);
    return -1;
}