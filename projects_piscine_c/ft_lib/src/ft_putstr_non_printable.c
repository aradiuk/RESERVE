/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradiuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 23:24:17 by aradiuk           #+#    #+#             */
/*   Updated: 2016/11/01 23:26:15 by aradiuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int		ft_power(int i)
{
	int result;

	result = 1;
	while (i - 1 != 0)
	{
		result = result * 16;
		i--;
	}
	return (result);
}

int		length(int i)
{
	int result;

	result = 0;
	while (i != 0)
	{
		i /= 16;
		++result;
	}
	return (result);
}

void	print(char c)
{
	int		length;
	char	*hex;

	hex = "0123456789abcdef";
	length = length(c);
	ft_putchar('\\');
	if (length == 1)
		ft_putchar('0');
	while (length > 0)
	{
		ft_putchar(hex[c / ft_power(length)]);
		c = c - (c / ft_power(length)) * ft_power(length);
		length--;
	}
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] == 127)
			print(str[i]);
		else
			ft_putchar(str[i]);
		i++;
	}
}
