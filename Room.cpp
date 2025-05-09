#include "Room.h"
#include "pch.h"
#include <cstdlib>
#include <ctime>

using namespace std;



//Random Number Generators for which room the player will go into when they choose a door to go into.

int Room::randRoom() { //For 1 room
	
	std::random_device rd2;     
	std::mt19937 rng2(rd2());    
	std::uniform_int_distribution<int> uni(1, 3); 
	uni.reset();
	auto randomNumberRoom1 = uni(rng2);

	return randomNumberRoom1;
}

void Room::randRoom2() //For 2 rooms
{
	std::random_device rd3;
	std::mt19937 rng3(rd3());
	std::uniform_int_distribution<int> uni(1, 3);
	uni.reset();
	auto randomNumberRoom2 = uni(rng3);

	std::random_device rd4;
	std::mt19937 rng4(rd4());
	std::uniform_int_distribution<int> uni2(1, 3);
	uni2.reset();
	auto randomNumberRoom3 = uni2(rng4);

	roomRandChoice2[0] = randomNumberRoom2;
	roomRandChoice2[1] = randomNumberRoom3;
}

void Room::randRoom3() //For 3 rooms
{
	std::random_device rd2;
	std::mt19937 rng2(rd2());
	std::uniform_int_distribution<int> uni(1, 3);
	uni.reset();
	auto randomNumberRoom1 = uni(rng2);

	std::random_device rd3;
	std::mt19937 rng3(rd3());
	std::uniform_int_distribution<int> uni2(1, 3);
	uni2.reset();
	auto randomNumberRoom2 = uni2(rng3);

	std::random_device rd4;
	std::mt19937 rng4(rd4());
	std::uniform_int_distribution<int> uni3(1, 3);
	uni3.reset();
	auto randomNumberRoom3 = uni3(rng4);

	roomRandChoice3[0] = randomNumberRoom1;
	roomRandChoice3[1] = randomNumberRoom2;
	roomRandChoice3[2] = randomNumberRoom2;

}
 
//Random Number Generator for the amount of doors that will be available to go at each 'crossroads' when playing

int Room::randDoor() { //For deciding how many rooms there will be 
	
	std::random_device rd1;     
	std::mt19937 rng1(rd1());    
	std::uniform_int_distribution<int> uni(1, 3); 

	auto randomNumberDoor = uni(rng1);
	
	return randomNumberDoor;
}

void Room::roomDungeon()  //This is the method for the layout of the 'randomly generated dungeon'
{
	doorNumber = randDoor();
	Room r;
	r.doorNumber = doorNumber;

	switch (doorNumber) {
		case 1: //Case checks for the amount of doors in this loop and gives each door a corresponding room that the user can choose to enter.
			roomNumber = randRoom();
			switch (roomNumber) {
				case 1:
					cout << "The door forwards is an empty room\n";
					break;
				case 2:
					cout << "The door forwards is an monster room\n";
					break;
				case 3:
					cout << "The door forwards is an upgrade room\n";
					break;
			}
			cout << "There is 1 door ahead of you, type a direction: \n\n";
			std::this_thread::sleep_for(1s);
			break;

		case 2:
			randRoom2();

			switch (roomRandChoice2[0]) {
			case 1:
				cout << "The door forwards is an empty room\n";
				break;
			case 2:
				cout << "The door forwards is an monster room\n";
				break;
			case 3:
				cout << "The door forwards is an upgrade room\n";
				break;
			}

			switch (roomRandChoice2[1]) {
			case 1:
				cout << "The door on the left is an empty room\n";
				break;
			case 2:
				cout << "The door on the left is an monster room\n";
				break;
			case 3:
				cout << "The door on the left is an upgrade room\n";
				break;
			}
			cout << "There are 2 doors ahead of you, Forwards and Left, type a direction: \n\n";
			std::this_thread::sleep_for(1s);
			break;

		case 3:
			randRoom3();

			switch (roomRandChoice3[0]) {
			case 1:
				cout << "The door forwards is an empty room\n";
				break;
			case 2:
				cout << "The door forwards is an monster room\n";
				break;
			case 3:
				cout << "The door forwards is an upgrade room\n";
				break;
			}

			switch (roomRandChoice3[1]) {
			case 1:
				cout << "The door on the left is an empty room\n";
				break;
			case 2:
				cout << "The door on the left is an monster room\n";
				break;
			case 3:
				cout << "The door on the left is an upgrade room\n";
				break;
			}

			switch (roomRandChoice3[2]) {
			case 1:
				cout << "The door on the right is an empty room\n";
				break;
			case 2:
				cout << "The door on the right is an monster room\n";
				break;
			case 3:
				cout << "The door on the right is an upgrade room\n";
				break;
			}


			cout << "There are 3 doors ahead of you, Forwards, Left and Right, type a direction: \n\n";

			break;
			std::this_thread::sleep_for(1s);
				

	}


}
