/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:58:51 by sguilher          #+#    #+#             */
/*   Updated: 2021/03/14 20:09:26 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	int		gnl;
	int		i;
	char	**line;

	// test 1: file with several lines
	if (!(fd1 = open("text01", O_RDONLY)))
	{
		printf("Error - file reading");
		return (1);
	}
	/* get next line return:
	return (1); // a line has been read
	return (0); // EOF has been reached
	return (-1); // an error happened
	*/
	i = 1;
	while (gnl = get_next_line(fd1, line) >= 0)
	{
		printf("line %i = %s\n", i, *line);
		i++;
		if (gnl = 0)
			printf("EOF\n");
	}

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

	return (0);
}
