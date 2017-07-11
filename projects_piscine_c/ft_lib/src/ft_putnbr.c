/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradiuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 10:24:03 by aradiuk           #+#    #+#             */
/*   Updated: 2016/10/31 19:46:55 by aradiuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int		ft_power(int a)
{
	int power;

	power = 1;
	while (a > 0)
	{
		power = power * 10;
		a--;
	}
	return (power);
}

int		ft_count(int a)
{
	int count;

	count = 0;
	while (a >= 10)
	{
		a = a / 10;
		count++;
	}
	return (count);
}

void	ft_putnbr(int nb)
{
	int count;
	int exc;

	exc = nb;
	if (nb == -2147483648)
		nb = -214748364;
	if (nb == 0)
		ft_putchar('0');
	else
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = -nb;
		}
		count = ft_count(nb);
		while (count > 0)
		{
			ft_putchar(((nb / ft_power(count)) % 10) + '0');
			count--;
		}
		ft_putchar(nb % 10 + '0');
		if (exc == -2147483648)
			ft_putchar('8');
	}
}
