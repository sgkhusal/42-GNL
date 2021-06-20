/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 21:34:27 by sguilher          #+#    #+#             */
/*   Updated: 2021/06/19 21:08:13 by sguilher         ###   ########.fr       */
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

int	gnl_read(int fd, char **next, char **tmp)
{
	char	*buf;
	char	*aux;
	int		nl;
	int		n_read;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	aux = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf || !aux)
		return (MALLOC_ERROR);
	n_read = READ_OK;
	nl = FOUND_LINE_FEED;
	if (ft_split_new_line(*next, aux, *tmp) == NO_LINE_FEED)
	{
		ft_bzero(aux, BUFFER_SIZE + 1);
		nl = NO_LINE_FEED;
		while (nl == NO_LINE_FEED)
		{
			*next = ft_strjoin(*next, aux, CLEAN);
			n_read = read(fd, buf, BUFFER_SIZE);
			if (n_read == READ_NOT_OK)
				return (READ_NOT_OK);
			buf[n_read] = '\0';
			nl = ft_split_new_line(buf, aux, *tmp);
			if (nl == NO_LINE_FEED && n_read == REACHED_EOF) ///
				return (n_read);
		}
		*next = ft_strjoin(*next, aux, CLEAN);
		ft_clean(&aux);
	}
	else
		*next = aux;
	ft_clean(&buf);
	return (nl);
}

int	get_next_line(int fd, char **line)
{
	static char	*next[OPEN_MAX];
	char		*tmp;
	int			nl;

	if (fd < 0 || BUFFER_SIZE < 1 || line == NULL || fd > OPEN_MAX)
		return (INPUT_ERROR);
	tmp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (MALLOC_ERROR);
	if (!next[fd])
		next[fd] = ft_strdup("", NO_CLEAN);
	nl = gnl_read(fd, &next[fd], &tmp);
	if (nl == 1 || (nl == 0 && next[fd])) ///
		*line = ft_strdup(next[fd], CLEAN);
	next[fd] = ft_strdup("", NO_CLEAN);
	if (nl < 1)
		return (nl);
	next[fd] = tmp;
	return (1);
}
