/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:57:13 by sguilher          #+#    #+#             */
/*   Updated: 2021/06/30 23:12:16 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_clean(char **str)
{
	if (str == NULL && !(*str))
		return ;
	if (*str)
		free(*str);
	*str = NULL;
}

int	check_new_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (NO_LINE_FEED);
}

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(char *s)
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

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	size;
	size_t	i;
	size_t	j;
	char	*join;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1 || !s1[0])
		return (ft_strdup(s2));
	else if (!s2 || !s2[0])
		return (ft_strdup(s1));
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
	join[i + j - 3] = '\0';
	return (join);
}
