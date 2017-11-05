/*************************************************
* Author: Emmet Cooke
* Date: 11/3/2017
* Description: This file contains the definitions
* for the functions declared in the Vampire class.
*************************************************/
#include "Vampire.hpp"

/*************************************************
* Description: Default Constructor.
*************************************************/
Vampire::Vampire()
{
	// Attack Die
	setNumAttackDie(1);
	setDieSides(12);

	// Defense Die
	setNumDefenseDie(1);

	// Armor
	setArmor(1);

	// Strength
	setStrength(18);
}

/*************************************************
* Description: Destructor.
*************************************************/
Vampire::~Vampire()
{
}

/*************************************************
* Description: Vampire's attack function. The
* attackRoll variable is incremented until the 
* corrent number of rolls has taken place. This value
* is then returned.
*************************************************/
int Vampire::attack()
{
	int attackRoll = 0;
	for (int i = 0; i < getNumAttackDie(); i++)
	{
		attackRoll += rand() % getDieSides() + 1;
	}
	return attackRoll;
}

/*************************************************
* Description: Vampire's defend function. Vampire's
* special ability charm is built into the function.
* There is a 50% chance that no damage is done
* to the Vampire.
* Returns true if the defender survives and false
* if they die.
*************************************************/
bool Vampire::defend(int damageIn)
{
	// Vampire's Charm ability
	if (rand() % 2 == 0)
	{
		return true;
	}
	// If charm does not work
	damageIn -= getArmor();
	setStrength(getStrength() - damageIn);
	if (getStrength() < 1)
	{
		return false;
	}
	return true;
}