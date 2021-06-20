/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:57:13 by sguilher          #+#    #+#             */
/*   Updated: 2021/06/19 22:28:51 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_clean(char **str)
{
	if (str == NULL && !(*str))
		return ;
	if (*str)
		free(*str);
	*str = NULL;
}

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	ft_bzero(char *s, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		s[i++] = '\0';
}

char	*ft_strdup(char *s, int clean)
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
	if (clean == 1 && s)
		ft_clean(&s);
	return (copy);
}

char	*ft_strjoin(char *s1, char *s2, int clean)
{
	size_t	size;
	size_t	i;
	size_t	j;
	char	*join;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1 || !s1[0])
		return (ft_strdup(s2, NO_CLEAN));
	else if (!s2 || !s2[0])
		return (ft_strdup(s1, NO_CLEAN));
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = (char *)malloc(size * sizeof(char));
	if (!join)
		return (NULL);
	i = 0;
	while (++i - 1 < ft_strlen(s1) && s1[i - 1])
		join[i - 1] = s1[i - 1];
	j = 0;
	while (++j - 1 + i - 1 < size)
		join[i + j - 2] = s2[j - 1];
	join[i + j - 2] = '\0';
	if (clean == 1 && s1) ///
		ft_clean(&s1);
	return (join);
}
