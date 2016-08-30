#include <unistd.h>
#include <stdio.h>

void 	putsudoku(char **mapsudoku);
int 	checkvalidecaracter(char **mapsudoku);

int 	checkline(char **mapsudoku, int y, int x, char nb)
{
	int x2;
	int y2;

	x2 = 0;
	y2 = 0;
	while (y2 < 9)
	{
		if (mapsudoku[y2][x] == nb)
			return (0);
		y2++;
	}
	while (x2 < 9)
	{
		if (mapsudoku[y][x2] == nb)
			return (0);
		x2++;
	}
	return (1);
}

int		checkblock(char **mapsudoku, int y, int x, char nb)
{
	int		x2;
	int		y2;

	x2 = x - (x % 3);
	y2 = y - (y % 3);
	x = x2;
	y = y2;
	while (y < y2 + 3)
	{
		x = x2;
		while (x < x2 + 3)
		{
			if (mapsudoku[y][x] == nb)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int 	numsudokuvalid(char **mapsudoku, int pos)
{
	char nb;
	int i;

	i = 0;
	nb = '1';
	if (pos == 81)
		return (1);
	else if (mapsudoku[pos / 9][pos % 9] != '.')
		i = numsudokuvalid(mapsudoku , pos + 1);
	else
	{
		while (nb <= '9')
		{
			if (checkline(mapsudoku, pos / 9, pos % 9, nb) == 1 && 
				checkblock(mapsudoku, pos / 9, pos % 9, nb) == 1)
			{
				mapsudoku[pos / 9][pos % 9] = nb;
				i += numsudokuvalid(mapsudoku, pos + 1);
			}
			nb++;
		}
		mapsudoku[pos / 9][pos % 9] = '.';
	}
	return(i);
}

void 	sudoku(char **mapsudoku, int pos)
{
	char nb;
	char point;

	nb = '1';
	point = '.';
	if (pos == 81)
		putsudoku(mapsudoku);
	else if (mapsudoku[pos / 9][pos % 9] != point)
		sudoku(mapsudoku , pos + 1);
	else
	{
		while (nb <= '9')
		{
			if (checkline(mapsudoku, pos / 9, pos % 9, nb) == 1 && 
				checkblock(mapsudoku, pos / 9, pos % 9, nb) == 1)
			{
				mapsudoku[pos / 9][pos % 9] = nb;
				sudoku(mapsudoku, pos + 1);
			}
			nb++;
		}
		mapsudoku[pos / 9][pos % 9] = point;
	}
}

int 	main(int argc, char **argv)
{
	int pos;

	pos  = 0;
	if (argc == 10 && 1 == numsudokuvalid(argv + 1, pos) &&
		1 == checkvalidecaracter(argv + 1))
		sudoku(argv + 1, pos);
	else
	{
		write(1, "erreur", 6);
		write(1, "\n", 1);
	}
	return (0);
}
