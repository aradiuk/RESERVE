/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradiuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 10:28:08 by aradiuk           #+#    #+#             */
/*   Updated: 2016/11/06 10:28:10 by aradiuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define N 9

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char		**create_puzzle(char **argv)
{
	char **puzzle;
	int i;
	int j;

	i = 0;
	puzzle = (char**)malloc(sizeof(char*) * n);
	while (i < n)
	{
		puzzle[i] = (char*)malloc(sizeof(char) * n);
		j = 0;
		while (j < n)
		{
			puzzle[i][j] = argv[i + 1][j];
			j++;
		}
		i++;
	}
	return (puzzle);
}

int		check_row(int i, int temp, char **puzzle)
{
	int c;

	c = 0;
	while (c < N)
	{
		if (puzzle[i][c] == temp)
			return (1);
		c++;
	}
	return (0);
}

int		check_column(int j, int temp, char **puzzle)
{
	int c;

	c = 0;
	while (c < N)
	{
		if (puzzle[c][j] == temp)
			return (1);
		c++;
	}
	return (0);
}

int		check_square(int i, int j, char temp, char **puzzle)
{
	int c;
	int d;

	c = (i / 3) * 3;
	while (c < c + 3)
	{
		d = (i / 3) / 3;
		while (d < d + 3)
		{
			if (puzzle[c][d] == temp)
				return (1);
			d++;
		}
		c++;
	}
	return (0);
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
			j = 1;
			while (puzzle[i][j])
			{
				if (puzzle[i][j] != '.' && (puzzle[i][j] < 48 || puzzle[i][j] > 57))
					return (0);
				j++;
			}
			if (j != 9)
				return (0);
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
	while (temp <= 9)
	{
		if (check_row(i, temp, puzzle) && check_column(j, temp, puzzle)
			&& check_square(i, j, temp, puzzle))
		{
			puzzle[i][j] = temp;
			if(fill(puzzle, index + 1))
				return (1);
		}
	}
	puzzle[i][j] = '.';
	return (0);
}

void	print_puzzle(char **puzzle)
{
	int i;
	int j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (puzzle[i][j])
		{
			write(1, &puzzle[i][j], 1);
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
		if (fill(argv, N))
			print_puzzle(argv);
		else
			write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
