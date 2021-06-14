/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:57:23 by sguilher          #+#    #+#             */
/*   Updated: 2021/06/14 02:28:01 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
//# define BUFFER_SIZE 10 /////////////////////////////////////////////

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h> //////////////////////////////////////////////TIRAR

typedef struct s_gnl
{
	char	*content;
	char	*next;
}				t_gnl;

int		get_next_line(int fd, char **line);
void	ft_clean(char *str);
size_t	ft_strlen(char *str);
void	ft_bzero(char *s, size_t len);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2, int clean);

#endif
