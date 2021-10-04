/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 13:47:35 by mdenys            #+#    #+#             */
/*   Updated: 2020/11/17 23:55:45 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char			*check_reminder(char *reminder)
{
	char	*rtn;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!reminder)
		return (0);
	while (reminder[i] && reminder[i] != '\n')
		i++;
	if (!reminder[i])
	{
		free(reminder);
		return (0);
	}
	if (!(rtn = malloc(sizeof(char) * ((ft_strlen(reminder) - i) + 1))))
		return (0);
	i++;
	while (reminder[i])
		rtn[j++] = reminder[i++];
	rtn[j] = '\0';
	free(reminder);
	return (rtn);
}

char			*gnl(char *str)
{
	int		i;
	char	*rtn;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (!(rtn = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		rtn[i] = str[i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

int				get_line(int fd, char **line, char **reminder)
{
	char			*buff;
	int				r_d;

	r_d = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!ft_rn(*reminder) && r_d != 0)
	{
		if ((r_d = read(fd, buff, BUFFER_SIZE)) == -1)
		{
			free(buff);
			return (-1);
		}
		buff[r_d] = '\0';
		*reminder = ft_strjoin(*reminder, buff);
	}
	free(buff);
	*line = gnl(*reminder);
	*reminder = check_reminder(*reminder);
	if (r_d == 0)
		return (0);
	return (1);
}

t_netnext_line	*new_linked_list_el(const int fd)
{
	t_netnext_line *new;

	new = (t_netnext_line *)malloc(sizeof(t_netnext_line));
	new->fd = fd;
	new->reminder = NULL;
	new->next = NULL;
	return (new);
}

int				get_next_line(int fd, char **line)
{
	static t_netnext_line	*head;
	t_netnext_line			*temp;

	if (fd < 0)
		return (-1);
	if (fd == 0)
		return (0);
	if (head == NULL)
		head = new_linked_list_el(fd);
	temp = head;
	while (temp->fd != fd)
	{
		if (temp->next == NULL)
			temp->next = new_linked_list_el(fd);
		temp = temp->next;
	}
	return (get_line(fd, line, &temp->reminder));
}
