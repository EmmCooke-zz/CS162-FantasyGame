/*************************************************
* Author: Emmet Cooke
* Date: 11/3/2017
* Description: This is the header file for the
* BlueMen class. 
*************************************************/
#ifndef BLUE_MEN_HPP
#define BLUE_MEN_HPP

#include "Character.hpp"
class BlueMen :
	public Character
{
public:
	// Default Constructor
	BlueMen();
	// Destructor
	~BlueMen();

	// Virtual function overriden from Character
	virtual bool defend(int damageIn);
};

#endif