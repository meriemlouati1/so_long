/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouati <mlouati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 23:07:25 by mlouati           #+#    #+#             */
/*   Updated: 2024/08/02 12:20:59 by mlouati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

int		ft_strlen(char *str);
int		ft_strncmp(char *s1, char *s2, int n);
void	*ft_memcpy(void *dest, void *src, int n);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	**ft_split(char *s, char c);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);

#endif
