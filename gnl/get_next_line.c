/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 19:17:03 by sguilher          #+#    #+#             */
/*   Updated: 2021/06/10 06:03:56 by sguilher         ###   ########.fr       */
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
	while (str[i])
	{
		if (i == 0)
		{
			while (str[i] == '\n')
				i++;
		}
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
			return (1);
		}
		else
			new_l[j] = str[i];
		i++;
		j++;
	}
	new_l[j] = '\0';
	return (0);
}

int	ft_gnl(int fd, char *buf, char *new_l, char *tmp, char **line)
{
	int		n_read;

	n_read = read(fd, buf, BUFFER_SIZE);
	if (n_read <= 0)
		return (n_read);
	buf[n_read] = '\0';
	printf("read_return = %d\n", n_read);
	printf("%s\n", buf);
	*line = "";
	while (ft_split_new_line(buf, new_l, tmp) == 0)
	{
		*line = ft_strjoin(*line, new_l);
		printf("%s\n", *line);
		n_read = read(fd, buf, BUFFER_SIZE);
		if (n_read <= 0)
			return (n_read);
		buf[n_read] = '\0';
		printf("read_return = %d\n", n_read);
		printf("%s\n", buf);
	}
	free(buf);
	*line = ft_strjoin(*line, new_l);
	return(1); ///////
}

int	get_next_line(int fd, char **line)
{
	static char	*next_l = NULL;
	char		*buf;
	char		*new_l;
	char		*tmp;
	int			nl;

	if (fd < 0 || BUFFER_SIZE < 1 || line == NULL || fd > RLIMIT_NOFILE)
		return (-1);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	new_l = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	tmp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf || !new_l || !tmp)
		return (-1);
	if (next_l)
	{
		printf ("entendeu que tem residual antigo");
		if (ft_split_new_line(next_l, new_l, tmp) == 1)
		{
			*line = new_l;
			free(next_l);
			next_l = ft_strdup(tmp);
			free(tmp);
			free(buf);
			return (1);
		}
		else
		{
			ft_bzero(new_l, ft_strlen(new_l));
			nl = ft_gnl(fd, buf, new_l, tmp, line);
			if (nl < 1)
				return (nl);
			*line = ft_strjoin(next_l, *line);
			free(next_l);
			if (tmp)
				next_l = ft_strdup(tmp);
			free(tmp);
		}
	}
	nl = ft_gnl(fd, buf, new_l, tmp, line);
	if (nl < 1)
		return (nl);
	//if (tmp)
		next_l = ft_strdup(tmp);
	free(tmp);
	return (1);
}
