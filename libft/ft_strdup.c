/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:42:46 by scoskun           #+#    #+#             */
/*   Updated: 2022/01/05 19:20:28 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*new;
	size_t	i;

	i = 0;
	len = ft_strlen(s1) + 1;
	new = (char *) malloc((sizeof(char) * len));
	if (!new)
		return (0);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
/*
#include <stdio.h>

int main()
{
	char a[] = "seawdwadawdlan";
	char *b = ft_strdup(a);

	printf("%s",b);
}*/
