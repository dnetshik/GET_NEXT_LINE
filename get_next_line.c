/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetshik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 16:56:34 by dnetshik          #+#    #+#             */
/*   Updated: 2017/06/26 07:53:11 by dnetshik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "./libft/includes/libft.h"

static int		get_read(int const fd, char **mem_stack)
{
	char		*buff;
	char		*tmp;
	int			ret;

	if (!(buff = (char *)malloc(sizeof(*buff) * (BUFF_SIZE + 1))))
		return (-1);
	ret = read(fd, buff, BUFF_SIZE);
	if (ret > 0)
	{
		buff[ret] = '\0';
		tmp = ft_strjoin(*mem_stack, buff);
		free(*mem_stack);
		*mem_stack = tmp;
	}
	free(buff);
	return (ret);
}

int				get_next_line(int const fd, char **line)
{
	static	char	*mem_stack;
	char			*store;
	int				ret;

	if ((!mem_stack && (mem_stack = (char *)malloc(sizeof(*mem_stack))) == NULL)
			|| !line || fd < 0 || BUFF_SIZE < 0)
		return (-1);
	store = ft_strchr(mem_stack, '\n');
	while (store == NULL)
	{
		ret = get_read(fd, &mem_stack);
		if (ret == 0)
		{
			if (ft_strlen(mem_stack) == 0)
				return (0);
			mem_stack = ft_strjoin(mem_stack, "\n");
		}
		if (ret < 0)
			return (-1);
		else
			store = ft_strchr(mem_stack, '\n');
	}
	*line = ft_strsub(mem_stack, 0, ft_strlen(mem_stack) - ft_strlen(store));
	mem_stack = ft_strdup(store + 1);
	return (1);
}
