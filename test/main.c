/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:58:51 by sguilher          #+#    #+#             */
/*   Updated: 2021/06/15 06:07:22 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

#define TITLE1(string)		"\033[1;33m" string "\033[0m"
#define TITLE2(string)		"\033[0;32m" string "\033[0m"
#define LINE(string)		"\033[38;5;75m" string "\033[0m"
#define GNL_RET(string)		"\033[38;5;43m" string "\033[0m"
#define LINE_RET(string)	"\033[0;33m" string "\033[0m"
#define LINE_NOT_OK(string)	"\033[0;31m" string "\033[0m"
#define LINE_OK(string)		"\033[1;32m" string "\033[0m"

#define NOT_OK	0
#define OK		1

int	check_line(char *str1, char *str2, int line)
{
	size_t	i = 0;

	while (i < ft_strlen(str2))
	{
		if (str1[i] != str2[i])
		{
			printf(LINE("NOT OK at line %d\n"), line);
			printf(LINE("value that should be readed: %s\n"), str1);
			printf(LINE("your function value:         ") LINE_NOT_OK("%s\n"), str2);
			return(NOT_OK);
		}
		i++;
	}
	return (OK);
}

void	test_script(int fd, char **str)
{
	char	*line;
	int		gnl;
	int		i;
	int		gnl_ok;

	line = NULL;
	i = 1;
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		gnl_ok = check_line(str[i - 1], line, i);
		//printf(LINE("Line %d ") GNL_RET("[gnl return = %d]: ") LINE_RET("%s\n"), i, gnl, line);
		free(line);
		if (gnl_ok == NOT_OK)
			return ;
		i++;
	}
	if (line != NULL && gnl == 0)
	{
		gnl_ok = check_line(str[i - 1], line, i);
		//printf(LINE("Line %d ") GNL_RET("[gnl return = %d]: ") LINE_RET("%s\n"), i, gnl, line);
		free(line);
	}
	if (gnl_ok == OK)
		printf(LINE_OK("OK\n"));
	if (gnl == 0)
		printf("EOF\n");
	if (gnl == -1)
		printf("error\n");
	close(fd);
}

void	test_hello2()
{
	char	*str[1];
	int		fd;

	printf(TITLE2("File with a single line of size = 12 test\n"));
	printf(TITLE2("check for BUFFER_SIZE = 11, 12 and 13\n"));
	fd = open("file_tests/hello2.txt", O_RDONLY);
	str[0] = ft_strdup("Hello World!");
	test_script(fd, str);
}

void	test_hello()
{
	char	*str[2];
	int		fd;

	printf(TITLE2("File with a single line of size = 12 and one empty line test\n"));
	fd = open("file_tests/hello.txt", O_RDONLY);
	str[0] = ft_strdup("Hello World!");
	str[1] = ft_strdup("");
	test_script(fd, str);
}

void	test_hotel_diablo()
{
	char *str[12];
	int		fd;

	printf(TITLE2("File with several lines test\n"));
	fd = open("file_tests/hotel_diablo", O_RDONLY);
	str[0] = ft_strdup("");
	str[1] = ft_strdup("Welcome, to Hotel Diablo!");
	str[2] = ft_strdup("1");
	str[3] = ft_strdup("2");
	str[4] = ft_strdup("3jfhgkdh");
	str[5] = ft_strdup("");
	str[6] = ft_strdup("");
	str[7] = ft_strdup("4");
	str[8] = ft_strdup("5");
	str[9] = ft_strdup("");
	str[10] = ft_strdup("");
	str[11] = ft_strdup("");
	test_script(fd, str);
}

void	test_empty_file()
{
	char	*str[1];
	int		fd;

	printf(TITLE2("Empty line test\n"));
	fd = open("file_tests/empty_file", O_RDONLY);
	str[0] = ft_strdup("");
	test_script(fd, str);
}

void	test_multiple_empty_line()
{
	char	*str[5];
	int		fd;

	printf(TITLE2("Multiple empty line test\n"));
	fd = open("file_tests/multiple_empty_line", O_RDONLY);
	str[0] = ft_strdup("");
	str[1] = ft_strdup("");
	str[2] = ft_strdup("");
	str[3] = ft_strdup("");
	str[4] = ft_strdup("");
	test_script(fd, str);
}

void	test_single_long_line()
{
	char	*str[1];
	int		fd;

	printf(TITLE2("Single long line test\n"));
	fd = open("file_tests/single_long_line", O_RDONLY);
	str[0] = ft_strdup("pppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp");
	test_script(fd, str);
}

void	test_multiple_long_line()
{
	char	*str[6];
	int		fd;

	printf(TITLE2("Multiple long line test\n"));
	fd = open("file_tests/multiple_long_line", O_RDONLY);
	str[0] = ft_strdup("pppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp");
	str[1] = ft_strdup("pppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp");
	str[2] = ft_strdup("pppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp");
	str[3] = ft_strdup("");
	str[4] = ft_strdup("pppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp");
	str[5] = ft_strdup("");
	test_script(fd, str);
}

void	test_single_short_line1()
{
	char	*str[1];
	int		fd;

	printf(TITLE2("Single short line 1 test\n"));
	fd = open("file_tests/single_short_line1", O_RDONLY);
	str[0] = ft_strdup("1");
	test_script(fd, str);
}

void	test_single_short_line2()
{
	char	*str[1];
	int		fd;

	printf(TITLE2("Single short line 2 test\n"));
	fd = open("file_tests/single_short_line2", O_RDONLY);
	str[0] = ft_strdup("42");
	test_script(fd, str);
}

void	test_single_short_line3()
{
	char	*str[1];
	int		fd;

	printf(TITLE2("Single short line 3 test\n"));
	fd = open("file_tests/single_short_line3", O_RDONLY);
	str[0] = ft_strdup("424");
	test_script(fd, str);
}

void	test_single_short_line4()
{
	char	*str[1];
	int		fd;

	printf(TITLE2("Single short line 4 test\n"));
	fd = open("file_tests/single_short_line4", O_RDONLY);
	str[0] = ft_strdup("4244");
	test_script(fd, str);
}

void	test_multiple_short_line()
{
	char	*str[6];
	int		fd;

	printf(TITLE2("Multiple short line test\n"));
	fd = open("file_tests/multiple_short_line", O_RDONLY);
	str[0] = ft_strdup("1");
	str[1] = ft_strdup("42");
	str[2] = ft_strdup("142");
	str[3] = ft_strdup("4242");
	str[4] = ft_strdup("");
	str[5] = ft_strdup("42");
	test_script(fd, str);
}

void	test_binary_file()
{
	char	*line;
	int		gnl;
	int		i;
	int		fd;

	printf(TITLE2("Binary file test\n"));
	fd = open("file_tests/binary_file", O_RDONLY);
	line = NULL;
	i = 1;
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		printf(LINE("Line %d ") GNL_RET("[gnl return = %d]: ") LINE_RET("%s\n"), i, gnl, line);
		free(line);
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
	printf(TITLE1("***** Get Next Line Tester *****\n"));

	test_hello2();
	test_hello();
	test_hotel_diablo();
	test_empty_file();
	test_multiple_empty_line();
	//test_single_long_line();
	//test_multiple_long_line();
	test_single_short_line1();
	test_single_short_line2();
	test_single_short_line3();
	test_single_short_line4();
	test_multiple_short_line();
	test_binary_file();

	return (0);

	// test 4: fd = stdin = 0
	// test 7: read from a redirection
	// test 7: send a new line to the standard output
}
