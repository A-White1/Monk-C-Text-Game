#include "Enemy.h"
int Enemy::enemyAttackPoints = 2;

void Enemy::setEnemyHealth(int eHealth) //General getters and setters for the goblin enemy
{
	enemyHealth = eHealth;
}

void Enemy::setEnemyAttackPoints(int eAttack)
{
	enemyAttackPoints = eAttack;
}

int Enemy::getEnemyAttackPoints()
{
	return enemyAttackPoints;
}	

int Enemy::getEnemyHealth()
{
	return enemyHealth;
}
