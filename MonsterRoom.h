#pragma once
#include "MonkCharacter.h"
#include "Enemy.h"
class MonsterRoom : public Enemy , public MonkCharacter
{
public:
	void combat();
	int actionNumGen();
	int enemyAttackGen();
	int enemyChoiceGen();
	void enemyDifficulty();
private:
	static int eDifficulty;
	bool choiceCheck = false;
	bool userTurn = true;
	bool actionFail;
	int combatInput;
	int actionNum;
	int willEnemyAct;
	int enemyAttackChoice;
	bool diffChoiceCheck = false;
};


