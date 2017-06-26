/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetshik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 20:01:00 by dnetshik          #+#    #+#             */
/*   Updated: 2017/06/10 11:38:48 by dnetshik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_isspace(int s)
{
	if ((s >= '\t' && s <= '\r') || (s == 32))
		return (1);
	return (0);
}

int					ft_atoi(const char *str)
{
	long			retrn;
	int				chrsgn;
	int				i;

	i = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-')
		chrsgn = -1;
	else
		chrsgn = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	retrn = 0;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		retrn = retrn * 10 + str[i] - '0';
		i++;
	}
	retrn = retrn * chrsgn;
	return (retrn);
}
