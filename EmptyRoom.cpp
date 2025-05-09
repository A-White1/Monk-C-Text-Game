#include "EmptyRoom.h"
#include "MonkCharacter.h"
#include "pch.h"

using namespace std;

void EmptyRoom::emptyRoomHeal() 
/*Method for the empty room.This will automatically heal the player to their maximum health, 
if they have upgraded health, the health will be put to the new maximum.*/
{
	cout << "**********************************************************************************************\n\n";

	cout << "Current player health [" << getMonkHealth() << "]\n";
	setMonkHealth(getMaxHealthPoints());

	std::this_thread::sleep_for(1s);
	cout << "You have entered the empty room....\n";
	std::this_thread::sleep_for(1s);
	cout << "As you walk through the room, you feel revitalized...\n";
	std::this_thread::sleep_for(1s);

	cout << "Player Health is now at maximum.\n";
	std::this_thread::sleep_for(1s);

	cout << "Current player health [" << getMonkHealth() << "]\n";
	cout << "**********************************************************************************************\n\n";
}
