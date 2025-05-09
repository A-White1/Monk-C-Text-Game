#pragma once
#include "pch.h"
#include <string>
 class MonkCharacter
{
public:
	void setMonkHealth(int playHealth);
	void setMonkMaxHealth(int playMaxHealth);
	void setMonkAttackPoints(int playAttackPoints);
	int getMonkAttackPoints();
	int getMonkHealth();
	int getMaxHealthPoints();
	void setMonkName(std::string playName);
	void setMonkItem(std::string playItem);
	std::string getMonkName();
	std::string getMonkItem();
	void setEmptyRoomCheck(bool eCheck);
	void setUpgradeRoomCheck(bool uCheck);
	void setMonsterRoomCheck(int mCheck);
	bool getEmptyRoomCheck();
	bool getUpgradeRoomCheck();
	int getMonsterRoomCheck();
protected:
	static int monsterRoomValid;
	static bool emptyRoomValid;
	static bool upgradeRoomValid;
	static int monkHealth;
	static int monkMaxHealth;
	static int monkAttackPoints;
	static std::string monkName;
	static std::string monkItem;
	
};
 

