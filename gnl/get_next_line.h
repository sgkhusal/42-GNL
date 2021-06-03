/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:57:23 by sguilher          #+#    #+#             */
/*   Updated: 2021/06/03 06:19:15 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
//# define BUFFER_SIZE 32 /////////////////////////////////////////////

# include <unistd.h>
# include <stdlib.h>
# include <sys/resource.h>
# include <stdio.h> //////////////////////////////////////////////TIRAR

typedef struct s_line
{
	char			*content;
	struct s_line	*next;
}				t_list;

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
char	*ft_last_str(char *s, int pos);
char	*ft_first_str(char *s, int pos);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);

#endif
