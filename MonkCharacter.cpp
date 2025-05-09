#include "MonkCharacter.h"
#include "EmptyRoom.h"

int MonkCharacter::monkHealth = 15;  //Initializing static variables for the player character and also the room checks for completing the game.
int MonkCharacter::monkMaxHealth = 15;
int MonkCharacter::monkAttackPoints = 3;

int MonkCharacter::monsterRoomValid = 0; //This is done so the values don't change when a new instance of the class is called.
bool MonkCharacter::emptyRoomValid = false;
bool MonkCharacter::upgradeRoomValid = false;

std::string MonkCharacter::monkName = "";
std::string MonkCharacter::monkItem = "";


void MonkCharacter::setMonkHealth(int playHealth) //Getters and setters for the monk character and the room checks.
{
	monkHealth = playHealth;
}

void MonkCharacter::setMonkMaxHealth(int playMaxHealth)
{
	monkMaxHealth = playMaxHealth;
}

void MonkCharacter::setMonkAttackPoints(int playAttackPoints)
{
	monkAttackPoints = playAttackPoints;
}

int MonkCharacter::getMonkAttackPoints()
{
	return monkAttackPoints;
}

int MonkCharacter::getMonkHealth()
{
	return monkHealth;
}

int MonkCharacter::getMaxHealthPoints()
{
	return monkMaxHealth;
}

void MonkCharacter::setMonkName(std::string playName)
{
	monkName = playName;
}

void MonkCharacter::setMonkItem(std::string playItem)
{
	monkItem = playItem;
}

std::string MonkCharacter::getMonkName()
{
	return monkName;
}

std::string MonkCharacter::getMonkItem()
{
	return monkItem;
}

void MonkCharacter::setEmptyRoomCheck(bool eCheck)
{
	emptyRoomValid = eCheck;
}

void MonkCharacter::setUpgradeRoomCheck(bool uCheck)
{
	upgradeRoomValid = uCheck;
}

void MonkCharacter::setMonsterRoomCheck(int mCheck)
{
	monsterRoomValid = mCheck;
}

bool MonkCharacter::getEmptyRoomCheck()
{
	return emptyRoomValid;
}

bool MonkCharacter::getUpgradeRoomCheck()
{
	return upgradeRoomValid;
}

int MonkCharacter::getMonsterRoomCheck()
{
	return monsterRoomValid;
}




