#include "MonsterRoom.h"
#include "pch.h"
#include "MonkCharacter.h"
#include "Enemy.h"
using namespace std;

int MonsterRoom::eDifficulty = 0;
 
void MonsterRoom::combat() //Method for the monster room. This holds the game combat system
{
	cout << "**********************************************************************************************\n\n";
	std::this_thread::sleep_for(1s);
	cout << "\\\\\\\\\\\\\\\\\\MONSTER ROOM\\\\\\\\\\\\\\\\\\" << '\n';
	std::this_thread::sleep_for(1s);
	cout << "A goblin approaches!\n";
	std::this_thread::sleep_for(1s);
	

	while (getMonkHealth() >= 1 && getEnemyHealth() >= 1) {  //Will loop until either the player or enemy are at 0 or below health points.

		switch (actionNum) {  //actionNum is a randomly generated number which decides if the players move will work on not. 
		case 1:
			actionFail = true; //If it is true, the move works.
			break;
		case 2:
			actionFail = false; // If it is false, it fails.
			break;
		}

		actionNum = actionNumGen(); // Randomly Generated number for if the player move works
		willEnemyAct = enemyAttackGen(); // Randomly Generated number for if the enemy move works
		enemyAttackChoice = enemyAttackGen(); // Randomly Generated number to decide if the enemy will defend or attack.

		if (userTurn == true) { //If userTurn is true, the player attacks, if it is false, the enemy attacks

			cout << getMonkName() << ", it is your turn to act... type [1] for ATTACK and type [2] to DEFEND\n";
			cin >> combatInput;
			
			while (!choiceCheck) //choiceCheck loops the validation until the user inputs a correct value
			{
				cin >> combatInput;
				if (combatInput != 1 && combatInput != 2) {  //Validation so that the player can only input "1" or "2" for attack and defend respectively.
					cout << "Invalid choice\n";
					cin.clear();
					std::this_thread::sleep_for(1s);
					cin.ignore(10000, '\n');
				}
				else {
					choiceCheck = true;
				}
			}

			switch (combatInput) {
			case 1:
				if (actionFail == true) { // If attack fails
					cout << "**********************************************************************************************\n\n";
					std::this_thread::sleep_for(1s);
					cout << "Attack Failed\n";
					userTurn = false;
					std::this_thread::sleep_for(1s);
					
				}
				else { // If attack works
					cout << "**********************************************************************************************\n";
					std::this_thread::sleep_for(1s);
					cout << "Attack hit! Goblin lost: [" << getMonkAttackPoints() << "] health points\n";
					setEnemyHealth(getEnemyHealth() - getMonkAttackPoints());

					if (getEnemyHealth() < 1) {
						cout << "Current enemy health: [0]\n";
					}
					else {
						cout << "Current enemy health: [" << getEnemyHealth() << "]\n";
					}
					std::this_thread::sleep_for(1s);
					userTurn = false;

				}
				break;

			case 2:
				if (actionFail == true) { //If defence fails
					cout << "**********************************************************************************************\n\n";
					std::this_thread::sleep_for(1s);
					cout << "Defend Failed\n";
					userTurn = false;
					std::this_thread::sleep_for(1s);
				}
				else {//If defence works
					cout << "**********************************************************************************************\n";
					std::this_thread::sleep_for(1s);
					cout << "Defence worked, you have gained 1 health point!\n";
					if (getMonkHealth() >= getMaxHealthPoints()) {
						setMonkHealth(getMaxHealthPoints());
					}
					else {
						setMonkHealth(getMonkHealth() + 1);
					}

					cout << getMonkName() << "'s health: [" << getMonkHealth() << "] \n";
					userTurn = false;
				}
				break;

			}

		}
		else if (userTurn == false) {
			if (getEnemyHealth() < 1) { /*Skips the enemy's turn if the enemy loses all health before its turn,
										as it is dead so it should't be able to attack.*/
				continue;
			}
			else {
				cout << "It's the goblin's turn to move...\n";
				std::this_thread::sleep_for(1s);
				switch (enemyAttackChoice) {
				case 1: //These cases are the same as the players', but for the enemy.
					if (willEnemyAct == 1) {
						cout << "**********************************************************************************************\n\n";
						std::this_thread::sleep_for(1s);
						cout << "The Goblin's attack failed\n";
						userTurn = true;
						std::this_thread::sleep_for(1s);
						continue;

						
					}
					else {
						cout << "**********************************************************************************************\n";
						std::this_thread::sleep_for(1s);
						cout << "Attack hit! You have lost: [" << getEnemyAttackPoints() << "] health points\n";
						std::this_thread::sleep_for(1s);
						setMonkHealth(getMonkHealth() - getEnemyAttackPoints());

						if (getMonkHealth() < 1) {
							cout << getMonkName() << "'s health: [0]\n";
						}
						else {
							cout << getMonkName() << "'s health: [" << getMonkHealth() << "] \n";
						}
						userTurn = true;
						continue;

					}


				case 2:
					if (willEnemyAct == 1) {
						cout << "**********************************************************************************************\n\n";
						std::this_thread::sleep_for(1s);
						cout << "Goblin's defence failed\n";
						userTurn = true;
						std::this_thread::sleep_for(1s);
						continue;
						
						
					}
					else {
						cout << "**********************************************************************************************\n";
						std::this_thread::sleep_for(1s);
						cout << "Defence worked, goblin gained 1 health point!\n";
						std::this_thread::sleep_for(1s);
						if (getEnemyHealth() >= 10) {
							setEnemyHealth(10);
						}
						else{
							setEnemyHealth(getEnemyHealth() + 1);
						}
						cout << "Current enemy health: [" << getEnemyHealth() << "]\n";
						std::this_thread::sleep_for(1s);
						userTurn = true;
						continue;

					}

					break;
				}

			}
		}

		

	}

	if (getMonkHealth() < 1) { //If you lose all health, game over and the you exit the game.
		cout << "**********************************************************************************************\n";
		cout << "You have lost all your health...\n";
		cout << "////////////////////Game Over/////////////////\n";
		std::this_thread::sleep_for(3s);
		std::exit(0);
	
	}
	else if(getEnemyHealth() < 1){ //If the enemy loses the game, the game continues.
		cout << "**********************************************************************************************\n";
		cout << "The Goblin has lost all health...\n";
		cout << "You have won the battle!\n";
		std::this_thread::sleep_for(1s);
		setEnemyHealth(10); //This is added so that the next enemy will have full health in the next battle.


		
	}

}

