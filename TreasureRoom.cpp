#include "TreasureRoom.h"
#include "pch.h"

using namespace std;

void TreasureRoom::treasureRoom() //Method for treasure room. This will be called at the end of the game
{
	cout << "**********************************************************************************************\n";
	std::this_thread::sleep_for(2s);
	cout << "You see a glowing room in the distance...\n";
	std::this_thread::sleep_for(2s);
	cout << "You open the room...\n";
	std::this_thread::sleep_for(2s);
	cout << "In front of you is a treasure chest\n";
	std::this_thread::sleep_for(2s);
	cout << "You open the chest...\n";
	std::this_thread::sleep_for(2s);
	cout << "Inside you see [" << getMonkItem() << "]!\n"; //The treasure will be the players item they were asked for at the start of the game.
	std::this_thread::sleep_for(2s);
	cout << "Congratulations, [" << getMonkName() << "] you have won the game!\n";
	std::this_thread::sleep_for(1s);
	std::exit(0);

}
