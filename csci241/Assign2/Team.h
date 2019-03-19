#ifndef TEAM_H
#define TEAM_H

#include "Player.h"

	//*****************************************************************
	// FILE:      Player.h
	// AUTHOR:    your name
	// LOGON ID:  your z-ID
	// DUE DATE:  due date of assignment
	//
	// PURPOSE:   Contains the declaration for the Player class.
	//*****************************************************************

class Team
{
	private:
		Player 	players[40];
		int	numOfPlayers;

	public:
			Team();
			Team(const char*);
		void	sortByName();
		int	searchForName(char*);
		void	updateStats(const char*);
		void 	print();
};

#endif
