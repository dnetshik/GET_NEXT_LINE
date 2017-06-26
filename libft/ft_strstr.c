/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetshik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 08:42:36 by dnetshik          #+#    #+#             */
/*   Updated: 2017/06/10 10:07:34 by dnetshik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int matches;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0')
	{
		matches = 0;
		while (little[matches] == big[i + matches] && little[matches] != '\0')
			matches++;
		if (little[matches] == '\0')
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
