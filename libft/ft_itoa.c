/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetshik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 09:56:48 by dnetshik          #+#    #+#             */
/*   Updated: 2017/06/10 11:51:35 by dnetshik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_length(int n, size_t *len, int *weight)
{
	*len = 1;
	if (n >= 0)
	{
		*len = 0;
		n = -n;
	}
	*weight = 1;
	while (n / *weight < -9)
	{
		*weight *= 10;
		*len += 1;
	}
}

char			*ft_itoa(int n)
{
	size_t		len;
	int			wght;
	size_t		car;
	char		*str;

	ft_length(n, &len, &wght);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	car = 0;
	if (n < 0)
	{
		str[car] = '-';
		car++;
	}
	if (n > 0)
		n = -n;
	while (wght >= 1)
	{
		str[car++] = -(n / wght % 10) + 48;
		wght /= 10;
	}
	str[car] = '\0';
	return (str);
}
