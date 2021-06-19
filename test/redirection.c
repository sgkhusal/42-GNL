/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 07:00:03 by sguilher          #+#    #+#             */
/*   Updated: 2021/06/19 17:04:30 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(void)
{
	char	*line;
	int		gnl;
	int		i;
	int		fd;

	line = NULL;
	i = 1;
	fd = 0;
	printf(TITLE1("***** Get Next Line Tester - fd Redirection*****\n"));
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
	if (gnl == -1 && (BUFFER_SIZE < 1 || fd < 0 || fd > OPEN_MAX))
		printf(LINE_OK("OK\n"));
	close(fd);

	return (0);
}
