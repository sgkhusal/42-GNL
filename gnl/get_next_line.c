/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 21:34:27 by sguilher          #+#    #+#             */
/*   Updated: 2021/06/17 04:07:52 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_split_new_line(char *str, char *line, char *next)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			line[j] = '\0';
			j = -1;
			while (str[++i])
				next[++j] = str[i];
			next[++j] = '\0';
			return (FOUND_LINE_FEED);
		}
		else
			line[j] = str[i];
		i++;
		j++;
	}
	line[j] = '\0';
	return (NO_LINE_FEED);
}

int	gnl_read(int fd, char *buf, char **next, t_gnl *tmp)
{
	int	nl;
	int	n_read;

	n_read = READ_OK;
	nl = FOUND_LINE_FEED;
	if (ft_split_new_line(*next, (*tmp).content, (*tmp).next) == NO_LINE_FEED)
	{
		ft_bzero((*tmp).content, BUFFER_SIZE + 1);
		if (!(*tmp).content)
			return (MALLOC_ERROR);
		nl = NO_LINE_FEED;
		while (nl == NO_LINE_FEED)
		{
			*next = ft_strjoin(*next, (*tmp).content, CLEAN);
			n_read = read(fd, buf, BUFFER_SIZE);
			if (n_read == READ_NOT_OK)
				return (READ_NOT_OK);
			buf[n_read] = '\0';
			nl = ft_split_new_line(buf, (*tmp).content, (*tmp).next);
			if (nl == NO_LINE_FEED && n_read == REACHED_EOF) ///
				return (n_read);
		}
		*next = ft_strjoin(*next, (*tmp).content, CLEAN);
	}
	else
		*next = (*tmp).content;
	return (nl);
}

int	get_next_line(int fd, char **line)
{
	static char	*next[OPEN_MAX];
	t_gnl		tmp;
	char		*buf;
	int			nl;

	if (fd < 0 || BUFFER_SIZE < 1 || line == NULL || fd > OPEN_MAX)
		return (INPUT_ERROR);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	tmp.content = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	tmp.next = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf || !tmp.next || !tmp.content)
		return (MALLOC_ERROR);
	if (!next[fd])
		next[fd] = ft_strdup("", NO_CLEAN);
	nl = gnl_read(fd, buf, &next[fd], &tmp);
	ft_clean(&buf);
	if (nl == 1 || (nl == 0 && next[fd])) ///
		*line = ft_strdup(next[fd], CLEAN);
	next[fd] = ft_strdup("", NO_CLEAN);
	if (nl < 1)
		return (nl);
	next[fd] = tmp.next;
	return (1);
}
