/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <mlothair@student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:46:23 by mlothair          #+#    #+#             */
/*   Updated: 2021/10/11 15:32:37 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 0
#endif

int	there_is_more(char *c)
{
	while (*c)
	{
		if (*c == '\n')
		{
			if (*(c + 1))
				return (1);
			else
				return (0);
		}
		c++;
	}
	return (0);
}

void	shiftLeft(char **str)
{
	char	temp;
	int		i;
	int		j;

	i = 0;
	while (i < BUFFER_SIZE && (*str)[i] != '\0')
	{
		if ((*str)[i] == '\n')
			break ;
		i++;
	}
	i++;
	j = 0;
	while (j < BUFFER_SIZE + 1)
	{
		if (j < ((BUFFER_SIZE + 1) - i))
		{
			temp = (*str)[j];
			(*str)[j] = (*str)[j + i];
			(*str)[j + i] = temp;
		}
		else
			(*str)[j] = '\0';
		j++;
	}
}

int	check_c(char **c, int *fd, t_vals *vals, char **nl)
{
	if (*c != 0 && there_is_more(*c))
	{
		shiftLeft(c);
		(*vals).rv = -1;
		return (1);
	}
	if (*c == 0)
	{
		*c = malloc(BUFFER_SIZE + 1);
		if (*c == 0)
			return (0);
		(*vals).prev = 1;
	}
	ft_bzero(*c, BUFFER_SIZE + 1);
	(*vals).rv = read(*fd, *c, BUFFER_SIZE);
	if (*c[0] == 0 && (*vals).rv <= 0 && *nl == 0)
	{
		if ((*vals).rv == 0 && (*vals).prev)
		{
			(*vals).prev = 0;
			free(*c);
		}
		return (0);
	}
	return (1);
}

int	fill_n(char **nl, char **c)
{
	char	*tmp;

	if (*nl == 0)
	{
		*nl = malloc(BUFFER_SIZE + 1);
		if (*nl == 0)
		{
			free(c);
			return (0);
		}
		ft_bzero(*nl, BUFFER_SIZE + 1);
		ft_memcpy(*nl, *c, BUFFER_SIZE);
	}
	else
	{
		tmp = *nl;
		*nl = ft_strjoin(*nl, *c);
		free(tmp);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	char			*nl;
	static char		*c;
	static t_vals	v;

	v.rv = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (c != 0)
			free(c);
		return (0);
	}
	nl = 0;
	while (1)
	{
		if (!check_c(&c, &fd, &v, &nl))
			return (0);
		if (!fill_n(&nl, &c))
			return (0);
		if (v.rv == 0 || (fc(c, '\n', 0)) || (l(c) < BUFFER_SIZE && v.rv != -1))
		{
			fc(nl, '\n', 1);
			return (nl);
		}
	}
}
