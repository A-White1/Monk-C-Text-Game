#pragma once
class Room
{
public:
	int randRoom(); // method to generate random room types for 1 door
	void randRoom2(); // method to generate random number types for 2 doors
	void randRoom3(); // method to generate a random room types for 3 doors
	int randDoor(); // method to generate a random number of doors
	void roomDungeon(); 
	int doorNumber;
	int roomRandChoice2[2];
	int roomRandChoice3[3];
	int roomNumber;
private:
	int randomNumberRoom1;
	int randomNumberRoom2;
	int randomNumberRoom3;
	int randomNumberDoor;
	
	
};

