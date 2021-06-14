/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:58:51 by sguilher          #+#    #+#             */
/*   Updated: 2021/06/14 05:26:05 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

#define TITLE1(string)		"\033[1;33m" string "\033[0m"
#define TITLE2(string)		"\033[1;33m" string "\033[0m"
#define LINE(string)		"\033[1;32m" string "\033[0m"
#define LINE_RET(string)	"\033[1;31m" string "\033[0m"

void	test_script(int fd)
{
	char	*line;
	int		gnl;
	int		i;

	line = NULL;
	i = 1;
	printf("fd = %d\n", fd);
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		printf(LINE("Line %d : ") LINE_RET("%s\n"), i, line);
		ft_clean(line);
		line = NULL;
		i++;
	}
	if (gnl == 0)
		printf("EOF\n");
	if (gnl == -1)
		printf("error\n");
	close(fd);
}

int	main(void)
{
	int		fd;

	printf(TITLE1("***** Get Next Line Tester *****\n"));

	printf(TITLE2("File with a single line of size = 12\n"));
	fd = open("file_tests/hello2.txt", O_RDONLY);
	test_script(fd);

	printf(TITLE2("File with a single line of size = 12 and one empty line\n"));
	fd = open("file_tests/hello.txt", O_RDONLY);
	test_script(fd);

	printf(TITLE2("File with several lines\n"));
	fd = open("file_tests/hotel_diablo", O_RDONLY);
	test_script(fd);

	printf(TITLE2("Empty line\n"));
	fd = open("file_tests/empty_file", O_RDONLY);
	test_script(fd);

	printf(TITLE2("Multiple empty line\n"));
	fd = open("file_tests/empty_file_multiple_empty_line", O_RDONLY);
	test_script(fd);

	/*printf(TITLE2("Single long line\n"));
	fd = open("file_tests/single_long_line", O_RDONLY);
	test_script(fd);

	printf(TITLE2("Multiple long line\n"));
	fd = open("file_tests/multiple_long_line", O_RDONLY);
	test_script(fd);*/

	printf(TITLE2("Single short line 1\n"));
	fd = open("file_tests/single_short_line1", O_RDONLY);
	test_script(fd);

	printf(TITLE2("Single short line 2\n"));
	fd = open("file_tests/single_short_line2", O_RDONLY);
	test_script(fd);

	printf(TITLE2("Single short line 3\n"));
	fd = open("file_tests/single_short_line3", O_RDONLY);
	test_script(fd);

	printf(TITLE2("Single short line 4\n"));
	fd = open("file_tests/single_short_line4", O_RDONLY);
	test_script(fd);

	printf(TITLE2("Multiple short line\n"));
	fd = open("file_tests/multiple_short_line", O_RDONLY);
	test_script(fd);

	printf(TITLE2("Binary file\n"));
	fd = open("file_tests/binary_file", O_RDONLY);
	test_script(fd);

	return (0);



	// test 4: fd = stdin = 0
	// test 7: read from a redirection
	// test 7: send a new line to the standard output
}
