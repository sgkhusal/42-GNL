/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 21:34:27 by sguilher          #+#    #+#             */
/*   Updated: 2021/06/30 21:46:46 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	check_new_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (NO_LINE_FEED);
}

void	gnl_strjoin(char **next, char *buffer, int only_next)
{
	char	*aux;

	if (only_next == 0)
	{
		aux = ft_strjoin(*next, buffer);
		ft_clean(next);
		*next = aux;
	}
	else
	{
		aux = ft_strdup(buffer);
		ft_clean(next);
		*next = aux;
	}
}

int	gnl_split(char *buffer, char **next, char *tmp, int only_next)
{
	char	*aux;
	int		i;
	int		j;

	aux = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!aux)
		return (MALLOC_ERROR);
	i = -1;
	while (buffer[++i] && buffer[i] != '\n')
		aux[i] = buffer[i];
	aux[i] = '\0';
	j = 0;
	i++;
	while (buffer[i])
	{
		tmp[j] = buffer[i];
		i++;
		j++;
	}
	tmp[j] = '\0';
	gnl_strjoin(next, aux, only_next);
	ft_clean(&aux);
	return (1);
}

int	gnl_read(int fd, char *buf, char **next, char *tmp)
{
	int	nl;
	int	n_read;

	nl = check_new_line(*next);
	if (nl == NO_LINE_FEED)
	{
		while (nl == NO_LINE_FEED)
		{
			n_read = read(fd, buf, BUFFER_SIZE);
			if (n_read < READ_OK)
				return (n_read);
			buf[n_read] = '\0';
			nl = check_new_line(buf);
			if (nl == NO_LINE_FEED)
				gnl_strjoin(next, buf, 0);
		}
		nl = gnl_split(buf, next, tmp, 0);
	}
	else
		nl = gnl_split(*next, next, tmp, 1);
	return (nl);
}

int	get_next_line(int fd, char **line)
{
	static char	*next[OPEN_MAX];
	char		*tmp;
	char		*buf;
	int			nl;

	if (fd < 0 || BUFFER_SIZE < 1 || line == NULL || fd > OPEN_MAX)
		return (INPUT_ERROR);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	tmp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf || !tmp)
		return (MALLOC_ERROR);
	if (!next[fd])
		next[fd] = ft_strdup("");
	nl = gnl_read(fd, buf, &next[fd], tmp);
	ft_clean(&buf);
	if (nl == 1 || (nl == 0 && next[fd]))
		*line = ft_strdup(next[fd]);
	ft_clean(&next[fd]);
	if (nl == 1)
		next[fd] = tmp;
	else
		ft_clean(&tmp);
	return (nl);
}
