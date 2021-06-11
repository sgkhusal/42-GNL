/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 19:17:03 by sguilher          #+#    #+#             */
/*   Updated: 2021/06/11 06:18:40 by sguilher         ###   ########.fr       */
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

int	ft_read_line(int fd, char *buf, char *content, t_gnl tmp)
{
	int		n_read;

	n_read = read(fd, buf, BUFFER_SIZE);
	if (n_read < 1) //
		return (n_read);
	buf[n_read] = '\0';
	//printf("read_return = %d\n", n_read); ///
	//printf("%s\n", buf); ///
	while (ft_split_new_line(buf, tmp.content, tmp.next) == 0)
	{
		//printf("tmp.content: %s\n", tmp.content);
		content = ft_strjoin(content, tmp.content, 1);
		printf("1. content in ft_read_line: %s\n", content);
		ft_bzero(tmp.content, ft_strlen(tmp.content));
		n_read = read(fd, buf, BUFFER_SIZE);
		if (n_read < 1)
			return (n_read);
		buf[n_read] = '\0';
		//printf("read_return = %d\n", n_read);
		//printf("%s\n", buf);
	}
	content = ft_strjoin(content, tmp.content, 1);
	printf("2. content in ft_read_line: %s\n", content);
	return (1); ///////
}

int	ft_gnl(int fd, char **line, char *buf, char *content, t_gnl tmp)
{
	static char	*next = NULL;
	int	nl;

	if (next)
	{
		//printf ("entendeu que tem residual antigo\n");
		if (ft_split_new_line(next, tmp.content, tmp.next) == 1)
		{
			printf("1. content in ft_gnl: %s\n", tmp.content);
			*line = ft_strdup(tmp.content);
		}
		else
		{
			ft_bzero(tmp.content, ft_strlen(tmp.content));
			nl = ft_read_line(fd, buf, content, tmp);
			printf("2. content in ft_gnl: %s\n", content);
			if (nl < 1)
				return (nl);
			*line = ft_strjoin(next, content, 0);
		}
		free(next);
	}
	else
	{
		nl = ft_read_line(fd, buf, content, tmp);
		printf("3. content in ft_gnl: %s\n", content);
		printf("3. tmp.content in ft_gnl: %s\n", tmp.content);
		printf("3. tmp.next in ft_gnl: %s\n", tmp.next);
		printf("3. buf in ft_gnl: %s\n", buf);
		if (nl < 1)
			return (nl);
		*line = ft_strdup(content);
	}
	printf("*line: %s\n", *line);
	if (tmp.next)
		next = ft_strdup(tmp.next);
	printf("next content:\n%s\n", next);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	t_gnl		tmp;
	char		*buf;
	char		*content;
	int			nl;

	if (fd < 0 || BUFFER_SIZE < 1 || line == NULL || fd > RLIMIT_NOFILE)
		return (-1);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	content = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	tmp.content = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	tmp.next = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf || !content || !tmp.next || !tmp.content)
		return (-1);
	ft_bzero(content, BUFFER_SIZE + 1);
	ft_bzero(tmp.content, BUFFER_SIZE + 1);
	ft_bzero(tmp.next, BUFFER_SIZE + 1);
	nl = ft_gnl(fd, line, buf, content, tmp);

	ft_clean(content, tmp, buf);
	return (nl);
}
