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
* Description: HarryPotter's defend function. Returns
* true if the defender survives and false if they
* die.
*************************************************/
bool HarryPotter::defend(int damageIn)
{
	damageIn -= getArmor();
	setStrength(getStrength() - damageIn);
	if (getStrength() < 1)
	{	// Harry's special ability
		if (hogwarts)
		{
			setStrength(20);
			hogwarts = false;
			return true;
		}
		return false;
	}
	return true;
}
