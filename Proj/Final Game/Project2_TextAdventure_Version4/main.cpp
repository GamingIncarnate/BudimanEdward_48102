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
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void dispMap();
void showMenu();
void makeRd();
void saveGame(int);
void storyFunc(string[]);
void inventory(string[],int);
void gameFx(int,string[]);
bool death(int);
int load();
int dangerRd();


//Program Execution
int main(int argc, char** argv) {
    //Set random number seed
     srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    bool isDead=false;
    char menuItm;
    const int SIZE=100;
    int instance=0;
    string invItm[SIZE];
    string storyItm[SIZE];

    //Display main menu
    showMenu();
    cin>>menuItm;
    while(menuItm<49||menuItm>52){
        cout<<"Sorry, that's not an option"<<endl;
        cin>>menuItm;
    }
    
    //Write the story
    storyFunc(storyItm);
    
    //Main game
    if (menuItm==49){ //When the player starts a new game
        do{
            cout<<storyItm[instance]<<endl;
            isDead=death(instance);
            if (isDead==true) return 0;
            gameFx(instance,invItm);
            if (instance==19){
                instance=dangerRd();
                cout<<storyItm[instance]<<endl;
                return 0;
            }
            cin>>instance;
        }while(instance!=103);
        
    }else if (menuItm==50){ //When the player loads a previous game
        instance=load();
        do{
            cout<<storyItm[instance]<<endl;
            isDead=death(instance);
            if (isDead==true) return 0;
            gameFx(instance,invItm);
            cin>>instance;
            if (instance==19){
                instance=dangerRd();
                cout<<storyItm[instance]<<endl;
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

    cout<<"Thanks for playing!"<<endl;
    return 0;
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

void makeRd(){
//Declare variables
    short obst;
    ofstream out;
    string rdRow;
//Create a random road
    out.open("road.dat"); //Open road file
    rdRow="===START===";out<<rdRow<<endl; //Create start banner
    rdRow="x] | | | [x";out<<rdRow<<endl; //Create blank starting road line
    for (short i=0; i<=10; i++){ //Random road generator
        obst=rand()%6;
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

void saveGame(int instance){
    ofstream out;
    string save;
    
    cout<<"Would you like to save?"<<endl;
    cin>>save;
    
    if (save=="yes"||save=="Yes"||save=="YES"||save=="y"||save=="Y"){
        out.open("savegame.dat");
        out<<instance;
        out.close();
        out.clear();  
        cout<<"Game saved."<<endl;
    }
}

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
            "around the blockage, but to no luck. It seems you have to turn back for now.\n"
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
            "militia to go and kill the orc, and they return victorious, dragging the huge carcass behind them as they paraded through "
            "the streets. The rest of your life is uneventful and you die peacefully on your bed after telling stories of your adventure "
            "for years at the local tavern. You manage to reach the tender age of 69 before you pass on to the next life. Thanks for playing.";
    storyItm[21]=" ";
}

void inventory(string invItm[], int instance){
    int invCntr=0;
    int invSize=10;
    switch (instance){
        case 2:invItm[invCntr]="A brick"; invCntr++; break;
        case 102: for(int i=0;i<=invSize-1;i++){
            cout<<i+1<<". "<<invItm[i]<<endl;
        }break;
    }
}

void gameFx(int instance,string invItm[]){
    if (instance==101) dispMap();
    inventory(invItm,instance);
    switch (instance){
        case 11:saveGame(instance);break;
    }
}

bool death(int instance){
    switch (instance){
        case 8: return true; break;
        case 10: return true; break;
        case 12: return true; break;
        case 13: return true; break;
        case 14: return true; break;
        case 15: return true; break;
    }
    return false;
}

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

int dangerRd(){
//Declare variables
    char move;
    short rows, cols;
    short prow=0, pcol=5;
    ofstream out;
    ifstream in;
    string line;
//Danger Road game
//Create random road
    makeRd();
//Create player and track movements
    while(prow!=12){

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
            case 'W':case'w':cout<<"Your car sucks and can't go uphill. But it can jump."<<endl; prow++; break;
            default:cout<<"Your car doesn't respond."<<endl;
        }
        prow++; //Ensure the player goes down

        //See if the player has reached the end
        if (prow==12){
            return 20;
            //Close the file
            in.close();
            out.close();
        }
        //Close the file
        in.close();
        out.close();
    }//Close while loop
}
