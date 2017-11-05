/*************************************************
* Author: Emmet Cooke
* Date: 11/3/2017
* Description: This is the header file for the Vampire
* class.
*************************************************/
#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Character.hpp"
class Vampire :
	public Character
{
public:
	// Default Constructor
	Vampire();
	// Destructor
	~Vampire();

	// Virtual functions overriden from Character
	virtual int attack();
	virtual bool defend(int damageIn);
};

#endif