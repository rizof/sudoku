#include <unistd.h>
#include <stdio.h>

int	 	ft_strlen(char *mapsudoku)
{
	int i;

	i = 0;
	while (*mapsudoku)
	{
		mapsudoku++;
		i++;
	}
	return (i);
}
void 	putsudoku(char **mapsudoku)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (mapsudoku[y])
	{
		x = 0;
		while (mapsudoku[y][x])
		{
			write(1, &mapsudoku[y][x], 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

int 	checkvalidecaracter(char **mapsudoku)
{
	int  	i;
	char 	point;
	char 	c;

	c = 0;
	point = '.';
	i = 0;
	while (i < 81)
	{
		if(!((9 == ft_strlen(mapsudoku[i / 9]))))
			return (0);
		c = mapsudoku[i / 9][i % 9];
		if (!((c == point ) || (c >= '1' && c <= '9')))
			return (0);
		i++;
	}
	return (1);
}