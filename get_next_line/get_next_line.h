/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouati <mlouati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:59:06 by mlouati           #+#    #+#             */
/*   Updated: 2024/08/04 08:17:08 by mlouati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

char	*ft_strjoin_gnl(char *dest, char *src);
int		ft_strlen_gnl(const char *str);
int		check_new_line(char *ptr);
char	*ft_update(char *next_line);
char	*ft_read(char *next_line, int fd);
char	*extract_line(char *next_line);
char	*get_next_line(int fd);
int		until_newline(const char *str);
#endif