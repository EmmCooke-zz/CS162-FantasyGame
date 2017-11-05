/*************************************************
* Author: Emmet Cooke
* Date: 11/3/2017
* Description: This is the header file for the
* Barbarian class. 
*************************************************/
#ifndef HARRY_POTTER_HPP
#define HARRY_POTTER_HPP

#include "Character.hpp"
class HarryPotter :
	public Character
{
public:
	// Default Constructor
	HarryPotter();
	// Destructor
	~HarryPotter();

	// Virtual functions overriden from Character
	virtual int attack();
	virtual bool defend(int damageIn);
};

#endif