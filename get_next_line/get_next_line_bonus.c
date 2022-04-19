/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:53:48 by scoskun           #+#    #+#             */
/*   Updated: 2022/01/26 12:32:14 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*new[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	new[fd] = first_to_read(fd, new[fd]);
	if (!new[fd])
		return (NULL);
	line = get_line(new[fd]);
	new[fd] = left_to_read(new[fd]);
	return (line);
}
/*
#include <fcntl.h>
int main()
{
    int fd;
    int fd1;
	int fd2;
    char *line;
    int i;

    i = 1;
    fd = open("deneme.txt", O_RDONLY);
    fd1 = open("deneme1.txt", O_RDONLY);
    fd2 = open("deneme3.txt", O_RDONLY);
   	printf("%d\n", fd);
    printf("%d\n", fd1);
	printf("%d\n", fd2);
	printf("%d\n", BUFFER_SIZE);
    while (fd <= 5)
    {
		while(i <= 7)
		{
        	line = get_next_line(fd);
        	printf(" [%d] %s", i,line);
			free(line);
        	i++;
		}
		printf("\n");
		i = 1;
		fd++;
    }
    close(fd);
    return (0);
}*/
