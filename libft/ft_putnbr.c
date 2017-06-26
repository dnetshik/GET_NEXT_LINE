/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetshik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 08:18:26 by dnetshik          #+#    #+#             */
/*   Updated: 2017/06/10 11:38:07 by dnetshik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long	lngnbr;

	lngnbr = (long)n;
	if (lngnbr < 0)
	{
		ft_putchar('-');
		lngnbr *= -1;
	}
	if (lngnbr >= 10)
	{
		ft_putnbr(lngnbr / 10);
		ft_putnbr(lngnbr % 10);
	}
	else
	{
		ft_putchar(lngnbr + '0');
	}
}
