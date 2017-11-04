/*************************************************
* Program: Project 3 - Fantasy Game
* Author: Emmet Cooke
* Date: 11/3/2017
* Description: This program runs a Fantasy Game simulation.
*************************************************/
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Menu.hpp"
#include "validateInput.hpp"

int main()
{
	Menu mainMenu("Welcome to the Fantasy Fighting Game.", 2);
	mainMenu.setOption(0, "Play Game");
	mainMenu.setOption(1, "Exit");

	bool exitChoice = false;
	string validateInput;
	int menuChoice;
	mainMenu.printPrompt();

	do
	{
		mainMenu.printOptions();
		getline(cin, validateInput);
		menuChoice = getInt(validateInput);

		switch (menuChoice)
		{
		case 1: // Play game
			break;
		case 2: // Exit
			exitChoice = true;
			break;
		default:
			cout << "Please enter a valid menu choice." << endl;
		}
	} while (!exitChoice);

	return 0;
}