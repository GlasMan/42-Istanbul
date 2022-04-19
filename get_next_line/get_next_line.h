/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:46:05 by scoskun           #+#    #+#             */
/*   Updated: 2022/01/26 18:03:29 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*get_line(char *new);
char	*left_to_read(char *next);
char	*get_next_line(int fd);
char	*first_to_read(int fd, char *new);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1

# endif

#endif
