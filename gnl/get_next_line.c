/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 21:34:27 by sguilher          #+#    #+#             */
/*   Updated: 2021/06/15 06:05:52 by sguilher         ###   ########.fr       */
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

int	ft_read_line(int fd, int n_read, char *buf, t_gnl *tmp)
{
	int		nl;
	char	*content;

	nl = 0;
	content = ft_strdup("");
	while (nl == 0 && n_read > 0)
	{
		buf[n_read] = '\0';
		printf("buf = %s\n", buf);
		nl = ft_split_new_line(buf, (*tmp).content, (*tmp).next);
		content = ft_strjoin(content, (*tmp).content, 1);
		printf("content = %s\n", content);
		ft_bzero((*tmp).content, ft_strlen((*tmp).content));
		if (nl == 0)
			n_read = read(fd, buf, BUFFER_SIZE);
	}
	if (n_read >= 0)
	{
		ft_clean((*tmp).content);
		(*tmp).content = ft_strdup(content);
		printf("tmp.content = %s\n", (*tmp).content);
	}
	ft_clean(content);
	ft_clean(buf);
	if (n_read < 1)
			return (n_read);
	return (1);
}

int	gnl_next(int fd, char *buf, char **next, t_gnl *tmp)
{
	int	nl;
	int	n_read;

	if (ft_split_new_line(*next, (*tmp).content, (*tmp).next) == 0)
	{
		ft_bzero((*tmp).content, ft_strlen((*tmp).content));
		n_read = read(fd, buf, BUFFER_SIZE);
		if (n_read < 1)
		{
			ft_clean(*next);
			ft_clean((*tmp).next);
			ft_clean(buf);
			if (n_read < 0)
				ft_clean((*tmp).content);
			return (n_read);
		}
		nl = ft_read_line(fd, n_read, buf, tmp);
		if (nl < 1)///////////////////////////////////
		{
			ft_clean((*tmp).next);
			if (nl < 0)
				ft_clean((*tmp).content);
		}
		(*tmp).content = ft_strjoin(*next, (*tmp).content, 2); // precisaria liberar o tmp.content no strjoin
	}
	else
		nl = 1;
	ft_clean(*next);
	return (nl);
}

int	gnl_not_next(int fd, char *buf, t_gnl *tmp)
{
	int	nl;
	int	n_read;

	n_read = read(fd, buf, BUFFER_SIZE);
	if (n_read < 1)
	{
			ft_clean((*tmp).next);
			ft_clean((*tmp).content);
			ft_clean(buf);
			return (n_read);
	}
	nl = ft_read_line(fd, n_read, buf, tmp);
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
	printf("nl = %d\ntmp.content = %s\n", nl, tmp.content); //
	if (nl == 1 || (nl == 0 && tmp.content))
		*line = ft_strdup(tmp.content);
	if (nl < 1)
		return (nl);
	next[fd] = ft_strdup(tmp.next);
	ft_clean(tmp.content); ///
	ft_clean(tmp.next); ///
	//printf("line = %s\n", *line);
	//printf("next = %s\n", next[fd]);
	return (1);
}
