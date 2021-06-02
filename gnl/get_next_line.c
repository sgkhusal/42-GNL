/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:57:10 by sguilher          #+#    #+#             */
/*   Updated: 2021/06/02 23:35:07 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	//static int	size = 0;
	int		nread;
	char	*buf;

	//check fd value
	if(fd == -1) // || fd > RLIMIT_NOFILE)
	{
		printf("open error\n");
		return (-1);
	}
	printf("fd = %d\n", fd);

	//check BUFFER_SIZE value
	if(BUFFER_SIZE < 1)
	{
		printf("BUFFER_SIZE error\n");
		return (-1);
	}

	//check memory allocation for buf
	if(!(buf = (char *)malloc((BUFFER_SIZE + 1)* sizeof(char))))
	{
		printf("malloc error\n");
		return (-1);
	}
	buf[BUFFER_SIZE] = '\0';
	if((nread = read(fd, buf, BUFFER_SIZE)) == -1)
	{
		printf("read error\n");
		return (0);
	}
	printf("read_return = %d\n", nread);
	buf[BUFFER_SIZE + 1] = '\0';
	*line = buf;
	printf("%s\n", *line);
	//free(buf);
	return (1);
}
