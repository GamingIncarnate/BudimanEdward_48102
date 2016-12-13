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
#include <ctime>    //Time
#include <cstdlib>  //Random Number Generator
#include <iomanip>  //Numer manipulation
using namespace std;

//User Libraries

//Global Constants
const short COLUMNS=5; //Columns for the 2d array

//Function Prototypes
void dispMap();                            //Use to display map
void showMenu();                           //Use to display menu
void makeRd();                             //Creates a random road
void saveGame(int);                        //Saves current instance into a file
void storyFunc(string[]);                  //String that holds the story
void fillAry(int,int[][COLUMNS]);          //Fills the 2d array randomly
void useAry(int,int[][COLUMNS]);           //Arbitrarily uses the 2d array by sorting and searching
void inventory(int,int,int[],string[]);    //Use to display inventory
bool death(int);                           //Use to check and validate death
int load();                                //Reads save file for instance
int dangerRd();                            //Old project 1 game 
float ageNum(short);                       //Arbritrary float and read by value

//Program Execution
int main(int argc, char** argv) {
    //Declare all Variables Here
    bool isDead=false;          //Boolean value to determine death
    char menuItm;               //Option player chooses in the menu
    const int SIZE=100,         //Constant size for arrays                  
            INVSIZE=10;         //Constant size for inventory arrays
    int instance=0,             //Current part of the story
            invNum[INVSIZE]={}; //Numbers on the left side of the inventory list
    int random[SIZE][COLUMNS];  //2d array
    float age;                  //Age value at the end of the game
    string storyItm[SIZE];      //Holds the story instances
    string invName[INVSIZE];    //Holds the names of items in the inventory
    //Set random array
    srand(static_cast<unsigned int>(time(0)));
    fillAry(SIZE,random);
    useAry(SIZE,random);
    //Display main menu
    showMenu();
    cin>>menuItm;
    while(menuItm<49||menuItm>52){
        cout<<"Sorry, that's not an option"<<endl;
        cin>>menuItm;
    }
    //Write the story
    storyFunc(storyItm);
    //Enter in values for inventory numbers
    for (int i=0;i<=INVSIZE;i++){
        invNum[i]=i+1;
    }
    //Main game
    if (menuItm==49){ //When the player starts a new game
        do{
            cout<<storyItm[instance]<<endl; //Display the story text
            isDead=death(instance); //Check if player is dead
            if (isDead==true) return 0; //If dead end program
            cin>>instance;
            if (instance==101){ //Check if player wanted to display the map
                dispMap();
                cin>>instance;
            }else if (instance==102){ //Check if the player wanted to see the inventory
                inventory(instance,INVSIZE,invNum,invName);
                cin>>instance;
            }else if (instance==11){ //Check if player wanted to save the game
                saveGame(instance);
            }else if (instance==2){ //If player get to instance 2 give them a brick
                invName[0]="A brick";
            }else if (instance==19){ //If player gets to instance 9, play Danger Road
                instance=dangerRd();
                cout<<storyItm[instance]<<endl;
                if (instance==20){
                    age=ageNum(5); //Call ageNum to randomize age
                    if (age<11){age+=40;
                    }else if (age<21){age+=30;
                    }else age+=20;                            
                    cout<<setprecision(3)<<age<<" years old. Thanks for playing!"<<endl;
                }
                return 0;
            }
        }while(instance!=103); //Ends the do-while loop   
    }else if (menuItm==50){ //When the player loads a previous game
        instance=load(); //Load the saved instance
        do{
            cout<<storyItm[instance]<<endl; //Display the story text
            isDead=death(instance); //Check if player is dead
            if (isDead==true) return 0; //If dead end program
            cin>>instance;
            if (instance==101){ //Check if player wanted to display the map
                dispMap();
                cin>>instance;
            }else if (instance==102){ //Check if the player wanted to see the inventory
                inventory(instance,INVSIZE,invNum,invName);
                cin>>instance;
            }else if (instance==11){ //Check if player wanted to save the game
                saveGame(instance);
            }else if (instance==2){ //If player get to instance 2 give them a brick
                invName[0]="A brick";
            }else if (instance==19){ //If player gets to instance 9, play Danger Road
                instance=dangerRd();
                cout<<storyItm[instance]<<endl;
                if (instance==20){
                    age=ageNum(5); //Call ageNum to randomize age
                    if (age<11){age+=40;
                    }else if (age<21){age+=30;
                    }else age+=20;                            
                    cout<<setprecision(3)<<age<<" years old. Thanks for playing!"<<endl;
                }
                return 0;
            }
        }while(instance!=103);  
    }else if (menuItm==51){ //When the player reads instructions
        cout<<"==Instructions=="<<endl;
        cout<<"This is a choose your own adventure game. Playing the game is easy.\n"
                "Simply enter in the number of the option you see below the story text and press enter.\n"
                "To open the map, input 101.\n"
                "To open your inventory, input 102.\n"
                "To quit the game, input 103.\n"
                "That's all you need. Good luck!"<<endl;
        return 0;
    }else if (menuItm==52){ //When the player decides to exit
        cout<<"Thanks for playing!"<<endl;
        return 0;
    }
    return 0;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   Display Map **************************************
//Purpose:  To display the map file
//Inputs:   N/A
//Output:   Outputs the information in the file visually
//******************************************************************************
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
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//****************************  Show Menu **************************************
//Purpose:  Show the menu file
//Inputs:   N/A
//Output:   Outputs the text inside the menu
//******************************************************************************
void showMenu(){
    //Declare variables
    ifstream in;
    string line;
    //Open the file
    in.open("menu.dat");
    //Display menu
    for (short i=0;i<=4;i++){
        getline(in,line);
        cout<<line<<endl;
    }
    //Close the file
    in.close();
    in.clear();
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************  Make Road *****************************************
//Purpose:  Produce a randomly generated road
//Inputs:   N/A
//Output:   Outputs the road onto road.dat
//******************************************************************************
void makeRd(){
    //Declare variables
    short obst; //Final random number
    float obsticle; //Initial random number
    ofstream out;
    string rdRow;
    //Create a random road
    out.open("road.dat"); //Open road file
    rdRow="===START===";out<<rdRow<<endl; //Create start banner
    rdRow="x] | | | [x";out<<rdRow<<endl; //Create blank starting road line
    for (short i=0; i<=10; i++){ //Random road generator
        obsticle=rand()%6+rand()%6;
        obst=obsticle+0.5f;
        switch (obst){
            case 0:rdRow="x]x|x| | [x"; break;
            case 1:rdRow="x]x| |x| [x"; break;
            case 2:rdRow="x]x| | |x[x"; break;
            case 3:rdRow="x] |x|x| [x"; break;
            case 4:rdRow="x] |x| |x[x"; break;
            case 5:rdRow="x] | |x|x[x"; break;                   
        }
        out<<rdRow<<endl; //Shove random road lines into road.dat
    }
    rdRow="====END===="; out<<rdRow<<endl; //Create end banner
    //close road.dat
    out.close();
    out.clear();  
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************  Save Game *****************************************
//Purpose:  Save the story progress of the player
//Inputs:   The story instance the player is in
//Output:   Outputs the instance number to the savegame file
//******************************************************************************
void saveGame(int instance){
    //Declare Variables
    ofstream out;
    string save;
    //Check if player wants to save
    cout<<"Would you like to save?"<<endl;
    cin>>save;
    if (save=="yes"||save=="Yes"||save=="YES"||save=="y"||save=="Y"){
        //Open the file
        out.open("savegame.dat");
        out<<instance;
        //Close the file
        out.close();
        out.clear();  
        cout<<"Game saved."<<endl;
    }
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************  Story Function ************************************
//Purpose:  Store the story elements into a string array
//Inputs:   The story string array
//Output:   The story string array filled
//******************************************************************************
void storyFunc(string storyItm[]){
    //Enter the story into an array
    storyItm[0]="You awake in a cave. The air is stale and musty, and darkness permeates all around you. "
            "Who are you? How did you get here? These are questions you can't seem to recall the answer to. "
            "What do you do?\n"
            "1. I really try and remember who I am and how I got here. I sit down and focus my mind.\n"
            "2. I take a better look around the place to see if I can find any clues or useful items.\n"
            "3. I choose a direction and start walking.";    
    storyItm[1]="Some time passes. Exactly how long is unknown, as there is no light reaches this underground prison. "
            "As you continue to ponder about your past, little snippets return to your memory. Your name is... Gareth... "
            "Gareth Something. Your head starts to ache as you strain to remember more. The last thing you remember doing "
            "was gathering firewood, before you felt a sharp pain in the back of your head and the world turned to darkness. "
            "You touch your head with your fingertips. It's wet.\n"
            "4. I cry out for help as loud as I can.\n"
            "2. I take a better look around the place to see if I can find any clues or useful items.\n"
            "3. I choose a direction and start walking.";   
    storyItm[2]="You search around, gingerly feeling for things in front of you. You can't even see your hands in the "
            "pitch darkness. By sheer luck, you kick a loose rock. Picking it up, you are surprised to fid that is has a "
            "defined shape. You have found a brick. But what is a brick doing here? Where exactly are you?\n"
            "5. I look for other signs of life in the cave.\n"
            "4. I cry out for help as loud as I can.\n"
            "3. I choose a direction and start walking.";    
    storyItm[3]="You start to walk in a random direction, reaching out with ever sense but sight, listening to your instincts "
            "more than logic. After a few seconds of walking, you hit a wall. It's surface is smooth and made of large,"
            " bulbous shapes. It's a stone wall. How peculiar. You decide to walk along the wall to see what else you can "
            "find. A few moments later, you hit another wall. Perhaps this is not a natural cave as you first thought.\n"
            "4. I cry out for help as loud as I can.\n"
            "6. I keep walking along the wall and look for an exit.";    
    storyItm[4]="You take a lung-full of the thick air, and you bellow a the loudest yell you can muster. The sound bounces "
            "painfully back to your ears. Hold on. What was that? AS the ringing fades from your ears you hear the sound "
            "of footsteps from up above. It's followed quickly by the sound of a creaking door, and there is a faint glow "
            "coming from a now illuminated stairway. Faint outlines of things are now visible in the room you are in. "
            "THUD. THUD. THUD. Something is making its way down to you.\n"
            "7. I stay still and wait for it to come down. Who knows? It could be friendly.\n"
            "8. I hide around the corner of the stairway and wait to attack whatever comes.\n"
            "9. I look around quickly for a place to hide.";   
    storyItm[5]="You keep searching, but in vain. You see nothing in the all encompassing void around you. Just as you feel "
            "insanity creeping upon your mind, you walk into a wall. As you move your hands along its smooth surface, you "
            "come to the realization that its a stone wall. Man-made and unnatural. Where ARE you?\n"
            "4. I cry out for help as loud as I can.\n"
            "6. I keep walking along the wall and look for an exit.";   
    storyItm[6]="You slowly make your way along the wall, reaching out as far as possible with your arms. To your great "
            "relief, you stumble across an entrance to a corridor. Perhaps there is a way out of here. The corridor leads "
            "to a spiral stairway, which you slowly take up up upwards into the unknown darkness. As you round the "
            "corner of the spiral, you see a faint glow up ahead. Crunch crunch munch. With your hearing strained as hard "
            "as it can be, you hear the sound of loud eating. Of bones being broken and chewed. Sneaking your way to the top "
            "of the stairs, the origin of the noise is revealed. An orc, huge and green, with arm muscles bigger than your "
            "head, is making a meal of what appears to be the remains of... a human.\n"
            "10. I sneak up behind him and attack. I can win with the element of surprise.\n"
            "11. Attacking such a thing is crazy. I try to sneak past it.\n"
            "12. It doesn't look too scary. I yell to try and scare it off.";   
    storyItm[7]="You decide to stay put and see what comes appears. THUD. THUD. THUD. Closer and closer the noises come. The "
            "faint glow getting brighter and brighter until IT, comes into view. A giant creature with green skin and muscles "
            "bigger than your head. It snorts and growls as it stares at you.\n"
            "14. I try to run past it!\n"
            "15. I attack before it can react!\n"
            "16. I stay perfectly still and don't move a muscle.";    
    storyItm[8]="You steel your nerves for the fight to come, and press your back against the wall. Your breathing intensifies "
            "but you manage to lower it to a less audible state. THUD. THUD. THUD. A candle turns the corner and... you "
            "leap onto the whatever was holding the candle! Unfortunately, you find yourself on the back of an orc. With a "
            "hand as big as your head, it grips your skull and lifts you from its back. It promptly crushes your skull with "
            "one swift motion. You are dead.";   
    storyItm[9]="Looking around at the new shapes in the room, you spot what appears to be a pile of bricks. Thinking on your "
            "feet, you decide to hide behind it. Whatever was lumbering its way down the stairs arrives, and you can hear "
            "loud breathing and an occasional snort. Whatever this is isn't human, and in this world, that means not friendly. "
            "The creature growls as it realizes that you are gone from where it had left you, and it starts to sniff the air "
            "for your scent.\n"
            "13. I jump out and make a break for it!\n"
            "15. I attack it before it can react!\n"
            "17. I stay perfectly still and hide as best as possible.";
    storyItm[10]="As quietly as you can, you sneak up behind the orc. Step by step, inch by inch, you skulk towards the beast. "
            "After some mental preparation, and a second for dramatic effect...you POUNCE on the orc! It roars in anger as it "
            "jumps up and begins to thrash around the cave. You hold on for dear life as the orc swings you helplessly back and"
            " forth. It backs up onto the wall and squishes you, knocking the air clean from your lungs, and causing dust to "
            "fall from the ceiling. You let go and fall to the floor. Almost blind with anger, the orc bellows at you, spit "
            "flying from its mouth. It stomps your head into the floor and your skull turns to mush. You are dead.";   
    storyItm[11]="Step by step, inch by inch, you make your way past the brute. Crunch munch munch. As you get closer you can see "
            "what it had been snacking on more clearly. It was a human, an old man it seems. the scene is too gruesome to "
            "describe, along with the terrifying stench. Holding your breath and walking on the tips of your toes, you manage to "
            "sneak past the orc. Following the slight breeze you make it to the door behind the orc and leave. The cool night "
            "air greets you as you leave the great danger behind. In the dim moonlight you make out that you were actually in a "
            "house, the house of Old Man Patrik. That was probably him getting eaten back there. Oh well, nothing you can do now. "
            "Luckily, there is a road that leads from the house to a pond and another, much older house. From the house, you can "
            "make your way towards the town.\n"
            "18. I make my way to the pond.\n"
            "19. I make my way into town.";   
    storyItm[12]="Taking a huge breath, filling your lungs to the top, you let out the bravest, scarriest scream you can muster. "
            "The orc is still... after what seems like eons it turns around and stares right at you. It sucks in gallons of air "
            "from its huge mouth and returns the gesture. The sheer force of its voice rocks your entire body. Your ears are"
            " ringing and you feel dizzy. With surprising speed, the orc crosses the distance between you and him. With a single"
            "punch, it knocks you to the wall. You land badly, with your head first. Your vision slowly fades as you lose your "
            "grip on consciousness. Unfortunately, you never wake up again.";    
    storyItm[13]="You squat prepare to sprint for your life. 1...2...3... and go! You explode from behind the pile of bricks and "
            "charge towards the stairway. Now you see what it was. An orc. Green with muscles the size of your head, it stands "
            "between you and the only exit from the room. You try to run past it, but it's hulking mass is simply too big to "
            "squeeze through. It grabs your head with its meaty hands and squeezes. It's horrific face is the last thing you see.";    
    storyItm[14]="You sprint towards the orc and try to get to the stairway behind it. Unfortunately, it's hulking mass is simply "
            "too big to squeeze through. It grabs your head with its meaty hands and squeezes. It's horrific face is the last thing "
            "you see.";    
    storyItm[15]="You pick up one of the bricks from the pile nearby, and you charge the creature. You manage to reach it before it"
            "could think, and hit it in the head with the brick. And you hit it in the head with the brick. And you hit it in the "
            "head with the brick. Over and over and over. The orc barely flinches as you exhaust yourself. After a few minutes of "
            "flailing to no effect, the orc grabs your head with its humongous hands, and crushes your skull. You are dead.";
    storyItm[16]="You hold your breath and freeze for your life. The orc stares right at you for what seems like an eternity. It "
            "snorts and turns around, lumbering back up the stairs. You give a sigh or relief. That was a close one. You take the "
            "stairway upwards and see quite a sight. As you round the corner of the spiral, you see a faint glow up ahead. Crunch "
            " crunch munch. With your hearing strained as hard as it can be, you hear the sound of loud eating. Of bones being "
            "broken and chewed. Sneaking your way to the top of the stairs, you see that the orc is making a meal of what appears "
            "to be the remains of... a human.\n"
            "10. I sneak up behind him and attack. I can win with the element of surprise.\n"
            "11. Attacking such a thing is crazy. I try to sneak past it.\n"
            "12. It doesn't look too scary. I yell to try and scare it off.";     
    storyItm[17]="You hold your breath for what seems like an eternity. 1...2...3... minutes pass. You are paralyzed with fear. Just"
            "when you think you can't hold it any longer, the orc turns around and leaves the room. You give a sigh or relief. "
            "That was a close one. You take the stairway upwards and see quite a sight. As you round the corner of the spiral, "
            "you see a faint glow up ahead. Crunch crunch munch. With your hearing strained as hard as it can be, you hear the sound "
            "of loud eating. Of bones being broken and chewed. Sneaking your way to the top of the stairs, you see that the orc is "
            "making a meal of what appears to be the remains of... a human.\n"
            "10. I sneak up behind him and attack. I can win with the element of surprise.\n"
            "11. Attacking such a thing is crazy. I try to sneak past it.\n"
            "12. It doesn't look too scary. I yell to try and scare it off."; 
    storyItm[18]="As you make your way to the pond, walking the old dirt road, where it leads to the side of a large hill. As you round "
            "the corner though, you come upon an impasse. The way ahead is blocked by a fallen tree. You look to the sides for any way "
            "around the blockage, but to no avail. It seems you have to turn back for now.\n"
            "19. I turn back and make my way to town.";
    storyItm[19]="You walk the dirt road to town. The night air is cool and crisp, and the stars are out and about. Thankfully, the way"
            " there is uneventful, and there are no more monsters yearning for your flesh in the area. When you reach the town, the "
            "gatekeeper is frightened by your gruesome looks. Bloody, tattered clothes. Entire body covered in dirt. You explain your"
            "particular situation, and he believes you. 'Worse than anything I'd ever seen. I'm surprised you're still alive. I'll talk to"
            "people about the orc threat. You go and rest up.' Thanking him, you enter the town and go to your house, where you clean "
            "yourself and plop into bed. That night, you have a strange dream...\n"
            "         a=left          d=right         s=down          ";
    storyItm[20]="You awaken from the dream, rested but confused. What was that? Pushing it to the back of your mind, you decide to get "
            "your head injury attended to. The doctor bandages your wounds, and in a few days you feel good as new. The town forms a "
            "militia to slay the orc, and they return victorious, dragging the huge carcass behind them as they paraded through "
            "the streets. The rest of your life is uneventful and you die peacefully on your bed after telling stories of your adventure "
            "for years at the local tavern. You manage to reach the tender age of...";
    storyItm[21]=" ";
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************  Fill Array ****************************************
//Purpose:  Fill the 2d array with random values
//Inputs:   Constant size of arrays(SIZE) & the 2d array
//Output:   Filled 2d array
//******************************************************************************
void fillAry(int n,int random[][COLUMNS]){
    //Fill the array
    for (int i=0;i<=n;i++){ //Every row
        for(int j=0;j<=COLUMNS;j++){ //Every column
            random[i][j]=rand()%1000+1; //random numbers between 1 and 1000
        }
    }
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************  Use Array  ****************************************
//Purpose:  Utilize the 2d array for something
//Inputs:   SIZE & randomly filled 2d array
//Output:   N/A
//******************************************************************************
void useAry(int size,int random[][COLUMNS]){
    //Declare Variables
    const int SIZE=500;
    int randum[SIZE]; //1d array which holds info from the 2d array
    int rows,value,find;
    //Transfer the values from the random 2d array to a 1d array
    for(int i=0;i<=SIZE; i++){
        for(int j=0;j<=COLUMNS;j++){
            randum[i]=random[rows][j];
        }
        if(i%5==0) rows++;
    }   
    //Sort the new 1d array
    for(int i=0;i<SIZE-1;i++){
        for(int j=i+1;j<SIZE;j++){
            if(randum[i]>randum[j]){
                randum[i]=randum[i]^randum[j];
                randum[j]=randum[i]^randum[j];
                randum[i]=randum[i]^randum[j];
            }
        }
    }   
    //Linear search for random number
    value=rand()%1000+1;
    for(int i=0;i<SIZE;i++){
        if(randum[i]==value)find=i;
    }
    find=-1;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************  Inventory  ****************************************
//Purpose:  Display player inventory
//Inputs:   The instance number, size of the inventory array, the array for 
//          numbering the inventory list, & the array for item names
//Output:   Outputs display of inventory arrays
//******************************************************************************
void inventory(int instance,int INVSIZE,int invNum[],string invName[]){
    //Display inventory banner
    cout<<"==Inventory=="<<endl;
    //Display inventory
    for (int i=0;i<=INVSIZE-1;i++){
        cout<<invNum[i]<<invName[i]<<endl;
    }
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//***************************  Death  ******************************************
//Purpose:  Determine if player is dead
//Inputs:   Instance number 
//Output:   Outputs boolean value
//******************************************************************************
bool death(int instance){
    //State which instances will kill
    switch (instance){
        case 8: return true; break;
        case 10: return true; break;
        case 12: return true; break;
        case 13: return true; break;
        case 14: return true; break;
        case 15: return true; break;
    }
    //Player is not in any instance listed above
    return false;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************     Load    ****************************************
//Purpose:  Load saved game
//Inputs:   N/A
//Output:   Outputs instance number from savegame.dat
//******************************************************************************
int load(){
    //Declare variables
    ifstream in;
    int instance;
    //Open the file
    in.open("savegame.dat");
    in>>instance;
    //close the file
    in.close();
    in.clear();
    //Return the instance
    return instance;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************  Danger Road ***************************************
//Purpose:  Pad the game out with strange dream sequence/ put previous code to 
//          good use
//Inputs:   N/A
//Output:   Integer value instance
//******************************************************************************
int dangerRd(){
    //Declare variables
    bool isDone=false;     //Value to check if player is finished
    char move;             //The player's movement option
    short rows, cols;      //Amount of rows and columns
    short prow=0, pcol=5;  //Player position
    ofstream out;
    ifstream in;
    string line;
    //Danger Road game
    //Create random road
    makeRd();
    //Create player and track movements
    while(isDone==false){
        //Input values
        in.open("road.dat");
        rows=13; cols=9;
        //Display Output and write to the player file
        out.open("player.dat");
        getline(in,line); //Read start banner
        cout<<line<<endl; //Display start banner
        for(int row=0;row<=rows;row++){
            getline(in,line); //Read road lines
            if(row==prow&&line[pcol-1]==' ')line[pcol-1]='V'; //Replace spaces with character
            if(row==prow&&line[pcol-1]=='x'){ //Check if player has crashed
                cout<<"Due to your head injury, you go into a coma. You never wake up again."<<endl;
                isDone=true;
                in.close();
                out.close();
                return 21;}
            cout<<line<<endl; //Display road lines
            out<<line; //Shove new lines into player file
        }
        //Player movements
        char move;
        cin>>move;
        switch (move){
            case 'A':case'a':pcol-=2; break; //Character moves one lane left
            case 'D':case'd':pcol+=2; break; //Character moves one lane right
            case 'S':case's':pcol+=0; break; //Character stays straight
            case 'W':case'w':cout<<"Strange. Nothing happens."<<endl; prow--; break;
            default:cout<<"Your go straight down."<<endl;
        }
        prow++; //Ensure the player goes down
        //See if the player has reached the end
        if (prow==12){
            isDone=true;
        }//Close the if statement    
    }//Close while loop
    //Close the files
    in.close();
    out.close();
    return 20;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************  Age Number  ***************************************
//Purpose:  Further randomize the age value
//Inputs:   Integer value of 5
//Output:   Random Number
//******************************************************************************
float ageNum(short n){
    float ageNum;
    ageNum=((rand()%100+1)/(rand()%10+1))+(sizeof(int)*n);
    return ageNum;
}