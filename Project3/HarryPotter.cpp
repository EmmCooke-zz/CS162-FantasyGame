/*************************************************
* Author: Emmet Cooke
* Date: 11/3/2017
* Description: This file contains the definitions
* for the functions declared in the HarryPotter class.
*************************************************/
#include "HarryPotter.hpp"

/*************************************************
* Description: Default Constructor.
*************************************************/
HarryPotter::HarryPotter()
{
	// Attack Die
	setNumAttackDie(2);
	setDieSides(6);

	// Defense Die
	setNumDefenseDie(2);

	// Armor
	setArmor(0);

	// Strength
	setStrength(10);
}

/*************************************************
* Description: 
*************************************************/
HarryPotter::~HarryPotter()
{
}

/*************************************************
* Description: HarryPotter's attack function. The
* attackRoll variable is incremented until the 
* corrent number of rolls has taken place. This value
* is then returned.
*************************************************/
int HarryPotter::attack()
{
	int attackRoll = 0;
	for (int i = 0; i < getNumAttackDie(); i++)
	{
		attackRoll += rand() % getDieSides() + 1;
	}
	return attackRoll;
}

/*************************************************
* Description: HarryPotter's defend function. Returns
* true if the defender survives and false if they
* die.
*************************************************/
bool HarryPotter::defend(int damageIn)
{
	// Harry Potter's special ability
	// Turns to false when he first dies
	static bool Hogwarts = true;

	damageIn -= getArmor();
	setStrength(getStrength() - damageIn);
	if (getStrength() < 1)
	{	// Harry's special ability
		if (Hogwarts)
		{
			setStrength(20);
			return true;
		}
		return false;
	}
	return true;
}
