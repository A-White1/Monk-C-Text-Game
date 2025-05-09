#pragma once
#include "MonkCharacter.h"
#include "EmptyRoom.h"
class UpgradeRoom : public MonkCharacter
{
public:
	void upgradeRoom();
private:
	int upgradeCheck = 0;
	int choiceForUpgrade;
	bool choices = false;
};

