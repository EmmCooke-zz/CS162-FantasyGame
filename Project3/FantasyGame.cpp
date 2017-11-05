/*************************************************
* Author: Emmet Cooke
* Date: 11/3/2017
* Description: This file contains the definitions
* for the functions declared in the FantasyGame class.
*************************************************/
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <iomanip>
using std::setw;
using std::setprecision;

#include <ctime>

#include "validateInput.hpp"
#include "FantasyGame.hpp"
#include "Menu.hpp"

// All of the character classes
#include "Character.hpp"
#include "Vampire.hpp"		
#include "Barbarian.hpp"	
#include "BlueMen.hpp"		
#include "Medusa.hpp"
#include "HarryPotter.hpp"

/*************************************************
* Description: Default Constructor.
*************************************************/
FantasyGame::FantasyGame()
{
	srand(time(nullptr));
}

/*************************************************
* Description: Destructor.
*************************************************/
FantasyGame::~FantasyGame()
{
}

/*************************************************
* Description: This function runs the game.
*************************************************/
void FantasyGame::runGame()
{
	int heroes[2];
	cout << "Welcome to Fantasy Game Fighter!" << endl;
	cout << "-------------------------------" << endl;
	for (int i = 0; i < 2; i++)
	{
		heroes[i] = printHeroes(i);
	}

	setFighter1(heroes[0]);
	setFighter2(heroes[1]);
	
	while (fighter1->alive() && fighter2->alive())
}

/*************************************************
* Description: This function sets the fighter1 to
* the chosen hero.
*************************************************/
void FantasyGame::setFighter1(int fighterIn)
{
	switch (fighterIn)
	{
	case 1: fighter1 = new Vampire;
		break;
	case 2: fighter1 = new Barbarian;
		break;
	case 3: fighter1 = new BlueMen;
		break;
	case 4: fighter1 = new Medusa;
		break;
	case 5: fighter1 = new HarryPotter;
	}
}

/*************************************************
* Description: This function sets the fighter2 to
* the chosen hero.
*************************************************/
void FantasyGame::setFighter2(int fighterIn)
{
	switch (fighterIn)
	{
	case 1: fighter2 = new Vampire;
		break;
	case 2: fighter2 = new Barbarian;
		break;
	case 3: fighter2 = new BlueMen;
		break;
	case 4: fighter2 = new Medusa;
		break;
	case 5: fighter2 = new HarryPotter;
	}
}

/*************************************************
* Description: This function prints the heroes
* list and then returns which hero has been chosen.
*************************************************/
int FantasyGame::printHeroes(int heroNum)
{
	Menu heroMenu(5);
	heroMenu.setOption(0, "Vampire");
	heroMenu.setOption(1, "Barbarian");
	heroMenu.setOption(2, "Blue Men");
	heroMenu.setOption(3, "Medusa");
	heroMenu.setOption(4, "Harry Potter");

	int heroChoice = 0;
	string validateInput;
	do
	{
		heroMenu.printOptions();
		cout << "Please choose a hero (1-5): ";
		getline(cin, validateInput);
		heroChoice = getInt(validateInput);
		if (heroChoice < 1 || heroChoice > 5)
		{
			cout << "Please enter a valid menu choice." << endl;
		}

	} while (heroChoice < 1 || heroChoice > 5);

	return heroChoice;
}

/*************************************************
* Description: This function outputs the current stats
* of each character each round.
*************************************************/
void FantasyGame::printStats(Character* attacker, int attackRoll,
							Character* defender, int defendRoll)
{
	cout << "--------------------------------" << endl;
	cout << "Attacker     : " << attacker->getName() << endl;
	cout << "Attacker Roll: " << attackRoll << endl << endl;
	cout << "Defender     : " << defender->getName() << endl;
	cout << "Defender Armor: " << defender->getArmor() << endl;
	cout << "Defender Strength: " << defender->getStrength() << endl;
	cout << "Defender Roll: " << defendRoll << endl << endl;
	cout << "Total Damage Inflicted: " << attackRoll - defendRoll << endl;
	// Inflict damage here?
	defender->defend(attackRoll - defendRoll);
	cout << "Defenders New Strength: " << defender->getStrength() << endl;
}
