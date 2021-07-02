/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 21:34:27 by sguilher          #+#    #+#             */
/*   Updated: 2021/07/02 20:05:05 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	gnl_next(char **next, char *aux, int only_next)
{
	if (only_next == 0)
	{
		gnl_strjoin(next, aux);
		ft_clean(&aux);
	}
	else if (only_next == 1)
	{
		ft_clean(next);
		*next = aux;
	}
}

int	gnl_split(char *str, char **next, char *tmp, int only_next)
{
	char	*aux;
	int		i;
	int		j;

	aux = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!aux)
		return (MALLOC_ERROR2);
	i = -1;
	while (str[++i] && str[i] != '\n')
		aux[i] = str[i];
	aux[i] = '\0';
	j = -1;
	while (str[++i])
		tmp[++j] = str[i];
	tmp[++j] = '\0';
	gnl_next(next, aux, only_next);
	return (1);
}

int	check_new_line(char *str, char **next, char *tmp, int only_next)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (gnl_split(str, next, tmp, only_next));
		i++;
	}
	if (only_next == 0)
		gnl_strjoin(next, str);
	return (NO_LINE_FEED);
}

int	gnl_read(int fd, char *buf, char **next, char *tmp)
{
	int	nl;
	int	n_read;

	nl = check_new_line(*next, next, tmp, 1);
	while (nl == NO_LINE_FEED)
	{
		n_read = read(fd, buf, BUFFER_SIZE);
		if (n_read < READ_OK)
			return (n_read);
		buf[n_read] = '\0';
		nl = check_new_line(buf, next, tmp, 0);
	}
	if (nl == MALLOC_ERROR2)
		return (MALLOC_ERROR);
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
