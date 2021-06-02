/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:58:51 by sguilher          #+#    #+#             */
/*   Updated: 2021/06/02 23:02:43 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
# include <stdlib.h>

int	main(void){
	//int		buffer_size = 5;
	int		fd;
	char	*line = NULL;
	int		gnl;


	fd = open("hello.txt", O_RDONLY);
	gnl = get_next_line(fd, &line);
	printf("%s\n", line);
	gnl = get_next_line(fd, &line);
	printf("%s\n", line);
	close(fd);
	return(0);

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
