/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <mlothair@student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:54:44 by mlothair          #+#    #+#             */
/*   Updated: 2021/10/10 18:44:13 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ch;

	i = 0;
	ch = (char *) s;
	while (i <= n)
	{
		ch[i] = '\0';
		i++;
	}
}

int	fc(char *s, char c, int cut)
{
	while (1)
	{
		if (*s == c)
		{
			if (cut)
				*(s + 1) = '\0';
			return (1);
		}
		if (*s == '\0')
			return (0);
		s++;
	}
}

size_t	l(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*new_str;
	unsigned int	i;
	size_t			size;

	if (s1 == 0)
		return (0);
	size = l(s1) + l(s2);
	new_str = malloc(size + 1);
	if (new_str == 0)
		return (0);
	if (size == 0)
	{
		new_str[0] = 0;
		return (new_str);
	}
	ft_memcpy(new_str, s1, l(s1));
	i = l(s1);
	while (i < size)
	{
		new_str[i] = *s2;
		s2++;
		i++;
	}
	new_str[size] = '\0';
	return (new_str);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*or_dst;
	size_t	i;

	i = 0;
	or_dst = dst;
	if (dst == 0 && src == 0)
		return (dst);
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (or_dst);
}
