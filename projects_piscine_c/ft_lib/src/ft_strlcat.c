/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradiuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 12:28:37 by aradiuk           #+#    #+#             */
/*   Updated: 2016/11/01 22:12:44 by aradiuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < (int)size - i - 1)
	{
		dest[i + j] = src[j];
		j++;
	}
	while (src[j] != '\0')
		j++;
	if ((int)size < i)
		return (size + j);
	return (i + j);
}
