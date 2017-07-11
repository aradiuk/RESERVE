/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradiuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 21:28:51 by aradiuk           #+#    #+#             */
/*   Updated: 2016/10/31 21:34:40 by aradiuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[0] == '\0')
			return (1);
		if (str[i] > '9' || str[i] < '0')
			return (0);
		i++;
	}
	return (1);
}
