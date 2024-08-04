/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouati <mlouati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:59:01 by mlouati           #+#    #+#             */
/*   Updated: 2024/08/03 13:35:05 by mlouati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	until_newline(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] && str[i] == '\n')
		i++;
	return (i);
}

int	ft_strlen_gnl(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_new_line(char *ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return (0);
	while (ptr[i])
	{
		if (ptr[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*extract_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	line = malloc(until_newline(str) + 1);
	if (!line)
		return (NULL);
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*ft_update(char *next_line)
{
	int		i;
	char	*updated_line;
	int		len;

	i = 0;
	if (!next_line)
		return (NULL);
	len = until_newline(next_line);
	if (!next_line[len])
	{
		free(next_line);
		return (NULL);
	}
	updated_line = malloc(ft_strlen_gnl(next_line) - len + 1);
	if (!updated_line)
		return (NULL);
	while (next_line[len])
		updated_line[i++] = next_line[len++];
	updated_line[i] = '\0';
	free(next_line);
	return (updated_line);
}
