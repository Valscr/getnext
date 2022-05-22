/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:19:24 by vescaffr          #+#    #+#             */
/*   Updated: 2022/05/22 10:48:32 by vescaffr         ###   ########.fr       */
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

char    *create_dest()
{
        char    *s;

        s = malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if (!s)
                return (0);
        return (s);
}

int     check_end(char *dest, int i)
{
        while (dest[i] != '\0')
        {
                if (dest[i] == '\n')
                        return (0);
                i++;
        }
        return (1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	int		i;
	char	*dest;
	int		j;

	i = 0;
	size = strlen(s1) + strlen(s2) + 1;
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

char	*get_next_line(int fd)
{
	char	*dest;
	static int	i;

        if (BUFFER_SIZE < 0 || fd < 0 || read(fd, &dest, 0) < 0)
		return (0);
	dest = malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if (!dest)
                return (0);
        read(fd, dest, BUFFER_SIZE);
        while (check_end(dest, i))
        { 
	       read(fd, dest, BUFFER_SIZE);
		read(fd, new,
               dest = ft_strjoin(dest, create_dest());
		printf("deest = %s\n", dest);
	}
	while (dest[i] != '\n')
	{
		i++;
	}
	dest[++i] = '\0';         
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
