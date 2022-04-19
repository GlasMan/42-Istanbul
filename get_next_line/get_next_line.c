/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:31:16 by scoskun           #+#    #+#             */
/*   Updated: 2022/01/31 12:24:34 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*first_to_read(int fd, char *new)
{
	char	*buff;
	int		read_bytes;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while ((!ft_strchr(new, '\n')) && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		new = ft_strjoin(new, buff);
	}
	free(buff);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*new;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	new = first_to_read(fd, new);
	if (!new)
		return (NULL);
	line = get_line(new);
	new = left_to_read(new);
	return (line);
}
/*
#include <fcntl.h>

int main()
{
    int fd;
    char *line;
    int i;

    i = 1;
    fd = open("deneme.txt", O_RDONLY);
    while (i < 5)
    {
        line = get_next_line(fd);
        printf("%s",line);
		free(line);
        i++;
    }
    close(fd);
    return (0);
}*/
