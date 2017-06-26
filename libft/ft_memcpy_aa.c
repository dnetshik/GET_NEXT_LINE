/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_aa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetshik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 11:03:45 by dnetshik          #+#    #+#             */
/*   Updated: 2017/06/10 10:21:56 by dnetshik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy_aa(void *s1, const void *s2, size_t n)
{
	char		*cur1;
	char		*cur2;

	if (n == 0 || s1 == s2)
		return (s1);
	cur1 = (char *)s1;
	cur2 = (char *)s2;
	while (n--)
	{
		cur1[n] = cur2[n];
	}
	return (s1);
}
