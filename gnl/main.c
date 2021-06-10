/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:58:51 by sguilher          #+#    #+#             */
/*   Updated: 2021/06/10 20:52:41 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*line;
	int		fd;
	int		gnl;

	//*line = NULL;
	fd = open("hotel_diablo", O_RDONLY);
	printf("fd = %d\n", fd);
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		printf("resultado na main: %s\n", line);
	}
	if (gnl == 0)
		printf("EOF\n");
	if (gnl == -1)
		printf("error\n");
	close(fd);
	return (0);
	// test 1: file with several lines
	// test 2: file with a single line
	// test 3: empty file
	// test 4: fd = stdin = 0
	// test 5: BUFFER_SIZE = 1
	// test 6: BUFFER_SIZE = 0
	// test 7: BUFFER_SIZE < 0
	// test 7: BUFFER_SIZE = 9999
	// test 7: BUFFER_SIZE = 10000000
	// test 7: read from a redirection
	// test 7: send a new line to the standard output
}
