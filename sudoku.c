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

int		checkblock(char **mapsudoku, int y, int x, char c)
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
			if (mapsudoku[y][x] == c)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int 	numsudokuvalid(char **mapsudoku, int pos)
{
	char c;
	char point;
	int i;

	i = 0;
	c = '1';
	point = '.';
	if (pos == 81)
		return (1);
	else if (mapsudoku[pos / 9][pos % 9] != point)
		i = numsudokuvalid(mapsudoku , pos + 1);
	else
	{
		while (c <= '9')
		{
			if (checkline(mapsudoku, pos / 9, pos % 9, c) == 1 && 
				checkblock(mapsudoku, pos / 9, pos % 9, c) == 1)
			{
				mapsudoku[pos / 9][pos % 9] = c;
				i += numsudokuvalid(mapsudoku, pos + 1);
			}
			c++;
		}
	}
		mapsudoku[pos / 9][pos % 9] = point;
	return(i);
}

void 	sudoku(char **mapsudoku, int pos)
{
	char c;
	char point;

	c = '1';
	point = '.';
	if (pos == 81)
		putsudoku(mapsudoku);
	else if (mapsudoku[pos / 9][pos % 9] != point)
		sudoku(mapsudoku , pos + 1);
	else
	{
		while (c <= '9')
		{
			if (checkline(mapsudoku, pos / 9, pos % 9, c) == 1 && 
				checkblock(mapsudoku, pos / 9, pos % 9, c) == 1)
			{
				mapsudoku[pos / 9][pos % 9] = c;
				sudoku(mapsudoku, pos + 1);
			}
			c++;
		}
	}
		mapsudoku[pos / 9][pos % 9] = point;
}

int 	main(int argc, char **argv)
{
	if (argc == 10 && checkvalidecaracter(argv + 1) == 1 && 
		numsudokuvalid(argv + 1) == 1)
		sudoku(argv + 1, 0);
	else
	{
		write(1, "erreur", 6);
		write(1, "\n", 1);
	}
	return (0);
}