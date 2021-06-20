/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:57:23 by sguilher          #+#    #+#             */
/*   Updated: 2021/06/19 20:57:19 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
//# define BUFFER_SIZE 10 /////////////////////////////////////////////

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h> //////////////////////////////////////////////TIRAR

# define READ_NOT_OK -1
# define READ_OK 1
# define REACHED_EOF 0
# define MALLOC_ERROR -1
# define INPUT_ERROR -1
# define FOUND_LINE_FEED 1
# define NO_LINE_FEED 0
# define CLEAN 1
# define NO_CLEAN 0

int		get_next_line(int fd, char **line);
void	ft_clean(char **str);
size_t	ft_strlen(char *str);
void	ft_bzero(char *s, size_t len);
char	*ft_strdup(char *s, int clean);
char	*ft_strjoin(char *s1, char *s2, int clean);

#endif
