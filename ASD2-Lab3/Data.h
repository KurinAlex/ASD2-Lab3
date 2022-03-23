#pragma once

struct Data
{
	int hp;
	int damage;
	int skill;
	float priority;

	Data();

	friend bool operator< (const Data& left, const Data& right)
	{
		return left.priority < right.priority;
	}

	friend bool operator== (const Data& left, const Data& right)
	{
		return left.priority == right.priority;
	}
};