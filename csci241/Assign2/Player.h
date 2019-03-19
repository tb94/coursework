	#ifndef PLAYER_H
	#define PLAYER_H

	//**********************************************************************//
	//	FILE:		Player.h					//
	//	AUTHOR:		Tim Bretz					//
	//	LOGON ID:	z1697841					//
	//	DUE DATE:	2/12/2015					//
	//							    		//
	//	PURPOSE:   Contains the declaration for the Player class	//
	//**********************************************************************//

	class Player
	{
		private:
			int 	playerNum;

			char	playerName[26],
				position[3];

			int	numOfHits,
				timesAtBat;

		public:
				Player();
				Player(int newNum, char* newName, char* newPos, int newNumHits, int newAtBats);

			int	getNumber();
			char*	getName();
			char*	getPosition();
			int	getHits();
			int	getAtBats();
			void	setHits(int newNumHits);
			void	setAtBats(int newNumHits);
			double	battingAvg();
			void	print();
	};

	#endif
