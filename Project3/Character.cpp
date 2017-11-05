/*************************************************
* Author: Emmet Cooke
* Date: 11/3/2017
* Description: This file contains the definitions
* for the functions declared in the Character class.
*************************************************/
#include "Character.hpp"

/*************************************************
* Description: Default Constructor.
*************************************************/
Character::Character()
{
}

/*************************************************
* Description: Destructor.
*************************************************/
Character::~Character()
{
}

/*************************************************
* Description: Default Character attack function. 
* The attackRoll variable is incremented until the 
* corrent number of rolls has taken place. This value
* is then returned.
*************************************************/
int Character::attack()
{
	int attackRoll = 0;
	for (int i = 0; i < getNumAttackDie(); i++)
	{
		attackRoll += rand() % getDieSides() + 1;
	}
	return attackRoll;
}


/*************************************************
* Description: Default defend function. Returns
* true if the defender survives and false if they
* die.
*************************************************/
bool Character::defend(int damageIn)
{
	damageIn -= getArmor();
	setStrength(getStrength() - damageIn);
	if (getStrength() < 1)
	{
		return false;
	}
	return true;
}
