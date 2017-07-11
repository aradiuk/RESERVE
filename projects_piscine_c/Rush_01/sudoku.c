#include <unistd.h>

int		check_row(int i, char temp, char **puzzle)
{
	int c;

	c = 0;
	while (c < 9)
	{
		if (puzzle[i][c] == temp)
			return (0);
		c++;
	}
	return (1);
}

int		check_column(int j, char temp, char **puzzle)
{
	int c;
	
	c = 1;
	while (c <= 9)
	{
		if (puzzle[c][j] == temp)
			return (0);
		c++;
	}
	return (1);
}

int		check_square(int x, int y, char temp, char **puzzle)
{
	int i;
	int j;

	if (x <= 3)
		x = 1;
	else if (x <= 6)
		x = 4;
	else if (x <= 9)
		x = 7;
	y = y - (y % 3);
	i = 0;
	while (i++ < 3)
	{
		j = 0;
		while (j++ < 3)
		{
			if (puzzle[x][y] == temp)
				return(0);
			y++;
		}
		y = y -3;
		x++;
	}
	return (1);
}

int correct(int argc, char **puzzle)
{
	int i;
	int j;
	
	i = 1;
	if (argc == 10)
	{
		while (i <= 9)
		{
			j = 0;
			while (puzzle[i][j])
				j++;
			if (j != 9)
				return (0);
			i++;
		}
		return (1);
	}
	else
		return (0);
}

int fill(char **puzzle, int index)
{
	int i;
	int j;
	char temp;

	i = index / 9;
	j = index % 9;
	temp = '1';
	if (index == 90)
		return (1);
	if (puzzle[i][j] != '.')
		return (fill(puzzle, index + 1));
	while (temp <= '9')
	{
		if (check_row(i, temp, puzzle) && check_column(j, temp, puzzle)
			&& check_square(i, j, temp, puzzle))
		{
			puzzle[i][j] = temp;
			if(fill(puzzle, index + 1))
				return (1);
		}
		temp++;
	}
	puzzle[i][j] = '.';
	return (0);
}

void	print_puzzle(char **puzzle)
{
	int i;
	int j;

	i = 1;
	while (i <= 9)
	{
		j = 0;
		while (puzzle[i][j])
		{
			write(1, &puzzle[i][j], 1);
			if (j != 8)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (correct(argc, argv))
	{
		if (fill(argv, 9))
			print_puzzle(argv);
		else
			write(1, "Error1\n", 6);
	}
	else
		write(1, "Error2\n", 6);
	return (0);
}
