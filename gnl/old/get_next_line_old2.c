/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_old2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 19:17:03 by sguilher          #+#    #+#             */
/*   Updated: 2021/06/13 22:02:58 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// verificar e separar \n
int	ft_split_new_line(char *str, char *new_l, char *tmp)
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
			new_l[j] = '\0';
			j = 0;
			while (str[i + 1])
			{
				tmp[j] = str[i + 1];
				i++;
				j++;
			}
			tmp[j] = '\0';
			//printf("tem uma nova linha: \n"); ///
			//printf("%s\n\n", new_l);
			//printf("%s\n", tmp);
			return (1);
		}
		else
			new_l[j] = str[i];
		i++;
		j++;
	}
	new_l[j] = '\0';
	//printf("nao tem uma nova linha: \n"); ///
	//printf("%s\n", new_l);
	return (0);
}

int	ft_read_line(int fd, char *buf, t_gnl tmp)
{
	int		n_read;
	char	*content;


	while (ft_split_new_line(buf, tmp.content, tmp.next) == 0)
	{
		content = ft_strjoin(content, tmp.content, 1);
		ft_bzero(tmp.content, ft_strlen(tmp.content));
		n_read = read(fd, buf, BUFFER_SIZE);
		if (n_read < 1)
			return (n_read);
		buf[n_read] = '\0';
	}
	content = ft_strjoin(content, tmp.content, 1);
	tmp.content = ft_strdup(content);
	free(content);
	return (1); ///////
}

int	ft_gnl(int fd, char **line, char *buf, char **next)
{

	int	nl;

	if (ft_split_new_line(next, tmp.content, tmp.next) == 1)
	{
		printf("1. tmp.content in ft_gnl: %s\n", tmp.content);
		*line = ft_strdup(tmp.content);
	}
	else
	{
		ft_bzero(tmp.content, ft_strlen(tmp.content));
		nl = ft_read_line(fd, buf, tmp);
		printf("2. content in ft_gnl: %s\n", tmp.content);
		if (nl < 1)
			return (nl);
		*line = ft_strjoin(next, tmp.content, 0);
		free(next);
	}


	return (1);
}

int	get_next_line(int fd, char **line)
{
	t_gnl		tmp;
	char		*buf;
	int			nl;
	static char	*next[256];


	if (fd < 0 || BUFFER_SIZE < 1 || line == NULL || fd > OPEN_MAX)
		return (-1);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	tmp.content = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	tmp.next = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf || !tmp.next || !tmp.content)
		return (-1);
	ft_bzero(tmp.content, BUFFER_SIZE + 1);
	ft_bzero(tmp.next, BUFFER_SIZE + 1);
	if (next[fd])
		nl = ft_read_line(fd, next[fd], tmp);
	nl = ft_read_line(fd, buf, tmp);
	if (nl < 1)
		return (nl);
	*line = ft_strdup(tmp.content);
	nl = read(fd, buf, BUFFER_SIZE);
	if (nl < 1)
		return (nl);
	buf[nl] = '\0';
	if (tmp.next)
		next[fd] = ft_strdup(tmp.next);
	printf("next content:\n%s\n", next[fd]);
	ft_clean(content, tmp, buf);
	return (nl);
}
