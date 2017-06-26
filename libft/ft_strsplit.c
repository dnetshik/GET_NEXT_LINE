/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetshik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 10:00:00 by dnetshik          #+#    #+#             */
/*   Updated: 2017/06/10 10:23:41 by dnetshik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countp(const char *s, char c)
{
	int			cnt;
	int			substr;

	substr = 0;
	cnt = 0;
	while (*s != '\0')
	{
		if (substr == 1 && *s == c)
			substr = 0;
		if (substr == 0 && *s != c)
		{
			substr = 1;
			cnt++;
		}
		s++;
	}
	return (cnt);
}

static int		ft_lenw(const char *s, char c)
{
	int			len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**splt;
	int			wrd;
	int			indx;

	indx = 0;
	if (!s || !c)
		return (NULL);
	wrd = ft_countp((const char *)s, c);
	splt = (char **)malloc(sizeof(*splt) * (ft_countp((const char *)s, c) + 1));
	if (splt == NULL)
		return (NULL);
	while (wrd--)
	{
		while (*s == c && *s != '\0')
			s++;
		splt[indx] = ft_strsub((const char *)s, 0, ft_lenw((const char *)s, c));
		if (splt[indx] == NULL)
			return (NULL);
		s = s + ft_lenw(s, c);
		indx++;
	}
	splt[indx] = NULL;
	return (splt);
}
