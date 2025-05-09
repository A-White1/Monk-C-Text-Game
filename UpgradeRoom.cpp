#include "UpgradeRoom.h"
#include "pch.h"
using namespace std;

void UpgradeRoom::upgradeRoom() //Method for upgrade room.
{
	cout << "**********************************************************************************************\n\n";
	std::this_thread::sleep_for(1s);
	cout << "You have entered the upgrade room...\n";
	std::this_thread::sleep_for(1s);
	cout << "You have a choice, type [1] for an additional 5 health points\n";
	std::this_thread::sleep_for(1s);
	cout << "Or, type [2] for an additional 2 attack points\n";
	std::this_thread::sleep_for(1s);
	cout << "**********************************************************************************************\n\n";
	
	while (!choices) //Validation for the user inputting 1 or 2.
	{	
		cin >> choiceForUpgrade;
		if (choiceForUpgrade != 1 && choiceForUpgrade !=2) {
			cout << "Invalid choice\n";
			cin.clear();
			std::this_thread::sleep_for(1s);
			cin.ignore(10000, '\n');
		}
		else{
			choices = true;
			cin.clear();
			std::this_thread::sleep_for(1s);
			cin.ignore(10000, '\n');
		} 
	}
	int healthPts = getMonkHealth(); 
	int maxHPts = getMaxHealthPoints();
	int attackPts = getMonkAttackPoints();
	switch (choiceForUpgrade) {
	case 1: //Increases health points by five.
		cout << "You have chosen to upgrade your health...\n";
		std::this_thread::sleep_for(1s);
		cout << "Your health has been increased by [5] points\n";
		std::this_thread::sleep_for(1s);
		cout << "**********************************************************************************************\n\n";
		std::this_thread::sleep_for(1s);

		healthPts += 5;
		maxHPts += 5;

		setMonkMaxHealth(maxHPts);
		setMonkHealth(healthPts);

		cout << "Current player health " << getMonkHealth() << '\n';
		std::this_thread::sleep_for(1s);
		cout << "**********************************************************************************************\n\n";
		cout << "Current max health [" << getMaxHealthPoints() << "]\n";
		std::this_thread::sleep_for(1s);
		cout << "**********************************************************************************************\n\n";
		break;
	case 2: //Increases attack power by two points.
		cout << "You have chosen to upgrade your attack points...\n";
		std::this_thread::sleep_for(1s);
		cout << "Your attack points has been increased by [2] points\n";
		std::this_thread::sleep_for(1s);
		cout << "**********************************************************************************************\n\n";
		std::this_thread::sleep_for(1s);

		attackPts += 2;

		setMonkAttackPoints(attackPts);

		cout << "Current attack points [" << getMonkAttackPoints() << "]\n";
		std::this_thread::sleep_for(1s);
		cout << "**********************************************************************************************\n\n";

		break;

	}

	choices = false; //Resets choices so the user has to reinput their choice of upgrade the next time the method is called.
	cin.clear();

}
