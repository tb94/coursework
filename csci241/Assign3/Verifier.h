#ifndef VERIFIER_H
#define VERIFIER_H

class Verifier
{
	private:
		int 	grid[9][9];
	public:
		Verifier();
		void 	readGrid(const char*);
		void	printGrid();
		bool	verifySolution();
};

#endif
