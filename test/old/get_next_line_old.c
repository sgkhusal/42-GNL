/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_old.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:57:10 by sguilher          #+#    #+#             */
/*   Updated: 2021/06/09 20:03:53 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_have_c(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

void	ft_bzero(void *s, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *)s;
	while (i < len)
		ptr[i++] = '\0';
}

int	get_next_line(int fd, char **line)
{
	static char	*tmp = NULL;
	int			n_read;
	int			pos;
	char		*buf;
	char		*l;

	if (fd < 0 || BUFFER_SIZE < 1 || line == NULL || fd > RLIMIT_NOFILE)
		return (-1);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (-1);
	// incializing tmp
	if (!tmp)
		tmp = ft_strdup("");
	if (ft_have_c(tmp, '\n') > 0)
	{
		pos = ft_have_c(tmp, '\n');
		l = ft_first_str(tmp, pos);
		tmp = ft_strdup(ft_last_str(tmp, pos));
	}
	//reading the file
	n_read = read(fd, buf, BUFFER_SIZE);
	while (n_read > 0)
	{
		buf[n_read] = '\0';
		if (ft_have_c(buf, '\n') == 0)
		{
			pos = ft_have_c(buf, '\n');
			tmp = ft_strjoin(tmp, buf);
			ft_bzero(buf, BUFFER_SIZE + 1);
		}
		else
		{
			tmp = ft_strjoin(tmp, ft_first_str(buf, pos));
			l = ft_strdup(tmp);
			*line = l;
			free(tmp);
			tmp = ft_strdup(ft_last_str(buf, pos));
			free(buf);
			return (1);
		}
		n_read = read(fd, buf, BUFFER_SIZE);
	}
	printf("read_return = %d\n", n_read); ////////
	if (n_read == 0)
		return (0); // indicates EOF
	if (n_read == -1)
		return (-1);
	tmp = ft_strjoin(tmp, ft_first_str(buf, pos));
	l = ft_strdup(tmp);
	*line = l;
	free(tmp);
	tmp = ft_strdup(ft_last_str(buf, pos));
	free(buf);
	return (1);
}
