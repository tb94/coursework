#include "Player.h"
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

Player::Player()
{
	playerNum =	0;
	playerName[0] = '\0';
	position[0] =	'\0';
	numOfHits =	0;
	timesAtBat =	0;
}

Player::Player(int newNum, char* newName, char* newPos, int newNumHits, int newAtBats)
{
	strcpy(playerName, newName);
	strcpy(position, newPos);

	playerNum = newNum;

	setHits(newNumHits);
	setAtBats(newAtBats);
}

int Player::getNumber()
{
	return playerNum;
}

char* Player::getName()
{
	return playerName;
}

char* Player::getPosition()
{
	return position;
}

int Player::getHits()
{
	return numOfHits;
}

int Player::getAtBats()
{
	return timesAtBat;
}

void Player::setHits(int newNumHits)
{
	if(newNumHits >= 0)
		numOfHits = newNumHits;
	else
		numOfHits = 0;
}

void Player::setAtBats(int newAtBats)
{
	if(newAtBats >= 0)
		timesAtBat = newAtBats;
	else
		timesAtBat = 0;
}

double Player::battingAvg()
{
	double avg;

	if(timesAtBat == 0)
		return -1;
	else
	{
		avg = (double)numOfHits / (double)timesAtBat;
		return avg;
	}
}

void Player::print()
{
	cout 	<< left
		<< setw(4) << playerNum
		<< setw(27) << playerName
		<< setw(5) << position

		<< right
		<< setw(3) << numOfHits
		<< setw(5) << timesAtBat

		<< setprecision(3) << fixed << setw(7);

		if(battingAvg() == -1)
			cout << "  -  ";
		else
			cout << battingAvg();

	cout << endl;
}
