/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:57:10 by sguilher          #+#    #+#             */
/*   Updated: 2021/05/17 22:05:49 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static int	i = 0;
	int			count;
	char		*buffer[BUFFER_SIZE + 1];

	if (!(*buffer = malloc(BUFFER_SIZE * sizeof(char))))
		return (-1);
	if (count = read(fd, buffer, BUFFER_SIZE) > 0) // read function returns the number of bytes readed
	{

	}

	return (1); // a line has been read
	return (0); // EOF has been reached
	return (-1); // an error happened
}
