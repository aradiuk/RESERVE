/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradiuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 16:50:28 by aradiuk           #+#    #+#             */
/*   Updated: 2016/11/01 17:22:39 by aradiuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int		ft_power(int a, int length)
{
	int power;

	power = 1;
	while (a > 0)
	{
		power = power * length;
		a--;
	}
	return (power);
}

int		ft_count(int a, int length)
{
	int count;

	count = 0;
	while (a >= length)
	{
		a = a / length;
		count++;
	}
	return (count);
}

int		base_valid(char *base)
{
	int i;
	int j;

	i = 0;
	j = 1;
	if (base[0] == '\0' || base[1] == '\0')
		return (1);
	while (base[i] != '\0')
	{
		while (base[j] != '\0')
		{
			if (base[i] == base[j] || base[i] == '+' || base[i] == '-')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		print(int nb, int length, char *base)
{
	int count;

	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	count = ft_count(nb, length);
	while (count >= 0)
	{
		ft_putchar(base[nb / ft_power(count, length) % length]);
		count--;
	}
	return (0);
}

void	ft_putnbr_base(int nb, char *base)
{
	int exc;
	int length;
	int last_elem;

	length = 0;
	exc = nb;
	while (base[length] != '\0')
		length++;
	if (base_valid(base) == 1)
		return ;
	if (nb == -2147483648)
	{
		last_elem = nb % length * -1;
		nb /= length;
	}
	if (nb == 0)
		ft_putchar(base[0]);
	else
	{
		print(nb, length, base);
		if (exc == -2147483648)
			ft_putchar(base[last_elem]);
	}
}
