/*************************************************
* Author: Emmet Cooke
* Date: 11/3/2017
* Description: This file contains the definitions
* for the functions declared in the Barbarian class.
*************************************************/
#include "Barbarian.hpp"

/*************************************************
* Description: Default Constructor. 
*************************************************/
Barbarian::Barbarian()
{
	// Attack Die
	setNumAttackDie(2);
	setDieSides(6);

	// Defense Die
	setNumDefenseDie(2);

	// Armor
	setArmor(0);

	// Strength
	setStrength(12);
}

/*************************************************
* Description: Destructor.
*************************************************/
Barbarian::~Barbarian()
{
}

/*************************************************
* Description: Barbarian's attack function. The
* attackRoll variable is incremented until the 
* corrent number of rolls has taken place. This value
* is then returned.
*************************************************/
int Barbarian::attack()
{
	int attackRoll = 0;
	for (int i = 0; i < getNumAttackDie(); i++)
	{
		attackRoll += rand() % getDieSides() + 1;
	}
	return attackRoll;
}

/*************************************************
* Description: Barbarian's defend function. Returns
* true if the defender survives and false if they
* die.
*************************************************/
bool Barbarian::defend(int damageIn)
{
	damageIn -= getArmor();
	setStrength(getStrength() - damageIn);
	if (getStrength() < 1)
	{
		return false;
	}
	return true;
}
