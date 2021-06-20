/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 05:38:04 by sguilher          #+#    #+#             */
/*   Updated: 2021/06/20 06:19:42 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	check_error(int fd)
{
	char	*line;
	int		gnl;

	line = NULL;
	gnl = get_next_line(fd, &line);
	if (gnl == -1)
	{
		printf(" - Return Error");
		printf(LINE_OK(" - OK\n"));
	}
	else
		printf(LINE_NOT_OK("\nNOT OK - should have returned -1\n"));
}

void	test_arbitrary_fd(void)
{
	/* the result of this test should be: "Return error". */
	printf(TITLE1("Test 1: ") TITLE2("Arbitrary fd = 42 test"));
	check_error(42);
}

void	test_fd_limits(void)
{
	/* the result of this test should be: "Return error". */
	printf(TITLE1("Test 2.1: ") TITLE2("fd limit test - fd < 0"));
	check_error(-1);
	printf(TITLE1("Test 2.2: ") TITLE2("fd limit test - fd > %d"), OPEN_MAX);
	check_error(OPEN_MAX + 1);
}

void	test_scrpit(int fd)
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
		printf("EOF");
	if (gnl == -1)
		printf("Return Error");
	if (gnl == -1 && (BUFFER_SIZE < 1 || fd < 0 || fd > OPEN_MAX))
		printf(LINE_OK(" - OK\n"));
}

void	test_stdin(void)
{
	int		fd;

	fd = 0;
	printf(TITLE1("Test 3: ") TITLE2("fd = stdin test\n"));
	write(fd, "Type on your keyboard anything you want and finish with Ctrl+D:\n", 65);
	test_scrpit(fd);
}

void	test_stdout(void)
{
	int		fd;

	fd = 1;
	printf(TITLE1("\nTest 4: ") TITLE2("fd = stdout test\n"));
	write(fd, "Type on your keyboard anything you want and finish with Ctrl+D:\n", 65);
	test_scrpit(fd);
}

int	main(void)
{
	printf(TITLE1("***** File Descriptors Get Next Line Tester *****\n\n"));

	test_arbitrary_fd(); //ok
	test_fd_limits();
	test_stdin(); //ok
	test_stdout(); //ok

	return (0);
}