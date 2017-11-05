/*************************************************
* Author: Emmet Cooke
* Date: 11/3/2017
* Description: This file contains the definitions
* for the functions declared in the BlueMan class.
*************************************************/
#include "BlueMen.hpp"

/*************************************************
* Description: Default Constructor.
*************************************************/
BlueMen::BlueMen()
{
	// Attack Die
	setNumAttackDie(2);
	setDieSides(10);

	// Defense Die
	setNumDefenseDie(3);

	// Armor
	setArmor(3);

	// Strength
	setStrength(12);
}

/*************************************************
* Description: Destructor.
*************************************************/
BlueMen::~BlueMen()
{
}

/*************************************************
* Description: BlueMen's attack function. The
* attackRoll variable is incremented until the 
* corrent number of rolls has taken place. This value
* is then returned.
*************************************************/
int BlueMen::attack()
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
bool BlueMen::defend(int damageIn)
{
	damageIn -= getArmor();
	setStrength(getStrength() - damageIn);
	// BlueMen's special ability is Mob
	// If their strength is reduced by 4, they lose a die
	setNumDefenseDie(getStrength() / 4);
	if (getStrength() < 1)
	{
		return false;
	}
	return true;
}
