/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:58:49 by sguilher          #+#    #+#             */
/*   Updated: 2021/06/19 17:44:52 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	call_gnl(int fd)
{
	static int	l[OPEN_MAX];
	char		*line;
	int			gnl;
	int			i;

	line = NULL;
	i = 1;
	if (!l[fd])
		l[fd] = 1;
	while (i < 6)
	{
		gnl = get_next_line(fd, &line);
		printf(LINE("Line %d ") GNL_RET("[gnl return = %d]: ") LINE_RET("%s\n"), l[fd], gnl, line);
		free(line);
		i++;
		l[fd]++;
		if (gnl == 0)
		{
			printf("EOF\n");
			i = 6;
		}
	}
	if (gnl == -1)
		printf("Return Error\n");
}

int	main(void)
{
	int		fd1;
	int		fd2;

	printf(TITLE1("***** Get Next Line Tester *****\n"));
	printf(TITLE2("\nMultiple file descriptors test\n"));

	fd1 = open("file_tests/harry_potter1", O_RDONLY);
	fd2 = open("file_tests/harry_potter2", O_RDONLY);

	printf(TITLE2("\nFile 1:\n"));
	call_gnl(fd1);
	printf(TITLE2("\nFile 2:\n"));
	call_gnl(fd2);

	printf(TITLE2("\nCall file 1 again:\n"));
	call_gnl(fd1);

	printf(TITLE2("\nCall file 2 again:\n"));
	call_gnl(fd2);

	close(fd1);
	close(fd2);

	return (0);
}