int MonsterRoom::actionNumGen() //All these methods are for number generators
{
	
	std::random_device rd2;
	std::mt19937 rng2(rd2());
	std::uniform_int_distribution<int> uni(1, 2);
	uni.reset();
	auto randomAction = uni(rng2);
	return randomAction;

}

int MonsterRoom::enemyAttackGen()
{
	
	std::random_device rd2;
	std::mt19937 rng2(rd2());
	std::uniform_int_distribution<int> uni(1, 2);
	uni.reset();
	auto enemyrAction = uni(rng2);

	return enemyrAction;

}

int MonsterRoom::enemyChoiceGen()
{
	
	std::random_device rd2;
	std::mt19937 rng2(rd2());
	std::uniform_int_distribution<int> uni(1, 2);
	uni.reset();
	auto enemyChoice = uni(rng2);

	return enemyChoice;

}

void MonsterRoom::enemyDifficulty()
{
	cout << "//////////////////////////////////////////////////////////////////////////////////////////////\n\n";
	std::this_thread::sleep_for(1s);
	cout << "Before we get started, would you prefer to play easy or hard difficulty?\n";
	std::this_thread::sleep_for(1s);
	cout << "Type [1] for easy, and [2] for hard: ";
	std::this_thread::sleep_for(1s);

	while (!diffChoiceCheck) //choiceCheck loops the validation until the user inputs a correct value
	{
		cin >> eDifficulty;
		if (eDifficulty != 1 && eDifficulty != 2) {  //Validation so that the player can only input "1" or "2" for attack and defend respectively.
			cout << "Invalid choice\n";
			cin.clear();
			std::this_thread::sleep_for(1s);
			cin.ignore(10000, '\n');
		}
		else {
			diffChoiceCheck = true;
		}
	}

	switch (eDifficulty) {
		case 1:
			cout << "Ok, you chose easy difficulty\n";
			setEnemyAttackPoints(3);
			break;

		case 2:
			setEnemyAttackPoints(5);
			cout << "Ok, you chose hard difficulty\n";
			std::this_thread::sleep_for(1s);
			break;
	}
}


