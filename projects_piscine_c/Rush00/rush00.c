/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 12:51:48 by gtertysh          #+#    #+#             */
/*   Updated: 2016/10/30 12:52:09 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	rush_print(int x, int y, int i, int j)
{
	if (j > 1 && j < x && i > 1 && i < y)
		ft_putchar(' ');
	else if (j == 1 && i == 1)
		ft_putchar('o');
	else if (j == x && i == 1)
		ft_putchar('o');
	else if (j == 1 && i == y)
		ft_putchar('o');
	else if (j == x && i == y)
		ft_putchar('o');
	else if ((j > 1 && j < x) && (i == 1 || i == y))
		ft_putchar('-');
	else
		ft_putchar('|');
}

int		rush(int x, int y)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (i <= y)
	{
		while (j <= x)
		{
			rush_print(x, y, i, j);
			j++;
		}
		ft_putchar('\n');
		i++;
		j = 1;
	}
	return (0);
}
