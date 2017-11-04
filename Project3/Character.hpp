#pragma once
class Character
{
public:
	Character();
	~Character();

	virtual void attack() = 0;
	virtual void defend() = 0;
};

