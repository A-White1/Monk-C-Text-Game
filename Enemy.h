#pragma once
class Enemy
{
public:
	void setEnemyHealth(int eHealth);
	void setEnemyAttackPoints(int eAttack);
	int getEnemyAttackPoints();
	int getEnemyHealth();
private:
	int enemyHealth = 10;
	static int enemyAttackPoints;
};

