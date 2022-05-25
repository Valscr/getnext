/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 02:04:30 by vescaffr          #+#    #+#             */
/*   Updated: 2022/05/25 04:00:56 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

size_t	ft_strlen(char *s);
int		check_end(char *dest);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_cut_dest(char *dest);
char	*new_save(char *dest);
char	*get_next(char *save, int fd);
char	*get_next_line(int fd);

#endif
