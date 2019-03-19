#include <iostream>
#include <iomanip>
#include "Player.h"
#include "Team.h"

using namespace std;

int main()
{
/*	char name1[26] = "John Smith";
	char position1[3] = "1B";
	char name2[26] = "Alberto Rodriguez";
	char position2[3] = "P";
	double avg;

	// Test default constructor
	Player player1;

	// Test alternate constructor
	Player player2(25, name1, position1, 29, 95);

	// Test data validation
	Player player3(12, name2, position2, -6, -10);

	// Test accessor methods
	cout << "Printing player2 stats\n\n";
	cout << "NO: " << player2.getNumber() << endl;
	cout << "NAME: " << player2.getName() << endl;
	cout << "POS: " << player2.getPosition() << endl;
	cout << "H: " << player2.getHits() << endl;
	cout << "AB: " << player2.getAtBats() << endl;

	// Test print() and battingAverage() methods and whether constructors
	// properly initialized objects
	cout << "Printing player1\n\n";
	player1.print();
	cout << endl << endl;

	cout << "Printing player2\n\n";
	player2.print();
	cout << endl << endl;

	cout << "Printing player3\n\n";
	player3.print();
	cout << endl << endl;

	// Test set methods
	player3.setHits(player3.getHits() + 1);
	player3.setAtBats(player3.getAtBats() + 4);

	cout << "Printing updated player3\n\n";
	player3.print();
	cout << endl << endl;
*/

	Team daTeam("playerdata");
	daTeam.print();
	daTeam.updateStats("gamestats.txt");
	daTeam.print();

	return 0;
}
