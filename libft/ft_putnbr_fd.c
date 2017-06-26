/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetshik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 08:05:51 by dnetshik          #+#    #+#             */
/*   Updated: 2017/06/10 09:19:20 by dnetshik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbrlng;

	nbrlng = (long)n;
	if (nbrlng < 0)
	{
		ft_putchar_fd('-', fd);
		nbrlng *= -1;
	}
	if (nbrlng >= 10)
	{
		ft_putnbr_fd(nbrlng / 10, fd);
		ft_putnbr_fd(nbrlng % 10, fd);
	}
	else
	{
		ft_putchar_fd(nbrlng + '0', fd);
	}
}
