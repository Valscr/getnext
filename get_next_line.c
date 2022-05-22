/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:19:24 by vescaffr          #+#    #+#             */
/*   Updated: 2022/05/22 13:15:39 by vescaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

size_t  ft_strlen(char *s)
{
        size_t  i;

        i = 0;
        if (!s)
                return (0);
        while (s[i] != '\0')
                i++;
        return (i);
}

char    *create_dest()
{
        char    *s;

        s = malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if (!s)
                return (0);
        return (s);
}

int     check_end(char *dest, int j)
{
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
	if (!dest)
		return (0);
	while (s1[i] != '\0')
	{	
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		dest[i++] = s2[j++];
	dest[i] = '\0';
	return (dest);
}

char	*ft_cut_dest(char *dest, int f)
{
	char	*s;
	int	j;
	int	d;
	int	size;
	
	d = 0;
	j = f;
	while (dest[f] != '\n' && dest[f] != '\0')
		f++;
	size = f - j + 1;
	s = malloc(sizeof(char) * (size));
	while (d < size)
		s[d++] = dest[j++];
	s[d] = '\0';
	free(dest);
	return (s);
}

char	*get_next_line(int fd)
{
	char	*dest;
	char	*s;
	static int	i;

        if (BUFFER_SIZE < 0 || fd < 0 || read(fd, &dest, 0) < 0)
		return (0);
	dest = malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if (!dest)
                return (0);
        read(fd, dest, BUFFER_SIZE);
        while (check_end(dest, i))
        { 
		s = create_dest();
		if(read(fd, s, BUFFER_SIZE) == 0)
		{
			dest = ft_strjoin(dest, s);
			free(s);
			break;
		}
		dest = ft_strjoin(dest, s);
		free(s);
	}
	dest = ft_cut_dest(dest, i);
	i += ft_strlen(dest);
	return (dest);
}

int	main()
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
}
