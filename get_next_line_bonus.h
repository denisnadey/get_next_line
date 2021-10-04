/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 21:55:13 by mdenys            #+#    #+#             */
/*   Updated: 2020/11/17 23:58:39 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif

typedef	struct				s_netnext_line
{
	int						fd;
	char					*reminder;
	struct s_netnext_line	*next;
}							t_netnext_line;

int							get_next_line(int fd, char **line);
int							ft_rn(char *str);
size_t						ft_strlen(const char *s);
char						*ft_strjoin(const char *s1, const char *s2);

#endif
