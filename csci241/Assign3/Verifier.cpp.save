#include "Verifier.h"
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

Verifier::Verifier()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			grid[i][j] = 0;
		}
	}
}

void Verifier::readGrid(const char* data)
{
	int temp;

	ifstream inFile;

	inFile.open (data);

	if (!inFile)
	{
		cerr << "Error - unable to open input file\n";
		exit(1);
	}

	inFile >> temp;

	while (inFile)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				grid[i][j] = temp;
				inFile >> temp;
			}
		}
	}

	inFile.close();
}

void Verifier::printGrid()
{
	for (int i = 0; i < 9; i++)
	{
		if (i == 0 || i == 3 || i == 6)
		{
			cout << "-------------------------" << endl;
		}

		for (int j = 0; j < 9; j++)
		{
			if (j == 0 || j == 3 || j == 6)
			{
				cout << "| ";
			}

			cout << grid[i][j] << ' ';
		}

		cout << "|" << endl;
	}

	cout << "-------------------------" << endl;
}

bool Verifier::verifySolution()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
                {
			if (grid[i][j] <= 9 && grid[i][j] >= 1)
			{
				for (int count = i + 1; count < 9; count++)
				{
					if (grid[i][j] == grid[count][j])
						return false;
				}
			}

			else
				return false;
		}
	}

	for (int j = 0; j < 9; j++)
	{
		for (int i  = 0; i < 9;i++)
		{
			if (grid[i][j] <= 9 && grid[i][j] >= 1)
			{
				for (int count = j + 1; count < 9; count++)
				{
					if (grid[i][j] == grid[i][count])
						return false;
				}
			}

			else
				return false;
		}
	}

	int 	temp[9],
		count = 0,
		sub = 0;

	for (int i = 0; i <= 6; i += 3)
	{
		for (int j = 0; j <= 6; j += 3)
		{
			for (int m = i; m < (i + 3); m++)
			{
				for (int n = j; n < (j + 3); n++)
				{
					temp[count] = grid[m][n];
					count++;
				}
			}

			for (count = 0; count < 9; count++)
			{
				for (sub = count + 1; sub < 9; sub++)
				{
					if (temp[count] == temp[sub])
						return false;
				}
			}

			count = 0;
		}
	}

	return true;
}

