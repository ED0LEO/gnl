/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <mlothair@student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:46:14 by mlothair          #+#    #+#             */
/*   Updated: 2021/10/11 15:31:44 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_vals
{
	int	rv;
	int	prev;
}				t_vals;

char	*get_next_line(int fd);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	l(const char *s);
int		fc(char *s, char c, int cut);
void	ft_bzero(void *s, size_t n);

#endif
