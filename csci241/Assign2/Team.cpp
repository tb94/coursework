#include "Player.h"
#include "Team.h"
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <stdlib.h>

using namespace std;

Team::Team()
{
	numOfPlayers = 0;
}

Team::Team(const char* data)
{
	//Declare an input file stream variable (the code below assumes it is named inFile)
	ifstream inFile;

	//Open the file stream for binary input. Check to make sure the file was opened successfully as usual
	inFile.open(data, ios::binary);

	if (!inFile)
	{
		cerr << "Error - unable to open input file\n";
		exit(1);
	}

	//Read the database file into Team object
	inFile.read((char*)this, sizeof(Team));

	//Close the file stream
	inFile.close();

	sortByName();
}

void Team::sortByName()
{
	int 	i, j;
	Player	bucket;

	for (i = 1; i < numOfPlayers; i++)
	{
		bucket = players[i];

		for (j = i; (j > 0) && (strcmp(players[j-1].getName(), bucket.getName()) > 0); j--)
			players[j] = players[j-1];

		players[j] = bucket;
	}
}

int Team::searchForName(char* searchName)
{
	int 	low = 0,
		high = numOfPlayers - 1,
		mid;

  	while (low <= high)
	{
		mid = (low + high) / 2;

		if (strcmp(searchName, players[mid].getName()) == 0)
			return mid;

		if (strcmp(searchName, players[mid].getName()) < 0)
			high = mid - 1;
		else
			low = mid + 1;
      }

   return -1;
}

void Team::updateStats(const char* data)
{
	char	header[25],
		name[25],
		first[25],
		last[25],
		hits[10],
		atBats[10];

	int	nHits,
		nAtBats;

//	Open input file using the file name passed in as a parameter
	ifstream inFile;

	inFile.open(data);

//	Check for successful open
	if(!inFile)
	{
		cerr << "Error - unable to open input file \n";
		exit(1);
	}

//	Read the game date from the input file
	inFile >> header;

//	Print the header for the box score report
	cout 	<< "\nBOX SCORE FOR " << header << endl
		<< left << setw(26) << "\nName"
		<< right << setw(3) << "H" << right << setw(6) << "AB\n\n";

//	Read a first name from the input file
	inFile >> first;

	while (inFile)
	{
//		Read a last name from the input file
		inFile >> last;

//		Read number of hits from the input file
		inFile >> hits;

//		Read number of at bats from the input file
		inFile >> atBats;

//		Combine last name and first name to form search name
		strcpy(name, last);
		strcat(name, ", ");
		strcat(name, first);

//		Call search method and pass it search name
		int i = searchForName(name);

		if (i == -1)
			cout << "Error - player named " << name << " does not exist\n";
		else
		{
//			Print search name, hits, and at bats
			cout 	<< left << setw(25) << name
				<< right << setw(3) << hits
				<< setw(4) << atBats << endl;

			nHits = atoi(hits) + players[i].getHits();
			nAtBats = atoi(atBats) + players[i].getAtBats();

//			Update the hits and at bats for the Player object located at the index returned by the search method
			players[i].setHits(nHits);
			players[i].setAtBats(nAtBats);
		}

//		Read a first name from the input file
		inFile >> first;
	}

//	Close input file
	inFile.close();
}

void Team::print()
{
	cout	<< "\nCHICAGO WHITE SOX ROSTER\n"
		<< left
		<< setw(5) << "\nNO"
		<< setw(27) << "NAME"
		<< setw(5) << "POS"
		<< setw(5) << "H"
		<< setw(5) << "AB"
		<< setw(7) << "AVG" << endl << endl;

	for(int i = 0; i < numOfPlayers; ++i)
	{
		players[i].print();
	}
}
