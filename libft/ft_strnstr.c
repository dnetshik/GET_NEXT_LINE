/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetshik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 12:43:10 by dnetshik          #+#    #+#             */
/*   Updated: 2017/06/10 11:03:53 by dnetshik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *litle, size_t len)
{
	size_t		ln;

	if (*litle == '\0')
		return ((char *)big);
	ln = ft_strlen(litle);
	while (*big != '\0' && len-- >= ln)
	{
		if (*big == *litle && ft_memcmp(big, litle, ln) == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
