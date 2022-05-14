/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:19:24 by vescaffr          #+#    #+#             */
/*   Updated: 2022/05/14 17:21:35 by vescaffr         ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	static char	*dest;
	int	j;
	static int	i;
	static ssize_t	a;
	static int	turn;
	char	*s;
	int	d;
	int	size;

	j = 0;
	if (turn == 0)
	{
                dest = malloc(sizeof(char) * (1000));
		if (!dest)
                	return (0);
		a = read(fd, dest, 1000);
	}
	turn++;
	d = i;
	while (dest[d] != '\n')
		d++;
	size = d - i;
	s = malloc(sizeof(char) * (size + 1));
	while (j < size) 
	{
		s[j++] = dest[i++];
		if (i == a)
		{
			s[j] = '\0';
			i = 0;
			return (s);
		}
		if (j == BUFFER_SIZE && turn > 1)
		{
			i = 0;
		}	
	}
	if (i > BUFFER_SIZE)
		i = 0;
	else
		i++;
	if (dest[i] == '\n')
		i++;
	s[j] = '\n';
	s[++j] = '\0';
	return (s);
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
