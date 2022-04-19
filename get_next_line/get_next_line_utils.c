/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:32:07 by scoskun           #+#    #+#             */
/*   Updated: 2022/01/31 12:24:36 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

char	*get_line(char *new)
{
	int		i;
	char	*line;

	i = 0;
	if (!new[i])
		return (NULL);
	while (new[i] != '\n' && new[i])
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (new[i] != '\n' && new[i] != '\0')
	{
		line[i] = new[i];
		i++;
	}
	if (new[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*left_to_read(char *next)
{
	int		i;
	int		j;
	char	*left;

	i = 0;
	j = 0;
	while (next[i] != '\n' && next[i] != '\0')
		i++;
	if (!next[i])
	{
		free(next);
		return (NULL);
	}
	left = (char *)malloc(sizeof(char) * (ft_strlen(next) - i + 1));
	if (!left)
		return (NULL);
	i++;
	while (next[i] != '\0')
		left[j++] = next[i++];
	left[j] = '\0';
	free(next);
	return (left);
}
