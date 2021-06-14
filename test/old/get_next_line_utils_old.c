/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:57:13 by sguilher          #+#    #+#             */
/*   Updated: 2021/06/09 20:27:19 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_first_str(char *s, int pos)
{
	int		i;
	char	*first_str;

	first_str = (char *)malloc(pos * sizeof(char));
	if (!first_str)
		return (NULL);
	i = 0;
	while (i < pos && s[i])
	{
		first_str[i] = s[i];
		i++;
	}
	first_str[i] = '\0';
	return (first_str);
}

char	*ft_last_str(char *s, int pos)
{
	size_t	i;
	size_t	len;
	char	*last_str;

	len = ft_strlen(s);
	last_str = (char *)malloc((len - pos + 1) * sizeof(char));
	if (!last_str)
		return (NULL);
	i = 0;
	while (i < (len - pos + 1) && s[pos + i + 1])
	{
		last_str[i] = s[pos + i + 1];
		i++;
	}
	last_str[i] = '\0';
	return (last_str);
}

char	*ft_strdup(char *s)
{
	char	*copy;
	size_t	i;
	size_t	size;

	size = ft_strlen(s) + 1;
	copy = (char *)malloc(size * sizeof(char));
	if (copy)
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
	if (!s1 || !s1[0])
		return (ft_strdup(s2));
	if (!s2 || !s2[0])
		return (ft_strdup(s1));
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = (char *)malloc(size * sizeof(char));
	if (!join)
		return (NULL);
	i = -1;
	while (++i < ft_strlen(s1) && s1[i])
		join[i] = s1[i];
	j = -1;
	while (++j + i < size)
		join[i + j] = s2[j];
	join[i + j] = '\0';
	return (join);
}
