/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:58:51 by sguilher          #+#    #+#             */
/*   Updated: 2021/06/17 05:13:08 by sguilher         ###   ########.fr       */
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
#define LINE_NOT_OK(string)	"\033[1;31m" string "\033[0m"
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
			printf(LINE_NOT_OK("\n********** NOT OK at line %d **********\n\n"), line);
			printf(LINE("value that should be readed:       %s\n"), str1);
			printf(LINE_NOT_OK("your get_next_line function value: %s\n"), str2);
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
		if (gnl_ok == NOT_OK)
			return ;
		//printf(LINE("Line %d ") GNL_RET("[gnl return = %d]: ") LINE_RET("%s\n"), i, gnl, line);
		free(line);
		i++;
	}
	if (line != NULL && gnl == 0)
	{
		gnl_ok = check_line(str[i - 1], line, i);
		//printf(LINE("Line %d ") GNL_RET("[gnl return = %d]: ") LINE_RET("%s\n"), i, gnl, line);
		free(line);
	}
	if (gnl == 0)
		printf("EOF\n");
	if (gnl == -1)
		printf("Return Error\n");
	if (gnl_ok == OK)
		printf(LINE_OK("OK\n"));
	close(fd);
}

char	*ft_strdup_simple(char *s)
{
	char	*copy;
	size_t	i;
	size_t	size;

	size = ft_strlen(s) + 1;
	copy = (char *)malloc(size * sizeof(char));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < size - 1)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

void	test_hello2(void)
{
	char	*str[1];
	int		fd;

	printf(TITLE2("\nFile with a single line of size = 12 test\n"));
	printf(TITLE2("check for BUFFER_SIZE = 11, 12 and 13\n"));
	fd = open("file_tests/hello2.txt", O_RDONLY);
	str[0] = ft_strdup_simple("Hello World!");
	test_script(fd, str);
}

void	test_hello(void)
{
	char	*str[2];
	int		fd;

	printf(TITLE2("\nFile with a single line of size = 12 and one empty line test\n"));
	fd = open("file_tests/hello.txt", O_RDONLY);
	str[0] = ft_strdup_simple("Hello World!");
	str[1] = ft_strdup_simple("");
	test_script(fd, str);
}

void	test_hotel_diablo(void)
{
	char *str[12];
	int		fd;

	printf(TITLE2("\nFile with several lines test\n"));
	fd = open("file_tests/hotel_diablo", O_RDONLY);
	str[0] = ft_strdup_simple("");
	str[1] = ft_strdup_simple("Welcome, to Hotel Diablo!");
	str[2] = ft_strdup_simple("1");
	str[3] = ft_strdup_simple("2");
	str[4] = ft_strdup_simple("3jfhgkdh");
	str[5] = ft_strdup_simple("");
	str[6] = ft_strdup_simple("");
	str[7] = ft_strdup_simple("4");
	str[8] = ft_strdup_simple("5");
	str[9] = ft_strdup_simple("");
	str[10] = ft_strdup_simple("");
	str[11] = ft_strdup_simple("");
	test_script(fd, str);
}

void	test_empty_file(void)
{
	char	*str[1];
	int		fd;

	printf(TITLE2("\nEmpty line test\n"));
	fd = open("file_tests/empty_file", O_RDONLY);
	str[0] = ft_strdup_simple("");
	test_script(fd, str);
}

void	test_multiple_empty_line(void)
{
	char	*str[5];
	int		fd;

	printf(TITLE2("\nMultiple empty line test\n"));
	fd = open("file_tests/multiple_empty_line", O_RDONLY);
	str[0] = ft_strdup_simple("");
	str[1] = ft_strdup_simple("");
	str[2] = ft_strdup_simple("");
	str[3] = ft_strdup_simple("");
	str[4] = ft_strdup_simple("");
	test_script(fd, str);
}

void	test_single_long_line(void)
{
	char	*str[1];
	int		fd;

	printf(TITLE2("\nSingle long line test\n"));
	fd = open("file_tests/single_long_line", O_RDONLY);
	str[0] = ft_strdup_simple("pppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp");
	test_script(fd, str);
}

