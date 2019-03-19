#include <iostream>
#include <string>
#include <iomanip>
#include <locale>
#include <sstream>

using namespace std;

int main ()
{
	string 	name,
		tempStr;
	char	yn;
	int	sum,
		tempInt;
	bool	solved,
		again;
	do
	{
		solved = false;
		again = false;
		sum = 0;

		cout <<"\nEnter your name: ";
		getline (cin, name);

		for( unsigned i = 0; i < name.length(); i++)
		{
			if (islower(name[i]))
				sum += ((int)name[i] - 96);

			else if (isupper(name[i]))
				sum += ((int)name[i] - 64);

			else if (isdigit(name[i]))
				sum += ((int)name[i] - 48);

			else
				sum += 0;
		}

		while (solved == false)
		{

			switch (sum)
			{
				case 0:
					cout << "That name has the traits ";
					cout << "emptiness, nothingness, blank" << endl;
					solved = true;
					break;

				case 1:
					cout << "That name has the traits ";
					cout << "independence, loneliness, creativity, originality, dominance, leadership, impatience" << endl;
					solved = true;
					break;

				case 2:
					cout << "That name has the traits ";
					cout << "quiet, passive, diplomatic, co-operation, comforting, soothing, intuitive, compromising, patient" << endl;
					solved = true;
					break;

				case 3:
					cout << "That name has the traits ";
					cout << "charming, outgoing, self expressive, extroverted, abundance, active, energetic, proud" << endl;
					solved = true;
					break;

				case 4:
					cout << "That name has the traits ";
					cout << "harmony, truth, justice, order discipline, practicality" << endl;
					solved = true;
					break;

				case 5:
					cout << "That name has the traits ";
					cout << "new directions, excitement, change, adventure" << endl;
					solved = true;
					break;

				case 6:
					cout << "That name has the traits ";
					cout << "love, harmony, perfection, marriage, tolerance, public service" << endl;
					solved = true;
					break;

				case 7:
					cout << "That name has the traits ";
					cout << "spirituality, completeness, isolation, introspection" << endl;
					solved = true;
					break;

				case 8:
					cout << "That name has the traits ";
					cout << "organization, business, commerce, new beginnings" << endl;
					solved = true;
					break;

				case 9:
					cout << "That name has the traits ";
					cout << "romantic, rebellious, determined, passionate, compassionate" << endl;
					solved = true;
					break;

				case 11:
					cout << "That name has the traits ";
					cout << "idealism, visionary, inspirational" << endl;
					solved = true;
					break;

				case 12:
					cout << "That name has the traits ";
					cout << "perfectionist, discriminating" << endl;
					solved = true;
					break;

				case 22:
					cout << "That name has the traits ";
					cout << "builder, leader, humanitarian, practical, honest" << endl;
					solved = true;
					break;

				default:
					name = static_cast<ostringstream*>( &(ostringstream() << sum) ) ->str();
					sum = 0;

					for( unsigned i = 0; i < name.length(); i++)
					{
						tempStr = name[i];

						if( ! (istringstream(tempStr) >> tempInt) ) tempInt = 0;

						sum += tempInt;
					}
			}
		}

		cout << "\nAgain? (y/n) ";
		cin >> yn;

		if (yn == 'Y' || yn == 'y')
			again = true;

		cin.ignore();

	} while (again);

	return 0;
}
