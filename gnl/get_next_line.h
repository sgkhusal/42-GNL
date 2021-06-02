/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:57:23 by sguilher          #+#    #+#             */
/*   Updated: 2021/06/02 22:58:24 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
//# define BUFFER_SIZE 32 /////////////////////////////////////////////

# include <unistd.h>
# include <stdlib.h>
#include <stdio.h> //////////////////////////////////////////////TIRAR

typedef struct	s_line
{
	char			*content;
	struct s_line	*next;
}				t_list;

int	get_next_line(int fd, char **line);
t_list	*ft_lstnew(void *content);

#endif
