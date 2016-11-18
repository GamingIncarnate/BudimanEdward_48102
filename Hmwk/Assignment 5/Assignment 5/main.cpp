/* 
   File:   main
   Author: Edward Budiman
   Created on November 18th, 9:30 AM
   Purpose:  Assignment with a menu
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <iomanip>    //Formatting
#include <cmath>      //Square Root Function
#include <cstdlib>    //exit return
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
const unsigned char PERCENT=100;
//Function prototypes
void calculateRetail(float,float, float &);
float getLength (); //Function asks user for length
float getWidth ();  //Function asks user for width
float getArea (float,float);   //Function calculates area
void dispData (float,float,float);  //Function displays data
float getSales();
void findHighest(float,float,float,float);
int getAxidnts();
void findLow(int,int,int,int,int);
float tempCnv(float);
float tempCnv(float,float,float,float,float);
void  getScr(int &,int &,int &,int &,int &);//Get the scores
float  avgM1(int,int,int,int,int);          //Average the scores without minimum
int   getMin(int,int,int,int,int);          //Minimum Score
int poplshn(int,float,float);
bool isPrime(int);
void dollars(int,int &,int &,int &,int &,int &);
void cents(int,int &,int &,int &,int &);
bool isLpYr(int);  //Is it a leap year
int  getCVal(int); //Get the century value
int  getYVal(int); //Get the year value
int  getMVal(int,int);//Get the month value
string dayOfWk(int,int,int);//Return day of week

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    int menuItm;    //Choice from menu
    
    //Loop until users exits
    do{
    
        //Prompt for problem for user input
        cout<<"1.  Type 1  for Gaddis 1"<<endl;
        cout<<"2.  Type 2  for Gaddis 2"<<endl;
        cout<<"3.  Type 3  for Gaddis 3"<<endl;
        cout<<"4.  Type 4  for Gaddis 4"<<endl;
        cout<<"5.  Type 5  for Gaddis 7"<<endl;
        cout<<"6.  Type 6  for Gaddis 11"<<endl;
        cout<<"7.  Type 7  for Gaddis 16"<<endl;
        cout<<"8.  Type 8  for Gaddis 22"<<endl;
        cout<<"9.  Type 9  for Savitch 4"<<endl;
        cout<<"10. Type 10 for Savitch 7"<<endl;
        cin>>menuItm;

        //Go to the Problem
        switch(menuItm){
            case 1:{
                cout<<"Inside Gaddis 1"<<endl;
                //Declaration of Variables
                float price;
                float percent;
                float tMarkup;
                float total = 0;

                //Input values
                do{
                    cout<<"Please input the wholesale price of the item"<<endl;
                    cin>>price;
                }while(price<0);
                do{
                    cout<<"Please input the markup percent of the item"<<endl;
                    cin>>percent;
                }while(percent<0);

                //Process values -> Map inputs to Outputs
                calculateRetail(price,percent,total);

                //Display Output
                cout<<"The total price of the item is: $"<<total<<endl;

                //Exit Program
                return 0;
                break;
            }
            case 2:{
                cout<<"Inside Gaddis 2"<<endl;
                //Declare all Variables Here
                float length=getLength(); //Calls function and assigns length value
                float width=getWidth(); //Calls function and assigns width value

                //Input or initialize values Here

                //Process/Calculations Here
                float area=getArea(length,width); //Calls function and assigns area value

                //Output Located Here
                dispData(area,length,width); //Calls function and displays data
                //Exit
                return 0;  
                break;
            }
            case 3:{
                cout<<"Inside Gaddis 3"<<endl;
                //Declaration of Variables
                float nEast,sEast,nWest,sWest;

                //Input values

                //Process values -> Map inputs to Outputs

                //Display Output
                cout<<setw(90)<<"Regional Sales:"<<endl;
                cout<<endl;
                cout<<endl;
                cout<<"Northeast Sales:"<<endl;
                nEast=getSales();
                cout<<endl;
                cout<<"Northwest Sales:"<<endl;
                nWest=getSales();
                cout<<endl;
                cout<<"Southeast Sales:"<<endl;
                sEast=getSales();
                cout<<endl;
                cout<<"Southwest Sales:"<<endl;
                sWest=getSales();

                //Output the highest
                findHighest(nWest,sWest,nEast,nWest);

                //Exit Program
                return 0;
                break;
                }
            case 4:{
                cout<<"Inside Gaddis 4"<<endl;
                //Declare all Variables Here
                int north, south, east, west, central;
                int axidnts=0;

                //Input or initialize values Here
                cout<<"This is the north part of town."<<endl;
                north=getAxidnts();

                cout<<"This is the south part of town."<<endl;
                south=getAxidnts();

                cout<<"This is the east part of town."<<endl;
                east=getAxidnts();

                cout<<"This is the west part of town."<<endl;
                west=getAxidnts();

                cout<<"This is the central part of town."<<endl;
                central=getAxidnts();

                //Process/Calculations Here

                //Output Located Here
                findLow(north, south, east, west, central);
                //Exit
                return 0;
                break;
                }
            case 5:{
                cout<<"Inside Gaddis 7"<<endl;
                //Declare freezing and boiling pts of water
                //for degree Fahrenheit and Celsius 
                float f1=32.0f,f2=212.0f,c1=0.0f,c2=100.0f;
                int begF=0,endF=250;

                //Process values -> Map inputs to Outputs
                cout<<"Degree F   Degree C   Degree C"<<endl;
                cout<<fixed<<setprecision(2)<<showpoint;
                for(int degF=begF;degF<=endF;degF++){
                    cout<<setw(6)<<degF
                        <<setw(12)<<tempCnv(degF)
                        <<setw(11)<<tempCnv(degF,f1,f2,c1,c2)<<endl;
                }

                //Exit Program
                return 0;
                break;
            }
            case 6:{
                cout<<"Inside Gaddis 11"<<endl;
                //Declaration of Variables
                int s1,s2,s3,s4,s5;//5 scores
                float avg;//Average minus 1 score

                //Input values
                getScr(s1,s2,s3,s4,s5);

                //Process values -> Map inputs to Outputs
                avg=avgM1(s1,s2,s3,s4,s5);

                //Display Output
                cout<<fixed<<setprecision(2)<<showpoint;
                cout<<"Average minus lowest score = "<<avg<<endl;

                //Exit Program
                return 0;
            }
            case 7:{
                cout<<"Inside Gaddis 16"<<endl;
                //Declaration of Variables
                int pop,death,birth,years;//per year
                float bRate,dRate;

                //Input values
                cout<<"This program calculates the population as a function of time"<<endl;
                cout<<"Population?"<<endl;
                cin>>pop;
                cout<<"Birth Rate per year?"<<endl;
                cin>>birth;
                cout<<"Death Rate per year?"<<endl;
                cin>>death;
                cout<<"How many years to predict?"<<endl;
                cin>>years;

                //Process values -> Map inputs to Outputs
                bRate=1.0f*birth/pop;
                dRate=1.0f*death/pop;
                for(int year=1;year<=years;year++){
                    pop=poplshn(pop,dRate,bRate);
                    cout<<"Year "<<year<<" = population of "<<pop<<endl;
                }

                //Display Output

                //Exit Program
                return 0;
                break;
            }
            case 8:{
                cout<<"Gaddis 22"<<endl;
                //Declare Counter
                int count=0,columns=10;
                //Display Output
                for(int i=1;i<=1000;i++){
                    if(isPrime(i)){
                        cout<<setw(3)<<i<<" ";
                        count++;
                    if(count==columns){
                        cout<<endl;
                        count=0;
                    }
                    }
                }
                //Exit Program
                return 0;
                break;
            }
            case 9:{
                cout<<"Savitch 4"<<endl;
                //Declaration of Variables
                int n50s,n20s,n10s,n5s,n1s;       //Dollar quantities
                int quarter,dimes,nickles,pennies;//Coin quantities
                float tender,price;               //Price and Tendered amounts
                int tDolr,tCent,pDolr,pCent;      //Price and Tendered dollars and cents

                //Input values
                do{
                    cout<<"This program calculates the exact change"<<endl;
                    cout<<"What is the price of the purchase = $"<<endl;
                    cin>>price;
                    cout<<"What is the tendered amount = $ > Price"<<endl;
                    cin>>tender;
                }while(tender-price<0);

                //First step calculate dollars and cents
                pDolr=price+0.005f;           //Partial penny
                pCent=(price-pDolr)*100+0.005;//Number of cents with partial penny   
                tDolr=tender+0.005f;           //Partial penny
                tCent=(tender-tDolr)*100+0.005;//Number of cents with partial penny

                //Display the amounts
                cout<<"The price input     = $"<<pDolr<<"."<<pCent<<endl;
                cout<<"The tendered amount = $"<<tDolr<<"."<<tCent<<endl;
                if(tCent-pCent<0){
                    tDolr--;
                    tCent+=100;
                }
                cout<<"The change amount   = $"<<tDolr-pDolr<<"."<<tCent-pCent<<endl;

                //Calculate the Change
                dollars(tDolr-pDolr,n50s,n20s,n10s,n5s,n1s);
                cout<<n50s<<" number of 50's"<<endl;
                cout<<n20s<<" number of 20's"<<endl;
                cout<<n10s<<" number of 10's"<<endl;
                cout<<n5s<<" number of 5's"<<endl;
                cout<<n1s<<" number of 1's"<<endl;

                //Calculate the Change
                cents(tCent-pCent,quarter,dimes,nickles,pennies);
                cout<<quarter<<" number of quarters"<<endl;
                cout<<dimes<<" number of dimes"<<endl;
                cout<<nickles<<" number of nickels"<<endl;
                cout<<pennies<<" number of pennies"<<endl;

                //Exit Program
                return 0;
                break;
            }
            case 10:{
                cout<<"Inside Savitch 7"<<endl;
                //Declaration of Variables

                //Input values

                //Process values -> Map inputs to Outputs
                cout<<"Day of week = "<<dayOfWk(10,31,2016)<<endl;
                //Display Output

                //Exit Program
                return 0;
                break;
            }//End Case
        }//End the Switch/Case
    }while(menuItm>0&&menuItm<=10);//Ends the Do-While Loop

    //Exit Program
    return 0;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   Problem 1 ****************************************
//Purpose:  Calculates the retail price
//Inputs:   The price & the percent marked up
//Output:  The new total of the retail value
//******************************************************************************
void calculateRetail(float price,float percent,float &total){
    //Retail Price Calculations
    total=((price*percent)/PERCENT+price);
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   Problem 1 ****************************************
//Purpose:  Obtains a value for length
//Inputs:   The User inputs a float value
//Output:  The function outputs the float value
//******************************************************************************
float getLength(){
    float length;
    cout<<"Enter the length of the rectangle."<<endl;
    cin>>length;
    return length;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   Problem 1 ****************************************
//Purpose:  Obtains a value for width
//Inputs:   The User inputs a float value
//Output:  The function outputs the float value
//******************************************************************************
float getWidth(){
    float width;
    cout<<"Enter the width of the rectangle."<<endl;
    cin>>width;
    return width;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   Problem 1 ****************************************
//Purpose:  Calculate the area of the rectangle
//Inputs:   The values returned from getLength and getWidth
//Output:  A float value of the rectangle's area
//******************************************************************************
float getArea(float length,float width){
    float area;
    area=length*width;
    return area;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   Problem 1 ****************************************
//Purpose:  Display the measurements of the rectangle
//Inputs:   The values of the rectangle
//Output:  A display of the rectangle's parameters
//******************************************************************************
void dispData(float area, float length, float width){
    cout<<"The length of the rectangle is "<<length<<endl;
    cout<<"The width of the rectangle is "<<width<<endl;
    cout<<"The area of the rectangle is "<<area<<endl;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   Problem 1 ****************************************
//Purpose:  Receive the number of sales from the user
//Inputs:   number of sales
//Output:  number of sales>0
//******************************************************************************
float getSales(){
    //Declaration of Variables
    float sales;
    
    //Input the sales number for the region
    cout<<"Please input the sales for this region"<<endl;
    cin>>sales;
    
    if(sales<0){
        cout<<"Please input a number greater than 0"<<endl;
    }
    return sales;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   Problem 1 ****************************************
//Purpose:  Determine which division has the most sales
//Inputs:   number of sales from each division
//Output:  the name of the winning division and their sales
//******************************************************************************
void findHighest(float nWest,float sWest,float nEast,float sEast){
    if(nWest>nEast&&nWest>sEast){
        if(nWest>sWest){
            cout<<"The Northwest division had the greatest number of sales: $";
            cout<<nWest<<endl;
        }
    }else if(nEast>sEast&&nEast>nWest){
        if(nEast>sWest){
            cout<<"The Northeast division had the greatest number of sales: $";
            cout<<nEast<<endl;
        }
    }else if(sEast>nEast&&sEast>nWest){
        if(sEast>sWest){
                cout<<"The Southeast division had the greatest number of sales: $";
                cout<<sEast<<endl;
        }
    }else if(sWest>nEast&&sWest>sEast){
        if(sWest>nWest){
            cout<<"The Southwest division had the greatest number of sales: $";
            cout<<sWest<<endl;
        }
    }
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   Problem 1 ****************************************
//Purpose:  Ask for number of accidents and determine if over 0
//Inputs:   Number of accidents
//Output:  Number of accidents
//******************************************************************************
int getAxidnts(){
    int axidnts;
    cout<<"Enter the number of accidents for this area of the city."<<endl;
    cin>>axidnts;
    while (axidnts<0){
        cout<<"The number of accidents can't be less than 0."<<endl<<endl;
        cin>>axidnts;
    }
    return axidnts;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   Problem 1 ****************************************
//Purpose:  Determine which part of town is the most dangerous
//Inputs:   The number of accidents for each part of town
//Output:  A display of which city is the most dangerous and how many accidents
//******************************************************************************
void findLow(int north, int south, int east, int west, int central){
    if (north>south&&north>east&&north>west&&north>central){
        cout<<"The north part of town is the most dangerous with "<<north<<" accidents."<<endl;
    }else if (south>north&&south>east&&south>west&&south>central){
        cout<<"The south part of town is the most dangerous with "<<south<<" accidents."<<endl;
    }else if (east>north&&east>south&&east>west&&east>central){
        cout<<"The east part of town is the most dangerous with "<<east<<" accidents."<<endl;
    }else if (west>north&&west>south&&west>east&&west>central){
        cout<<"The west part of town is the most dangerous with "<<west<<" accidents."<<endl;
    }else{
        cout<<"The central part of town is the most dangerous with "<<central<<" accidents."<<endl;
    }
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   Problem 1 ****************************************
//Purpose: Convert from Farenheit to Celcius
//Inputs:   Farenheit
//Output:  Celcius
//******************************************************************************
float tempCnv(float f){
    return (f-32.0f)*5/9;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   Problem 1 ****************************************
//Purpose: Convert from Farenheit to Celcius
//Inputs:   Farenheit
//Output:  Celcius
//******************************************************************************
float tempCnv(float f,float f1,float f2,float c1,float c2){
    return c1+(f-f1)*(c2-c1)/(f2-f1);
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   Get Min   ****************************************
//Purpose:  Find minimum of 5 scores
//Inputs:   Inputs to the function here -> Description, Range, Units
//  s1-s5-> 5 scores between [0,100]
//Output:   Outputs to the function here -> Description, Range, Units
//  min ->  Minimum of 5 scores
//******************************************************************************
int getMin(int s1,int s2,int s3,int s4,int s5){
    int min=s1;
    if(min>s2)min=s2;
    if(min>s3)min=s3;
    if(min>s4)min=s4;
    if(min>s5)min=s5;
    return min;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   Average   ****************************************
//Purpose:  Average of 5 scores minus the minimum
//Inputs:   Inputs to the function here -> Description, Range, Units
//  s1-s5-> 5 scores between [0,100]
//Output:   Outputs to the function here -> Description, Range, Units
//  avg ->  Average of 5 scores with the minimum
//******************************************************************************
float avgM1(int s1,int s2,int s3,int s4,int s5){
    return 0.25f*(s1+s2+s3+s4+s5-getMin(s1,s2,s3,s4,s5));
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************  Get Score  ****************************************
//Purpose:  Find minimum of 5 scores
//Input&Output:   Inputs to the function here -> Description, Range, Units
//  s1-s5-> 5 scores between [0,100]
//******************************************************************************
void  getScr(int &s1,int &s2,int &s3,int &s4,int &s5){
    //Get data and determine if valid for each score
    int x;
    do{
        cout<<"Input score 1 between 0 and 100"<<endl;
        cin>>x;
    }while(x<0||x>100);
    s1=x;
    do{
        cout<<"Input score 2 between 0 and 100"<<endl;
        cin>>x;
    }while(x<0||x>100);
    s2=x;
    do{
        cout<<"Input score 3 between 0 and 100"<<endl;
        cin>>x;
    }while(x<0||x>100);
    s3=x;
    do{
        cout<<"Input score 4 between 0 and 100"<<endl;
        cin>>x;
    }while(x<0||x>100);
    s4=x;
    do{
        cout<<"Input score 5 between 0 and 100"<<endl;
        cin>>x;
    }while(x<0||x>100);
    s5=x;
}
bool isPrime(int n){
    if(n<2)return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)return false;
    }
    return true;
}
void cents(int d,int &n25s,int &n10s,int &n5s,int &n1s){
    //Calculate the change
    n25s=d/25;  //How many 25's
    d-=25*n25s;
    n10s=d/10;  //How many 10's
    d-=10*n10s;
    n5s=d/5;    //How many 5's
    d-=5*n5s;
    n1s=d;
}

void dollars(int d,int &n50s,int &n20s,int &n10s,int &n5s,int &n1s){
    //Calculate the change
    n50s=d/50;  //How many 50's
    d-=50*n50s;
    n20s=d/20;  //How many 20's
    d-=20*n20s;
    n10s=d/10;  //How many 10's
    d-=10*n10s;
    n5s=d/5;    //How many 5's
    d-=5*n5s;
    n1s=d;
}
string dayOfWk(int m,int d,int y){
    int nDay=(d+getMVal(m,y)+getYVal(y)+getCVal(y))%7;
    switch(nDay){
        case 0:return "Sunday";
        case 1:return "Monday";
        case 2:return "Tuesday";
        case 3:return "Wednesday";
        case 4:return "Thursday";
        case 5:return "Friday";
        case 6:return "Saturday";
        default:return "Bad Day";
    }
}

int  getMVal(int m,int y){
    switch(m){
        case 1:return isLpYr(y)?6:0;
        case 2:return isLpYr(y)?2:3;
        case 3:case 11:return 3;
        case 4:case  7:return 6;
        case 9:case 12:return 5;
        case 5:return 1;
        case 6:return 4;
        case 8:return 2;
        case 10:return 0;
        default:cout<<"Bad number"<<endl;exit(1);
    }
}

int getYVal(int year){
    int dig2=year%100;
    return dig2+dig2/4;
}

int getCVal(int year){
    return 2*(3-(year/100)%4);
}

bool isLpYr(int year){
    return ((year%400==0)||((year%4==0)&&(year%100!=0)));
}
int poplshn(int pop,float death,float birth){
    return pop*(1+birth-death);
}