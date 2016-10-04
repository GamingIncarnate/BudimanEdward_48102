/* 
 * File:   main.cpp
 * Author: Edward Budiman
 * Created on October 4, 2016, 11:26 AM
 * Purpose:  Sort 2, 3, and 4 numbers from highest to lowest
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    short a, b, c, d;
    
    //Input or initialize values Here
    cout<<"Enter the first number"<<endl;
    cin>>a;
    
    cout<<"Enter the second number"<<endl;
    cin>>b;
    
    cout<<"Enter the third number"<<endl;
    cin>>c;
    
    cout<<"Enter the fourth number"<<endl;
    cin>>d;
    //Process/Calculations Here
    cout<<"The first two numbers in order are ";
    if(a>b)
        cout<<a<<","<<b<<endl;
    else
        cout<<b<<","<<a<<endl;
    
    cout<<"The first three numbers in order are ";
    if((a>=b)&&(b>=c))
        cout<<a<<","<<b<<","<<c<<endl;
    else if((a>=c)&&(c>=b))
        cout<<a<<","<<c<<","<<b<<endl;
    else if((b>=a)&&(a>=c))
        cout<<b<<","<<a<<","<<c<<endl;
    else if((b>=c)&&(c>=a))
        cout<<b<<","<<c<<","<<a<<endl;
    else if((c>=b)&&(b>=a))
        cout<<c<<","<<b<<","<<a<<endl;
    else if((c>=a)&&(a>=b))
        cout<<c<<","<<a<<","<<b<<endl;
    
    cout<<"All numbers in order are ";
    if((a>=b)&&(b>=c)&&(c>=d))
        cout<<a<<","<<b<<","<<c<<","<<d<<endl;
    else if((a>=b)&&(b>=c)&&(d>=c))
        cout<<a<<","<<b<<","<<d<<","<<c<<endl;
    else if((a>=c)&&(c>=b)&&(b>=d))
        cout<<a<<","<<c<<","<<b<<","<<d<<endl;
    else if((a>=c)&&(c>=b)&&(b>=d))
        cout<<a<<","<<c<<","<<d<<","<<b<<endl;
    else if((a>=d)&&(d>=b)&&(b>=c))
        cout<<a<<","<<d<<","<<b<<","<<c<<endl;
    else if((a>=d)&&(d>=c)&&(c>=b))
        cout<<a<<","<<d<<","<<c<<","<<b<<endl;
    else if((b>=a)&&(a>=c)&&(c>=d))
        cout<<b<<","<<a<<","<<c<<","<<d<<endl;
    else if((b>=a)&&(a>=d)&&(d>=c))
        cout<<b<<","<<a<<","<<d<<","<<c<<endl;
    else if((b>=c)&&(c>=a)&&(a>=d))
        cout<<b<<","<<c<<","<<a<<","<<d<<endl;
    else if((b>=c)&&(c>=d)&&(d>=a))
        cout<<b<<","<<c<<","<<d<<","<<a<<endl;
    else if((b>=d)&&(d>=a)&&(a>=c))
        cout<<b<<","<<d<<","<<a<<","<<c<<endl;
    else if((b>=d)&&(d>=c)&&(c>=a))
        cout<<b<<","<<d<<","<<c<<","<<a<<endl;
    else if((c>=a)&&(a>=b)&&(b>=d))
        cout<<c<<","<<a<<","<<b<<","<<d<<endl;
    else if((c>=a)&&(a>=d)&&(d>=b))
        cout<<c<<","<<a<<","<<d<<","<<b<<endl;
    else if((c>=b)&&(b>=a)&&(a>=d))
        cout<<c<<","<<b<<","<<a<<","<<d<<endl;
    else if((c>=b)&&(b>=d)&&(d>=a))
        cout<<c<<","<<b<<","<<d<<","<<a<<endl;
    else if((c>=d)&&(d>=a)&&(a>=b))
        cout<<c<<","<<d<<","<<a<<","<<b<<endl;
    else if((c>=d)&&(d>=b)&&(b>=a))
        cout<<c<<","<<d<<","<<b<<","<<a<<endl;
    else if((d>=a)&&(a>=c)&&(c>=b))
        cout<<d<<","<<a<<","<<c<<","<<b<<endl;
    else if((d>=a)&&(a>=b)&&(b>=c))
        cout<<d<<","<<a<<","<<b<<","<<c<<endl;
    else if((d>=b)&&(b>=a)&&(a>=c))
        cout<<d<<","<<b<<","<<a<<","<<c<<endl;
    else if((d>=b)&&(b>=c)&&(c>=a))
        cout<<d<<","<<b<<","<<c<<","<<a<<endl;
    else if((d>=c)&&(c>=a)&&(a>=b))
        cout<<d<<","<<c<<","<<a<<","<<b<<endl;
    else if((d>=c)&&(c>=b)&&(b>=a))
        cout<<d<<","<<c<<","<<b<<","<<a<<endl;
    //Output Located Here

    //Exit
    return 0;
}

