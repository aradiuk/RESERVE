/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradiuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 16:57:35 by aradiuk           #+#    #+#             */
/*   Updated: 2016/11/01 19:14:55 by aradiuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;
	int check;
	int length;

	i = 0;
	length = 0;
	while (to_find[length] != '\0')
		length++;
	if (length == 0)
		return (str);
	while (str[i] != '\0')
	{
		check = 0;
		j = 0;
		while (str[i + j] == to_find[j])
		{
			check += 1;
			j++;
		}
		if (check == length)
			return (str + i);
		i++;
	}
	return (0);
}
