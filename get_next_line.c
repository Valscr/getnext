/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:19:24 by vescaffr          #+#    #+#             */
/*   Updated: 2022/05/25 02:35:48 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

int	check_end(char *dest)
{
	int	j;

	j = 0;
	if (!dest)
		return (1);
	while (dest[j] != '\0')
	{
		if (dest[j] == '\n')
			return (0);
		j++;
	}
	return (1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		size;
	int		i;
	char	*dest;
	int		j;

	i = 0;
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	dest = malloc(sizeof(char) * size);
	if (!dest || !s2)
		return (NULL);
	if (s1 != NULL)
	{
		while (s1[i] != '\0')
		{	
			dest[i] = s1[i];
			i++;
		}
	}
	j = 0;
	while (s2[j] != '\0')
		dest[i++] = s2[j++];
	dest[i] = '\0';
	free(s1);
	return (dest);
}

char	*ft_cut_dest(char *dest)
{
	char	*s;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!dest[i])
		return (NULL);
	while (dest[i] != '\0' && dest[i] != '\n')
		i++;
	s = malloc(sizeof(char) * i + 2);
	while (j < i)
	{
		s[j] = dest[j];
		j++;
	}
	if (dest[j] == '\n')
	{
		s[j] = dest[j];
		j++;
	}
	s[j] = '\0';
	return (s);
}

char	*new_s(char *dest)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (dest[i] && dest[i] != '\n')
		i++;
	if (!dest[i])
	{
		free(dest);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(dest) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (dest[i])
		str[j++] = dest[i++];
	str[j] = '\0';
	free(dest);
	return (str);
}

char	*get_next_line(int fd)
{
	char			*dest;
	static char		*save;
	int				bytes;
	char			*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	dest = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!dest)
		return (0);
	bytes = 1;
	while (check_end(save) && bytes != 0)
	{
		bytes = read(fd, dest, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(dest);
			return (NULL);
		}
		dest[bytes] = '\0';
		save = ft_strjoin(save, dest);
	}
	line = ft_cut_dest(save);
	save = new_s(save);
	free(dest);
	return (line);
}

/*int	main(void)
{
	int	fd1;
	int	fd2;
	int	fd3;
	int	fd4;
	int	fd5;
	int	fd6;

	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test.txt", O_RDONLY);
	fd3 = open("test.txt", O_RDONLY);
	fd4 = open("test.txt", O_RDONLY);
	fd5 = open("test.txt", O_RDONLY);
	fd6 = open("test.txt", O_RDONLY);

	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd3));
	printf("%s", get_next_line(fd4));
	printf("%s", get_next_line(fd5));
	printf("%s", get_next_line(fd6));
	return (0);
}*/
