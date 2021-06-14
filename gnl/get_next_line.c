/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 21:34:27 by sguilher          #+#    #+#             */
/*   Updated: 2021/06/14 03:05:19 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_split_new_line(char *str, char *line, char *next)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] == '\n')
		i++;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			line[j] = '\0';
			j = -1;
			while (str[++i])
				next[++j] = str[i];
			next[++j] = '\0';
			return (1);
		}
		else
			line[j] = str[i];
		i++;
		j++;
	}
	line[j] = '\0';
	return (0);
}

int	ft_read_line(int fd, char *buf, t_gnl *tmp)
{
	int		n_read;
	int		nl;
	char	*content;

	content = ft_strdup("");
	nl = ft_split_new_line(buf, (*tmp).content, (*tmp).next);
	while (nl == 0)
	{
		//printf("ft_split_new_line = 0\n");
		//printf("buf = %s\n", buf);
		content = ft_strjoin(content, (*tmp).content, 1);
		ft_bzero((*tmp).content, ft_strlen((*tmp).content));
		n_read = read(fd, buf, BUFFER_SIZE);
		if (n_read < 1)
			return (n_read);
		buf[n_read] = '\0';
		nl = ft_split_new_line(buf, (*tmp).content, (*tmp).next);
	}
	//printf("buf = %s\n", buf);
	content = ft_strjoin(content, (*tmp).content, 1);
	ft_clean((*tmp).content);
	(*tmp).content = ft_strdup(content);
	ft_clean(content);
	ft_clean(buf);
	return (1);
}

int	gnl_next(int fd, char *buf, char **next, t_gnl *tmp)
{
	int	nl;

	if (ft_split_new_line(*next, (*tmp).content, (*tmp).next) == 0)
	{
		ft_bzero((*tmp).content, ft_strlen((*tmp).content));
		nl = ft_read_line(fd, buf, tmp);
		if (nl < 1)
			return (nl);
		(*tmp).content = ft_strjoin(*next, (*tmp).content, 2); // precisaria liberar o tmp.content no strjoin
	}
	ft_clean(*next);
	return (1);
}

int	gnl_not_next(int fd, char *buf, t_gnl *tmp)
{
	int	nl;

	nl = read(fd, buf, BUFFER_SIZE);
	if (nl < 1)
		return (nl);
	buf[nl] = '\0';
	nl = ft_read_line(fd, buf, tmp);
	return (nl);
}

int	get_next_line(int fd, char **line)
{
	static char	*next[OPEN_MAX];
	t_gnl		tmp;
	char		*buf;
	int			nl;

	if (fd < 0 || BUFFER_SIZE < 1 || line == NULL || fd > OPEN_MAX)
		return (-1);
	if (*line)
		ft_clean(*line);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	tmp.content = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	tmp.next = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf || !tmp.next || !tmp.content)
		return (-1);
	ft_bzero(tmp.content, BUFFER_SIZE + 1);
	ft_bzero(tmp.next, BUFFER_SIZE + 1);
	if (next[fd])
		nl = gnl_next(fd, buf, &next[fd], &tmp);
	else
		nl = gnl_not_next(fd, buf, &tmp);
	if (nl < 1)
		return (nl);
	*line = ft_strdup(tmp.content);
	next[fd] = ft_strdup(tmp.next);
	ft_clean(tmp.content); ///
	ft_clean(tmp.next); ///
	printf("line = %s\n", *line);
	printf("next = %s\n", next[fd]);
	return (1);
}
