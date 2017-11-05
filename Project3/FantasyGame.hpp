/*************************************************
* Author: Emmet Cooke
* Date: 11/3/2017
* Description: This is the header file for the
*FantasyGame class.
*************************************************/
#include <memory>
using std::shared_ptr;
#include "Character.hpp"


class FantasyGame
{
private:
	shared_ptr<Character> fighter1;
	shared_ptr<Character> fighter2;
public:
	FantasyGame();
	~FantasyGame();
};

