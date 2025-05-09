#include <iostream>
#include "Room.h"
#include "pch.h"
#include "MonkCharacter.h"
#include "EmptyRoom.h"
#include "UpgradeRoom.h"
#include "MonsterRoom.h"
#include "TreasureRoom.h"

using namespace std;

int main() 
{           
    EmptyRoom er; //Creating instance of classes
    UpgradeRoom ur;
    MonsterRoom mr;
    TreasureRoom tr;


    system("title Monk");
    system("Color 0A");

    std::cout << R"(
          _____                   _______                   _____                    _____          
         /\    \                 /::\    \                 /\    \                  /\    \         
        /::\____\               /::::\    \               /::\____\                /::\____\        
       /::::|   |              /::::::\    \             /::::|   |               /:::/    /        
      /:::::|   |             /::::::::\    \           /:::::|   |              /:::/    /         
     /::::::|   |            /:::/~~\:::\    \         /::::::|   |             /:::/    /          
    /:::/|::|   |           /:::/    \:::\    \       /:::/|::|   |            /:::/____/           
   /:::/ |::|   |          /:::/    / \:::\    \     /:::/ |::|   |           /::::\    \           
  /:::/  |::|___|______   /:::/____/   \:::\____\   /:::/  |::|   | _____    /::::::\____\________  
 /:::/   |::::::::\    \ |:::|    |     |:::|    | /:::/   |::|   |/\    \  /:::/\:::::::::::\    \ 
/:::/    |:::::::::\____\|:::|____|     |:::|    |/:: /    |::|   /::\____\/:::/  |:::::::::::\____\
\::/    / ~~~~~/:::/    / \:::\    \   /:::/    / \::/    /|::|  /:::/    /\::/   |::|~~~|~~~~~     
 \/____/      /:::/    /   \:::\    \ /:::/    /   \/____/ |::| /:::/    /  \/____|::|   |          
             /:::/    /     \:::\    /:::/    /            |::|/:::/    /         |::|   |          
            /:::/    /       \:::\__/:::/    /             |::::::/    /          |::|   |          
           /:::/    /         \::::::::/    /              |:::::/    /           |::|   |          
          /:::/    /           \::::::/    /               |::::/    /            |::|   |          
         /:::/    /             \::::/    /                /:::/    /             |::|   |          
        /:::/    /               \::/____/                /:::/    /              \::|   |          
        \::/    /                 ~~                      \::/    /                \:|   |          
         \/____/                                           \/____/                  \|___|     
                                                                                                    		
    )" << '\n';

    
    string userDirection; // Local variables
    int userDoor;
    string playerName;
    string playerItem;

    mr.enemyDifficulty(); //Calls method that the user uses to decide the enemy's attack power

    string textBarrier = "**********************************************************************************************\n";
    string textBarrier2 = "//////////////////////////////////////////////////////////////////////////////////////////////\n\n";
    cout << textBarrier << '\n';
    cout << "Welcome to Monk! \n";
    std::this_thread::sleep_for(2s); //Text is delayed to give a rpg feel to it.
    cout << "This is an RPG game, where you play as a Monk, and have to explore the randomly generated dungeon to reach the treasure room. \n";
    std::this_thread::sleep_for(2s);
    cout << "Press ENTER to continue... \n";
    cin.get();
    cout << textBarrier << '\n';

    cout << "Enter your name: "; // User Enters their name
    cin >> playerName;
    mr.setMonkName(playerName);
    std::this_thread::sleep_for(2s);

    cout << "So, your name is: " << mr.getMonkName() << "?\n";
    std::this_thread::sleep_for(2s);

    
    cout << "Tell me about yourself... what item(s) do you like the most?: "; // User enters their favourite item
    cin >> playerItem;
    mr.setMonkItem(playerItem);
    std::this_thread::sleep_for(2s);

    cout << "Ok, so you like, " << mr.getMonkItem() << "?\n";
    std::this_thread::sleep_for(2s);
    cout << textBarrier2 << '\n'; 

    cout << "To navigate the dungeon, type 'L' to go left, 'F' to go forwards and 'R' to go right.\n\n"; 

    //This line below checks that the user has gone through at least 1 of each room and 2 monster rooms before completing the game.
    //All checks have to be completed for the game to end.

    while (!mr.getEmptyRoomCheck() || !mr.getUpgradeRoomCheck() || mr.getMonsterRoomCheck() < 2) {  

    Room r; //Instance of the room class
    r.roomDungeon(); //Calls to the room class roomDungeon method.
    userDoor = r.doorNumber; //Sets the output to the userDoor variable

    bool doorcheck = false; 
    string directions1[] = {"F", "f"};  //These arrays are all used for validation for the user choice of door direction below in the class.
    string directions2[] = { "F", "L", "f", "l" };
    string directions3[] = { "F", "L", "R", "f", "l", "r"};

    string directions2F[] = { "F", "f" };
    string directions2L[] = { "L", "l" };
    string directions3R[] = { "R", "r" };

    /*This area of code below uses the Room class and its various methods to generate 1 - 3 different doors each loop, and assigns each door its own room type
    and the user can choose to access whichever one they want. There is seperate validation depending on the number of rooms involved.*/
    

        switch (userDoor) { 
        case 1: //This switch case is here to account for the amount of rooms and applies validation for all number of directions of door.
            do {
                cin >> userDirection;
                bool onedirection = (std::find(std::begin(directions1), std::end(directions1), userDirection)
                    != std::end(directions1));

                if (!onedirection) {
                    cout << "Invalid direction\n";
                    std::this_thread::sleep_for(1s);
                }
                else {
                    onedirection = true;
                    doorcheck = true;
                }
            } while (!doorcheck);

            cout << "Direction '" << userDirection << "' selected\n";
            std::this_thread::sleep_for(1s);

            switch (r.roomNumber)
            {
            case 1:
                er.emptyRoomHeal();
                er.setEmptyRoomCheck(true);
                break;
            case 2:
                mr.combat();
                er.setMonsterRoomCheck(er.getMonsterRoomCheck() + 1);
                break;
            case 3:
                ur.upgradeRoom();
                er.setUpgradeRoomCheck(true);
                break;
            }
            break;

        case 2:

            do {
                cin >> userDirection;
                bool twodirection = (std::find(std::begin(directions2), std::end(directions2), userDirection)
                    != std::end(directions2));

                if (!twodirection) {
                    cout << "Invalid direction\n";
                    std::this_thread::sleep_for(1s);
                }
                else {
                    twodirection = true;
                    doorcheck = true;
                }

            } while (!doorcheck);


            cout << "Direction '" << userDirection << "' selected\n";
            std::this_thread::sleep_for(1s);
            {
                bool twodirection2F = (std::find(std::begin(directions2F), std::end(directions2F), userDirection)
                    != std::end(directions2F));

                bool twodirection2L = (std::find(std::begin(directions2L), std::end(directions2L), userDirection)
                    != std::end(directions2L));
                if (twodirection2F) {
                    switch (r.roomRandChoice2[0])
                    {
                    case 1:
                        er.emptyRoomHeal();
                        er.setEmptyRoomCheck(true);
                        break;
                    case 2:
                        mr.combat();
                        er.setMonsterRoomCheck(er.getMonsterRoomCheck() + 1);
                        break;
                    case 3:
                        ur.upgradeRoom();
                        er.setUpgradeRoomCheck(true);
                        break;
                    }
                }
                else if (twodirection2L) {
                    switch (r.roomRandChoice2[1])
                    {
                    case 1:
                        er.emptyRoomHeal();
                        er.setEmptyRoomCheck(true);
                        break;
                    case 2:
                        mr.combat();
                        er.setMonsterRoomCheck(er.getMonsterRoomCheck() + 1);
                        break;
                    case 3:
                        ur.upgradeRoom();
                        er.setUpgradeRoomCheck(true);
                        break;
                    }

                }
            }

            break;

        case 3:
            do {
                cin >> userDirection;
                bool threedirection = (std::find(std::begin(directions3), std::end(directions3), userDirection)
                    != std::end(directions3));

                if (!threedirection) {
                    cout << "Invalid direction\n";
                    std::this_thread::sleep_for(1s);
                }
                else {
                    threedirection = true;
                    doorcheck = true;
                }
            } while (!doorcheck);

            cout << "Direction '" << userDirection << "' selected\n";
            std::this_thread::sleep_for(1s);

            {
                bool twodirection3F = (std::find(std::begin(directions2F), std::end(directions2F), userDirection)
                    != std::end(directions2F));

                bool twodirection3L = (std::find(std::begin(directions2L), std::end(directions2L), userDirection)
                    != std::end(directions2L));

                bool twodirection3R = (std::find(std::begin(directions3R), std::end(directions3R), userDirection)
                    != std::end(directions3R));


                if (twodirection3F) {
                    switch (r.roomRandChoice3[0])
                    {
                    case 1:
                        er.emptyRoomHeal();
                        er.setEmptyRoomCheck(true);
                        break;
                    case 2:
                        mr.combat();
                        er.setMonsterRoomCheck(er.getMonsterRoomCheck() + 1);
                        break;
                    case 3:
                        ur.upgradeRoom();
                        er.setUpgradeRoomCheck(true);
                        break;
                    }
                }
                else if (twodirection3L) {
                    switch (r.roomRandChoice3[1])
                    {
                    case 1:
                        er.emptyRoomHeal();
                        er.setEmptyRoomCheck(true);
                        break;
                    case 2:
                        mr.combat();
                        er.setMonsterRoomCheck(er.getMonsterRoomCheck() + 1);
                        break;
                    case 3:
                        ur.upgradeRoom();
                        er.setUpgradeRoomCheck(true);
                        break;
                    }

                }
                else if (twodirection3R) {
                    switch (r.roomRandChoice3[2])
                    {
                    case 1:
                        er.emptyRoomHeal();
                        er.setEmptyRoomCheck(true);
                        break;
                    case 2:
                        mr.combat();
                        er.setMonsterRoomCheck(er.getMonsterRoomCheck() + 1);
                        break;
                    case 3:
                        ur.upgradeRoom();
                        er.setUpgradeRoomCheck(true);
                        break;
                    }

                }
            }
            break;
        }

    }

    tr.treasureRoom(); // If the user gets through all doors specified, the treasure room method is called which signifies the completion of the game.
    
}
