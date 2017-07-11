#include <stdio.h>

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void ft_putstr_non_printable(char *str)
{
	int i;
	int check

	i = 0;
	check = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 1f)
			{
				check = 1;
				break ;
			}
		i++;	
	}
	if (check == 0)
		ft_putstr(str);
	else
		while ()
}