void	test_multiple_long_line(void)
{
	char	*str[6];
	int		fd;

	printf(TITLE2("\nMultiple long line test\n"));
	fd = open("file_tests/multiple_long_line", O_RDONLY);
	str[0] = ft_strdup_simple("pppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp");
	str[1] = ft_strdup_simple("pppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp");
	str[2] = ft_strdup_simple("pppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp");
	str[3] = ft_strdup_simple("");
	str[4] = ft_strdup_simple("pppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp");
	str[5] = ft_strdup_simple("");
	test_script(fd, str);
}

void	test_single_short_line1(void)
{
	char	*str[1];
	int		fd;

	printf(TITLE2("\nSingle short line 1 test\n"));
	fd = open("file_tests/single_short_line1", O_RDONLY);
	str[0] = ft_strdup_simple("1");
	test_script(fd, str);
}

void	test_single_short_line2(void)
{
	char	*str[1];
	int		fd;

	printf(TITLE2("\nSingle short line 2 test\n"));
	fd = open("file_tests/single_short_line2", O_RDONLY);
	str[0] = ft_strdup_simple("42");
	test_script(fd, str);
}

void	test_single_short_line3(void)
{
	char	*str[1];
	int		fd;

	printf(TITLE2("\nSingle short line 3 test\n"));
	fd = open("file_tests/single_short_line3", O_RDONLY);
	str[0] = ft_strdup_simple("424");
	test_script(fd, str);
}

void	test_single_short_line4(void)
{
	char	*str[1];
	int		fd;

	printf(TITLE2("\nSingle short line 4 test\n"));
	fd = open("file_tests/single_short_line4", O_RDONLY);
	str[0] = ft_strdup_simple("4244");
	test_script(fd, str);
}

void	test_multiple_short_line(void)
{
	char	*str[6];
	int		fd;

	printf(TITLE2("\nMultiple short line test\n"));
	fd = open("file_tests/multiple_short_line", O_RDONLY);
	str[0] = ft_strdup_simple("1");
	str[1] = ft_strdup_simple("42");
	str[2] = ft_strdup_simple("142");
	str[3] = ft_strdup_simple("4242");
	str[4] = ft_strdup_simple("");
	str[5] = ft_strdup_simple("42");
	test_script(fd, str);
}

void	test_arbitrary_fd(void)
{
	char	*str[1];
	int		fd;

	/* the result of this test should be: "Return error". */
	printf(TITLE2("\nArbitrary fd = 42 test\n"));
	fd = 42;
	str[0] = ft_strdup_simple("arbitrary fd = 42");
	test_script(fd, str);
}

void	test_scrpit2(int fd)
{
	char	*line;
	int		gnl;
	int		i;

	line = NULL;
	i = 1;
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		printf(LINE("Line %d ") GNL_RET("[gnl return = %d]: ") LINE_RET("%s\n"), i, gnl, line);
		free(line);
		i++;
	}
	if (line != NULL && gnl == 0)
	{
		printf(LINE("Line %d ") GNL_RET("[gnl return = %d]: ") LINE_RET("%s\n"), i, gnl, line);
		free(line);
	}
	if (gnl == 0)
		printf("EOF\n");
	if (gnl == -1)
		printf("Return Error\n");
	close(fd);
}

void	test_fd_stdin(void)
{
	int		fd;

	fd = 0;
	printf(TITLE2("\nfd = stdin test\n"));
	write(fd, "Type on your keyboard anything you want and finish with Ctrl+D:\n\n", 66);
	test_scrpit2(fd);
}

void	test_fd_stdout(void)
{
	int		fd;

	fd = 1;
	printf(TITLE2("\nfd = stdout test\n"));
	write(fd, "What is going to happen?\n\n", 27);
	test_scrpit2(fd);
}

void	test_binary_file(void)
{
	char	*line;
	int		gnl;
	int		i;
	int		fd;

	printf(TITLE2("\nBinary file test\n"));
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

	//test_hello2(); //ok
	//test_hello(); //ok
	//test_hotel_diablo(); //ok
	//test_empty_file(); //ok
	//test_multiple_empty_line(); //ok
	//test_single_long_line(); //ok quando sozinho
	test_multiple_long_line(); //not ok
	//test_single_short_line1(); //ok
	//test_single_short_line2(); //ok
	//test_single_short_line3(); //ok
	//test_single_short_line4(); //ok
	//test_multiple_short_line(); //ok
	//test_arbitrary_fd(); //ok
	//test_fd_stdin(); //ok
	//test_fd_stdout(); //ok

	//test_binary_file();

	return (0);

	// test 7: read from a redirection
}
